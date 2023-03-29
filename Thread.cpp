//
// Created by saionji on 23-3-29.
//

#include "Thread.h"

void Thread::command(std::string comm,Mysql_connecter& mysql) {

    auto co=String::spilt(comm,'+');
    if (co[0]=="UPTH")
    {
        //"INSERT INTO `dia`.`agriculture` (`id`, `temperature`, `humidity`) VALUES (NULL, 56.3, 12.3);"
        std::string sql="INSERT INTO `dia`.`agriculture` (`id`, `temperature`, `humidity`,`data`,`time`) VALUES (NULL,";
        sql+=co[1];
        sql+=',';
        sql+=co[2];
        sql+=",curdate(),curtime());";
        lnprint(sql);
        mysql.insert(sql);

    }
}

std::vector<std::string> String::spilt(std::string o, char oi) {
    std::vector<std::string> result;
    long start= 0;

    for (int i=0;i<o.size();i++) {
        auto c = o[i];
        if (oi == c) {
            result.push_back(o.substr(start, i - start));
            start = i;
            start++;
        }
    }
   // pr "start :" A start END;
    if (start<o.size())
    {
        result.push_back(o.substr(start,o.size()-start));
    }
    return result;
}

void* Thread::socket_thread(void *so ) {
    std::string s;
    auto os=(Socket*) so;
    while (true)
    {
        s=os->recv_data();
        os->sv.push_back(s);
    }

}

void *Thread::commandThread(void *s) {
    Mysql_connecter connecter;
    auto strv=(strVector*) s;
    while (strv->size()>0) {
        auto a=strv->at(0);
        command(a,connecter);
        strv->erase(strv->begin());
    }
}