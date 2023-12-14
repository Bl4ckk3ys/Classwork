#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Date{
    int day;
    int month;
    int year;
};

struct Person{
    char* name;
    char* surname;
    struct Date BornDate;
    int gender;
    char* phonenumber;
    struct Person* BestFriend;
};

void PrintPersonInfo(struct Person p){
    printf("Name: %s\nSurname: %s\nBorn Date: %d\nGender: %s\nPhone Number: %s\n Best Friend: %s %s",p.name,p.surname,p.BornDate);
}

struct Person* createNewPerson(){
    char nameOfStruct[20];
    printf("Input name of struct: ");
    scanf("%s\n",nameOfStruct);
    
}
int main(){
    struct Person Denis = {"Denis","Karchkov",{19,7,1994},1,"88005553535",};
    struct Person Ilya = {"Ilya","Chechnev",{20,2,2005},1,"89101022075",};

    struct Person** notebook = malloc(sizeof(struct Person*)*100);
    int currentindex = 0;
    struct Person* newPerson = malloc(sizeof(struct Person));
    newPerson->name = "Denis";
    notebook[currentindex]=newPerson;
    currentindex++;
    
    return 1;
}