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

    int moveCount;
    string s;
    cin >> moveCount >> s;

    string moves = "RGB";
    int from = -1;

    for (int i = 0; i < moveCount; i++) {
        vector<int> to(moves.size());
        for (int j = 0; j < to.size(); j++)
            to[j] = s.find(moves[j], from + 1);

        int maxJ = max_element(to.begin(), to.end()) - to.begin();
        cout << moves[maxJ];
        from = to[maxJ];
    }
}