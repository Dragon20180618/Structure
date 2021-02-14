/*
 * @Description: 
 * @Author: 
 * @Date: 2021-02-13 21:32:27
 * @LastEditTime: 2021-02-14 12:50:03
 */
#include<stdio.h>
#include<malloc.h>
typedef struct{
    int *v;
    int len;
    int max;
}sqlist;
void init(sqlist *s){
    s->len=0;
    s->max=1;
    s->v=(int*)malloc(sizeof(int)*s->max);

}
void add(sqlist *s,int position, int value){
    int i;
    if(s->max==s->len){
        s->max*=2;
        s->len++;
        int *n=(int*)malloc(sizeof(int)*s->max);
        // printf("s->len:%d\ts->max:%d\n",s->len,s->max);
        for(i=s->len-1;i>position;i--){
            n[i]=s->v[i-1];
            // printf("i:%d,n[i]:%d\n",i,n[i]);
        }
        n[i]=value;
        i--;
        for(;i>0;i--){
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
    // printf("%d\n",s->v[0]);
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
int Index(sqlist *s,int value){//index is keyword, change to Index
    int i;
    for(i=0;i<s->len;i++){
        if(s->v[i]==value)
            return i;
    }
}
int main(){
    sqlist s;
    init(&s);
    add(&s,0,1);
    add(&s,0,2);
    add(&s,0,3);
    printf("%d\t%d\t%d\n",s.v[0],s.len,s.max);
    delete(&s,0);
    printf("%d\t%d\t%d\n",s.v[1],s.len,s.max);
    int x=Index(&s,1);
    printf("The index of value 1:%d\n",x);
    return 0;
}