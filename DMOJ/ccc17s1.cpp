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

    vector<int> b(size);
    for (int &value : b)
        cin >> value;

    int res = 0, sum = 0;
    for (int i = 0; i < a.size(); i++) {
        sum += a[i] - b[i];
        if (!sum)
            res = i + 1;
    }

    cout << res;
}