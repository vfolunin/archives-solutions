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
    double aNum, bNum;
    cin >> size >> aNum >> bNum;

    vector<int> aDen(size), bDen(size);
    for (int i = 0; i < size; i++)
        cin >> aDen[i] >> bDen[i];

    double res = 0;
    for (int ai = 0; ai < aDen.size(); ai++) {
        res = max(res, aNum / aDen[ai]);
        res = max(res, bNum / bDen[ai]);

        for (int bi = 0; bi < bDen.size(); bi++)
            if (ai != bi)
                res = max(res, aNum / aDen[ai] + bNum / bDen[bi]);
    }

    cout << fixed << res;
}