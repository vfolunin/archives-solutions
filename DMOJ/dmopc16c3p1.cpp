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

    int value, delta;
    string type;
    cin >> value >> type >> delta;

    cout << value + (type == "Behind" ? delta : -delta);
}