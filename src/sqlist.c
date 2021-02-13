/*
 * @Description: 
 * @Author: 
 * @Date: 2021-02-13 21:32:27
 * @LastEditTime: 2021-02-13 21:59:34
 */
#include<stdio.h>
typedef struct{
    int v[100];
    int len;
}sqlist;
void init(sqlist *s){
    s->len=0;
}
void add(sqlist *s,int position, int value){
    int i;
    s->len++;
    for(i=s->len-1;i>position;i--){
        s->v[i]=s->v[i-1];
    }
    s->v[position]=value;
    return;
}
void delete(sqlist *s, int position){
    int i;
    for(i=position;i<s->len-1;i++){
        s->v[i]=s->v[i+1];
    }
    s->len--;
    return;
}
int main(){
    sqlist s;
    init(&s);
    add(&s,0,2);
    printf("%d\n",s.v[0]);
    return 0;
}