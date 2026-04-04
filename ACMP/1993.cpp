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

    if (size == 4)
        cout << 1000;
    else
        cout << 100 << 9 - size % 3 << string(size - 4, '0');
}