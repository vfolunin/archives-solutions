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

    int size, factor;
    cin >> size >> factor;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    int res = 0;
    for (int value : a) {
        while (value % factor == 0) {
            value /= factor;
            res++;
        }
    }

    cout << res;
}