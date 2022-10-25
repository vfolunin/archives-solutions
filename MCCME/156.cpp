#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int size) {
    if (!size)
        return;

    int value;
    cin >> value;

    rec(size - 1);

    cout << value << " ";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    rec(size);
}