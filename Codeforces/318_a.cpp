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

    long long size, index;
    cin >> size >> index;
    index--;

    if (index < (size + 1) / 2)
        cout << index * 2 + 1;
    else
        cout << (index - (size + 1) / 2) * 2 + 2;
}