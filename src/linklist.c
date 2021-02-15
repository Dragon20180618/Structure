/*
 * @Description: 
 * @Author: 
 * @Date: 2021-02-14 12:50:54
 * @LastEditTime: 2021-02-14 21:58:40
 */
#include<stdio.h>
#include<malloc.h>
typedef struct Linklist{
    int v;
    struct Linklist *next;
}Linklist;
void init(Linklist *head){
    head->next=NULL;
}
void add(Linklist *head){
    Linklist *node=head;
    Linklist *w=(Linklist*)malloc(sizeof(Linklist));
    int value;
    printf("Input the node's value:");
    scanf("%d",&value);
    w->v=value;
    while(node->next){
        node=node->next;
    }
    node->next=w;
    w->next=NULL;
    return ;
}
void del(Linklist* head, int value){
    Linklist *node = head->next;
    Linklist *pre = head;
    while(node){
        if(node->v==value){
            pre->next=node->next;
            free(node);
            return;
        }
        node=node->next;
    }
}
void output(Linklist *head){
    if(!head->next){
        printf("The Linklist is null\n");
        return;
    }
    printf("The values of Linklist:");
    Linklist *node=head->next;
    while(node){
        printf("%d\t",node->v);
        node=node->next;
    }
    printf("\n");
}
int main(void){
    Linklist head;
    init(&head);
    add(&head);
    add(&head);
    output(&head);
    del(&head,1);
    output(&head);
    return 0;
}