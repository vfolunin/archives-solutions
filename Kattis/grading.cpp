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

    vector<int> limits(5);
    for (int &limit : limits)
        cin >> limit;

    int value;
    cin >> value;

    char mark = 0;
    while (mark < limits.size() && value < limits[mark])
        mark++;

    cout << (char)('A' + mark);
}