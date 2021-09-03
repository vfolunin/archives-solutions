#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Check {
    string date;
    int number;
    char seq = ' ';
    double value = 0;

    bool operator < (const Check &that) const {
        return number < that.number;
    }
};

istream &operator >> (istream &in, Check &c) {
    in >> c.date >> c.number >> c.value;
    return in;
}

ostream &operator << (ostream &out, Check &c) {
    out << setw(4) << c.number << c.seq;
    out << setw(10) << fixed << setprecision(2) << c.value;
    out << " " << c.date;
    return out;
}

void solve(int test) {
    vector<Check> checks;

    while (1) {
        string line;
        getline(cin, line);
        if (line.empty())
            break;
        
        stringstream ss(line);
        Check c;
        ss >> c;

        checks.push_back(c);
    }

    sort(checks.begin(), checks.end());
    for (int i = 1; i < checks.size(); i++)
        if (checks[i - 1].number + 1 != checks[i].number)
            checks[i].seq = '*';

    int height = (checks.size() + 2) / 3;

    if (test)
        cout << "\n";

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < 3; j++) {
            cout << checks[i + j * height];
            if (i + (j + 1) * height < checks.size()) {
                cout << "   ";
            } else {
                cout << "\n";
                break;
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore(2);

    for (int i = 0; i < n; i++)
        solve(i);
}