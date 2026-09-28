#ifndef DATA_H
#define DATA_H

#include "user.h"
#include "book.h"
#include "common.h"

// 使用./data/user.data和./data/book.data文件作持久化 

// 保存
void save_user_data(UserContext *user_context);
void save_book_data(BookContext *book_context);
void save_borrow_data(BorrowContext *borrow_context);

// 排序：补齐空行，按id排序
void sort_user_data();
void sort_book_data();
void sort_borrow_data();

// 初始化数据，从文件读取条目到内存,并得到size和list_size
void init_user_data(UserContext *user_context);
void init_book_data(BookContext *book_context);
void init_borrow_data(BorrowContext *borrow_context);

#endif