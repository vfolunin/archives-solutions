#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a;
    float b;
    char c;
    char d[51];
    scanf("%d %f %c %[^\n]", &a, &b, &c, d);

    printf("%d%f%c%s\n", a, b, c, d);
    printf("%d\t%f\t%c\t%s\n", a, b, c, d);
    printf("%10d%10f%10c%10s\n", a, b, c, d);
}