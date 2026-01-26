#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int getSum(vector<int> &p, int l, int r) {
    return p[r] - (l ? p[l - 1] : 0);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> pw(size), h(size);
    for (int i = 0; i < size; i++)
        cin >> pw[i] >> h[i];
    partial_sum(pw.begin(), pw.end(), pw.begin());

    vector<int> l(h.size(), -1), stack;
    for (int x = h.size() - 1; x >= 0; x--) {
        while (!stack.empty() && h[stack.back()] > h[x]) {
            l[stack.back()] = x;
            stack.pop_back();
        }
        stack.push_back(x);
    }

    vector<int> r(h.size(), h.size());
    stack.clear();
    for (int x = 0; x < h.size(); x++) {
        while (!stack.empty() && h[stack.back()] > h[x]) {
            r[stack.back()] = x;
            stack.pop_back();
        }
        stack.push_back(x);
    }

    int res = 0;
    for (int x = 0; x < h.size(); x++)
        res = max(res, h[x] * getSum(pw, l[x] + 1, r[x] - 1));

    cout << res;
}