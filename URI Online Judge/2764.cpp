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

    int d, m, y;
    scanf("%d/%d/%d", &d, &m, &y);

    printf("%02d/%02d/%02d\n", m, d, y);
    printf("%02d/%02d/%02d\n", y, m, d);
    printf("%02d-%02d-%02d\n", d, m, y);
}