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
    // 剩余数量
    int quantity;
}Book;

typedef struct{
    // 用户id
    int user_id;
    // 书籍id
    int book_id;
    // 借阅时间戳
    int borrow_time;
}Borrow;


void add_book(Book *book_list, int *book_size, int *book_list_size);
void get_book_list(Book *book_list, int book_size);
void modify_book(Book *book_list, int book_size);
void delete_book(Book *book_list, int *book_size, int *book_list_size);

void search_book_by_name(Book *book_list, int book_size);
void search_book_by_id(Book *book_list, int book_size);

void borrow_book(Book *book_list, int *book_size, int user_id);
void return_book(Book *book_list, int *book_size, int user_id);

#endif