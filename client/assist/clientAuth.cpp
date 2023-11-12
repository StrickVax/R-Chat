#include "../user/user.h"
#include "../user/userCred.h"
#include "clientAuth.h"


#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string>
#include <functional>
#include <thread>

ClientAuth::ClientAuth(int clientSocket, int serverPort, std::string serverDomainName) {
    this -> authSocket = clientSocket + 1;
    this -> serverPort = serverPort;
    this -> serverDomainName = serverDomainName;

    authSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (authSocket == -1) {
        std::cerr << "Error creating socket." << std::endl;
    }

    struct sockaddr_in serverAddr;
    struct hostent* serverInfo;

    // Resolve the domain name to an IP address
    serverInfo = gethostbyname(serverDomainName.c_str());
    if (serverInfo == nullptr) {
        std::cerr << "Error resolving host name." << std::endl;
        exit(0);
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(serverPort);
    memcpy(&serverAddr.sin_addr, serverInfo->h_addr, serverInfo->h_length);

    if (connect(authSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        std::cerr << "Error connecting to the server." << std::endl;
        exit(0);
    }

}

ClientAuth::~ClientAuth() {}

void ClientAuth::Prompt() {

    std::string choice;
    UserCred credentials;

    while(true){
        while (true) {
            //going to steal this code for the first character of the sending message (0 for register, 1 for login)
            std::cout << "Register(0) or Login(1): ";
            std::cin >> choice;

            if (choice == "0" || choice == "1") {
                break; // Exit the loop if a valid integer is entered
                
            } 
            
            else {
                std::cout << "Invalid input. Please enter a valid choice." << std::endl;
                std::cin.clear(); // Clear the error state
                std::cin.ignore(); // Discard the input buffer
            }
        }

        credentials.InputCredentials();

        this->authenticationUser = credentials.GetUser();

        if (choice == "0"){
            if(!Register())
            {
                std::cout << "This user already exists, please login instead." << std::endl;
                continue;
            }
            return;
        }

        else {
            //Login();
            return;
        }
    }

}

//This is where we can have the message to be sent to server 

bool ClientAuth::Register() {
    //ALWAYS START REGISTER WITH A 0 AND END WITH A NEWLINE OR IT WONT WORK RIGHT
    char message[] = "0test\n";
    /*std::string login = loginString();
    char *message = new char[login.length() + 1];
    message[0] == 0;
    for(int i = 1; i < login.length(); ++i)
    {
        message[i] = login.at(i);
    }
    message[login.length()] = '\0';*/
    int messageLength = strlen(message);
    int bytesSent = send(authSocket, message, messageLength, 0);
    if (bytesSent == -1) {
        std::cerr << "Error sending message." << std::endl;
        //delete message [];
        return false;
    }
    //delete message [];
    return ServerResponse();
}


bool ClientAuth::Login() {
    //ALWAYS START LOGIN WITH A 1 AND END WITH A NEWLINE OR IT WONT WORK RIGHT
    //logic to take input for use in the prompt method of client authenticator
    //char message[] = "1test\n";
    std::string login = loginString();
    char *message = new char[login.length() + 1];
    message[0] == 1;
    for(int i = 1; i < login.length(); ++i)
    {
        message[i] = login.at(i);
    }
    message[login.length()] = '\0';
    int messageLength = strlen(message);
    int bytesSent = send(authSocket, message, messageLength, 0);
    if (bytesSent == -1) {
        std::cerr << "Error sending message." << std::endl;
        //delete message[]
        return false;
    }
    //delete message[]
    return ServerResponse();
}

bool ClientAuth::ServerResponse() {
    //logic to take input for use in the prompt method of client authenticator
    char success[2];
    recv(authSocket, success, sizeof(success), 0);
    if(success[0] == 1){return true;}
    else{return false;}
    return false;
}


User ClientAuth::GetUser(){
    return this->authenticationUser;
}

std::string ClientAuth::loginString()
{
    std::string login;
    //login.append((char)0);
    login.append(authenticationUser.GetUsername());
    //login.append((char)17);
    login.append(authenticationUser.GetPassword());
    return login;
}