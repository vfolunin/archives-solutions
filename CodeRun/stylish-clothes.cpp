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

    int aSize;
    cin >> aSize;
    vector<int> a(aSize);
    for (int &value : a)
        cin >> value;

    int bSize;
    cin >> bSize;
    vector<int> b(bSize);
    for (int &value : b)
        cin >> value;

    int bestAi = 0, bestBi = 0;

    for (int ai = 0, bi = 0; ai < aSize && bi < bSize; ) {
        if (abs(a[ai] - b[bi]) < abs(a[bestAi] - b[bestBi])) {
            bestAi = ai;
            bestBi = bi;
        }
        if (a[ai] < b[bi])
            ai++;
        else
            bi++;
    }

    cout << a[bestAi] << " " << b[bestBi];
}