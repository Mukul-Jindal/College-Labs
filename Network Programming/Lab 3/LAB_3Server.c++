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
    int udpSocket;
    char receive[100];
    const char *message = "Hello this is server side";
    struct sockaddr_in serveraddr, clientaddr;
    if ((udpSocket = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    memset(&serveraddr, 0, sizeof(serveraddr));
    memset(&clientaddr, 0, sizeof(clientaddr));

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = INADDR_ANY;
    serveraddr.sin_port = htons(8080);

    if (bind(udpSocket, (const struct sockaddr *)&serveraddr,
             sizeof(serveraddr)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    socklen_t length;
    int n;
    length = sizeof(clientaddr);
    
    n=recvfrom(udpSocket,(char *)receive,100,MSG_WAITALL,(struct sockaddr *)&clientaddr,&length);
    receive[n]='\0';
    cout<<"Client : "<<receive<<endl;

    sendto(udpSocket,message,strlen(message),MSG_CONFIRM,(const struct sockaddr * ) &clientaddr,sizeof(clientaddr));
    return 0;
}