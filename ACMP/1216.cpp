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

    int l, r;
    cin >> l >> r;

    int maxIndex = max_element(a.begin() + l - 1, a.begin() + r) - a.begin();

    cout << a[maxIndex] << " " << maxIndex + 1;
}