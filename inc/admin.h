#ifndef ADMIN_H
#define ADMIN_H

#include "user.h" 

void admin_login(User *user_list, int *size, int *user_list_size);
void menu_select(User *user_list, int *size, int *user_list_size);

void add_user(User *user_list, int *size, int *user_list_size);
void get_user_list(User *user_list, int size);
void modify_user(User *user_list, int size);
void delete_user(User *user_list, int *size, int *user_list_size);

#endif