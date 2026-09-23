#ifndef DATA_H
#define DATA_H

#include "user.h"
#include "book.h"

// 使用./data/user.data和./data/book.data文件作持久化 

// 读入内存
void load_user_data(User *user_list, int *size);
void load_book_data(Book *book_list, int *book_size);

// 保存
void save_user_data(User *user_list, int size);
void save_book_data(Book *book_list, int book_size);

// 保存借阅信息
void save_borrow_data(Borrow *borrow_list, int borrow_size);

// 排序：补齐空行，按id排序
void sort_user_data();
void sort_book_data();
void sort_borrow_data();

// 初始化size，从文件读取条目数得到size和list_size
void init_user_size(User *user_list, int *size, int *user_list_size);
void init_book_size(Book *book_list, int *book_size, int *book_list_size);
void init_borrow_size(Borrow *borrow_list, int *borrow_size, int *book_list_size);

#endif