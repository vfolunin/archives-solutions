#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Solver {
    map<char, int> codes;
    string cypher, text;
    int outputSize = 0;

    void rec(int i) {
        if (i == cypher.size()) {
            cout << text << "\n";
            outputSize++;
            return;
        }

        for (auto &[c, code] : codes) {
            int nextI = i, curCode = 0;
            while (nextI < cypher.size() && curCode < code) {
                curCode = curCode * 10 + cypher[nextI] - '0';
                nextI++;
            }
            if (curCode == code) {
                text.push_back(c);
                rec(nextI);
                text.pop_back();
                if (outputSize == 100)
                    return;
            }
        }
    }
};

bool solve(int test) {
    int charCount;
    cin >> charCount;

    if (!charCount)
        return 0;

    Solver solver;
    for (int i = 0; i < charCount; i++) {
        char c;
        cin >> c >> solver.codes[c];
    }

    cin >> solver.cypher;

    cout << "Case #" << test << "\n";
    solver.rec(0);
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}