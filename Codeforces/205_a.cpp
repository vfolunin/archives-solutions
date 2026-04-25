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

    vector<pair<int, int>> a(size);
    for (int i = 0; i < size; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());

    if (a[0].first != a[1].first)
        cout << a[0].second + 1;
    else
        cout << "Still Rozdil";
}