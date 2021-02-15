/*
 * @Description: 
 * @Author: 
 * @Date: 2021-02-14 21:58:49
 * @LastEditTime: 2021-02-14 22:30:00
 */
#include<stdio.h>
#include<malloc.h>
typedef struct Dnode
{
    int v;
    struct Dnode* prior;
    struct Dnode* next;
}Dnode;
void Init(Dnode* head){
    head->next=head->prior=NULL;
}
void add(Dnode* head){
    Dnode *node=head,*w;
    int value;
    printf("Input the node's value:");
    scanf("%d",&value);
    while(node->next){
        node=node->next;
    }
    w=(Dnode*)malloc(sizeof(Dnode));
    w->v=value;
    w->prior=node;
    w->next=NULL;
    node->next=w;
    return;
}
void del(Dnode *head){
    Dnode* node=head;
    while(node->next){
        node=node->next;
    }
    node->prior->next=NULL;
    free(node);
}
void output(Dnode* head){
    if(!head->next){
        printf("The DLinklist is null\n");
        return;
    }
    Dnode* node=head->next;
    printf("The values of DLinklist: ");
    while(node){
        printf("%d\t",node->v);
        node=node->next;
    }
    printf("\n");
}
int main(){
    Dnode head;
    Init(&head);
    add(&head);
    output(&head);
    del(&head);
    output(&head);
    return 0;
}