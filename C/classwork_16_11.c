#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* fillArr(int size){
    int* pArr = malloc(sizeof(int)*size);
    srand(time(NULL));
    for(int i; i<size; i++){
        pArr[i] = rand()%21 - 10;
   }
   return pArr;
}
int findGlobalMin(int* pArr, int size){
    int min = 11;
    if (pArr[0]<=pArr[1] && pArr[0]<min) min = pArr[0];
    if (pArr[size-1]<=pArr[size-2] && pArr[size-1]<min) min = pArr[size-1];   
    for(int i = 1;i<size-1;i++){
        if (pArr[i]<pArr[i-1] && pArr[i]<pArr[i+1] && min>pArr[i])min = pArr[i];
    }

}

int findGlobalMax(int arr[]){
    return 0;
}

int main(){
    int size = 20;
    int* arr = fillArr(size);
    fillArr(size);
    return 0;
}