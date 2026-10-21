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

    int segmentCount, maxCoord;
    cin >> segmentCount >> maxCoord;

    vector<int> covered(maxCoord);
    for (int i = 0; i < segmentCount; i++) {
        int l, r;
        cin >> l >> r;

        fill(covered.begin() + l - 1, covered.begin() + r, 1);
    }

    cout << count(covered.begin(), covered.end(), 0) << "\n";
    for (int i = 0; i < covered.size(); i++)
        if (!covered[i])
            cout << i + 1 << " ";
}