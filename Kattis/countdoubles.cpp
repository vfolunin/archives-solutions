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

    int size, width;
    cin >> size >> width;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int count = 0;
    for (int i = 0; i < width; i++)
        count += a[i] % 2 == 0;
    int res = count >= 2;

    for (int i = width; i < size; i++) {
        count -= a[i - width] % 2 == 0;
        count += a[i] % 2 == 0;
        res += count >= 2;
    }

    cout << res;
}