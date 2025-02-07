#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int aSize;
    cin >> aSize;

    vector<int> a(aSize);
    unordered_map<int, int> aCount;
    for (int &value : a) {
        cin >> value;

        aCount[value]++;
    }

    int bSize;
    cin >> bSize;

    unordered_map<int, int> bCount;
    for (int i = 0; i < bSize; i++) {
        int value;
        cin >> value;

        bCount[value]++;
    }

    for (int &value : a) {
        if (aCount[value] && bCount[value]) {
            aCount[value]--;
            bCount[value]--;

            cout << value << " ";
        }
    }
}