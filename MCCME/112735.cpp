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

    int size, gap;
    cin >> size >> gap;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int bestSum = 0, bestL, bestR;
    for (int l = 0, r = gap + 1; r < a.size(); r++) {
        if (r > gap && bestSum < a[l] + a[r]) {
            bestSum = a[l] + a[r];
            bestL = l;
            bestR = r;
        }
        if (a[l] < a[r - gap])
            l = r - gap;
    }

    cout << bestL + 1 << " " << bestR + 1;
}