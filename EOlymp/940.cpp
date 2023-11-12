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

    map<int, int> count;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        count[value]++;
    }

    for (auto &[value, count] : count) {
        if (count * 2 > size) {
            cout << value;
            return 0;
        }
    }

    cout << -1;
}