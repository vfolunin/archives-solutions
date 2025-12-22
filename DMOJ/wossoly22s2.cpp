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

    int size;
    cin >> size;

    for (int i = size; i >= 1; i--)
        cout << i << " ";
    cout << "\n";

    cout << 1 << " ";
    for (int i = 3; i <= size; i++)
        cout << i << " ";
    if (size >= 2)
        cout << 2;
}