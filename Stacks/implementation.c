#include <stdio.h>
#include <stdlib.h>


struct SLL{
    int data;
    int tos;
    struct SLL * next;
};
struct SLL *first , *last = NULL;
void push(struct SLL *S ,int element);


void insertFromBeg(int element){
    struct SLL *newnode;
    newnode = (struct SLL*) malloc(sizeof(struct SLL));
    newnode->data = element;
    newnode->next = NULL;   
    if (first == NULL){
        first = last = newnode;
    }
    else{
        newnode->next = first;
        first = newnode;
    }
    printf("%d inserted from beginning \n" , first->data);
}

void insertFromEnd(int element){
    struct SLL *newnode;
    newnode = (struct SLL*) malloc(sizeof(struct SLL));
    newnode->data = element;
    newnode->next = NULL;
    if (first == NULL){
        first = last = newnode;
    }
    else{
        last->next = newnode;
        last = newnode;
    }
    printf("%d inserted from end \n" , last->data);
}
 
int deletefrombeg(){
    struct SLL *temp;
    if(first == NULL){
        printf("Can't delete ! list is empty\n");
    }
    else if(first->next == NULL){
        temp = first;
        first = NULL;
        free(temp);
    }
    else{
        temp = first;
        first = temp->next;
        free(temp);
    }
    printf("The element is deleted\n");
}  

int deletefromEnd(){
    int element;
    struct SLL *temp;
    if (first == NULL){
        printf("Can't delete");
    }
    else if(first->next == NULL){
        element = first->data;
        temp = first;
        first = NULL;
        free(temp);
    }
    else{
        temp = first;
        while(temp->next != last){
            temp = temp->next;
        }
        element = last->data;
        last = temp;
        temp = last->next;
        free(temp);
        last->next = NULL;
        printf("%d element is removed\n" ,element);
    }
}

void search(int key){
    int flag = 0;
    struct SLL *temp;
    if (first == NULL){
        flag = 0;
    }
    else{
        temp = first;
        while(temp != NULL){
            if(temp->data == key){
                flag=1;
            }
            temp = temp->next;
        }
        if (flag == 0){
            printf("There is no element found\n");
        }
        else{
            printf("Element %d found \n" , key);
        }
    }
}

void display(){
    struct SLL *temp;
    if (first == NULL){
        printf("The stack is empty \n");
    }
    else{
        temp = first;
        while(temp != NULL){
            printf("%d -> " , temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
void insertSpecific(int element , int pos){
    struct SLL *newnode;
    int i;
    struct SLL *temp;
    newnode = (struct SLL*) malloc(sizeof(struct SLL));
    newnode->data = element;
    newnode->next = NULL;
    if (first == NULL){
        first = last = newnode;
    }
    else{
        temp = first;
        for (i=1; i<pos -1 ; i++){
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        printf("%d is inserted at %d position\n" ,element , pos );
    }
}

void deleteSpecific(int pos){
    int element , i;
    struct SLL *temp , *tempp;
    if (first == NULL){
        printf("Can't delete");
    }
    else if(first->next == NULL){
        element = first->data;
        temp = first;
        first = NULL;
        free(temp);
    }
    else{
        temp = first;
        for(i=1 ; i<pos-1; i++){
            temp= temp->next;
        }   
        if(temp->next == last){
            last = temp;
            temp = last->next;
            free(temp);
            last->next = NULL;
        }
        else{
            tempp = temp->next;
            temp->next = tempp->next;
            free(tempp);
        }
    }
}

int main(){ 
    insertFromBeg(20);
    insertFromBeg(30);
    insertFromBeg(40);
    display();
    insertFromEnd(60);
    insertFromEnd(70);
    display();
    deletefrombeg();
    display();
    deletefromEnd();
    display();
    search(20);
    insertSpecific(40 , 3);
    display();
    insertSpecific(60 , 3);
    display();
    insertSpecific(70 , 3);
    display();
    deleteSpecific(3);
    display();
    deleteSpecific(3);
    display();
    return 0;
}                                  