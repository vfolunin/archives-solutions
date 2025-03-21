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

    for (int a = size / 2, b = size - size % 2; a; a--, b--)
        cout << a << " " << b << " ";

    if (size % 2)
        cout << size;
}