//
// Created by saionji on 23-3-29.
//

#include "Thread.h"
static  time_t timer = time(NULL);
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

void* Thread::socket_thread(Socket *so ) {
    std::string s;
    std::ofstream messgaeLog;
    messgaeLog.open("message.txt",std::ios::app);
    while (true)
    {
        s=so->recv_data();
        messgaeLog<< std::string(ctime(&timer)).substr(0,24) A ":  ";
        messgaeLog<< so->getIp()<<":" A so->getPort() A " ";
        messgaeLog<< s END;
        if (s=="close")
        {
            timer= time(NULL);
            pr std::string(ctime(&timer)).substr(0,24) A ":  ";
            pr so->getIp() A ":" A so->getPort() A "  close manually" END;
            delete so;
            break;
        }else
        {
            so->send_data("recvd;");
        so->sv.push_back(s);
        }
    }
    timer= time(NULL);
    pr std::string(ctime(&timer)).substr(0,24) A ":  ";
    lnprint("socket_thread quit");
}

void *Thread::commandThread(strVector* s) {

    timer=time(NULL);
    pr std::string(ctime(&timer)).substr(0,24) A ":  ";
    lnprint("gonna to start mysql connecter");
    Mysql_connecter connecter;
    timer= time(NULL);
    pr std::string(ctime(&timer)).substr(0,24) A ":  ";
    lnprint("mysql connector init succed");
    while (1)
    {
        while (s->size()>0) {
            auto a=s->at(0);
            //lnprint(a);
            command(a,connecter);
            s->erase(s->begin());
        }
    }
}