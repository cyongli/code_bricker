/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file many_threads.cpp
 * @author lichaoyong(com@baidu.com)
 * @date 2016/07/22 17:52:28
 * @brief 
 *  
 **/

#include <iostream>
#include <thread>
#include <vector>
#include <unistd.h>
using namespace std;

void hello(){
    cout << "hello" << endl;
    while(true) {
        sleep(1);
    }
}

int main(int argc, char *argv[]){
    vector<thread> v(100);
    for (int i = 0; i < 100; i++) {
    v[i] = thread(hello);
    }
    while(true) {
        sleep(1);
    }
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
