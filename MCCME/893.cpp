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

    int size, opCount;
    cin >> size >> opCount;

    vector<long long> a(size);
    for (long long &value : a)
        cin >> value;

    for (int i = 0; i < opCount; i++) {
        long long sum = accumulate(a.begin(), a.end(), 0LL);
        for (long long &value : a)
            value = sum - value;
    }

    auto [minIt, maxIt] = minmax_element(a.begin(), a.end());
    cout << *maxIt - *minIt;
}