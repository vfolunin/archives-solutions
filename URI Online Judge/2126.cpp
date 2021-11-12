#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    string a, b;
    if (!(cin >> a >> b))
        return 0;

    int count = 0, last = -1;
    for (int i = 0; i + a.size() <= b.size(); i++) {
        if (b.substr(i, a.size()) == a) {
            count++;
            last = i;
        }
    }

    cout << "Caso #" << test << ":\n";
    if (count) {
        cout << "Qtd.Subsequencias: " << count << "\n";
        cout << "Pos: " << last + 1 << "\n\n";
    } else {
        cout << "Nao existe subsequencia\n\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}