#include "common.h"
#include "user.h"

void user_login(User *user_list, int *size, int *user_list_size) {
    while(1) {
        printf("***************************************************************\n");
        printf("*************************用户登录模块***********************\n");
        printf("***************************************************************\n");
        printf("请输入用户名（如果输入 exit，就退出系统）：");
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

        // 判断用户名和密码是否正确
        int flag = 0;
        for(int i = 0; i < size; i++) {
            if(strcmp(username, user_list[i].username) == 0 && strcmp(password, user_list[i].password) == 0) {
                flag = 1;
                break;
            }
        }

        if(flag == 1) {
            // 登录成功， 进入菜单选择功能
            printf("登录成功，即将进入菜单选择功能..........\n");
            // 进入菜单选择模块
            // user_menu_select();

        }else {
            // 登录失败
            printf("用户名或密码错误~~~\n");
        }
    }
}

void user_menu_select(User *user_list, int *size, int *user_list_size) {
    printf("***************************************************************\n");
    printf("*********************用户菜单选择模块***********************\n");
    printf("***************************************************************\n\n");
    
    while(1) {
        printf("请输入功能编号（1：添加用户， 2： 查询用户列表，3：修改用户， 4：删除用户， -1：退出菜单选择）：");
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
            delete_user(user_list, size, *user_list_size);
        }else {
            printf("您输入的功能编号有误，请重新输入~~~");
        }
    }
}