#include <numeric>
#include <vector>
using namespace std;

vector<int> p;

void init(int size, const vector<int> &a) {
    p = a;
    partial_sum(p.begin(), p.end(), p.begin());
}

int ask(int l, int r) {
    l--;
    r--;
    return p[r] - (l ? p[l - 1] : 0);
}

vector<int> askAll(int queryCount, const vector<int> &l, const vector<int> &r) {
    vector<int> res(queryCount);
    for (int i = 0; i < res.size(); i++)
        res[i] = ask(l[i], r[i]);
    return res;
}