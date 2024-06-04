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

    int l = 0, r = a.size() - 1, res = 0;
    while (l <= r) {
        while (l <= r && a[l] != res + 1)
            l++;
        while (l <= r && a[r] != res + 1)
            r--;
        if (l <= r)
            res++;
    }

    cout << res;
}