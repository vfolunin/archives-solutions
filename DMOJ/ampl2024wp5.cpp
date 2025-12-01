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

    vector<int> b(size);
    for (int &value : b)
        cin >> value;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int minRes = 0, maxRes = 0;
    for (int i = 0; i < a.size(); i++) {
        minRes += (a[i] - b[i]) * (a[i] - b[i]);
        maxRes += (a[i] - b[b.size() - 1 - i]) * (a[i] - b[b.size() - 1 - i]);
    }

    cout << minRes << " " << maxRes;
}