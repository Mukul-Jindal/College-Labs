#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <argp.h>
#include <sys/errno.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int socketID, n;
    char sendMessage[100];
    char receiveMessage[100];
    struct sockaddr_in serverAddress;
    socketID = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    connect(socketID, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
    while (true)
    {
        cout<<"Enter Message: ";
        fgets(sendMessage,100,stdin);
        send(socketID, sendMessage, sizeof(sendMessage), 0);
        if (strcmp(sendMessage, "exit\n") == 0)
        {
            cout << "Exiting.......\n";
            break;
        }
        recv(socketID, receiveMessage, sizeof(receiveMessage), 0);
        cout<<"Received Message: "<<receiveMessage<<endl;
    }
    return 0;
}