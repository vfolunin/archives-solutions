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

    vector<int> sizes(3);
    for (int &size : sizes)
        cin >> size;

    vector<vector<int>> a(3);
    for (int i = 0; i < a.size(); i++) {
        a[i].resize(sizes[i]);
        for (int &value : a[i])
            cin >> value;
    }

    vector lcsSize(a[0].size() + 1, vector(a[1].size() + 1, vector<int>(a[2].size() + 1)));
    for (int size0 = 1; size0 <= a[0].size(); size0++) {
        for (int size1 = 1; size1 <= a[1].size(); size1++) {
            for (int size2 = 1; size2 <= a[2].size(); size2++) {
                if (a[0][size0 - 1] == a[1][size1 - 1] && a[0][size0 - 1] == a[2][size2 - 1])
                    lcsSize[size0][size1][size2] = lcsSize[size0 - 1][size1 - 1][size2 - 1] + 1;
                else
                    lcsSize[size0][size1][size2] = max({ lcsSize[size0 - 1][size1][size2], lcsSize[size0][size1 - 1][size2], lcsSize[size0][size1][size2 - 1] });
            }
        }
    }

    vector<int> res;
    for (int size0 = a[0].size(), size1 = a[1].size(), size2 = a[2].size(); size0 && size1 && size2; ) {
        if (a[0][size0 - 1] == a[1][size1 - 1] && a[0][size0 - 1] == a[2][size2 - 1]) {
            res.push_back(a[0][size0 - 1]);
            size0--;
            size1--;
            size2--;
        } else if (lcsSize[size0][size1][size2] == lcsSize[size0 - 1][size1][size2]) {
            size0--;
        } else if (lcsSize[size0][size1][size2] == lcsSize[size0][size1 - 1][size2]) {
            size1--;
        } else {
            size2--;
        }
    }
    reverse(res.begin(), res.end());

    cout << res.size() << "\n";
    for (int value : res)
        cout << value << " ";
}