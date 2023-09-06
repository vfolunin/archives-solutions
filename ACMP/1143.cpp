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

    vector<int> a;

    while (1) {
        int value;
        cin >> value;

        if (!value)
            break;

        a.push_back(value);
    }

    int res = 0;
    for (int i = 1; i + 1 < a.size(); i++)
        res += a[i - 1] < a[i] && a[i] > a[i + 1];

    cout << res;
}