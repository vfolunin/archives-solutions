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

    int size, price, limit;
    cin >> size >> price >> limit;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    int sum = 0, res = 0;
    for (int i = 0; i < a.size(); i++) {
        sum += a[i] * price;
        if (sum <= limit * (i + 1))
            res = i + 1;
    }

    cout << res;
}