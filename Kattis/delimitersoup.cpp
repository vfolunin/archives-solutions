#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

char complement(char c) {
    static string brackets = "()[]{}";
    return brackets[brackets.find(c) ^ 1];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string line;
    getline(cin, line);
    getline(cin, line);

    vector<char> stack;
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == ' ') {
            continue;
        } else if (line[i] == '(' || line[i] == '[' || line[i] == '{') {
            stack.push_back(line[i]);
        } else if (stack.empty() || stack.back() != complement(line[i])) {
            cout << line[i] << " " << i;
            return 0;
        } else {
            stack.pop_back();
        }
    }

    cout << "ok so far";
}