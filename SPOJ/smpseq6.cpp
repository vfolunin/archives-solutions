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

    int size, maxDist;
    cin >> size >> maxDist;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<int> b(size);
    for (int &value : b)
        cin >> value;

    for (int ai = 0; ai < a.size(); ai++) {
        for (int bi = max(ai - maxDist, 0); bi < b.size() && bi <= ai + maxDist; bi++) {
            if (a[ai] == b[bi]) {
                cout << ai + 1 << " ";
                break;
            }
        }
    }
}