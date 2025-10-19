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

    vector<int> pos(5);
    for (int i = 1; i < pos.size(); i++) {
        int delta;
        cin >> delta;

        pos[i] = pos[i - 1] + delta;
    }

    for (int i = 0; i < pos.size(); i++) {
        for (int j = 0; j < pos.size(); j++)
            cout << abs(pos[i] - pos[j]) << " ";
        cout << "\n";
    }
}