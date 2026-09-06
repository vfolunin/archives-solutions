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

    int size, charge;
    cin >> size >> charge;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<int> res(size + 1);
    for (int i = charge + 1; i < res.size(); i++)
        res[i] = max(res[i - 1], res[i - charge] + a[i - 1]);

    cout << res.back();
}