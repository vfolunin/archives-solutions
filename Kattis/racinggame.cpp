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

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int queryCount;
    cin >> queryCount;

    vector<int> values;
    for (int i = 0; i < queryCount; i++) {
        int type, arg;
        cin >> type >> arg;

        if (type == 1) {
            values.push_back(arg);
            sort(values.begin(), values.end());
            if (values.size() > 10)
                values.pop_back();
        } else if (type == 2) {
            for (int &value : values)
                value += arg;
        } else {
            cout << values[arg - 1] << "\n";
        }
    }
}