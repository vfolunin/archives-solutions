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

    int size, targetSum, pos1, value1, pos2, value2;
    cin >> size >> targetSum >> pos1 >> value1 >> pos2 >> value2;

    pos1 = (pos1 - 1) % 3;
    pos2 = (pos2 - 1) % 3;

    if (pos1 == pos2)
        cout << (value1 == value2 && value1 < targetSum ? targetSum - value1 - 1 : 0);
    else
        cout << (value1 + value2 < targetSum);
}