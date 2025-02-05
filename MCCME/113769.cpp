#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<long long> res(a.size() + 1);
    for (int i = 1; i < res.size(); i++) {
        res[i] = res[i - 1] + a[i - 1];
        if (i >= 10)
            res[i] = min(res[i], res[i - 10] + accumulate(a.begin() + i - 10, a.begin() + i, 0LL) - *min_element(a.begin() + i - 10, a.begin() + i));
    }

    cout << res.back();
}