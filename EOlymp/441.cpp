#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int zeroCount(int n) {
    int res = 0;
    while (n && n % 10 == 0) {
        res++;
        n /= 10;
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    nth_element(a.begin(), a.begin(), a.end(), [](int lhs, int rhs) {
        int lZeroCount = zeroCount(lhs), rZeroCount = zeroCount(rhs);
        if (lZeroCount != rZeroCount)
            return lZeroCount > rZeroCount;
        return lhs < rhs;
    });

    cout << a[0];
}