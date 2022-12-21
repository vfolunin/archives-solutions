#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> a(3);
    int sum = 0;
    for (int &value : a) {
        cin >> value;
        sum += value;
    }

    if (sum % 3) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    int res = 0;
    sum /= 3;
    for (int value : a)
        if (value > sum)
            res += value - sum;

    cout << res;
}