#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    cin >> n;
    cin.ignore();

    if (!n)
        return 0;

    string text;
    getline(cin, text);

    text.erase(remove(text.begin(), text.end(), ' '), text.end());
    for (char &c : text)
        c = toupper(c);

    string cypher(text.size(), ' ');
    for (int ci = 0, ti = 0; ti < text.size(); ci = 0) {
        while (cypher[ci] != ' ')
            ci++;
        for (; ci < cypher.size() && ti < text.size(); ci += n, ti++)
            cypher[ci] = text[ti];
    }

    cout << cypher << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}