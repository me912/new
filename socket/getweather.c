#include<stdio.h>
#include<string.h>	//strlen
#include<sys/socket.h>
#include<arpa/inet.h>	//inet_addr
#include <fcntl.h>
#include <unistd.h>
#include <netdb.h>
#include <stdlib.h>

#define cityid 1566083
#define apikey b3064c58d517c97cb9e4ff662ca05ba5
int main(){
    char *hostname = "api.openweathermap.org";
    int sockfd;
    struct sockaddr_in *weatherhost;
    char server_reply[2000];
    weatherhost = malloc(sizeof(struct sockaddr_in));

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1){
        perror("cant create a socket");
        exit(1);
    }
    struct hostent* he  = gethostbyname(hostname);
    
    struct in_addr ** addr_weatherapi = (struct in_addr **)he->h_addr_list;

    weatherhost->sin_addr = *addr_weatherapi[0];
    weatherhost->sin_family = AF_INET;
    weatherhost->sin_port = htons(80);

    if(connect(sockfd, (struct sockaddr*)weatherhost, sizeof(*weatherhost)) == -1)
    {
        perror("Connect error");
        exit(EXIT_FAILURE);
        
    }
    
    char* buf = "GET /data/2.5/onecall?lat=33.441792&lon=-94.037689&exclude=hourly,daily&appid=b3064c58d517c97cb9e4ff662ca05ba5 HTTP/1.1\r\nHost: api.openweathermap.org\r\nAccept: */*\r\n\r\n";
    send(sockfd, buf, strlen(buf), 0);
    printf("meassage sent!");
    read(sockfd, server_reply, 2000);
    printf("%s",server_reply);
    return 0;

    
    
}
