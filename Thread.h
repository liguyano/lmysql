//
// Created by saionji on 23-3-29.
//

#ifndef NETWORK_THREAD_H
#define NETWORK_THREAD_H
#include <thread>
#include <iostream>
#include "string"
#include "Mysql_connecter.h"
#include "Tcp_handle.h"


namespace String{
   std::vector<std::string> spilt(std::string o,char i);
}
namespace Thread{
    void command(std::string comm,Mysql_connecter& mysql);
    void* commandThread(strVector* s);
    void* socket_thread(Socket * so);
}


#endif //NETWORK_THREAD_H
