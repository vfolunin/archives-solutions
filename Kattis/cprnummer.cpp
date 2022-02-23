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

    string cpr;
    cin >> cpr;

    string factors = "43276504321";
    int value = 0;

    for (int i = 0; i < cpr.size(); i++)
        value += (cpr[i] - '0') * (factors[i] - '0');

    cout << (value % 11 == 0);    
}