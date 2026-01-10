#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
#include <random>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    unordered_set<string> values;
    for (int i = 0; i < size; i++) {
        string value;
        cin >> value;

        values.insert(value);
    }

    minstd_rand generator;
    while (1) {
        string value(size, '0');
        for (char &c : value)
            c += uniform_int_distribution<int>(0, 1)(generator);

        if (!values.count(value)) {
            cout << value;
            break;
        }
    }
}