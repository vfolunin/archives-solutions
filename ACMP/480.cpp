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

int rec(int from, int limit, vector<int> &p) {
    if (from == p.size())
        return 0;

    static vector<vector<int>> memo(180, vector<int>(81, -1));
    int &res = memo[from][limit];
    if (res != -1)
        return res;

    for (int count = 1; count <= limit && from + count <= p.size(); count++)
        res = max(res, getSum(p, from, p.size() - 1) - rec(from + count, count, p));
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> p(size);
    for (int &value : p)
        cin >> value;
    partial_sum(p.begin(), p.end(), p.begin());

    int limit;
    cin >> limit;

    cout << rec(0, limit, p);
}