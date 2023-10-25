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

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<int> b = a;
    sort(b.begin(), b.end());

    int l = 0, r = a.size() - 1, rev = 0;
    vector<int> res(a.size());

    for (int i = a.size() - 1; i >= 0; i--) {
        if (!rev) {
            if (a[i] == b[r]) {
                r--;
            } else if (a[i] == b[l]) {
                res[i] = 1;
                l++;
                rev = 1;
            } else {
                cout << "NO";
                return 0;
            }
        } else {
            if (a[i] == b[l]) {
                l++;
            } else if (a[i] == b[r]) {
                res[i] = 1;
                r--;
                rev = 0;
            } else {
                cout << "NO";
                return 0;
            }
        }
    }

    cout << "YES\n";
    for (int value : res)
        cout << value << " ";
}