//
// Created by saionji on 23-3-26.
//

#include "Mysql_connecter.h"

Mysql_connecter::Mysql_connecter() {
    mysql=new MYSQL;
    //1.初始化操作句柄
    //MYSQL *     STDCALL mysql_init(MYSQL *mysql);
    mysql_init(mysql);
    if(!mysql_real_connect(mysql,"43.136.94.231", "user01", "WWPdsg12", "dia", 3306, NULL, CLIENT_FOUND_ROWS))
    {
        //const char * STDCALL mysql_error(MYSQL *mysql);
        std::cout << mysql_error(mysql) << std::endl;
        return;
    }
    lnprint("init succed");
}

std::vector<char **> Mysql_connecter::select(std::string sql) {
    std::vector<char**> result;
    mysql_query(mysql, sql.c_str());
    auto re=mysql_store_result(mysql);
    auto rownum=mysql_num_rows(re);
    pr "rownum:";
    lnprint(rownum);
    pr "colm num:";
    lnprint(mysql_num_fields(re));
    for (int i = 0; i < rownum; ++i) {
        auto row=mysql_fetch_row(re);
        //lnprint(row[2]);
        result.push_back(row);
    }
    mysql_free_result(re);
    return result;
}

Mysql_connecter::~Mysql_connecter() {
    mysql_close(mysql);
    delete mysql;
}

void Mysql_connecter::insert(std::string sql) {
    mysql_query(mysql, sql.c_str());
}
