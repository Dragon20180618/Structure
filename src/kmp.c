/*
 * @Description: 
 * @Author: 
 * @Date: 2021-02-15 11:09:20
 * @LastEditTime: 2021-02-16 09:23:43
 */
#include<stdio.h>
#include<string.h>
int main(){ 
    char M[]="dasbdsa";
    char T[]="abbab";
    int i,j,k;
    int lenT=strlen(T),lenM=strlen(M);
    int t[5];
    //get particial match table;
    for(i=0;i<5;i++)
        t[i]=0;
    int sign;
    for(i=2;i<=5;i++){
        for(j=1;j<i;j++){
            sign=1;
            for(k=0;k<j;k++){
                printf("i:%d,j:%d,k:%d,T[k]:%c,T[i-j+k]:%c\n",i,j,k,T[k],T[i-j+k]);
                if(T[k]!=T[i-j+k]){
                   sign=0; 
                   break;
                }
            }
            if(sign==1){
                t[i-1]=j;
            }
        }
    }
    for(i=0;i<5;i++)
        printf("%d\t",t[i]);
}