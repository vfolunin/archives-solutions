#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int personCount, floorCount, bookCount;
    cin >> personCount >> floorCount >> bookCount;

    vector<int> up, down;
    for (int i = 0; i < personCount; i++) {
        int floor, hasBook;
        cin >> floor >> hasBook;

        if (hasBook)
            up.push_back(floorCount - floor);
        else
            down.push_back(floor);
    }

    int res = 0;

    while (bookCount > down.size()) {
        res += floorCount;
        bookCount -= down.size();
        up.swap(down);
    }

    sort(down.begin(), down.end());
    res += down[bookCount - 1] + floorCount;

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}