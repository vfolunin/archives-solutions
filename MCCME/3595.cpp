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

    vector<int> res(a.size() + 1);
    for (int len = 5; len <= a.size(); len++)
        res[len] = max(res[len - 1], res[len - 5] + accumulate(a.begin() + len - 5, a.begin() + len, 0));

    cout << res.back() * 10;
}