#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitSum(int n) {
    int res = 0;
    while (n) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

int divisorDigitSum(int n) {
    int res = 0;
    for (int d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            res += digitSum(d);
            if (d * d != n)
                res += digitSum(n / d);
        }
    }
    return res;
}

vector<int> prepareDds() {
    vector<int> dds(3001);
    for (int i = 1; i < dds.size(); i++)
        dds[i] = divisorDigitSum(i);
    return dds;
}

vector<int> ddf(int n) {
    static vector<int> dds = prepareDds();
    set<int> seen;
    vector<int> f;
    while (!seen.count(n)) {
        f.push_back(n);
        seen.insert(n);
        n = dds[n];
    }
    return f;
}

pair<vector<vector<int>>, vector<vector<int>>> prepare() {
    vector<vector<int>> ddfs(3001);
    for (int i = 1; i < ddfs.size(); i++)
        ddfs[i] = ddf(i);

    vector<vector<int>> maxs(3001, vector<int>(3001));
    for (int i = 0; i < maxs.size(); i++) {
        maxs[i][i] = i;
        for (int j = i + 1; j < maxs.size(); j++)
            maxs[i][j] = ddfs[j].size() > ddfs[maxs[i][j - 1]].size() ? j : maxs[i][j - 1];
    }

    return { ddfs, maxs };
}

bool solve(int test) {
    int l, r;
    if (!(cin >> l >> r))
        return 0;

    cout << "Input" << test << ": " << l << " " << r << "\n";

    if (l > r)
        swap(l, r);

    static auto p = prepare();
    auto &[ddfs, maxs] = p;
    auto &ddf = ddfs[maxs[l][r]];

    cout << "Output" << test << ": ";
    for (int i = 0; i < ddf.size(); i++)
        cout << ddf[i] << (i + 1 < ddf.size() ? " " : "\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}