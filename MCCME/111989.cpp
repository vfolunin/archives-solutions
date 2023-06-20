#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int getSum(vector<int> &p, int l, int r) {
    if (l > r)
        return 0;
    return p[r] - (l ? p[l - 1] : 0);
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

    vector<int> a(size + 1);
    for (int &value : a)
        cin >> value;

    int resBonus = getSum(p, 0, min<int>(p.size(), a[0]) - 1), resFrom = 0;
    for (int i = 1; i < a.size(); i++) {
        int bonus = getSum(p, i, min<int>(p.size(), i + a[i]) - 1);
        if (resBonus <= bonus) {
            resBonus = bonus;
            resFrom = i;
        }
    }

    cout << resBonus << " " << resFrom;
}