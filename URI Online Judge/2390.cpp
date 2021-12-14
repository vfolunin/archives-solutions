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

    int peopleCount;
    cin >> peopleCount;

    vector<int> times(peopleCount);
    for (int &t : times)
        cin >> t;

    int l = -1e9, r = -1e9, res = 0;
    for (int t : times) {
        if (r < t) {
            res += r - l;
            l = t;
        }
        r = max(r, t + 10);
    }
    res += r - l;

    cout << res << "\n";
}