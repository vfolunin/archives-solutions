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

    int keyCount;
    cin >> keyCount;

    vector<int> pressLeft(keyCount);
    for (int &value : pressLeft)
        cin >> value;

    int pressCount;
    cin >> pressCount;

    for (int i = 0; i < pressCount; i++) {
        int key;
        cin >> key;
        pressLeft[key - 1]--;
    }

    for (int value : pressLeft)
        cout << (value < 0 ? "yes\n" : "no\n");
}