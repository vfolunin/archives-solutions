#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getMask(int n) {
    int mask = 0;
    for (; n; n /= 10)
        mask |= 1 << (n % 10);
    return mask;
}

void solve() {
    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    for (int i = 0; i < a.size(); i++) {
        for (int j = i + 1; j < a.size(); j++) {
            for (int k = j + 1; k < a.size(); k++) {
                if ((getMask(a[i]) | getMask(a[j]) | getMask(a[k])) == 1023) {
                    cout << a[i] << " " << a[j] << " " << a[k] << "\n";
                    return;
                }
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}