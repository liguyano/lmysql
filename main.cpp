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
#include <cstring>
using namespace std;
int main() {
    MYSQL mysql;
    //1.初始化操作句柄
    //MYSQL *     STDCALL mysql_init(MYSQL *mysql);
    mysql_init(&mysql);
    /*
     * 操作句柄
     * host ： 服务端所在机器的ip地址
     * 数据库的用户名：
     * 数据库的密码：
     * 数据库名称
     * 数据库端口
     * unix_socket : AF_UNIX（进程间通信的方式）  AF_INET（网络套接字）
     * clientflag : CLIENT_FOUND_ROWS
     * */
    if(!mysql_real_connect(&mysql,"43.136.94.231", "user01", "WWPdsg12", "dia", 3306, NULL, CLIENT_FOUND_ROWS))
    {
        //const char * STDCALL mysql_error(MYSQL *mysql);
        cout << mysql_error(&mysql) << endl;
        return -1;
    }

    const char* sql = "INSERT INTO `dia`.`agriculture` (`temperature`, `humidity`, `data`) VALUES (12.5, 222.2, '2023-03-26')";
    mysql_query(&mysql, sql);
    mysql_close(&mysql);
    return 0;


}
