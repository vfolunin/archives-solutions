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

    vector<int> res(2);
    int l = 0, r = a.size() - 1;
    for (int i = 0; i < a.size(); i++) {
        if (a[l] >= a[r])
            res[i % 2] += a[l++];
        else
            res[i % 2] += a[r--];
    }

    cout << res[0] << ":" << res[1];
}