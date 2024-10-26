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

    vector<int> count(1001);
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        count[abs(value)] += value;
    }

    for (int value : count)
        if (value)
            cout << -value;
}