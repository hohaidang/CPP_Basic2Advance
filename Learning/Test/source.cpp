#include<stdio.h>
#include<stdlib.h>


 

void testNum(void){
    int num;
    printf("value of num: %d\n", num++);
    num++;
    printf("value of num: %d\n", num++);
}

 

int main(void)
{
    testNum();
    testNum();
    return 0;
}