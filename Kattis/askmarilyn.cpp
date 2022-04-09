#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    char choice = 'A' + rand() % 3;

    cout << choice << "\n";
    cout.flush();

    char hint;
    int hasPrize;
    cin >> hint >> hasPrize;

    choice = hasPrize ? hint : 'A' + 'B' + 'C' - choice - hint;
    cout << choice << "\n";
    cout.flush();

    cin >> hasPrize >> hint;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    for (int i = 0; i < 1000; i++)
        solve();
}