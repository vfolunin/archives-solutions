#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void print(long long n) {
    if (!n) {
        cout << 0;
        return;
    }

    static vector<pair<string, long long>> units = {
        {"kuti", 1e7}, {"lakh", 1e5}, {"hajar", 1e3}, {"shata", 100}
    };
    
    for (auto &[name, value] : units) {
        if (n >= value) {
            print(n / value);
            cout << " " << name;
            n %= value;
            if (n)
                cout << " ";
        }
    }

    if (n)
        cout << n;
}

bool solve(int test) {
    long long n;
    if (!(cin >> n))
        return 0;

    cout << setw(4) << test << ". ";
    print(n);
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}