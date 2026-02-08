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

    int size, limit;
    cin >> size >> limit;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<int> cuts;
    int balance = 0;
    for (int i = 0; i + 1 < a.size(); i++) {
        balance += a[i] % 2 ? 1 : -1;
        if (!balance)
            cuts.push_back(abs(a[i] - a[i + 1]));
    }

    sort(cuts.begin(), cuts.end());

    int res = 0;
    for (int i = 0; i < cuts.size(); i++) {
        if (limit >= cuts[i]) {
            limit -= cuts[i];
            res++;
        }
    }

    cout << res;
}