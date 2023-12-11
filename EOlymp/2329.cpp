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

    sort(a.begin(), a.end());

    vector<int> res(size);
    for (int i = 0, l = 0, r = a.size() - 1; i < a.size(); i++) {
        if (i % 2 == 0)
            res[l++] = a[i];
        else
            res[r--] = a[i];
    }

    for (int value : res)
        cout << value << " ";
}