#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double HALFPI = acos(0), EPS = 1e-9;

bool solve() {
    string line;
    if (!getline(cin, line))
        return 0;

    stringstream ss(line);

    double a, b, h, w;
    char c;
    ss >> a >> c >> b;

    if (a > b)
        swap(a, b);
    
    while (ss >> h >> c >> w) {
        char res = 'Y';

        for (double angle = 0; angle <= HALFPI + EPS; angle += 1e-3) {
            double len = a * cos(angle) + b * sin(angle);
            double delta = len - w;
            double y = a * sin(angle) + delta / tan(angle);

            if (y > h + EPS) {
                res = 'N';
                break;
            }
        }

        cout << res;
    }

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}