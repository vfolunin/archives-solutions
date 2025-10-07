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

    int sizeA, sizeB;
    cin >> sizeA >> sizeB;

    vector<int> a(sizeA);
    unordered_set<int> valuesA;
    for (int &value : a) {
        cin >> value;
        valuesA.insert(value);
    }

    vector<int> b(sizeB);
    unordered_set<int> valuesB;
    for (int &value : b) {
        cin >> value;
        valuesB.insert(value);
    }

    for (int value : a) {
        if (!valuesB.count(value)) {
            cout << value << " ";
            valuesB.insert(value);
        }
    }
    cout << "\n";
    for (int value : b) {
        if (!valuesA.count(value)) {
            cout << value << " ";
            valuesA.insert(value);
        }
    }
}