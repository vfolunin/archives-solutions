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

    unordered_map<string, int> count;
    cin >> count["Blue"] >> count["Red"] >> count["Yellow"];

    int size;
    cin >> size;

    long long res = 1;
    for (int i = 0; i < size; i++) {
        string type;
        cin >> type;

        res *= count[type];
    }

    cout << res;
}