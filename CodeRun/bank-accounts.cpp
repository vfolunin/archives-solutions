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

    unordered_map<string, int> accounts;

    string op;
    while (cin >> op) {
        if (op == "DEPOSIT") {
            string name;
            int value;
            cin >> name >> value;
            accounts[name] += value;
        } else if (op == "WITHDRAW") {
            string name;
            int value;
            cin >> name >> value;
            accounts[name] -= value;
        } else if (op == "BALANCE") {
            string name;
            cin >> name;
            if (accounts.count(name))
                cout << accounts[name] << "\n";
            else
                cout << "ERROR\n";
        } else if (op == "TRANSFER") {
            string name1, name2;
            int value;
            cin >> name1 >> name2 >> value;
            accounts[name1] -= value;
            accounts[name2] += value;
        } else {
            int p;
            cin >> p;
            for (auto &[name, value] : accounts)
                if (value > 0)
                    value += value * p / 100;
        }
    }
}