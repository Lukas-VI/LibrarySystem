#include "common.h"
#include "book.h"
#include "borrow_book.h"
#include "data.h"
#include <time.h>

void borrow_book(Book *book_list, int *book_size, Borrow *borrow_list, int *borrow_size, int *borrow_list_size, int user_id) {
    Borrow borrow;
    borrow.book_id = -1;
    borrow.user_id = -1;
    borrow.borrow_time = -1;
    
    printf("***************************************************************\n");
    printf("*************************借阅书籍模块***********************\n");
    printf("***************************************************************\n\n");

    while(1) {
        printf("请输入要借阅的书籍id（如果输入 -1，就退出借阅书籍模块）：");
        int select_id;
        scanf("%d", &select_id);
        if(select_id == -1) {
            printf("退出借阅书籍模块\n");
            break;
        }
        // 判断输入的id是否在列表内
        int flag = 0;
        for(int i = 0; i < *book_size; i++) {
            if(book_list[i].book_id == select_id) {
                flag = 1;
                break;
            }
        }
        if(!flag) {
            printf("您输入的书籍id有误，请重新输入\n");
            continue;
        }else if (book_list[select_id].quantity <= 0) {
            printf("该书籍已被借完，请重新输入\n");
            continue;
        }else {
            book_list[select_id].quantity--;

            // 如果borrow列表已满，realloc一个更大的空间
            if(borrow_size >= borrow_list_size) {
                borrow_list = realloc(borrow_list, (*borrow_list_size + 50) * sizeof(Borrow));
                if(borrow_list == NULL) {
                    printf("内存分配失败\n");
                    exit(1);
                }
                *borrow_list_size += 50;
            }

            borrow.book_id = select_id;
            borrow.user_id = user_id;
            time(&borrow.borrow_time);

            // 将结构体（一个用户的信息）添加到一个结构体的数组中
            borrow_list[*borrow_size] = borrow;
            (*borrow_size)++;

                printf("借阅成功，请及时归还\n");
            break;
        }
    }
    // 保存到文件中
    save_borrow_data(borrow_list, *borrow_size);
    save_book_data(book_list, *book_size);    
}

void return_book(Book *book_list, int *book_size, Borrow *borrow_list, int *borrow_size, int *borrow_list_size,  int user_id) {    
    printf("***************************************************************\n");
    printf("*************************归还书籍模块***********************\n");
    printf("***************************************************************\n\n");
    printf("请输入要归还的书籍id（如果输入 -1，就退出归还书籍模块）：");
    while(1) {
        int select_id;
        scanf("%d", &select_id);
        if(select_id == -1) {
            printf("退出归还书籍模块\n");
            break;
        }
        // 判断输入的id是否在列表内
        int flag = 0;
        for(int i = 0; i < *book_size; i++) {
            if(book_list[i].book_id == select_id) {
                flag = 1;
                break;
            }
        }
        if(!flag) {
            printf("您输入的书籍id有误，请重新输入\n");
            continue;
        }
    }
    // 保存到文件中
    save_book_data(book_list, *book_size);
}
