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
 
    unordered_set<string> values;

    while (1) {
        char op;
        cin >> op;

        if (op == '#')
            break;

        string value;
        cin >> value;

        if (op == '+')
            values.insert(value);
        else if (op == '-')
            values.erase(value);
        else
            cout << (values.count(value) ? "YES\n" : "NO\n");
    }
}