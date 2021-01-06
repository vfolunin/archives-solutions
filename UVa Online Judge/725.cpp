#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

map<int, vector<string>> answer;

void prepare() {
    string s = "0123456789";
    do {
        if (s[0] < s[5])
            continue;
        int a = stoi(s.substr(0, 5));
        int b = stoi(s.substr(5, 5));
        if (a % b == 0)
            answer[a / b].push_back(s);
    } while (next_permutation(s.begin(), s.end()));
}

bool solve(int test) {
    int n;
    cin >> n;

    if (!n)
        return 0;

    if (test)
        cout << "\n";

    if (answer.count(n)) {
        for (string &s : answer[n])
            cout << s.substr(0, 5) << " / " << s.substr(5, 5) << " = " << n << "\n";
    } else {
        cout << "There are no solutions for " << n << ".\n";
    }

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    prepare();
    for (int i = 0; solve(i); i++);
}