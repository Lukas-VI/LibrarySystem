#include "data.h"
#include "common.h"

void load_user_data(struct User *user_list, int *size) {
    FILE *fp = fopen("./data/user.data", "r");
    if(fp == NULL) {
        printf("打开文件失败\n");
        return;
    }
    while(fscanf(fp, "%d %s %s %s %s %s", &user_list[*size].id, user_list[*size].username, user_list[*size].password, user_list[*size].phone, user_list[*size].email, user_list[*size].name) != EOF) {
        (*size)++;
    }
    fclose(fp);
}

void load_book_data(struct Book *book_list, int *book_size) {
    FILE *fp = fopen("./data/book.data", "r");
    if(fp == NULL) {
        printf("打开文件失败\n");
        return;
    }
    while(fscanf(fp, "%s %s %s %f", book_list[*book_size].book_name, book_list[*book_size].author, book_list[*book_size].publisher, &book_list[*book_size].price) != EOF) {
        (*book_size)++;
    }
    fclose(fp);
}

void save_user_data(struct User *user_list, int size){
    FILE *fp = fopen("./data/user.data", "w");
    if(fp == NULL) {
        printf("打开文件失败\n");
        return;
    }
    // 从文件开头开始将内存中的数据覆写到文件
    // 指针fp指向文件开头
    fseek(fp, 0, SEEK_SET);
    
    for(int i = 0; i < size; i++) {
        fprintf(fp, "%d %s %s %s %s %s\n", user_list[i].id, user_list[i].username, user_list[i].password, user_list[i].phone, user_list[i].email, user_list[i].name);
    }
    fclose(fp);
}

void save_book_data(struct Book *book_list, int book_size){
    FILE *fp = fopen("./data/book.data", "w");
    if(fp == NULL) {
        printf("打开文件失败\n");
        return;
    }
    for(int i = 0; i < book_size; i++) {
        fprintf(fp, "%s %s %s %.2f\n", book_list[i].book_name, book_list[i].author, book_list[i].publisher, book_list[i].price);
    }
    fclose(fp);
}

// 序列化: 已删除的用户将在文件中的空余的行补齐
void serialize_user_data(){
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

void serialize_book_data(){
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

void init_user_size(struct User *user_list, int *size){
    FILE *fp = fopen("./data/user.data", "r");
    if(fp == NULL) {
        printf("打开文件失败\n");
        return;
    }
    while(fscanf(fp, "%d %s %s %s %s %s", &user_list[*size].id, user_list[*size].username, user_list[*size].password, user_list[*size].phone, user_list[*size].email, user_list[*size].name) != EOF) {
        (*size)++;
    }
    fclose(fp);
}

void init_book_size(struct Book *book_list, int *book_size){
    FILE *fp = fopen("./data/book.data", "r");
    if(fp == NULL) {
        printf("打开文件失败\n");
        return;
    }
    while(fscanf(fp, "%s %s %s %f", book_list[*book_size].book_name, book_list[*book_size].author, book_list[*book_size].publisher, &book_list[*book_size].price) != EOF) {
        (*book_size)++;
    }
    fclose(fp);
}