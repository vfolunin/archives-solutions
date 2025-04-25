#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    unordered_map<int, int> last;
    int minGap = 1e9, minGapFrom;

    for (int i = 0; i < a.size(); i++) {
        cin >> a[i];

        if (last.count(a[i]) && minGap > i - last[a[i]] - 1) {
            minGap = i - last[a[i]] - 1;
            minGapFrom = i - minGap;
        }

        last[a[i]] = i;
    }

    cout << minGap << "\n";
    for (int i = 0; i < minGap; i++)
        cout << a[minGapFrom + i] << "\n";
}