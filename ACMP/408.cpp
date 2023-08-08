#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string strip(string s) {
    for (int i = 0; i < 2; i++) {
        while (!s.empty() && s.back() == ' ')
            s.pop_back();
        reverse(s.begin(), s.end());
    }
    return s;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int width, lineCount;
    cin >> width >> lineCount;
    cin.ignore();

    vector<string> lines(lineCount);
    for (string &line : lines) {
        getline(cin, line);
        line = strip(line);

        if (line.size() > width) {
            cout << "Impossible.";
            return 0;
        }
    }

    for (string &line : lines) {
        int lSpaces = (width - line.size()) / 2;
        int rSpaces = width - line.size() - lSpaces;
        cout << string(lSpaces, ' ') << line << string(rSpaces, ' ') << "\n";
    }
}