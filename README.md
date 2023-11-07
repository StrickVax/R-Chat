
# R'Chat

 > Authors:
- [Devin Shaw](https://github.com/DevinRShaw)
- [Mario Cuaya](https://github.com/mcuaya1)
- [Brian Byun](https://github.com/brianubyun)
- [Abraham Zambrano](https://github.com/StrickVax)
- [Mac Boyd](https://github.com/mboyd020)


## Project Description
 > * R'Chat is a chat room that runs on a server, authenticates, and accepts multiple clients at once, allowing clients to chat in real-time with each other. R'Chat allows admin users to moderate clients and keeps chat logs for later inspection by admin users.
>  * Discord is a common application that all of the team members use, which is a part of why we are interested in how programming for a chat application works. 
>  * Clients will run client executable, with terminal prompts for user authentication upon connection. Upon connection, client messages will be broadcast and received by other clients. Client will disconnect upon specific user input format. Server will also terminate upon specific input format by a server admin.
 > * Creating a client/server style chat room serves as an introduction to using C++ for socket programming and multithreading, both of which are important concepts in Embedded Systems, System Programming, Distributed Systems, and Cloud Computing. It is also a good exercise in using authentication methods and storing data. This project is also complex enough that it requires proper use of OOP concepts to keep code readable and scalable so it is great practice for us as students.
 > * This project is written in C++ and utilizes C++ tools such as CMake for ease of development. The functionality is supported by libraries for socket programming (networking), multithreading (multiple client handling), JSON file formatting for storing user credentials.
>  * Upon successful login user will be prompted with "Welcome to R'Chat"
>  * Upon unsuccessful login user will be prompted with "That is not a user, try again (y), register(r) or quit(q)"
>  * Messages from other users will be displayed in format "<username>: message contents"

 > ## Phase II
 > * Schedule two check-ins using Calendly. You need to pick both time slots on Tuesday of week 6. The check-ins will occur on Zoom. Your entire team must be present for both check-ins.
 >   * The first check-in needs to be scheduled with your lab TA. During that meeting, you will discuss your project design/class diagram from phase II.
 >   * The second check-in should be scheduled with a reader. During that meeting you will discuss:
 >     * The tasks you are planning for the first sprint
 >     * How work will be divided between the team members
## User Interface Specification

### Navigation Diagram
![navigation-graph drawio (1)noadmin drawio](https://github.com/cs100/final-project-azamb015-dshaw013-bbyun004-mcuay001-mboyd020/assets/88609025/6fe0d819-0e9d-4612-8666-7c9ef8236dff)



### Screen Layouts
> All interactions will occur via a Linux bash shell terminal. 

## Class Diagram
 > 
> 
> ![R'Chart class diagram drawio (1)](https://github.com/cs100/final-project-azamb015-dshaw013-bbyun004-mcuay001-mboyd020/assets/88609025/9a40fc61-9ea9-438f-bcc2-df5ff6658f9a)

> * The server class instantiates a server object that uses socket programming and creates threads to handle server input and client connection. 

> * Server Authenticator takes username and password from client to search data file for user existences.

> * Client class instantiates a client object that creates a connection to the server using sockets, server port, and server domain name. Also creates threads to handle sending and receiving messages from the server.

> * Client Authenticator sends username and password to the server, then prompts user based on server response

> * User class represents user information such as name and password. 



 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on Zoom and should be conducted by Wednesday of week 8.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
