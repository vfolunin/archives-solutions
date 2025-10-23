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

    int a, b, c;
    cin >> a >> b >> c;

    for (int i = 0; i < a; i++)
        for (int j = 0; j < 3; j++)
            cout << "*" << (j < 2 ? string(b, ' ') : "\n");

    cout << string(3 + b * 2, '*') << "\n";

    for (int i = 0; i < c; i++)
        cout << string(1 + b, ' ') << "*\n";
}