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

    int size, queryCount;
    cin >> size >> queryCount;

    unordered_map<int, int> pos;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        pos[value] = i + 1;
    }
    
    for (int i = 0; i < queryCount; i++) {
        int value;
        cin >> value;

        cout << pos[value] << "\n";
    }
}