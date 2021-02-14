#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string card;
    getline(cin, card);
    card.erase(remove(card.begin(), card.end(), ' '), card.end());

    int sum = 0;
    for (int i = 0; i < 16; i += 2) {
        int v = (card[i] - '0') * 2;
        sum += v / 10 + v % 10;
    }
    for (int i = 1; i < 16; i += 2)
        sum += (card[i] - '0');
    
    cout << (sum % 10 ? "Invalid\n" : "Valid\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
        solve();
}