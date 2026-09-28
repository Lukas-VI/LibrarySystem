#ifndef COMMON_H
#define COMMON_H

#define PROJECT_NAME "Library System"

#define DEFAULT_ARRARY_SIZE 100

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    // 用户的数组，这个数组的每个元素都是一个用户的信息（用户的结构体对象）
    User *user_list;
    // 定义一个变量来记录数组中元素的个数
    int user_size;
    int user_list_capacity;
}UserContext;

typedef struct {
    // 书籍的数组，这个数组的每个元素都是一个书籍的信息（书籍的结构体对象）
    Book *book_list;
    // 定义一个变量来记录数组中元素的个数
    int book_size;
    int book_list_capacity;
}BookContext;

typedef struct {
    // 借阅的数组，这个数组的每个元素都是一个借阅的信息（借阅的结构体对象）
    Borrow *borrow_list;
    // 定义一个变量来记录数组中元素的个数
    int borrow_size;
    int borrow_list_capacity;
}BorrowContext;




#endif
