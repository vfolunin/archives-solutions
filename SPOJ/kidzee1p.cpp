#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int a, b, c;
    cin >> a >> b >> c;

    bool arithmetic = b - a == c - b;
    bool geometric = b * b == c * a;

    cout << "Case " << test << ": ";
    if (arithmetic && geometric)
        cout << "Both\n";
    else if (arithmetic)
        cout << "Arithmetic Progression\n";
    else if (geometric)
        cout << "Geometric Progression\n";
    else
        cout << "None\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int testCount;
    cin >> testCount;

    for (int test = 1; test <= testCount; test++)
        solve(test);
}