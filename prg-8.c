	#include <stdio.h>

void towerOfHanoi(int n, char source, char target, char auxiliary) {
   
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", source, target);
        return;
    }
    
 
    towerOfHanoi(n - 1, source, auxiliary, target);
    
   
    printf("Move disk %d from rod %c to rod %c\n", n, source, target);
    
   
    towerOfHanoi(n - 1, auxiliary, target, source);
}

int main() {
    int n = 4;
    printf("Solution for Tower of Hanoi with %d disks:\n", n);
    towerOfHanoi(n, 'A', 'C', 'B'); // A is the source rod, C is the target rod, B is the auxiliary rod
    return 0;
}