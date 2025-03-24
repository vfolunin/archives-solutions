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

    if (a == 21)
        cout << "Vasya wins";
    else if (b == 21)
        cout << "Petya wins";
    else if ((a + b) / 5 % 2)
        cout << "Petya serves";
    else
        cout << "Vasya serves";
}