#include <stdio.h>

long int ifact(int n , long int a){
    if (n==0){
        return a;
    }
    else{
        return ifact(n-1, a*n);
    }
}

//  a chai 1 nei hunxa usually 

int main(){
    int n , a;
    printf("Enter the value of a\n");
    scanf("%d" , &a);
    printf("Enter the value of n\n");
    scanf("%d" , &n);
    int fact = ifact(n,a);
    printf("The factorial of %d is %d \n", n ,fact);
    return 0;
}