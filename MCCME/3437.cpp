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

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int mask;
        cin >> mask;

        int res = 0;
        for (int i = 0; i < a.size(); i++)
            if (mask & (1 << i))
                res += a[i];

        cout << res << "\n";
    }
}