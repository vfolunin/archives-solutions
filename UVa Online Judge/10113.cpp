#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

struct Fraction {
    long long num, den;

    void normalize() {
        long long d = gcd(num, den);
        num /= d;
        den /= d;
    }

    Fraction(long long num = 0, long long den = 1) : num(num), den(den) {
        normalize();
    }

    Fraction operator + (const Fraction &that) const {
        return Fraction(num * that.den + that.num * den, den * that.den);
    }

    Fraction operator * (const Fraction &that) const {
        return Fraction(num * that.num, den * that.den);
    }
};

Fraction dfs(map<string, map<string, Fraction>> &graph, const string &v, const string &target, set<string> &visited) {
    if (v == target)
        return Fraction(1, 1);

    visited.insert(v);

    for (auto &[to, f] : graph[v]) {
        if (!visited.count(to)) {
            Fraction res = dfs(graph, to, target, visited);
            if (res.num > 0)
                return res * f;
        }
    }

    return Fraction(-1, 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    map<string, map<string, Fraction>> graph;

    while (1) {
        string type;
        cin >> type;

        if (type == ".")
            break;

        if (type == "!") {
            long long a, b;
            string aName, bName, eq;
            cin >> a >> aName >> eq >> b >> bName;

            graph[aName][bName] = Fraction(a, b);
            graph[bName][aName] = Fraction(b, a);
        } else {
            string aName, bName, eq;
            cin >> aName >> eq >> bName;

            set<string> visited;
            auto [a, b] = dfs(graph, aName, bName, visited);
            if (a != -1)
                cout << a << " " << aName << " = " << b << " " << bName << "\n";
            else
                cout << "? " << aName << " = ? " << bName << "\n";
        }
    }
}