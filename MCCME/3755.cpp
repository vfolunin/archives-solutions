#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> parseInts(string &line) {
    stringstream ss(line);
    vector<int> res;
    int value;
    while (ss >> value)
        res.push_back(value);
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    string line;
    cin >> n;
    getline(cin, line);

    vector<int> yesCount(n + 1), noCount(n + 1);
    int totalYesCount = 0;
    while (1) {
        getline(cin, line);
        if (line == "HELP")
            break;

        vector<int> values = parseInts(line);

        getline(cin, line);
        if (line == "YES") {
            for (int value : values)
                yesCount[value]++;
            totalYesCount++;
        } else {
            for (int value : values)
                noCount[value]++;
        }
    }

    for (int value = 1; value <= n; value++)
        if (yesCount[value] == totalYesCount && !noCount[value])
            cout << value << " ";
}