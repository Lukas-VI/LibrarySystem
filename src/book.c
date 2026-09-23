#include "common.h"
#include "user.h"
#include "book.h"

void add_book(Book *book_list, int *book_size, int *book_list_size) {
    // 创建一个书籍结构体的对象
    Book book;
    // 打印欢迎信息
    printf("***************************************************************\n");
    printf("*************************添加书籍模块***********************\n");
    printf("***************************************************************\n\n");
    //输入书籍信息
     // 将书籍信息保存到一个书籍的结构体中
    printf("请输入书名：");
    scanf("%s", book.book_name);
    printf("请输入作者：");
    scanf("%s", book.author);
    printf("请输入出版社：");
    scanf("%s", book.publisher);
    printf("请输入价格：");
    scanf("%f", &book.price);
    printf("请输入剩余数量：");
    scanf("%d", &book.quantity);

    // 如果书籍列表已满，realloc一个更大的空间
    if(*book_size >= *book_list_size) {
        book_list = realloc(book_list, (*book_list_size + 50) * sizeof(Book));
        if(book_list == NULL) {
            printf("内存分配失败\n");
            exit(1);
        }
        *book_list_size += 50;
    }

    // 将结构体（一本书的信息）添加到一个结构体的数组中
    book_list[*book_size] = book;
    (*book_size)++;

    // 读取文件内最大id生成新id
    int max_id = 0;
    for(int i = 0; i < *book_size - 1; i++) {
        if(book_list[i].book_id > max_id) {
            max_id = book_list[i].book_id;
        }
    }
    book_list[*book_size - 1].book_id = max_id + 1;

    // 保存到文件中
    save_book_data(book_list, *book_size);
    
}


void get_book_list(Book *book_list, int book_size) {
    // 打印欢迎信息
    printf("***************************************************************\n");
    printf("*************************查询书籍列表模块***********************\n");
    printf("***************************************************************\n\n");

    printf("----------------------------------------------------------------------------------------------------------------\n");
    printf("%20s %20s %20s %20s %20s %20s\n", "书名", "作者", "出版社", "价格", "剩余数量", "ID");
    printf("---------------------------------------------------------------------------------------------------------------\n");
    // 循环打印所有的书籍信息
    for(int i = 0; i < book_size; i++) {     
        printf("%20s %20s %20s %20s %20s %20d\n", book_list[i].book_name, book_list[i].author, book_list[i].publisher, book_list[i].price, book_list[i].quantity, book_list[i].book_id);
        printf("---------------------------------------------------------------------------------------------------------------\n");
    
    }
}

void modify_book(Book *book_list, int book_size) {
    int select;
    int item;

    printf("***************************************************************\n");
    printf("*************************修改书籍模块***********************\n");
    printf("***************************************************************\n\n");

    while(1) {
        printf("请输入要修改的书籍编号（如果输入 -1，就退出修改书籍模块）：");
        scanf("%d", &select);
        if(select == -1) {
            printf("退出修改书籍模块\n");
            break;
        }else if(select < 0 || select >= book_size) {
            printf("您输入的书籍编号有误，请重新输入\n");
        }else {
            break;
        }
    }
    printf("请输入要修改的书籍信息：\n");
    printf("1. 书名\n");
    printf("2. 作者\n");
    printf("3. 出版社\n");
    printf("4. 价格\n");
    printf("5. 剩余数量\n");
    scanf("%d", &item);
    
    switch(item) {
        case 1:
            printf("请输入新的书名：");
            scanf("%s", book_list[select].book_name);
            break;
        case 2:
            printf("请输入新的作者：");
            scanf("%s", book_list[select].author);
            break;
        case 3:
            printf("请输入新的出版社：");
            scanf("%s", book_list[select].publisher);
            break;
        case 4:
            printf("请输入新的价格：");
            scanf("%s", book_list[select].price);
            break;
        case 5:
            printf("请输入新的剩余数量：");
            scanf("%s", book_list[select].quantity);
            break;
        default:
            printf("输入有误，请重新输入\n");
    }
    // 保存到文件中
    save_book_data(book_list, book_size);

}

void delete_book(Book *book_list, int *book_size, int *book_list_size) {
    int select_id;

    printf("***************************************************************\n");
    printf("*************************删除书籍模块***********************\n");
    printf("***************************************************************\n\n");
    
    while(1) {
        printf("请输入要删除的书籍id（如果输入 -1，就退出删除书籍模块）：");
        scanf("%d", &select_id);
        if(select_id == -1) {
            printf("退出删除书籍模块\n");
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
    // 删除内存中的书籍信息
    for(int i = select_id; i < *book_size - 1; i++) {
        book_list[i] = book_list[i + 1];
    }
    (*book_size)--;

    if(*book_list_size - *book_size >= 100) {
        book_list = realloc(book_list, (*book_list_size - 50) * sizeof(Book));
        if(book_list == NULL) {
            printf("内存分配失败\n");
            exit(1);
        }
        *book_list_size -= 50;
    }

    // 同步至文件
    save_book_data(book_list, *book_size);
    sort_book_data();
}

void search_book_by_name(Book *book_list, int book_size) {

}

void search_book_by_id(Book *book_list, int book_size) {

}

void borrow_book(Book *book_list, int *book_size, int user_id) {
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
            printf("借阅成功，请及时归还\n");
            break;
        }
    }
    // 保存到文件中
    save_book_data(book_list, *book_size);    
}

void return_book(Book *book_list, int *book_size, int user_id) {
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