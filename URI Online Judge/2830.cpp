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

    int a, b;
    cin >> a >> b;
    a--;
    b--;

    vector<string> round = { "oitavas", "quartas", "semifinal", "final" };

    for (int bit = 3; bit >= 0; bit--) {
        if ((a ^ b) & (1 << bit)) {
            cout << round[bit] << "\n";
            break;
        }
    }
}