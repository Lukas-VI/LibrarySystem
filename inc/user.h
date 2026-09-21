#ifndef USER_H
#define USER_H

#include "common.h"


// 用户的结构体，用来保存一个用户的信息
struct User{
    // ID
    int id;
    // 用户名
    char username[20];
    // 密码
    char password[20];
    // 手机号
    char phone[12];
    // 邮箱
    char email[25];
    // 姓名
    char name[10];
};

void user_login(struct User *user_list, int size);

#endif