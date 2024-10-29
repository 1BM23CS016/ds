#include <stdio.h>
int fib (int n);
int main() {
   
    int n, result;
    printf("\nEnter number: ");
    scanf("%d", &n);
    result = fib(n);
    printf( "%dth number of fibonacci series is %d" , n, result);


}


int fib(int n){
    if (n == 1){
        return 0;
         }
    else if (n == 2){
        return 1; 
        }
    else {
        return fib(n - 1) + fib(n - 2);
    }
}
