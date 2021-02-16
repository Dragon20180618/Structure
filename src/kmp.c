/*
 * @Description: 
 * @Author: 
 * @Date: 2021-02-15 11:09:20
 * @LastEditTime: 2021-02-16 11:10:06
 */
#include<stdio.h>
#include<string.h>
#include<malloc.h>
int main(){ 
    char M[]="dasbabbaabbabbdsa";//index:8
    char T[]="abbab";
    int i,j,k;
    int lenT=strlen(T),lenM=strlen(M);
    int *t=(int*)malloc(sizeof(int)*lenT);//table
    //get particial match table;
    for(i=0;i<lenT;i++)
        t[i]=0;
    int sign;//match sign
    for(i=2;i<lenT;i++){//needn't first and last 
        for(j=1;j<i;j++){
            sign=1;
            for(k=0;k<j;k++){
                printf("i:%d,j:%d,k:%d,T[k]:%c,T[i-j+k]:%c\n",i,j,k,T[k],T[i-j+k]);
                if(T[k]!=T[i-j+k]){
                   sign=0; 
                   break;
                }
            }
            if(sign==1)
                t[i-1]=j;
        }
    }
    for(i=0;i<lenT;i++)
        printf("%d\t",t[i]);//output table
    printf("\n");
    i=0,j=0;//reset ij
    while(i<=lenM-lenT){
        printf("i:%d\tj:%d\n",i,j);
        if(M[i]==T[j]){
            i++;
            j++;
            if(j==lenT){
                printf("answer:%d\n", i-j);//final
                return 0;
            }
        }
        else{
            if(j==0){
                i++;
                continue;
            }
            i-=t[j-1];
            j=0;
        }
    }
}