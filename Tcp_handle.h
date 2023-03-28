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
#define PORT 7000
#define QUEUE 20

class Tcp_handle {
public:
    Tcp_handle();
};


#endif //NETWORK_TCP_HANDLE_H
