#include <iostream>
#include<sys/select.h>
#include<unistd.h>
#include<sys/types.h>
#include <mysql/mysql.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include <cstdlib>
#include <cstdio>
#include "Mysql_connecter.h"
#include <cstring>
using namespace std;
int main() {
   Mysql_connecter connecter;
   //connecter.insert("INSERT INTO `dia`.`agriculture` (`id`, `temperature`, `humidity`) VALUES (NULL, 56.3, 12.3);");
   auto re=connecter.select("select * from agriculture where id <20;");
    for (auto item:re) {
        lnprint(item[2]);
    }
    re=connecter.select("select * from agriculture where id <20;");
    for (auto item:re) {
        lnprint(item[2]);
    }
    return 0;
}
