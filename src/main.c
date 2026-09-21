#include <stdlib.h>

#include "common.h"
#include "user.h"
#include "admin.h"
#include "book.h"
#include "data.h"



void printWelcome(); 
void login_select();



// 用户的数组，这个数组的每个元素都是一个用户的信息（用户的结构体对象）
struct User user_list[100];
// 定义一个变量来记录数组中元素的个数
int size = 0;
// 书籍的数组，这个数组的每个元素都是一个书籍的信息（书籍的结构体对象）
struct Book book_list[100];
// 定义一个变量来记录数组中元素的个数
int book_size = 0;



int main() {
    printf("Hello, %s!\n", PROJECT_NAME);
    init_user_size(user_list, &size);
    init_book_size(book_list, &book_size);
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
        admin_login(user_list, &size);
    }else if(select == 2) {
        user_login(user_list, size);
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




