#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int res = 1;
    for (int i = 0; i < a.size(); i++) {
        if (a[i]) {
            if (i && a[i - 1])
                res += 5;
            else
                res++;
        } else if (i && !a[i - 1]) {
            res = -1;
            break;
        }
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}