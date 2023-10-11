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

    vector<int> count(3);
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        count[value - 1]++;
    }

    cout << max((count[1] + count[2] - count[0] + 1) / 2, 0);
}