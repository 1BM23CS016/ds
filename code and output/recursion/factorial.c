#include <stdio.h>
int fact (int n);
int main() {
   
    int n, result;
    printf("\nEnter number: ");
    scanf("%d", &n);
    result = fact(n);
    if (n<0){
        printf("Undefined for negative numbers!");
    }
    else {
    printf( "factorial of %d = %d" , n, result);
    }


}

int fact( int n){
    if ((n == 0) || (n == 1)){
        return 1;
    }
    else {
        return n * fact(n - 1);
    }
}