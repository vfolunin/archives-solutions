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

    int linesPerPage, lineNumber;
    cin >> linesPerPage >> lineNumber;
    lineNumber--;

    cout << lineNumber / linesPerPage + 1 << " " << lineNumber % linesPerPage + 1;
}