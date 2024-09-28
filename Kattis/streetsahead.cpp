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

    unordered_map<string, int> index;
    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;

        index[s] = i;
    }

    for (int i = 0; i < queryCount; i++) {
        string a, b;
        cin >> a >> b;
        
        cout << abs(index[a] - index[b]) - 1 << "\n";
    }
}