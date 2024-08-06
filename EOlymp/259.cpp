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

    int aSize;
    cin >> aSize;

    vector<int> a(aSize);
    for (int &value : a)
        cin >> value;

    int bSize;
    cin >> bSize;

    int res = -1;
    for (int i = 0; i < bSize; i++) {
        int value;
        cin >> value;

        if (binary_search(a.begin(), a.end(), value))
            res = value;
    }

    cout << res;
}