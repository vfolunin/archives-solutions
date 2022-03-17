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
    int res = 1;

    for (int i = 0; i < size; i++) {
        cin >> a[i];
        res += i && a[i - 1] > a[i];
    }

    cout << res;
}