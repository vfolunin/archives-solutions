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

    vector<int> zeroPos;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        if (!value)
            zeroPos.push_back(i);
    }

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int index;
        cin >> index;
        cout << (index <= zeroPos.size() ? zeroPos[index - 1] + 1 : -1) << " ";
    }
}