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

    vector<int> a(size);
    map<int, int> count;
    int shiftedValue = -1e9;

    for (int &value : a) {
        cin >> value;
        count[value]++;
        if (shiftedValue == -1e9 || count[shiftedValue] < count[value] ||
            count[shiftedValue] == count[value] && shiftedValue > value)
            shiftedValue = value;
    }

    for (int value : a)
        if (value != shiftedValue)
            cout << value << " ";

    for (int i = 0; i < count[shiftedValue]; i++)
        cout << shiftedValue << " ";
}