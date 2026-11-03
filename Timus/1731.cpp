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

    int aSize, bSize;
    cin >> aSize >> bSize;

    for (int i = 1; i <= aSize; i++)
        cout << i << " ";
    cout << "\n";
    for (int i = 1; i <= bSize; i++)
        cout << (aSize + 1) * i << " ";
}