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

    string ops;
    cin >> ops;

    vector<int> cups = { 1, 0, 0 };

    for (char op : ops) {
        if (op == 'A')
            swap(cups[0], cups[1]);
        else if (op == 'B')
            swap(cups[1], cups[2]);
        else
            swap(cups[0], cups[2]);
    }

    cout << find(cups.begin(), cups.end(), 1) - cups.begin() + 1;
}