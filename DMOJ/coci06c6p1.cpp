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

    unordered_map<string, int> count;
    int res = 0;

    for (int i = 0; i < size; i++) {
        string name;
        cin >> name;

        count[name]++;
        res += count[name] > 1 && count[name] * 2 > i + 2;
    }

    cout << res;
}