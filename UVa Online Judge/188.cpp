#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int code(string &word) {
    int res = 0;
    for (char c : word)
        res = res * 32 + c - 'a' + 1;
    return res;
}

bool solve() {
    string line;
    if (!getline(cin, line))
        return 0;

    stringstream ss(line);
    vector<int> codes;
    string word;
    while (ss >> word)
        codes.push_back(code(word));

    int c = 1;
    while (1) {
        int nextC = c;

        for (int i = 0; i < codes.size(); i++)
            for (int j = i + 1; j < codes.size(); j++)
                if (c / codes[i] % codes.size() == c / codes[j] % codes.size())
                    nextC = max(nextC, min((c / codes[i] + 1) * codes[i], (c / codes[j] + 1) * codes[j]));
        
        if (nextC == c)
            break;
        c = nextC;
    }

    cout << line << "\n" << c << "\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}