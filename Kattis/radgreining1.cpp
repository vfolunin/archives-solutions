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

    int size, partCount;
    cin >> size >> partCount;

    string res(size, '?');
    for (int i = 0; i < partCount; i++) {
        int from;
        string part;
        cin >> from >> part;
        from--;
        
        for (int j = 0; j < part.size(); j++) {
            if (from + j >= res.size() || res[from + j] != '?' && res[from + j] != part[j]) {
                cout << "Villa";
                return 0;
            }
            res[from + j] = part[j];
        }
    }

    cout << res;
}