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

    int b, x;
    cin >> b >> x;

    for (int &value : a)
        value = abs(value - x);
    sort(a.begin(), a.end());

    b = abs(b - x);

    int res = 0;
    for (int value : a) {
        if (value < b) {
            b -= value;
            res++;
        }
    }

    cout << res;
}