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

    int size;
    cin >> size;

    vector<string> a(size);
    for (string &s : a)
        cin >> s;

    vector<string> b(size);
    for (string &s : b)
        cin >> s;

    vector<string> signs = { "rock", "scissors", "paper" };

    int resA = 0, resB = 0;
    for (int i = 0; i < a.size(); i++) {
        int ai = find(signs.begin(), signs.end(), a[i]) - signs.begin();
        int bi = find(signs.begin(), signs.end(), b[i]) - signs.begin();

        resA += (ai + 1) % signs.size() == bi;
        resB += (bi + 1) % signs.size() == ai;
    }

    cout << resA << " " << resB;
}