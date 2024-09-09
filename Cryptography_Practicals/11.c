#include <stdio.h>

long long factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}
int main() {
    long long possible_keys = factorial(25) / factorial(2); 
    printf("Possible keys: %lld\n", possible_keys);
    return 0;
}
Output:
Possible keys: 3517267638786981888
