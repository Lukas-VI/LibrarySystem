#ifndef USER_H
#define USER_H

#include "common.h"
#include "book.h"
#include "borrow_book.h"

// 用户的结构体，用来保存一个用户的信息
typedef struct{
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
}User;

void user_login(UserContext user_context, BookContext book_context, BorrowContext borrow_context, int login_id);
void user_menu_select(UserContext user_context, BookContext book_context, BorrowContext borrow_context, int login_id);
void modify_user_personal(UserContext user_context, int login_id);

int form_id_to_index(int id, UserContext user_context);

#endif