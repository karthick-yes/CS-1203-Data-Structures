#include <stdio.h>
//Implementation of a simple list in C


void insert(int list[],int value, int index, int size) {
    if (index > size){
        printf("Error: index out of range\n");
        return;
    }

    for(int i = size; i > index; i -- ){
        list[i] = list[i - 1];
    }

    list[index] = value;
}
    




int main(){
    int list[10] = {1,2,3,4,5,6,7,8,9};

    insert(list, 50, 4, 9);

    for(int i = 0; i < 10; i++){
        printf("%d, ", list[i]);
    }


    return 0;

}  
 