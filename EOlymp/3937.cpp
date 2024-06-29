#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitRoot(int n) {
    int res = 0;
    while (n) {
        res += n % 10;
        n /= 10;
    }
    return res < 10 ? res : digitRoot(res);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> a;
    for (int value; cin >> value; )
        a.push_back(value);

    sort(a.begin(), a.end(), [](int lhs, int rhs) {
        int lRoot = digitRoot(lhs);
        int rRoot = digitRoot(rhs);
        if (lRoot != rRoot)
            return lRoot < rRoot;
        return lhs < rhs;
    });

    for (int value : a)
        cout << value << " ";
}