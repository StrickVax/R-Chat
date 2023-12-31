#ifndef CHATLOGGER_H
#define CHATLOGGER_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>

class Logger {
public:
    Logger(std::string saveFileName = "R'ChatLogs.txt") {
        this->saveFile = saveFileName;
    }

    void logMessage(char message[] ) {
      //Get current time
      auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

      //Converts time to string
      char timeString[100]; 
      std::strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", std::localtime(&now));

      //Open the file in append mode
      std::ofstream ChatLog(this->saveFile, std::ios_base::app);

      //Write the timestamp and message to file
      ChatLog << "[" << timeString << "] " << message << std::endl;

      ChatLog.close();
    }

private:
    std::string saveFile;
};

#endif 