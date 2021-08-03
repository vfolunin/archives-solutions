#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Polynomial {
    vector<int> coeff;

    Polynomial mul(int n) const {
        Polynomial res = *this;
        for (int &c : res.coeff)
            c *= n;
        return res;
    }

    Polynomial mulN() const {
        Polynomial res = *this;
        res.coeff.insert(res.coeff.begin(), 0);
        return res;
    }

    Polynomial add(const Polynomial &that) const {
        Polynomial res = *this;
        res.coeff.resize(max(res.coeff.size(), that.coeff.size()));
        for (int i = 0; i < that.coeff.size(); i++)
            res.coeff[i] += that.coeff[i];
        return res;
    }

    void print() const {
        int first = 1;
        for (int p = coeff.size() - 1; p >= 0; p--) {
            if (!coeff[p] && (p || !first))
                continue;
            if (first)
                first = 0;
            else
                cout << "+";
            if (coeff[p] > 1 || !p)
                cout << coeff[p];
            if (coeff[p] > 1 && p)
                cout << "*";
            if (p) {
                cout << "n";
                if (p > 1)
                    cout << "^" << p;
            }
        }
    }
};

Polynomial readStatements();

Polynomial readOp() {
    int n;
    cin >> n;
    return { { n } };
}

Polynomial readLoop() {
    string arg;
    cin >> arg;
    Polynomial p = readStatements();
    if (arg == "n")
        return p.mulN();
    else
        return p.mul(stoi(arg));
}

Polynomial readStatements() {
    Polynomial p = { { 0 } };
    while (1) {
        string keyword;
        cin >> keyword;

        if (keyword == "END")
            break;

        if (keyword == "OP")
            p = p.add(readOp());
        else
            p = p.add(readLoop());
    }
    return p;
}

Polynomial readProgram() {
    string header;
    cin >> header;
    return readStatements();
}

void solve(int test) {
    cout << "Program #" << test << "\n";
    cout << "Runtime = ";
    readProgram().print();
    cout << "\n\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}