/*
 * @Description: 
 * @Author: 
 * @Date: 2021-02-13 21:32:27
 * @LastEditTime: 2021-02-14 12:20:25
 */
#include<stdio.h>
#include<malloc.h>
typedef struct{
    int *v;
    int len;
    int max;
}sqlist;
void init(sqlist *s){
    s->v=(int*)malloc(sizeof(int)*100);
    s->len=0;
    s->max=100;

}
void add(sqlist *s,int position, int value){
    int i;
    if(s->max=s->len){
        s->max*=2;
        s->len++;
        int *n=(int*)malloc(sizeof(int)*s->max);
        for(i=0;i<position;i++){
            n[i]=s->v[i];
        }
        n[i]=value;
        i++;
        for(;i<s->len;i++){
            n[i]=s->v[i];
        }
        free(s->v);
        s->v=n;
        return;
    }
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
    if(s->len<s->max/4&&s->max!=0){
        s->max/=2;
        int *n=(int *)malloc(sizeof(int)*s->max);
        for(i=0;i<s->len;i++){
            n[i]=s->v[i];
        }
        free(s->v);
        s->v=n;
    }
    return;
}
int main(){
    sqlist s;
    init(&s);
    add(&s,0,2);
    printf("%d\n",s.v[0]);
    return 0;
}