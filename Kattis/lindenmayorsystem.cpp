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

    int transitionCount, iterationCount;
    cin >> transitionCount >> iterationCount;

    vector<string> transition(26);
    for (int i = 0; i < 26; i++)
        transition[i] = string(1, i + 'A');
    for (int i = 0; i < transitionCount; i++) {
        char a;
        string buf, b;
        cin >> a >> buf >> b;
        transition[a - 'A'] = b;
    }

    string s;
    cin >> s;

    for (int i = 0; i < iterationCount; i++) {
        string nextS;
        for (char c : s)
            nextS += transition[c - 'A'];
        s = nextS;
    }

    cout << s;
}