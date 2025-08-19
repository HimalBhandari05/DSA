#include <stdio.h> 
#define max 5
#define true 1
#define false 0



struct stack{
    int tos;
    int data[max];
}S;


void Push(struct stack *s , int element);
int isFull(struct stack *s);
int isEmpty(struct stack *s);
int Pop(struct stack *s);

int main(){ 
    S.tos = -1;
    int choice;
    do
    {
        printf("1.Push Data \n2.Pop Data\n3.IsFull\n4.IsEmpty\n5.Exit\n");
        scanf("%d" , &choice);

        switch(choice){
            case 1:

                int element;
                printf("\nEnter the element to Push the data: ");
                scanf("%d" ,&element);
                Push(&S , element);
                break;

            case 2:
                printf("The popped value is : %d\n" , Pop(&S));
                break;

            case 3:
                printf("The situation of is full  is : %d\n" , isFull(&S));
                break;

            case 4:
                printf("The situation of is empty is : %d\n" ,isEmpty(&S));
                break;

            case 5:
                printf("The end \n");
                break;
            default:
                printf("Invalid Value \n");
                break;
        }
    } while ( choice != 5 );
    return 0;
    
}

void Push(struct stack *s , int element){
    if (s->tos == max-1){
        printf("The stack is full ! \n");
    }
    else{
        s->tos +=1;
        s->data[s->tos] = element;
    }
}


int isFull(struct stack *s){
    if(s->tos == max-1){
        return true;
    }
    else{
        return false;
    }
}


int isEmpty(struct stack *s){
    if(s->tos == -1){
        return true;
    }
    else{
        return false;
    }
}


int Pop(struct stack *s){
    int element;
    if (s->tos == -1){
        printf("The stack is empty ! \n");
    }
    else{
        element =s->data[s->tos];
        s->tos-=1;
        return element;
    }
}