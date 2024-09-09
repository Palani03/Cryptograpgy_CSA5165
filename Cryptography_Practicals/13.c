#include <stdio.h>
#define MOD 26

int mod(int x) {
    return (x % MOD + MOD) % MOD;
}
int main() {
    int p1[2] = {0, 1}, c1[2] = {2, 3}, p2[2] = {1, 2}, c2[2] = {3, 4};
    int key[2][2] = {
        {mod(c1[0] - c2[0]), mod(c1[1] - c2[1])},
        {mod(p1[0] * mod(c1[0] - c2[0]) + p1[1] * mod(c1[1] - c2[1])),
         mod(p2[0] * mod(c1[0] - c2[0]) + p2[1] * mod(c1[1] - c2[1]))}
    };
    printf("Recovered key:\n%d %d\n%d %d\n", key[0][0], key[0][1], key[1][0], key[1][1]);
    return 0;
}
Output:
Recovered key:
25 25
25 23
