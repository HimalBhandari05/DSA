#include <stdio.h>
int moves = 0;

void TOH( int n , char src , char dst , char temp ){
    
    if (n==1){
        printf("Move disc %d from %c to %c\n" , n , src  , dst);
        moves += 1;
    }
    else{
        TOH(n-1 , src , temp , dst);
        printf("Move disc %d from %c to %c \n" , n , src , dst);
        TOH(n-1  , temp , dst , src);
        moves += 1;
    }
}

int main(){
    int choice; 
    printf("Enter the choices 'n' \n");
    scanf("%d" , &choice);
    char source , destn , temp;
    source = 'A';
    destn = 'C';
    temp = 'B';
    TOH(choice , source , destn , temp);
    printf("Total Moves : %d\n" , moves);
    return 0;
}

