#include <iostream>
#include "Mysql_connecter.h"
#include "Tcp_handle.h"
#include <cstring>
#include "Thread.h"
using namespace std;

int main() {

    //Thread::command("UPTH+12.7+9.77",connecter);
    Tcp_handle tcp(7001);
    strVector strv;
    pthread_t pid;
    pthread_create(&pid, NULL, Thread::commandThread, (void *)&strv);
    while (true)
    {
        auto so=new Socket(tcp.listen(),strv);

        pthread_create(&pid, NULL, Thread::socket_thread, (void *)so);
    }
   /* Socket socket1(12);
    Tcp_handle handle;
    auto so =handle.listen();
    auto s=so->recv_data();
    lnprint(s);
    so->send_data("hello\r");
    so->send_data("hello\r");
    so->send_data("hello\r");
    delete so;*/
    return 0;
}
/*   Mysql_connecter connecter;
   //connecter.insert("INSERT INTO `dia`.`agriculture` (`id`, `temperature`, `humidity`) VALUES (NULL, 56.3, 12.3);");
   auto re=connecter.select("select * from agriculture where id <20;");
    for (auto item:re) {
        lnprint(item[2]);
    }
    re=connecter.select("select * from agriculture where id <20;");
    for (auto item:re) {
        lnprint(item[2]);
    }*/