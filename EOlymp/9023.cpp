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
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int from = a[0];
    for (int i = 1; i < a.size(); i++)
        from = max(from, a[i] - i);

    long long res = 0;
    for (int i = 0; i < a.size(); i++)
        res += from + i - a[i];

    cout << res;
}