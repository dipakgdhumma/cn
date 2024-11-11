#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fstream>

using namespace std;

int main ()
{
  int clientSocket = socket(AF_INET, SOCK_DGRAM, 0);

    // specifying address
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    	char message[2000] = {0};
    //ifstream infile("temp.txt" ios::binary);
    ifstream inFile("data.mp3", std::ios::binary);
    while(inFile.read(message,sizeof(message)))
    {
    	sendto(clientSocket, message, strlen(message), 0,(struct sockaddr*)&serverAddress,
            sizeof(serverAddress));
    }
    sendto(clientSocket, message, strlen(message), 0,(struct sockaddr*)&serverAddress,
            sizeof(serverAddress));

    // sending data
    cout << "data send";
    //const char* message = "Hello, server!";
    //sendto(clientSocket, message, strlen(message), 0,(struct sockaddr*)&serverAddress,
      //      sizeof(serverAddress));
      close(clientSocket);
      return 0;
}
