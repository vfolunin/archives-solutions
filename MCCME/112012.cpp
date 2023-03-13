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

    string line;
    getline(cin, line);

    int aCount = count(line.begin(), line.end(), 'A');
    int bCount = count(line.begin(), line.end(), 'B');

    if (aCount > bCount)
        cout << "A";
    else if (aCount < bCount)
        cout << "B";
    else
        cout << "=";
}