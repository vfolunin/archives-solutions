#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int size, int index) {
    if (size == 1)
        return 1;
    else if (index % 2 == 0)
        return index / 2;
    else
        return size / 2 + rec((size + 1) / 2, index / 2 + 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, index;
    cin >> size >> index;

    cout << rec(size, index);
}