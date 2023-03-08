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

    vector<int> a(size), odd;
    for (int &value : a) {
        cin >> value;
        if (value % 2)
            odd.push_back(value);
    }

    sort(odd.begin(), odd.end());

    for (int i = 0, j = 0; i < a.size(); i++) {
        if (a[i] % 2)
            cout << odd[j++] << " ";
        else
            cout << a[i] << " ";
    }
}