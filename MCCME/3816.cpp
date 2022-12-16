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

    int size, defenderCount;
    cin >> size >> defenderCount;

    int borderCount = (size - 1) * 4;
    defenderCount -= borderCount;

    if (defenderCount >= 0)
        cout << size + defenderCount / 2;
    else
        cout << 0;
}