#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool test(int a, int b, int c) {
    for (int i = 1; i <= a; i++)
        if ((a - i) % 3 == 0 && b > i && (b - i - 1) % 3 == 0 && c > i && (c - i - 1) % 3 == 0)
            return 1;
    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a, b, c;
    cin >> a >> b >> c;
    
    if (test(a, b, c))
        cout << 1;
    else if (test(b, a, c))
        cout << 2;
    else
        cout << 3;
}