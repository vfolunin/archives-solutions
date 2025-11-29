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

    vector<string> res;
    for (int height; cin >> height; ) {
        if (height) {
            for (int value = 1; value <= height; value++)
                res.push_back(string(5 - value, '.') + string(value, 'x'));
            for (int value = height - 1; value; value--)
                res.push_back(string(5 - value, '.') + string(value, 'x'));
        } else {
            res.push_back(string(5, '.'));
        }
    }

    for (int y = 0; y < res[0].size(); y++) {
        for (int x = 0; x < res.size(); x++)
            cout << res[x][y];
        cout << "\n";
    }
}