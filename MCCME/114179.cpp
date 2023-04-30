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

    int aSize;
    cin >> aSize;

    vector<int> a(aSize);
    for (int &value : a)
        cin >> value;

    int bSize;
    cin >> bSize;

    vector<int> b(bSize);
    for (int &value : b)
        cin >> value;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, res = 0;
    for (int value : b) {
        while (i < a.size() && a[i] < value)
            i++;
        res += i < a.size();
        i++;
    }

    cout << res;
}