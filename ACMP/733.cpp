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

    vector<int> l = a;
    for (int i = 1; i < a.size(); i++)
        l[i] = max(l[i], l[i - 1]);

    vector<int> r = a;
    for (int i = (int)a.size() - 2; i >= 0; i--)
        r[i] = max(r[i], r[i + 1]);

    vector<int> res;
    for (int i = 0; i < a.size(); i++)
        if (l[i] <= a[i] || r[i] <= a[i])
            res.push_back(a[i]);

    cout << res.size() << "\n";
    for (int value : res)
        cout << value << " ";
}