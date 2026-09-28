#ifndef BORROW_BOOK_H
#define BORROW_BOOK_H

typedef struct{
    // 用户id
    int user_id;
    // 书籍id
    int book_id;
    // 借阅时间戳
    time_t borrow_time;
}Borrow;

void borrow_book(Book *book_list, int *book_size, Borrow *borrow_list, int *borrow_size, int *borrow_list_size,  int user_id);
void return_book(Book *book_list, int *book_size, Borrow *borrow_list, int *borrow_size, int *borrow_list_size,  int user_id);

#endif