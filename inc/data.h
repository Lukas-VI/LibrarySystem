#ifndef DATA_H
#define DATA_H

#include "user.h"
#include "book.h"

// 使用./data/user.data和./data/book.data文件作持久化 

// 读入内存
void load_user_data(struct User *user_list, int *size);
void load_book_data(struct Book *book_list, int *book_size);

// 保存
void save_user_data(struct User *user_list, int size);
void save_book_data(struct Book *book_list, int book_size);

// 序列化: 已删除的用户将在文件中的空余的行补齐
void serialize_user_data();
void serialize_book_data();

// 初始化size，从文件读取条目数得到size
void init_user_size(struct User *user_list, int *size);
void init_book_size(struct Book *book_list, int *book_size);

#endif