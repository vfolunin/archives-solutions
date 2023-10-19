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

    vector<string> a(size);
    for (string &s : a)
        cin >> s;

    sort(a.begin(), a.end());

    vector<int> res(a.size(), 1);
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < i; j++)
            if (a[i] != a[j] && a[i].substr(0, a[j].size()) == a[j])
                res[i] = max(res[i], res[j] + 1);

    cout << *max_element(res.begin(), res.end());
}