//
// Created by saionji on 23-3-26.
//

#ifndef NETWORK_MYSQL_CONNECTER_H
#define NETWORK_MYSQL_CONNECTER_H
#include <mysql/mysql.h>
#include <iostream>
#include "self_made.h"
#include <vector>
class Mysql_connecter {
public:
    Mysql_connecter();
    void insert(std::string sql);
    std::vector<char **> select(std::string sql);
    ~Mysql_connecter();
private:
    MYSQL* mysql;
};


#endif //NETWORK_MYSQL_CONNECTER_H
