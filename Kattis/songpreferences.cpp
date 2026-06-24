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

    for (int i = 0; i < queryCount; i++) {
        vector<int> a(size);
        for (int &value : a) {
            cin >> value;

            value = pos[value - 1];
        }

        int inversionCount = 0;
        for (int i = 0; i < size; i++)
            for (int j = i + 1; j < size; j++)
                inversionCount += a[i] > a[j];

        cout << inversionCount << "\n";
    }
}