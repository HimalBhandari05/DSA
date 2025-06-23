#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define max 50
struct stack {
    int tos;
    float data[max];
} S;

void Push(struct stack *s , float element);
float Pop(struct stack *s);

int main() {
    S.tos = -1;
    float op1, op2, result, num;
    char postfix[100];
    char *token; 
    printf("Enter expression with space : \n");
    fgets(postfix , 100 , stdin);  // this takes the input with extra spaces too and ends with a new line
    token = strtok(postfix , " \n"); // it tokenize the postfix and add \0 after scan of delimmeter and eventually ends with \0 for all tokens
    //  yesto hunxa  |'3'|'\0'|'4'|'\0'| and so on 

    while(token != NULL){  // token null nahunjel samma while loop run hunxa 
        if(isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))){
            num = atof(token);
            Push(&S , num); 
        }
        else {
            op1 = Pop(&S);
            op2 = Pop(&S);
            switch (token[0]) {
                case '*': Push(&S, op2 * op1); 
                    break;
                case '-': Push(&S, op2 - op1); 
                    break;
                case '+': Push(&S, op2 + op1); 
                    break;
                case '/': Push(&S, op2 / op1); 
                    break;
                case '^': Push(&S, pow(op2, op1)); 
                    break;
                default: printf("Invalid operator"); 
                    break;
            }
        }
        token = strtok(NULL , " \n"); // jaha null end vako thyo tespaxi token feri start hunxa
    }
    result = Pop(&S);
    printf("The result is %f\n", result);
}

void Push(struct stack *s , float element) {
    if (s->tos == max - 1) {
        printf("The stack is full!\n");
    } else {
        s->tos += 1;
        s->data[s->tos] = element;
    }        
}

float Pop(struct stack *s) {
    float element = 0;
    if (s->tos == -1) {
        printf("Stack Underflow\n");
    } else {
        element = s->data[s->tos];
        s->tos -= 1;
    }
    return element;
}