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

    vector<int> res(a.size());
    for (int i = 1; i < a.size(); i++) {
        res[i] = a[i] - a[0];
        for (int j = 2; j < i; j++)
            res[i] = min(res[i], max(res[j - 1], a[i] - a[j]));
    }

    cout << res.back();
}