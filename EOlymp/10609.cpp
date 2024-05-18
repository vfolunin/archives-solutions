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

    int size, targetCount;
    cin >> size >> targetCount;

    vector<int> a(size);
    unordered_map<int, int> count;
    for (int &value : a) {
        cin >> value;
        count[value]++;
    }

    for (int &value : a) {
        if (count[value] == targetCount) {
            cout << value;
            return 0;
        }
    }

    cout << -1;
}