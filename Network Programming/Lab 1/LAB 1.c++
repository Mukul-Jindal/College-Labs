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
    int sockfd = socket(AF_LOCAL,SOCK_STREAM,0);
    return 0;
}