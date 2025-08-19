#include <stdio.h>

long int gcd(int a , int b){
    if (b==0){
        return a;
    }
    else{
        return gcd(b , a%b);
    }
}

int main(){
    int a , b , GCD;
    printf("Enter the value of a and b \n");
    scanf("%d , %d" , &a , &b);
    GCD = gcd(a,b);
    printf("The hcf of two numberr is  %d" ,GCD );
    return 0;
}