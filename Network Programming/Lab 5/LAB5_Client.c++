#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int socketName,n;
    char sendMessage[100],receiveMessage[100];
    struct sockaddr_in address;

    socketName = socket(AF_INET,SOCK_DGRAM,0);
    bzero(&address,sizeof(address));

    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_family = AF_INET;
    address.sin_port = htons(8080);
    socklen_t length;
    while (true)
    {
        cout<<"Client: ";
        fgets(sendMessage,100,stdin);
        sendto(socketName,sendMessage,100,0,(struct sockaddr *)&address,sizeof(address));
        if (strcmp(sendMessage,"exit\n")==0)
        {
            cout<<"Exiting...........\n";
            break;
        }
        
        n = recvfrom(socketName,receiveMessage,100,0,(struct sockaddr *)&address,&length);
        receiveMessage[n]='\0';
        cout<<"Server: "<<receiveMessage<<endl;
    }
    close(socketName);
    return 0;
}