/*
 * @Description: 
 * @Author: 
 * @Date: 2021-02-16 14:57:03
 * @LastEditTime: 2021-02-16 16:15:12
 */
#include<stdio.h>
#include<malloc.h>
typedef struct node{
    int v;
    struct node *lchild, *rchild;
}node;
void preorder(node *n){
    if(!n)
        return;
    printf("%d\t",n->v);
    preorder(n->lchild);
    preorder(n->rchild);
}
void inorder(node *n){
    if(!n)
        return;
    inorder(n->lchild);
    printf("%d\t",n->v);
    inorder(n->rchild);    
}
void lastorder(node *n){
    if(!n)
        return;
    lastorder(n->lchild);
    lastorder(n->rchild);  
    printf("%d\t",n->v);  
}
void levelorder(node *n){
    node *a[5]={NULL,NULL,NULL,NULL,NULL};
    int p=0;
    printf("%d\n",n->v);
    if(n->lchild)
        a[p++]=n->lchild;
    if(n->rchild)
        a[p++]=n->rchild;
    while(a[0]){
        if(a[0]->lchild)
            a[p++]=a[0]->lchild;
        if(a[0]->rchild)
            a[p++]=a[0]->rchild;
        printf("%d\t",a[0]->v);
        p--;
        if(p==0)
            return;
        for(int i=0;i<p;i++){
            a[i]=a[i+1];
        }
    }
}
void test(){
    node *root=(node*)malloc(sizeof(node));
    node *r=(node*)malloc(sizeof(node));
    node *l=(node*)malloc(sizeof(node));
    l->v=1;
    r->lchild=r->rchild=l->lchild=l->rchild=NULL;
    root->v=2;
    r->v=3;
    root->lchild=l;
    root->rchild=r;
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    lastorder(root);
    printf("\n");
    levelorder(root);
    printf("\n");
}
int main(void){
    test();
    // printf("%d\n",root->lchild->v);
    return 0;
}