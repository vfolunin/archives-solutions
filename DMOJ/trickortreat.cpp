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

    int size, limit;
    cin >> size >> limit;
    limit++;

    vector<int> a(size);
    for (int &value : a) {
        cin >> value;
        value++;
    }

    sort(a.begin(), a.end());

    int res = 0;
    while (res < a.size() && limit >= a[res])
        limit -= a[res++];

    cout << res;
}