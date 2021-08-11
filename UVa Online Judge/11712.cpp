#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int verdictCount;
    cin >> verdictCount;

    if (!verdictCount)
        return 0;

    static vector<string> machine = {
        "0 1 1 1 R",
        "1 1 2 0 R",
        "2 0 2 0 R",
        "2 1 3 0 R",
        "3 0 4 0 R",
        "4 0 3 0 L",
    };

    cout << machine.size() << " " << verdictCount << "\n";
    for (string &rule : machine)
        cout << rule << "\n";

    for (int i = 0; i < verdictCount; i++) {
        string verdict;
        cin >> verdict;

        if (verdict == "AC")
            cout << "1 1\n";
        else if (verdict == "WA")
            cout << "1 2\n";
        else if (verdict == "MLE")
            cout << "2 1\n";
        else
            cout << "3 1\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}