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
 
    unordered_map<int, int> count;
    int value, mostFrequentValue;

    for (int i = 0; cin >> value; i++) {
        count[value]++;
        if (!i || count[mostFrequentValue] < count[value])
            mostFrequentValue = value;
    }

    cout << mostFrequentValue;
}