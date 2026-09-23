#ifndef BOOK_H
#define BOOK_H

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
}Book;

void add_book();
void get_book_list();
void modify_book();
void delete_book();

void search_book_by_name();
void search_book_by_id();

void borrow_book();
void return_book();

#endif