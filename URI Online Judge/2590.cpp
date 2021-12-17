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
    
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int p;
        scanf("%d", &p);

        static int res[] = { 1, 7, 9, 3 };
        printf("%d\n", res[p & 3]);
    }
}