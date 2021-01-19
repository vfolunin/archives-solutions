#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    vector<string> codes;
    while (1) {
        string code;
        if (!(cin >> code))
            return 0;
        if (code != "9")
            codes.push_back(code);
        else
            break;
    }

    sort(codes.begin(), codes.end());
    for (int i = 1; i < codes.size(); i++) {
        if (codes[i - 1].size() <= codes[i].size() &&
            codes[i].substr(0, codes[i - 1].size()) == codes[i - 1]) {
            cout << "Set " << test << " is not immediately decodable\n";
            return 1;
        }
    }

    cout << "Set " << test << " is immediately decodable\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}