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

    int sum;
    cin >> sum;

    cout << sum << " cent" << (sum == 1 ? "" : "s") << " requires ";

    vector<int> nominals = { 25, 10, 5, 1 };
    vector<string> names = { "quarter", "dime", "nickel", "cent" };

    for (int i = 0, first = 1; i < nominals.size(); i++) {
        int count = sum / nominals[i];
        sum %= nominals[i];

        if (count) {
            if (first)
                first = 0;
            else
                cout << ", ";

            cout << count << " " << names[i] << (count == 1 ? "" : "s");
        }
    }

    cout << ".";
}