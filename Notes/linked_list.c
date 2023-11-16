#include<stdio.h>
#include<stdlib.h>
//insert at the beginning implementation of linked lists
// define the data structure
struct Node
{
    int data;//the data part of the structure
    struct Node* next;//the pointer to the next address

};
//declare the pointer to head as a global variable
struct Node* head;
//create the insert function which would insert in the beginning
void insert(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = x;
    temp -> next = head;
    head = temp;

}
//to traverse and print the values of each nodes
void Print(){
    struct Node* temp = head;
    printf("List is:");
    while(temp != NULL){
        printf("%d", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}



int main(){
    head = NULL;
    printf("How many numbers?\n");
    int i, n, x;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        printf("Enter the desired number\n");
        scanf("%d", &x);
        insert(x);
        Print();
    }


}
