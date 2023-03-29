//
// Created by saionji on 23-3-28.
//

#include "Tcp_handle.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "self_made.h"
Tcp_handle::Tcp_handle(int port) {


    struct sockaddr_in servaddr;
    //创建一个TCP的socket
    if( (listenfd = socket(AF_INET,SOCK_STREAM,0)) == -1) {
        printf(" create socket error: %s (errno :%d)\n",strerror(errno),errno);

    }
    //先把地址清空，检测任意IP
    memset(&servaddr,0,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);
    //地址绑定到listenfd
    if ( bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1) {
        printf(" bind socket error: %s (errno :%d)\n",strerror(errno),errno);
    }

}

int Tcp_handle::listen() {
    int connfd;
    if( ::listen(listenfd,10) == -1) {
        printf(" listen socket error: %s (errno :%d)\n",strerror(errno),errno);
       // return -1;
    }
    if( (connfd = accept(listenfd, (struct sockaddr *)NULL, NULL))  == -1) {
        printf(" accpt socket error: %s (errno :%d)\n",strerror(errno),errno);
        //return -2;
    }
    return connfd;
}

Tcp_handle::~Tcp_handle() {
    close(listenfd);
}

Socket::Socket(int id,strVector& sv) : id(id),sv(sv) {

}

int Socket::send_data(const std::string& message) const {
    return send(id,message.c_str(),message.length(),0);
}

Socket::~Socket() {
    close(id);
}

std::string Socket::recv_data() const {
    auto buff=new char[1024];
    auto size=recv(id,buff,1024,0);
    buff[size]='\0';
    std::string result(buff);
    delete[] buff;
    return result;
}

