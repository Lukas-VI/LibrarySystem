#include "data.h"
#include "common.h"

void save_user_data(UserContext *user_context){
    FILE *fp = fopen("./data/user.data", "w");
    if(fp == NULL) {
        printf("打开文件失败\n");
        return;
    }
    // 从文件开头开始将内存中的数据覆写到文件
    // 指针fp指向文件开头
    fseek(fp, 0, SEEK_SET);

    for(int i = 0; i < user_context->user_size; i++) {
        fprintf(fp, "%d %s %s %s %s %s\n", 
            user_context->user_list[i].id, 
            user_context->user_list[i].username, 
            user_context->user_list[i].password, 
            user_context->user_list[i].phone, 
            user_context->user_list[i].email, 
            user_context->user_list[i].name);
    }
    fclose(fp);
}

void save_book_data(BookContext *book_context){
    FILE *fp = fopen("./data/book.data", "w");
    if(fp == NULL) {
        printf("打开文件失败\n");
        return;
    }
    for(int i = 0; i < book_context->book_size; i++) {
        fprintf(fp, "%s %s %s %.2f\n",        
        book_context->book_list[i].book_name, 
        book_context->book_list[i].author, 
        book_context->book_list[i].publisher, 
        book_context->book_list[i].price);
    }
    fclose(fp);
}

void save_borrow_data(BorrowContext *borrow_context) {
    FILE *fp = fopen("./data/borrow.data", "w");
    if(fp == NULL) {
        printf("打开文件失败\n");
        return;
    }
    for(int i = 0; i < borrow_context->borrow_size; i++) {
        fprintf(fp, "%d %d %lld\n", 
            borrow_context->borrow_list[i].user_id, 
            borrow_context->borrow_list[i].book_id, 
            borrow_context->borrow_list[i].borrow_time);
    }
    fclose(fp);
}

// 排序：补齐空行，按id排序
void sort_user_data(){
    FILE *fp = fopen("./data/user.data", "r+");
    if(fp == NULL) {
        printf("打开文件失败\n");
        return;
    }
    char line[100];
    while(fgets(line, sizeof(line), fp) != NULL) {
        if(strcmp(line, "\n") == 0) {
            fseek(fp, -strlen(line), SEEK_CUR);
            fprintf(fp, "empty\n");
        }
    }
    fclose(fp);
}

void sort_book_data(){
    FILE *fp = fopen("./data/book.data", "r+");
    if(fp == NULL) {
        printf("打开文件失败\n");
        return;
    }
    char line[100];
    while(fgets(line, sizeof(line), fp) != NULL) {
        if(strcmp(line, "\n") == 0) {
            fseek(fp, -strlen(line), SEEK_CUR);
            fprintf(fp, "empty\n");
        }
    }
    fclose(fp);
}

void init_user_data(UserContext *ctx)
{
    FILE *fp = fopen("./data/user.data", "r");
    if (fp == NULL) {
        printf("打开文件失败，视为无数据\n");
        ctx->user_size = 0;
        return;
    }

    ctx->user_size = 0;

    User tmp;
    while (fscanf(fp, "%d %s %s %s %s %s",
                  &tmp.id, tmp.username, tmp.password,
                  tmp.phone, tmp.email, tmp.name) == 6)
    {
        /* 容量不够时扩容（注意 realloc 失败不能覆盖原指针！） */
        if (ctx->user_size >= ctx->user_list_capacity) {
            int new_cap = (ctx->user_list_capacity == 0)
                          ? 8 : ctx->user_list_capacity * 2;

            User *new_list = realloc(ctx->user_list,
                                     new_cap * sizeof(User));
            if (new_list == NULL) {
                printf("内存分配失败\n");
                fclose(fp);
                exit(1);
            }
            ctx->user_list = new_list;      // 扩容成功才赋值
            ctx->user_list_capacity = new_cap;
        }

        ctx->user_list[ctx->user_size] = tmp;
        ctx->user_size++;
    }
    fclose(fp);
}

void init_book_data(BookContext *ctx)
{
    FILE *fp = fopen("./data/book.data", "r");
    if (fp == NULL) {
        printf("打开文件失败，视为无数据\n");
        ctx->book_size = 0;
        return;
    }

    ctx->book_size = 0;

    Book tmp;
    while (fscanf(fp, "%d %s %s %s %f %s",
                  &tmp.book_id, tmp.book_name, tmp.author,
                  tmp.publisher, &tmp.price, &tmp.quantity) == 6)
    {
        /* 容量不够时扩容（注意 realloc 失败不能覆盖原指针！） */
        if (ctx->book_size >= ctx->book_list_capacity) {
            int new_cap = (ctx->book_list_capacity == 0)
                          ? 8 : ctx->book_list_capacity * 2;

            User *new_list = realloc(ctx->book_list,
                                     new_cap * sizeof(User));
            if (new_list == NULL) {
                printf("内存分配失败\n");
                fclose(fp);
                exit(1);
            }
            ctx->book_list = new_list;      // 扩容成功才赋值
            ctx->book_list_capacity = new_cap;
        }

        ctx->book_list[ctx->book_size] = tmp;
        ctx->book_size++;
    }
    fclose(fp);
}

void init_book_data(BorrowContext *ctx)
{
    FILE *fp = fopen("./data/borrow.data", "r");
    if (fp == NULL) {
        printf("打开文件失败，视为无数据\n");
        ctx->borrow_size = 0;
        return;
    }

    ctx->borrow_size = 0;

    Borrow tmp;
    while (fscanf(fp, "%d %d %lld",
                  &tmp.user_id, &tmp.book_id, &tmp.borrow_time) == 3)
    {
        /* 容量不够时扩容（注意 realloc 失败不能覆盖原指针！） */
        if (ctx->borrow_size >= ctx->borrow_list_capacity) {
            int new_cap = (ctx->borrow_list_capacity == 0)
                          ? 8 : ctx->borrow_list_capacity * 2;

            User *new_list = realloc(ctx->borrow_list,
                                     new_cap * sizeof(User));
            if (new_list == NULL) {
                printf("内存分配失败\n");
                fclose(fp);
                exit(1);
            }
            ctx->borrow_list = new_list;      // 扩容成功才赋值
            ctx->borrow_list_capacity = new_cap;
        }

        ctx->borrow_list[ctx->borrow_size] = tmp;
        ctx->borrow_size++;
    }
    fclose(fp);
}