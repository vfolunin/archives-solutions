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

    int k4, k7, k9;
    cin >> k4 >> k7 >> k9;

    vector<int> indexes(3);
    for (int &index : indexes)
        cin >> index;

    sort(indexes.begin(), indexes.end());

    for (int index : indexes) {
        if (index <= k7)
            cout << 7;
        else if (index <= k7 + k9)
            cout << 9;
        else
            cout << 4;
    }
}