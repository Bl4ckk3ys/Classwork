#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillArray(double* pArr, int size){
    srand(time(NULL));
    for(int i = 0;i<size;i++){
        pArr[i] = (double)rand()/1000;
    }
}

void fillFile(int* pArr, int size){
    FILE* pf;
    pf = fopen("text.txt","w");
    if(pf == NULL) printf("File not found");
    for (int i = 0;i<size;i++){
        fputc(pArr[i],pf);
    }
    fclose(pf);
}

void printFile(int size){
    FILE* pf;
    pf = fopen("text.txt","w");
    if(pf == NULL) printf("File not found");

    while (feof(pf)==0){
        fgets(buf,sizeof(double)*size,pf);
        printf("%s\n",buf)
    }
    
    fclose(pf);
}

int main(){
    int size = 0;
    scanf("%d",size);
    double* pArr = malloc(sizeof(double)*size);
    fillArray(pArr,size);
    return 1;
}