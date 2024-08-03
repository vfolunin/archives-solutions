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

    int aSize, bSize;
    cin >> aSize >> bSize;

    vector<int> a(aSize);
    for (int &value : a)
        cin >> value;

    vector<int> b(bSize);
    for (int &value : b)
        cin >> value;

    int res = 0;
    while (a != b) {
        int value = a[0];
        a.erase(a.begin());
        for (int i = 0; i < value; i++) {
            if (i == a.size())
                a.emplace_back();
            a[i]++;
        }
        res++;
    }

    cout << res;
}