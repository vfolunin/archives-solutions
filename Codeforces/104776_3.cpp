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

    int size, index;
    cin >> size >> index;

    if (index < size)
        cout << 4;
    else if (index == size)
        cout << 3;
    else if (index == 2 * size)
        cout << 6;
    else
        cout << 5;
}