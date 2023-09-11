#include<sys/socket.h>
#include<sys/types.h>
#include<netdb.h>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int socketName,n;
    char sendMessage[100],receiveMessage[100];
    struct sockaddr_in serverAddress,clientAddress;

    bzero(&serverAddress,sizeof(serverAddress));
    bzero(&clientAddress,sizeof(clientAddress));

    socketName = socket(AF_INET,SOCK_DGRAM,0);
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port= htons(8080);
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(socketName,(struct sockaddr *)&serverAddress,sizeof(serverAddress));

    socklen_t length;
    length = sizeof(clientAddress);

    while (true)
    {
        n=recvfrom(socketName,receiveMessage,100,0,(struct sockaddr *)&clientAddress,&length);
        // receiveMessage[n]="\0";
        cout<<"Client: "<<receiveMessage<<endl;
        if(strcmp(receiveMessage,"exit\n")==0)
        {
            cout<<"Exiting............\n";
            break;
        }
        cout<<"Server: ";
        fgets(sendMessage,100,stdin);
        sendto(socketName,sendMessage,100,0,(struct sockaddr *)&clientAddress,sizeof(clientAddress));
    }
    close(socketName);
    return 0;
}