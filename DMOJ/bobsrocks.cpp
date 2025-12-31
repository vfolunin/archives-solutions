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

    vector<int> count(51);
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        count[value]++;
    }

    int res = 0;
    for (int value = 1; value < count.size(); value++)
        if (res * count[res] < value * count[value])
            res = value;

    cout << res;
}