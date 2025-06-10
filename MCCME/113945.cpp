#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, opCount;
    cin >> size >> opCount;

    unordered_set<int> values;
    int maxValue = 0;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        values.insert(value);
        maxValue = max(maxValue, value);
    }

    int mex = 1;
    for (int i = 0; i < opCount; i++) {
        if (mex == maxValue + 1) {
            mex += opCount - i;
            break;
        }

        while (values.count(mex))
            mex++;
        values.insert(mex);
    }

    cout << mex;
}