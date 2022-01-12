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

    string hey;
    cin >> hey;

    cout << "h" << string(2 * (hey.size() - 2), 'e') << "y";
}