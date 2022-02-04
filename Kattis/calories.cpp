#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double totalC = 0, fatC = 0;

    while (1) {
        static vector<double> perGram = { 9, 4, 4, 4, 7 };
        vector<double> val(5);
        vector<char> unit(5);
        double c = 0, p = 0;

        bool done = 0;
        for (int i = 0; i < 5; i++) {
            string token;
            cin >> token;

            if (token == "-") {
                done = 1;
                break;
            }

            val[i] = stod(token.substr(0, token.size() - 1));
            unit[i] = token.back();

            if (unit[i] == 'g') {
                val[i] *= perGram[i];
                unit[i] = 'C';
            }

            if (unit[i] == 'C')
                c += val[i];
            else
                p += val[i];
        }

        if (done)
            break;

        if (p) {
            p = c / (100 - p);

            for (int i = 0; i < 5; i++) {
                if (unit[i] == '%') {
                    val[i] *= p;
                    unit[i] = 'C';
                }
            }
        }

        fatC += val[0];

        for (int i = 0; i < 5; i++)
            totalC += val[i];
    }

    if (!totalC)
        return 0;

    cout.precision(0);
    cout << fixed << fatC / totalC * 100 << "%\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}