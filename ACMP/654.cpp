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

    long long res = 0;
    for (int i = 0; i + 1 < a.size(); i++)
        if (a[i] < a[i + 1])
            res += a[i + 1] - a[i];

    res += *max_element(a.begin(), a.end()) - a.back();

    cout << res;
}