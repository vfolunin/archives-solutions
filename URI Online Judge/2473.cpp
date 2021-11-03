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

    vector<int> bet(6);
    for (int &x : bet)
        cin >> x;

    int match = 0;
    for (int i = 0; i < 6; i++) {
        int x;
        cin >> x;
        match += find(bet.begin(), bet.end(), x) != bet.end();
    }
    
    vector<string> verdict = {
        "azar", "azar", "azar", "terno", "quadra", "quina", "sena"
    };
    cout << verdict[match] << "\n";
}