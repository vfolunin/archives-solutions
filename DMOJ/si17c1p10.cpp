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

    for (int i = 0; i < 2; i++) {
        int size;
        cin >> size;

        vector<int> a(size);
        for (int &value : a)
            cin >> value;

        vector<int> b(size);
        for (int &value : b)
            cin >> value;

        int res = 0;
        for (int j = 0; j < a.size(); j++)
            res += a[j] * b[j];

        cout << res << " ";
    }
}