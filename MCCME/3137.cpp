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

    int n;
    cin >> n;

    vector<int> count(7);
    for (int i = 0, mod = 1e6; i < count.size(); i++, mod /= 10) {
        count[i] = n / mod;
        n %= mod;
    }

    vector<string> name = {
        "Millions", "Hundreds of thousands", "Tens of thousands", "Thousands", "Hundreds", "Tens", "Ones"
    };
    for (int i = 0; i < name.size(); i++)
        cout << name[i] << ": " << count[i] << "\n";

    cout << "Result: " << count[0];
    for (int i = 1; i < count.size(); i++) {
        cout << " - " << count[i];
        count[0] -= count[i];
    }
    cout << " = " << count[0];
}