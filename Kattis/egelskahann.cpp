#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int joseph2(int size) {
    if (size == 1)
        return 1;
    else if (size % 2)
        return joseph2(size / 2) * 2 + 1;
    else
        return joseph2(size / 2) * 2 - 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    cout << joseph2(size);
}