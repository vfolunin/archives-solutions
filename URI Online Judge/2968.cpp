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

    int a, b;
    cin >> a >> b;

    int p = a * b;
    for (int i = 1; i < 10; i++)
        cout << (p * i + 9) / 10 << (i < 9 ? ' ' : '\n');
}