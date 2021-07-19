#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getMin(vector<int> a, vector<int> b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int res = 0;
    for (int i = 0, j = 0; i < a.size() || j < b.size(); ) {
        if (i < a.size() && j < b.size() && a[i] == b[j]) {
            res += a[i];
            i++;
            j++;
        } else if (i < a.size() && (j == b.size() || a[i] < b[j])) {
            res += a[i];
            i++;
        } else {
            res += b[j];
            j++;
        }
    }
    return res;
}

int getMax(vector<int> a, vector<int> b) {
    int res = 0;
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
            res += min(a[i], b[j]);
    return res;
}

void solve() {
    int size;
    cin >> size;

    vector<int> a(size);
    for (int &x : a)
        cin >> x;

    vector<int> b(size);
    for (int &x : b)
        cin >> x;

    int min = getMin(a, b), delta = getMax(a, b) - min;

    cout << "Matty needs at least " << min << " blocks, and can add at most " << delta << " extra blocks.\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}