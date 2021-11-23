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

    int n;
    cin >> n;

    map<string, int> count;
    for (int i = 0; i < n; i++) {
        string name, type;
        cin >> name >> type;
        count[type]++;
    }

    cout << count["X"] << " Hobbit(s)\n";
    cout << count["H"] << " Humano(s)\n";
    cout << count["E"] << " Elfo(s)\n";
    cout << count["A"] << " Anao(s)\n";
    cout << count["M"] << " Mago(s)\n";
}