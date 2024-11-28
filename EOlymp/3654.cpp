#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

string getMinShift(string &s) {
    string res = s;
    for (int i = 1; i < s.size(); i++) {
        rotate(s.begin(), s.begin() + 1, s.end());
        res = min(res, s);
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    unordered_set<string> values;
    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;

        values.insert(getMinShift(s));
    }

    cout << values.size();
}