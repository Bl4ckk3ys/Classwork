#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* int_to_char(int s){
    int i = 0, size = 0, copy = s;
    while(copy>0){
        size++;
        copy /= 10;
    }

    char* str = malloc(size+1);

    while (s > 0){
        str[size-i-1] = s % 10 + 48;
        s /= 10;
        i++;
    }
    str[size] = '\0';
    return str;
}

void delete(char* str, char elem){
    for (int i = 0; i < strlen(str); i++){
        if (str[i] == elem){
            for (int j = i; j < strlen(str)-1; j++){
                str[j] == str[j+1];
            }
        }    
    }
    printf("%s", str);
}

int main(){
    int num = 123;
    printf("%s\n", int_to_char(num));
    char str[] = "121341\0";
    delete(str, '1');
    
    return 0;
}