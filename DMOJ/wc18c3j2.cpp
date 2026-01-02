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

    vector<int> a;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value <= 100)
            a.push_back(value);
    }

    sort(a.rbegin(), a.rend());

    int res = 0;
    for (int i = 0; i < 2 && i < a.size(); i++)
        res += a[i];

    cout << res;
}