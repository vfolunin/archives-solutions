#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    while (getline(cin, s)) {
        stringstream ss(s);
        int value, sum = 0;
        while (ss >> value)
            sum += value;
        cout << sum << "\n";
    }
}