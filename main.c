#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* generate(int size){
    int* pArr = malloc(sizeof(int)*size);
    for(int i = 0;i<size;i++){
        pArr[i] = 1;
    }
    return pArr;
}

void randomReplace(int* pArr,int size){
    srand(time(NULL));
    int rand_i = rand()%size; 
    pArr[rand_i] =  -1;
}

void findNumber(int* pArr, int size, int* pIndex){
    for(int i = 0; i<size;i++){
        if(pArr[i]==-1){
            *pIndex = i;
            break;
        }
    }
}
void SumOfMatrix(int* matrix1, int* matrix2, int* matrix3){
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
             matrix3[i*3+j] =  matrix1[i*3+j] + matrix2[i*3+j];
        }
    }
}
void print_two_int(double* nums){
    int* IntArray = (int*)nums;
    printf("%d %d\n",IntArray[0],IntArray[1]);
}

void operate(int a, int b, int* pS, int* pR, int* pP, double* pD){
    *pS = a+b;
    *pR = a-b;
    *pP = a*b;
    if(b!=0){
        *pD = (double)a/b;
    }
    else pD = 0;
}
    

int main(){
    int a = 10, b = 5, s, r, p;
    double d;
    operate(a,b,&s,&r,&p,&d);
    printf("%d %d %d %d %d %lf\n",a,b,s,r,p,d);


    // int first = 10;
    // int second = 1000;

    // int* array = malloc(sizeof(int)*2);
    // array[0] = first;
    // array[1] = second;

    // double* pointer = (double*)array;

    // print_two_int(pointer);

    // int* matrix1 = malloc(sizeof(int)*9);
    // int* matrix2 = malloc(sizeof(int)*9);
    // int* matrix3 = malloc(sizeof(int)*9);
    // for (int i = 0; i<9; i++){
    //     matrix1[i] = i;
    //     matrix2[i] = 8-i;
    // }
    // SumOfMatrix(matrix1,matrix2,matrix3);
    // for(int i = 0;i<3;i++){
    //     for(int j = 0;j<3;j++){                                     
    //         printf("%d\t",matrix3[i*3+j]);
    //     }
    //     printf("\n");
    // }
    // int index;
    // int* pArray = generate(10);
    // randomReplace(pArray,10);
    // findNumber(pArray,10,&index);
    // printf("%d",index);
    // int size_array = 9;
    // int* pArray = malloc(sizeof(int)*size_array);
    // for(int i = 0;i<size_array;i++){
    //     pArray[i]= i;
    // }
    //двумерный массив через указатели
    // int* row1 =  malloc(sizeof(int)*4);
    // int* row2 =  malloc(sizeof(int)*4);
    // int* row3 =  malloc(sizeof(int)*4);
    // int* row4 =  malloc(sizeof(int)*4);
    
    // int** rows = malloc(sizeof(int*)*4); //массив указателей
    // rows[0] = row1;
    // rows[1] = row2;
    // rows[2] = row3;
    // rows[3] = row4;
    // for(int i = 0;i<4;i++){
    //     for(int j = 0;j<4;j++){
    //         rows[i][j] = i*j;
    //         printf("%d\t",rows[i][j]);
    //     }
    //     printf("\n");
    // }
    //проход двумерного массива (как)через одномерный
    // for(int i = 0;i<3;i++){
    //     for(int j = 0;j<3;j++){
    //         printf("%d\t",pArray[i*3+j]);
    //     }
    //     printf("\n");
    // }
    // free(pArray);//Всегда очищать память, после выделения оперативной памяти
    return 0;
}