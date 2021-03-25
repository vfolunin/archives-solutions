#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int lineCount;
    cin >> lineCount;

    if (!lineCount)
        return 0;

    cin.ignore();

    vector<string> lines(lineCount);
    for (string &line : lines)
        getline(cin, line);

    cout << "Case " << test << ":\n";
    cout << "#include<string.h>\n";
    cout << "#include<stdio.h>\n";
    cout << "int main()\n";
    cout << "{\n";
    for (string &line : lines) {
        cout << "printf(\"";
        for (char c : line) {
            if (c == '"' || c == '\\')
                cout << '\\';
            cout << c;
        }
        cout << "\\n\");\n";
    }
    cout << "printf(\"\\n\");\n";
    cout << "return 0;\n";
    cout << "}\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}