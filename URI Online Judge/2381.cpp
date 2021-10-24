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

    int studentCount, pos;
    cin >> studentCount >> pos;

    vector<string> names(studentCount);
    for (string &name : names)
        cin >> name;
    sort(names.begin(), names.end());

    cout << names[pos - 1] << "\n";
}