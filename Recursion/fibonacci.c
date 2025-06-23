#include <stdio.h>


long int fibo(int n){
    if ( n==0|| n==1 )
    {
        return 1;
    }
    else{
        return fibo(n-1) + fibo(n-2);
    }
}



int main(){
    int n;
    printf("Enter the number:\n");
    scanf("%d" , &n);
    int ret = fibo(n);
    printf("The nth fibo term is : %d \n" , ret);
    return 0;
}