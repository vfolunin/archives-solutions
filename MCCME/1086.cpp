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

    vector<pair<int, int>> b(size);
    for (int i = 0; i < size; i++) {
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(b.rbegin(), b.rend());

    vector<int> res(size);
    for (int i = 0; i < size; i++)
        res[a[i].second] = b[i].second;

    for (int value : res)
        cout << value + 1 << " ";
}