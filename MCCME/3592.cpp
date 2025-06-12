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

    sort(a.begin(), a.end());

    long long res = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = i + 1, l = j, r = j; j < a.size(); j++) {
            while (l < a.size() && a[i] * a[i] + a[j] * a[j] >= a[l] * a[l])
                l++;

            while (r < a.size() && a[i] + a[j] > a[r])
                r++;

            res += r - l;
        }
    }

    cout << res;
}