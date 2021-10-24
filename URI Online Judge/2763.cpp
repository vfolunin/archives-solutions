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

    char a[10], b[10], c[10], d[10];
    scanf("%[0-9].%[0-9].%[0-9]-%[0-9]", a, b, c, d);

    printf("%s\n%s\n%s\n%s\n", a, b, c, d);
}