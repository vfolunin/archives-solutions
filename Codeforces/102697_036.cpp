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

    int size;
    cin >> size;

    unordered_map<string, int> limit;
    for (int i = 0; i < size; i++) {
        string key;
        cin >> key >> limit[key];
    }

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        string key;
        cin >> key;
        
        cout << limit[key] << "\n";
    }
}