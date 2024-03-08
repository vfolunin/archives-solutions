#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Monom {
    int coeff = 1, exponent = 0;

    long long evaluate(int x) {
        long long res = coeff;
        for (int i = 0; i < exponent; i++)
            res *= x;
        return res;
    }

    friend istream &operator >> (istream &in, Monom &monom) {
        if (in.peek() == '+' || in.peek() == '-') {
            if (in.peek() == '-')
                monom.coeff = -1;
            in.get();
        }
        if (isdigit(in.peek())) {
            int value;
            in >> value;
            monom.coeff *= value;
        }
        if (in.peek() == '*') {
            in.get();
        }
        if (in.peek() == 'x') {
            in.get();
            monom.exponent = 1;
            if (in.peek() == '^') {
                in.get();
                in >> monom.exponent;
            }
        }
        return in;
    }
};

struct Polynom {
    vector<Monom> monoms;

    long long evaluate(int x) {
        long long res = 0;
        for (Monom &monom : monoms)
            res += monom.evaluate(x);
        return res;
    }

    friend istream &operator >> (istream &in, Polynom &polynom) {
        while (!isspace(in.peek()))
            in >> polynom.monoms.emplace_back();
        return in;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Polynom polynom;
    int x;
    cin >> polynom >> x;

    cout << polynom.evaluate(x);
}