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

    int aSize;
    cin >> aSize;

    map<int, int> count;
    for (int i = 0; i < aSize; i++) {
        int value;
        cin >> value;
        count[value]++;
    }

    int bSize;
    cin >> bSize;

    for (int i = 0; i < bSize; i++) {
        int value;
        cin >> value;
        cout << count[value] << " ";
    }
}