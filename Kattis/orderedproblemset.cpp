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

    bool found = 0;
    for (int partCount = 2; partCount <= size; partCount++) {
        if (size % partCount)
            continue;
        int partSize = size / partCount;

        bool ok = 1;
        for (int from = 0; from + partSize * 2 <= size && ok; from += partSize)
            ok &= *max_element(a.begin() + from, a.begin() + from + partSize) <
                  *min_element(a.begin() + from + partSize, a.begin() + from + partSize * 2);

        if (ok) {
            found = 1;
            cout << partCount << "\n";
        }
    }

    if (!found)
        cout << -1;
}