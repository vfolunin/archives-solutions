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

    for (int i = 0; i + 1 < size; i++) {
        int j = min_element(a.begin() + i, a.end()) - a.begin();
        swap(a[i], a[j]);

        cout << i + 1 << "-" << j + 1 << "\n";
    }
}