#include "admin.h"
#include "user.h"
#include "common.h"
#include "data.h"
#include "edit_user.h"


void admin_login(User *user_list, int *size, int *user_list_size, Book *book_list, int *book_size, int *book_list_size) {
    while(1) {
        printf("***************************************************************\n");
        printf("*************************管理员登录模块***********************\n");
        printf("***************************************************************\n");
        printf("请输入管理员的用户名（如果输入 exit，就退出系统）：");
        char username[20];
        scanf("%s", username);

        // 如果用户名输入的是 exit, 就退出系统
        if(strcmp(username, "exit") == 0) {
            printf("bye bye~~~\n");
            break;
        }

        printf("请输入密码：");
        char password[20];
        scanf("%s", password);

        if(strcmp(username, "1") == 0 && strcmp(password, "1") == 0) {
            // 登录成功， 进入菜单选择功能
            // printf("登录成功，即将进入菜单选择功能..........\n");
            // 进入菜单选择模块
            admin_menu_select(user_list, size, user_list_size, book_list, book_size, book_list_size);

        }else {
            // 登录失败
            printf("用户名或密码错误~~~\n");
        }
    }
}

void admin_menu_select(User *user_list, int *size, int *user_list_size, Book *book_list, int *book_size, int *book_list_size) {
    printf("***************************************************************\n");
    printf("*********************管理员用户编辑菜单选择模块***********************\n");
    printf("***************************************************************\n\n");
    
    while(1) {
        printf("请输入功能编号\n（1：添加用户， 2： 查询用户列表，3：修改用户， 4：删除用户，\n 5.添加书籍，6.查询书籍列表，7：修改书籍，8：删除书籍\n -1：退出菜单选择）：");
        int flag;
        scanf("%d", &flag);
        if(flag == -1) {
            printf("退出菜单选择模块~~~~");
            break;
        }else if(flag == 1) {  // 添加用户
            add_user(user_list, size, user_list_size);
        }else if(flag == 2) { // 查询用户列表
            get_user_list(user_list, *size);
        }else if(flag == 3) { // 修改用户
            modify_user(user_list, *size);
        }else if(flag == 4) {  // 删除用户
            delete_user(user_list, size, user_list_size);
        }else if (flag == 5)
        {
            add_book(book_list, book_size, book_list_size);
        }else if (flag == 6)
        {
            get_book_list(book_list, *book_size);
        }else if (flag == 7)
        {
            modify_book(book_list, *book_size);
        }else if (flag == 8)
        {
            delete_book(book_list, book_size, book_list_size);
        }else {
            printf("您输入的功能编号有误，请重新输入~~~");
        }
    }
}


