#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string readLine() {
    string line;
    getline(cin, line);

    stringstream ss(line);
    string word, res;
    while (ss >> word)
        res += (res.empty() ? "" : " ") + word;

    return res;
}

bool solve(int test) {
    int lineCount;
    cin >> lineCount;
    cin.ignore();

    if (!lineCount)
        return 0;

    vector<string> lines(lineCount);
    int maxWidth = 0;
    for (string &line : lines) {
        line = readLine();
        maxWidth = max<int>(maxWidth, line.size());
    }
    
    if (test)
        cout << "\n";
    for (string &line : lines)
        cout << setw(maxWidth) << right << line << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}