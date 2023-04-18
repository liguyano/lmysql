# lmysql
## update in Tue Apr 18 21:49:07 2023
add a log system.  
```c++
timer= time(NULL);
pr std::string(ctime(&timer)).substr(0,24) A ":  ";
```
when the client close the connection, the program will make a error.
Build the log system.
## update in 2023年 04月 18日 星期二 20:22:09 CST
the program run properly.
use the thread.h instant of pthread.h. 
## update in Mar 29th 2023 
build the basis struct but the don't run properly.
May be not received the date , or may be the message 
vector haven't connected.
