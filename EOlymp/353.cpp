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

    vector<int> maxPairTo(a.size());
    maxPairTo[1] = a[0] + a[1];
    for (int i = 2; i < a.size(); i++)
        maxPairTo[i] = max(maxPairTo[i - 1], a[i - 1] + a[i]);

    int res = 0;
    for (int i = 3; i < a.size(); i++)
        res = max(res, maxPairTo[i - 2] + a[i - 1] + a[i]);

    cout << res;
}