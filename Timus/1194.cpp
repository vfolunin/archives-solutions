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

    int size, pairCount;
    cin >> size >> pairCount;

    cout << size * (size - 1) / 2 - pairCount;
}