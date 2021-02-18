/*
 * @Description: the position of global variable
 * @Author: 
 * @Date: 2021-02-18 10:19:40
 * @LastEditTime: 2021-02-18 11:38:43
 */
#include<stdio.h>
// void f1(){
//     printf("%d\n",a);
// }
int a=1;
void f2(){
    printf("%d\n",a);
}
int main(){
    // f1();
    f2();
    return 0;
}