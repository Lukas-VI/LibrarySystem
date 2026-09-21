#include <stdio.h>
#include <string.h>
#include "common.h"

void printWelcome(); 
void admin_login();
void user_login();
void login_select();
void menu_select();

void add_user();
void get_user_list();
void modify_user();
void delete_user();

void add_book();
void get_book_list();
void modify_book();
void delete_book();

// 使用./data/user.data和./data/book.data文件作持久化 
void load_user_data();
void load_book_data();


// 用户的结构图，用来保存一个用户的信息
struct User{
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

struct Book{
    // 书名
    char book_name[20];
    // 作者
    char author[20];
    // 出版社
    char publisher[20];
    // 价格
    float price;
};

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

    while (1)
    {
        // 打印欢迎信息
        printWelcome();
        login_select();
    }
    return 0;
}

// 登录模块
void admin_login() {
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

        if(strcmp(username, "admin") == 0 && strcmp(password, "admin") == 0) {
            // 登录成功， 进入菜单选择功能
            // printf("登录成功，即将进入菜单选择功能..........\n");
            // 进入菜单选择模块
            menu_select();

        }else {
            // 登录失败
            printf("用户名或密码错误~~~\n");
        }
    }
}

void user_login() {
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
            menu_select();

        }else {
            // 登录失败
            printf("用户名或密码错误~~~\n");
        }
    }
}

void login_select() {
    int select;
    printf("请输入登录类型（1：管理员登录， 2： 用户登录， -1：退出系统）：");
    scanf("%d", &select);
    if(select == -1) {
        printf("退出系统~~~~\n");
        exit(0);
    }else if(select == 1) {
        admin_login();
    }else if(select == 2) {
        user_login();
    }else {
        printf("您输入的登录类型有误，请重新输入~~~\n");
    }
}

// 添加用户
void add_user() {
    // 创建一个用户结构体的对象
    struct User user;
    // 打印欢迎信息
    printf("***************************************************************\n");
    printf("*************************添加用户模块***********************\n");
    printf("***************************************************************\n\n");
    //输入用户信息
     // 将用户信息保存到一个用户的结构体中
    printf("请输入用户名：");
    scanf("%s", user.username);
    printf("请输入密码：");
    scanf("%s", user.password);
    printf("请输入手机号：");
    scanf("%s", user.phone);
    printf("请输入邮箱：");
    scanf("%s", user.email);
    printf(("请输入姓名："));
    scanf("%s", user.name);


    // 将结构体（一个用户的信息）添加到一个结构体的数组中
    user_list[size] = user;
    size++;
}

// 查询用户列表
void get_user_list(){
    // 打印欢迎信息
    printf("***************************************************************\n");
    printf("*************************查询用户列表模块***********************\n");
    printf("***************************************************************\n\n");

    printf("----------------------------------------------------------------------------------------------------------------\n");
    printf("%20s %20s %20s %20s %20s\n", "用户名", "密码", "手机号", "邮箱", "姓名");
    printf("---------------------------------------------------------------------------------------------------------------\n");
    // 循环打印所有的用户信息
    for(int i = 0; i < size; i++) {     
        printf("%20s %20s %20s %20s %20s\n", user_list[i].username, user_list[i].password, user_list[i].phone, user_list[i].email, user_list[i].name);
        printf("---------------------------------------------------------------------------------------------------------------\n");
    
    }
}
// 修改用户
void modify_user() {
    int select;
    int item;
    
    printf("***************************************************************\n");
    printf("*************************修改用户模块***********************\n");
    printf("***************************************************************\n\n");

    printf("请输入要修改的用户编号：");
    scanf("%d", &select);
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
            scanf("%s", user_list[select].username);
            break;
        case 2:
            printf("请输入新的密码：");
            scanf("%s", user_list[select].password);
            break;
        case 3:
            printf("请输入新的手机号：");
            scanf("%s", user_list[select].phone);
            break;
        case 4:
            printf("请输入新的邮箱：");
            scanf("%s", user_list[select].email);
            break;
        case 5:
            printf("请输入新的姓名：");
            scanf("%s", user_list[select].name);
            break;
        default:
            printf("输入有误，请重新输入\n");
    }

}
// 删除用户
void delete_user() {
    int select;
    printf("***************************************************************\n");
    printf("*************************删除用户模块***********************\n");
    printf("***************************************************************\n\n");

    printf("请输入要删除的用户编号：");
    scanf("%d", &select);
    
    // 删除用户信息
    for(int i = select; i < size - 1; i++) {
        user_list[i] = user_list[i + 1];
    }
    size--;
}

// 功能菜单的选择
void menu_select() {
    printf("***************************************************************\n");
    printf("*************************菜单选择模块***********************\n");
    printf("***************************************************************\n\n");
    
    while(1) {
        printf("请输入功能编号（1：添加用户， 2： 查询用户列表，3：修改用户， 4：删除用户， -1：退出菜单选择）：");
        int flag;
        scanf("%d", &flag);
        if(flag == -1) {
            printf("退出菜单选择模块~~~~");
            break;
        }else if(flag == 1) {  // 添加用户
            add_user();
        }else if(flag == 2) { // 查询用户列表
            get_user_list();
        }else if(flag == 3) { // 修改用户
            modify_user();
        }else if(flag == 4) {  // 删除用户
            delete_user();
        }else {
            printf("您输入的功能编号有误，请重新输入~~~");
        }

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

void load_user_data() {
    FILE *fp = fopen("./data/user.data", "r");
    if(fp == NULL) {
        printf("打开文件失败\n");
        return;
    }
    while(fscanf(fp, "%s %s %s %s %s", user_list[size].username, user_list[size].password, user_list[size].phone, user_list[size].email, user_list[size].name) != EOF) {
        size++;
    }
    fclose(fp);
}

void load_book_data() {
    FILE *fp = fopen("./data/book.data", "r");
    if(fp == NULL) {
        printf("打开文件失败\n");
        return;
    }
    while(fscanf(fp, "%s %s %s %f", book_list[book_size].book_name, book_list[book_size].author, book_list[book_size].publisher, &book_list[book_size].price) != EOF) {
        book_size++;
    }
    fclose(fp);
}


