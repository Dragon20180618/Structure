/*
 * @Description: 
 * @Author: 
 * @Date: 2021-02-15 09:49:01
 * @LastEditTime: 2021-02-15 09:59:03
 */
#include<stdio.h>
#include<malloc.h>
typedef struct stack{
    int v[100];
    int sp;
}stack;
stack ss;
void Init(){
    int i;
    for(i=0;i<100;i++)
        ss.v[i]=0;
    ss.sp=0;
}
void push(int value){
    if(ss.sp==100){
        printf("stack overflow\n");
        return;
    }
    ss.v[ss.sp]=value;
    ss.sp++;
}
int pop(){
    if(ss.sp==0){
        printf("stack overflow\n");
        return -1;
    }
    ss.sp--;
    return ss.v[ss.sp];
}
int main(void){
    free(&ss);
    return 0;
}