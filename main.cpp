#include <iostream>
#include "Mysql_connecter.h"
#include "Tcp_handle.h"
#include <cstring>
#include "Thread.h"
using namespace std;

int main() {
    Tcp_handle tcp(7001);
    strVector strv;
    thread th1(Thread::commandThread,&strv);
    vector<thread*> threads;time_t timer = time(NULL);
    while (true)
    {
        auto so=new Socket(tcp.listen(),strv);
        timer= time(NULL);
        pr std::string(ctime(&timer)).substr(0,24) A ":  ";
        pr so->getIp() A ":" A so->getPort() A " ";
        lnprint("connected");
        auto th2=new thread(Thread::socket_thread,so);
        threads.push_back(th2);
    }
    return 0;
}