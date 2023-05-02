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

    vector<int> can(5e4 + 1);
    can[0] = 1;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        for (int sum = can.size() - 1; sum >= value; sum--)
            can[sum] |= can[sum - value];
    }

    cout << count(can.begin(), can.end(), 1);
}