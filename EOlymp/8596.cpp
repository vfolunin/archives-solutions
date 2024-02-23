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

    int size;
    long long cost1, cost2;
    cin >> size >> cost1 >> cost2;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    long long res = 0;
    for (int i = 1; i < a.size(); i++)
        res += min((a[i] - a[i - 1]) * cost1, cost2);

    cout << res;
}