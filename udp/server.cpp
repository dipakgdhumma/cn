// C++ program to show the example of server application in
// socket programming
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

int main()
{
    // creating socket
    int serverSocket = socket(AF_INET, SOCK_DGRAM, 0);

    // specifying the address
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // binding socket.
    bind(serverSocket, (struct sockaddr*)&serverAddress,
         sizeof(serverAddress));

    // listening to the assigned socket
    //listen(serverSocket, 5);

    // accepting connection request
    //int clientSocket
      //  = accept(serverSocket, nullptr, nullptr);
      sockaddr_in clientAddress;
      socklen_t clientaddrlen =  sizeof(clientAddress);

    // recieving data
    char buffer[1024] = { 0 };
    recvfrom(serverSocket, buffer, sizeof(buffer), 0,(struct sockaddr*)&clientAddress,&clientaddrlen);
    cout << "Message from client: " << buffer
              << endl;

    // closing the socket.
    close(serverSocket);

    return 0;
}

