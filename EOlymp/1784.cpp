#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

bool isGood(vector<int> &a, int limit) {
    for (int i = 0; i + 1 < a.size(); i++)
        if (abs(a[i + 1] - a[i]) > limit)
            return 0;
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, limit;
    cin >> size >> limit;

    vector<int> a(size);
    iota(a.begin(), a.end(), 0);
    int res = 0;

    do {
        res += isGood(a, limit);
    } while (next_permutation(a.begin(), a.end()));

    cout << res;
}