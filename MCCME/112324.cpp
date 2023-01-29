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

    vector<int> a(size), b;
    for (int i = 0; i < size; i++) {
        cin >> a[i];
        if (i % 2 == 0)
            b.push_back(a[i]);
    }

    sort(b.begin(), b.end());

    for (int i = 0; i < size; i++)
        cout << (i % 2 ? a[i] : b[i / 2]) << " ";
}