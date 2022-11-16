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
 
    vector<int> a;
    unordered_map<int, int> count;
    int value;

    while (cin >> value) {
        a.push_back(value);
        count[value]++;
    }

    for (int value : a)
        if (count[value] == 1)
            cout << value << " ";
}