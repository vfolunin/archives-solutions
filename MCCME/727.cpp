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

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int resIndex, resCost = 1e9;

    for (int i = 0; i < size; i++) {
        int cost = 0;
        for (int j = 0; j < size; j++)
            cost += a[j] * min(abs(i - j), size - abs(i - j));

        if (resCost > cost) {
            resIndex = i + 1;
            resCost = cost;
        }
    }

    cout << resIndex;
}