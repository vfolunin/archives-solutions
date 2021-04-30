#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(vector<int> &a, int depth, map<int, int> &resMap) {
    if (is_sorted(a.begin(), a.end())) {
        resMap[depth]++;
        return;
    }
    if (!resMap.empty() && resMap.begin()->first < depth)
        return;

    for (int i = 0; i + 1 < a.size(); i++) {
        if (a[i] > a[i + 1]) {
            swap(a[i], a[i + 1]);
            rec(a, depth + 1, resMap);
            swap(a[i], a[i + 1]);
        }
    }
}

bool solve(int test) {
    int n;
    cin >> n;

    if (!n)
        return 0;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    map<int, int> resMap;
    rec(a, 0, resMap);
    int res = resMap.empty() || !resMap.begin()->first ? 0 : resMap.begin()->second;

    cout << "There are " << res << " swap maps for input data set " << test << ".\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}