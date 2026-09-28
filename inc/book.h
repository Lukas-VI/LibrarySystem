#ifndef BOOK_H
#define BOOK_H

#include <time.h>

typedef struct{
    // ID
    int book_id;
    // 书名
    char book_name[20];
    // 作者
    char author[20];
    // 出版社
    char publisher[20];
    // 价格
    float price;
    // 剩余数量
    int quantity;
}Book;

void add_book(BookContext *book_context);
void get_book_list(BookContext book_context);
void modify_book(BookContext *book_context);
void delete_book(BookContext *book_context);

void search_book_by_name(BookContext book_context);
void search_book_by_id(BookContext book_context);

#endif