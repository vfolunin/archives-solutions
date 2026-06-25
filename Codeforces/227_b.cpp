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

    vector<int> pos(size);
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        pos[value - 1] = i;
    }

    int queryCount;
    cin >> queryCount;

    long long resL = 0, resR = 0;
    for (int i = 0; i < queryCount; i++) {
        int value;
        cin >> value;

        resL += pos[value - 1] + 1;
        resR += pos.size() - pos[value - 1];
    }

    cout << resL << " " << resR;
}