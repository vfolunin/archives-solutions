#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isTag(const string &s) {
    if (s.size() < 3 || s.front() != '<' || s.back() != '>')
        return 0;
    for (int i = 1; i + 1 < s.size(); i++)
        if (!isalpha(s[i]) && (s[i] != '/' || i != 1))
            return 0;
    return 1;
}

bool isValid(const string &s) {
    vector<string> stack;
    string tag;

    for (char c : s) {
        tag += c;
        if (c == '>') {
            if (!isTag(tag))
                return 0;
            else if (tag[1] != '/')
                stack.push_back(tag.substr(0, 1) + "/" + tag.substr(1));
            else if (stack.empty() || stack.back() != tag)
                return 0;
            else
                stack.pop_back();
            tag.clear();
        }
    }

    return tag.empty() && stack.empty();
}

string restore(string &s) {
    string symbols = "<>/";
    for (char symbol = 'a'; symbol <= 'z'; symbol++)
        symbols += symbol;

    for (char &c : s) {
        char pc = c;
        for (char symbol : symbols) {
            c = symbol;
            if (isValid(s))
                return s;
        }
        c = pc;
    }

    return "";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    getline(cin, s);

    cout << restore(s);
}