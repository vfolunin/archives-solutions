#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(vector<int> &a, int i, int targetSum, vector<int> &cur, vector<int> &res) {
    if (i == a.size()) {
        if (!targetSum && (res.empty() || res.size() > cur.size()))
            res = cur;
        return;
    }

    rec(a, i + 1, targetSum, cur, res);

    if (targetSum >= a[i]) {
        cur.push_back(a[i]);
        rec(a, i + 1, targetSum - a[i], cur, res);
        cur.pop_back();
    }

    if (targetSum >= 2 * a[i]) {
        cur.push_back(a[i]);
        cur.push_back(a[i]);
        rec(a, i + 1, targetSum - 2 * a[i], cur, res);
        cur.pop_back();
        cur.pop_back();
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  
    int targetSum, size;
    cin >> targetSum >> size;

    vector<int> a(size);
    int maxSum = 0;
    for (int &value : a) {
        cin >> value;
        maxSum += 2 * value;
    }

    if (maxSum < targetSum) {
        cout << -1;
        return 0;
    }

    vector<int> cur, res;
    rec(a, 0, targetSum, cur, res);

    cout << res.size() << "\n";
    for (int value : res)
        cout << value << " ";
}