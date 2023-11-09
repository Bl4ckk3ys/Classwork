#include <stdio.h>

int main(){
    int array[10] = {1,2,3,4};
    int a = 10;
    printf("Size of array = %d\n",sizeof(array));
    printf("%p \n",&array[0]);
    printf("%p \n",&array[1]);
    printf("%p \n",&array[2]);
    printf("%p \n",&array[3]);

    return 0;
}