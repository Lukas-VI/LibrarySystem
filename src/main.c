#include <stdlib.h>

#include "common.h"
#include "user.h"
#include "admin.h"
#include "book.h"
#include "data.h"



void printWelcome(); 
void login_select();

UserContext user_context;
BookContext book_context;
BorrowContext borrow_context;

int login_id = -1; // 登录的用户id，-1表示未登录


int main() {
    printf("Hello, %s!\n", PROJECT_NAME);

    init_user_data(&user_context);
    init_book_data(&book_context);
    init_borrow_data(&borrow_context);

    while (1)
    {
        // 打印欢迎信息
        printWelcome();
        login_select();
    }
    return 0;
}

// 登录模块
void login_select() {
    int select;

    printf("请输入登录类型（1：管理员登录， 2： 用户登录， -1：退出系统）：");
    
    scanf("%d", &select);
    
    if(select == -1) {
        printf("退出系统~~~~\n");
        exit(0);
    }else if(select == 1) {
        admin_login(user_list, &user_size, &user_list_capacity, book_list, &book_size, &book_list_capacity);
    }else if(select == 2) {
        user_login(user_list, &user_size, &user_list_capacity, book_list, &book_size, &book_list_capacity, borrow_list, &borrow_size, &borrow_list_capacity, login_id);
    }else {
        printf("您输入的登录类型有误，请重新输入~~~\n");
    }
}

// 打印欢迎信息
void printWelcome() {
    printf("***************************************************************\n");
    printf("***************************************************************\n");
    printf("*********************欢迎来到用户管理系统************************\n");
    printf("*********************1. 管理员登录************************\n");
    printf("*********************2. 用户登录************************\n");
    printf("*********************-1. 退出系统************************\n");
    printf("***************************************************************\n");
    printf("***************************************************************\n");
}

