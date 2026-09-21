#include "common.h"
#include "user.h"

void user_login(struct User *user_list, int size) {
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
