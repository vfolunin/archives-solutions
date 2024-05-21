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

    int size, diff;
    cin >> size >> diff;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;
    sort(a.begin(), a.end());
    
    int res = 0;
    for (int l = 0, r = 0; r < size; r++) {
        while (a[l] + diff < a[r])
            l++;
        res += a[l] + diff == a[r];
    }

    cout << res;
}