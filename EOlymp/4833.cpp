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

    vector<int> a;
    for (int value; cin >> value; )
        a.push_back(value);

    vector<int> res(a.size(), 1);
    for (int i = 1; i < a.size(); i++)
        for (int j = 0; j < i; j++)
            if (a[j] && a[i] % a[j] == 0)
                res[i] = max(res[i], res[j] + 1);

    cout << *max_element(res.begin(), res.end());
}