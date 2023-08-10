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

    int res = 0;
    for (int from = 0; from < size; ) {
        int to = max_element(a.begin() + from, a.end()) - a.begin();
        res += (to - from + 1) * a[to];
        from = to + 1;
    }

    cout << res;
}