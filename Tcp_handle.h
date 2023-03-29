//
// Created by saionji on 23-3-28.
//

#ifndef NETWORK_TCP_HANDLE_H
#define NETWORK_TCP_HANDLE_H
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <iostream>
#include <vector>

#define strVector std::vector<std::string>
#define PORT 7000
#define QUEUE 20
class Socket;
class Tcp_handle {
private:
    int listenfd;
public:
    ~Tcp_handle();
    Tcp_handle(int port=7001);
    int listen();
};
class Socket{
private:
    const int id;
public:
    strVector& sv;
    ~Socket();

    explicit Socket(int id,strVector& sv);
    std::string recv_data() const;
    int send_data(const std::string& message) const;
};


#endif //NETWORK_TCP_HANDLE_H
