// 9. Write recursive program to find GCD of 3 numbers.
#include <stdio.h>
 
int gcd(int a, int b) {
    if (b == 0) {
        return a; 
    }
    return gcd(b, a % b); 
}

 
int gcdOfThree(int a, int b, int c) {
    return gcd(gcd(a, b), c);  
}

int main() {
    int num1, num2, num3,result;

    
    printf("Enter three positive integers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    
     result = gcdOfThree(num1, num2, num3);

    
    printf("G.C.D of %d, %d and %d is %d\n", num1, num2, num3, result);

    return 0;
}
