#ifndef ADMIN_H
#define ADMIN_H

#include "user.h" 

void admin_login(UserContext user_context, BookContext book_context);
void admin_menu_select(UserContext user_context, BookContext book_context);
#endif