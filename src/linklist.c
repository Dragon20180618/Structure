/*
 * @Description: 
 * @Author: 
 * @Date: 2021-02-14 12:50:54
 * @LastEditTime: 2021-02-14 20:34:50
 */
#include<stdio.h>
#include<malloc.h>
typedef struct{
    int v;
    struct Linklist *next;
}Linklist;
void init(Linklist *head){
    head->next=NULL;
}
void add(Linklist *head){
    Linklist *node=head;
    Linklist *w;
    int value;
    printf("Input the node's value:");
    scanf("%d",value);
    w->v=value;
    while(node->next!=NULL){
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
int main(void){
    Linklist head;
    int a;
    printf("%d\n",scanf("%d",&a));
    // create(&head);
    return 0;
}