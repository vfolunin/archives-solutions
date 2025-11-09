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

    int amount, queryCount;
    cin >> amount >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        char sign;
        int delta;
        cin >> sign >> delta;

        amount += sign == '+' ? delta : -delta;
    }

    cout << amount;
}