#include "admin.h"
#include "user.h"
#include "common.h"
#include "data.h"


void admin_login(User *user_list, int *size, int *user_list_size) {
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
            menu_select(user_list, size, user_list_size);

        }else {
            // 登录失败
            printf("用户名或密码错误~~~\n");
        }
    }
}

void menu_select(User *user_list, int *size, int *user_list_size) {
    printf("***************************************************************\n");
    printf("*********************管理员用户编辑菜单选择模块***********************\n");
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


// 添加用户
void add_user(User *user_list, int *size, int *user_list_size) {
    // 创建一个用户结构体的对象
    User user;
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

    // 如果用户列表已满，realloc一个更大的空间
    if(*size >= *user_list_size) {
        user_list = realloc(user_list, (*user_list_size + 50) * sizeof(User));
        if(user_list == NULL) {
            printf("内存分配失败\n");
            exit(1);
        }
        *user_list_size += 50;
    }

    // 将结构体（一个用户的信息）添加到一个结构体的数组中
    user_list[*size] = user;
    (*size)++;

    // 读取文件内最大id生成新id
    int max_id = 0;
    for(int i = 0; i < *size - 1; i++) {
        if(user_list[i].id > max_id) {
            max_id = user_list[i].id;
        }
    }
    user_list[*size - 1].id = max_id + 1;


    // 保存到文件中
    save_user_data(user_list, *size);

}

// 查询用户列表
void get_user_list(User *user_list, int size) {
    // 打印欢迎信息
    printf("***************************************************************\n");
    printf("*************************查询用户列表模块***********************\n");
    printf("***************************************************************\n\n");

    printf("----------------------------------------------------------------------------------------------------------------\n");
    printf("%20s %20s %20s %20s %20s %20s\n", "用户名", "密码", "手机号", "邮箱", "姓名", "ID");
    printf("---------------------------------------------------------------------------------------------------------------\n");
    // 循环打印所有的用户信息
    for(int i = 0; i < size; i++) {     
        printf("%20s %20s %20s %20s %20s %20d\n", user_list[i].username, user_list[i].password, user_list[i].phone, user_list[i].email, user_list[i].name, user_list[i].id);
        printf("---------------------------------------------------------------------------------------------------------------\n");
    
    }
}

// 修改用户
void modify_user(User *user_list, int size) {
    int select;
    int item;

    printf("***************************************************************\n");
    printf("*************************修改用户模块***********************\n");
    printf("***************************************************************\n\n");

    while(1) {
        printf("请输入要修改的用户编号（如果输入 -1，就退出修改用户模块）：");
        scanf("%d", &select);
        if(select == -1) {
            printf("退出修改用户模块~~~~\n");
            break;
        }else if(select < 0 || select >= size) {
            printf("您输入的用户编号有误，请重新输入~~~\n");
        }else {
            break;
        }
    }
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
    // 保存到文件中
    save_user_data(user_list, size);

}
// 删除用户
void delete_user(User *user_list, int *size, int *user_list_size) {
    int select_id;

    printf("***************************************************************\n");
    printf("*************************删除用户模块***********************\n");
    printf("***************************************************************\n\n");
    
    while(1) {
        printf("请输入要删除的用户id（如果输入 -1，就退出删除用户模块）：");
        scanf("%d", &select_id);
        if(select_id == -1) {
            printf("退出删除用户模块~~~~\n");
            break;
        }
        // 判断输入的id是否在列表内
        int flag = 0;
        for(int i = 0; i < *size; i++) {
            if(user_list[i].id == select_id) {
                flag = 1;
                break;
            }
        }
        if(!flag) {
            printf("您输入的用户id有误，请重新输入~~~\n");
            continue;
        }
    }
    // 删除内存中的用户信息
    for(int i = select_id; i < *size - 1; i++) {
        user_list[i] = user_list[i + 1];
    }
    (*size)--;

    if(*user_list_size - *size >= 100) {
        user_list = realloc(user_list, (*user_list_size - 50) * sizeof(User));
        if(user_list == NULL) {
            printf("内存分配失败\n");
            exit(1);
        }
        *user_list_size -= 50;
    }

    // 同步至文件
    save_user_data(user_list, *size);
    sort_user_data();
}