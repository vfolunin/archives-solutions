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

    vector<vector<double>> num(2, vector<double>(3));
    vector<double> den(3);
    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < 3; j++)
            num[s[0] == 'Y'][j] += s[j + 1] == 'Y';
        den[s[0] == 'Y']++;
    }

    for (int i = 0; i < 3; i++) {
        double a = num[1][i] / den[1];
        double b = num[0][i] / den[0];

        if (a >= b)
            cout << "Not Effective\n";
        else
            cout << fixed << (b - a) / b * 100 << "\n";
    }
}