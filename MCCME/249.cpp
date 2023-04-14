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

    sort(a.begin(), a.end());

    int res = 0;
    for (int i = 0; i < a.size(); i++)
        for (int j = i + 1; j < a.size(); j++)
            for (int k = j + 1; k < a.size(); k++)
                res += a[i] + a[j] > a[k];

    cout << res;
}