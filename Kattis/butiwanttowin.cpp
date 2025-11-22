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
    long long den = 0;
    for (int &value : a) {
        cin >> value;
        den += value;
    }

    sort(a.begin(), a.end());
    long long num = a[a.size() - 2];

    for (int i = 0; i < a.size() - 2; i++) {
        num += a[i];
        if (num * 2 > den) {
            cout << i + 1;
            return 0;
        }
    }

    cout << "IMPOSSIBLE TO WIN";
}