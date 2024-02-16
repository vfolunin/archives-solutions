#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int roundCount;
    cin >> roundCount;
    
    int aScore = 0, bScore = 0;
    for (int i = 0; i < roundCount; i++) {
        char a, b;
        cin >> a >> b;

        string symbols = "RSP";
        int ai = symbols.find(a);
        int bi = symbols.find(b);

        aScore += (ai + 1) % symbols.size() == bi;
        bScore += (bi + 1) % symbols.size() == ai;
    }

    if (aScore > bScore)
        cout << "Player 1\n";
    else if (aScore < bScore)
        cout << "Player 2\n";
    else
        cout << "TIE\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}