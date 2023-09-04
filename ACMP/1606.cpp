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

    vector<string> digitNames(10);
    for (string &name : digitNames)
        cin >> name;

    int size;
    cin >> size;

    for (int i = 0; i < size; i++) {
        string value;
        cin >> value;

        string res;
        for (char digit : value)
            res = max(res, digitNames[digit - '0']);

        cout << res << "\n";
    }
}