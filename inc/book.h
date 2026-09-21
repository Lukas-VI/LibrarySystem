#ifndef BOOK_H
#define BOOK_H

void add_book();
void get_book_list();
void modify_book();
void delete_book();

struct Book{
    // 书名
    char book_name[20];
    // 作者
    char author[20];
    // 出版社
    char publisher[20];
    // 价格
    float price;
};

#endif