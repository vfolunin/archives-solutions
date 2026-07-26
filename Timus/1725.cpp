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

    if (index > size / 2)
        index = size + 1 - index;

    cout << max(0, size - index - 2);
}