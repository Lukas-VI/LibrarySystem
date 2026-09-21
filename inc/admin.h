#ifndef ADMIN_H
#define ADMIN_H

#include "user.h" 

void admin_login(struct User *user_list, int *size);
void menu_select(struct User *user_list, int *size);

void add_user(struct User *user_list, int *size);
void get_user_list(struct User *user_list, int size);
void modify_user(struct User *user_list, int size);
void delete_user(struct User *user_list, int size);

#endif