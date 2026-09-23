#include "common.h"
#include "user.h"
#include "book.h"


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

void user_menu_select(User *user_list, int *size, Book *book_list, int *book_size, int *user_list_size, int *book_list_size, int login_id) {
    printf("***************************************************************\n");
    printf("*********************用户菜单选择模块***********************\n");
    printf("***************************************************************\n\n");
    
    while(1) {
        printf("请输入功能编号（1：借阅书籍，2：归还书籍，3： 查询书籍列表，4：修改个人信息， -1：退出菜单选择）：");
        int flag;
        scanf("%d", &flag);
        if(flag == -1) {
            printf("退出菜单选择模块~~~~");
            break;
        }else if(flag == 1) {  // 借阅书籍
            borrow_book(book_list, book_size, login_id);
        }else if(flag == 2) { // 归还书籍
            return_book(book_list, book_size, login_id);
        }else if(flag == 3) { // 查询书籍列表
            get_book_list(book_list, *book_size);
        }else if(flag == 4) { // 修改个人信息
            modify_user_personal(user_list, *size, login_id);
        }else {
            printf("您输入的功能编号有误，请重新输入~~~");
        }
    }
}

// 修改个人信息
void modify_user_personal(User *user_list, int size, int login_id) {
    int select;
    int item;
    int index = form_id_to_index(login_id, user_list, size);

    printf("***************************************************************\n");
    printf("*************************修改用户模块***********************\n");
    printf("***************************************************************\n\n");

    printf("请输入要修改的用户信息：\n");
    printf("1. 用户名\n");
    printf("2. 密码\n");
    printf("3. 手机号\n");
    printf("4. 邮箱\n");
    printf("5. 姓名\n");
    scanf("%d", &item);
    

    switch(item) {
        case 1:
            printf("请输入新的用户名：");
            scanf("%s", user_list[index].username);
            break;
        case 2:
            printf("请输入新的密码：");
            scanf("%s", user_list[index].password);
            break;
        case 3:
            printf("请输入新的手机号：");
            scanf("%s", user_list[index].phone);
            break;
        case 4:
            printf("请输入新的邮箱：");
            scanf("%s", user_list[index].email);
            break;
        case 5:
            printf("请输入新的姓名：");
            scanf("%s", user_list[index].name);
            break;
        default:
            printf("输入有误，请重新输入\n");
    }
    // 保存到文件中
    save_user_data(user_list, size);

}

int form_id_to_index(int id, User *user_list, int size)
{
    for(int i = 0; i < size; i++) {
        if(user_list[i].id == id) {
            return i;
        }
    }
    return -1;
}