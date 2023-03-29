//
// Created by saionji on 23-3-29.
//

#ifndef NETWORK_THREAD_H
#define NETWORK_THREAD_H
#include <pthread.h>
#include <iostream>
#include "string"
#include "Mysql_connecter.h"
#include "Tcp_handle.h"


namespace String{
   std::vector<std::string> spilt(std::string o,char i);
}
namespace Thread{
    void command(std::string comm,Mysql_connecter& mysql);
    void* commandThread(void * s);
    void* socket_thread(void* so);
}


#endif //NETWORK_THREAD_H
