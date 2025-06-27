#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int queryCount;
    cin >> queryCount;

    unordered_set<string> values;
    for (int i = 0; i < queryCount; i++) {
        char type;
        string value;
        cin >> type >> value;

        if (type == '+')
            values.insert(value);
        else if (type == '-')
            values.erase(value);
        else
            cout << (values.count(value) ? "Jebb\n" : "Neibb\n");
    }
}