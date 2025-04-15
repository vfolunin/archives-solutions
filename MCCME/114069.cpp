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

    int last = a[0];
    for (int i = 0; i + 1 < a.size(); i++) {
        int cur = a[i] == a[i + 1] + 1;
        last -= cur;

        cout << cur;
    }
    cout << last;
}