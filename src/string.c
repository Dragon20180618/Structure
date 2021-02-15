/*
 * @Description: 
 * @Author: 
 * @Date: 2021-02-15 10:43:51
 * @LastEditTime: 2021-02-15 11:03:29
 */
#include<stdio.h>
int main(){
    int i,j;
    char a[10]="aabcddass";
    printf("main string:%s\n",a);
    char test[4]="aaa";
    printf("test string:%s\n",test);
    i=0,j=0;
    while(i<=7){
        if(j==3){
            printf("%d\n",i);
            return 0;
        }
        else if(a[i+j]==test[j]){
            j++;
        }
        else{
            i++;
            j=0;
        }
    }
    printf("can't find it\n");
}