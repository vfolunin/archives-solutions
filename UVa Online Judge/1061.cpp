#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string bloodType(const string &genes) {
    if (genes == "OO")
        return "O";
    if (genes == "AB" || genes == "BA")
        return "AB";
    if (genes.find("A") != -1)
        return "A";
    return "B";
}

string rhType(const string &genes) {
    if (genes == "--")
        return "-";
    return "+";
}

string type(const string &bloodGenes, const string &rhGenes) {
    return bloodType(bloodGenes) + rhType(rhGenes);
}

vector<string> types(const string &p1, const string &p2, const string &c) {
    set<string> res;

    for (const string &p1b : { "OO", "AO", "AA", "BO", "BB", "AB" }) {
        for (const string &p1r : { "++", "+-", "--" }) {
            if (p1 != "?" && type(p1b, p1r) != p1)
                continue;

            for (const string &p2b : { "OO", "AO", "AA", "BO", "BB", "AB" }) {
                for (const string &p2r : { "++", "+-", "--" }) {
                    if (p2 != "?" && type(p2b, p2r) != p2)
                        continue;

                    for (int b1 = 0; b1 < 2; b1++) {
                        for (int b2 = 0; b2 < 2; b2++) {
                            string cb;
                            cb += p1b[b1];
                            cb += p2b[b2];

                            for (int r1 = 0; r1 < 2; r1++) {
                                for (int r2 = 0; r2 < 2; r2++) {
                                    string cr;
                                    cr += p1r[r1];
                                    cr += p2r[r2];

                                    if (c != "?" && type(cb, cr) != c)
                                        continue;

                                    if (p1 == "?")
                                        res.insert(type(p1b, p1r));
                                    else if (p2 == "?")
                                        res.insert(type(p2b, p2r));
                                    else
                                        res.insert(type(cb, cr));
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return vector<string>(res.begin(), res.end());
}

bool solve(int test) {
    string p1, p2, c;
    cin >> p1 >> p2 >> c;

    if (p1 == "E")
        return 0;

    vector<string> t = types(p1, p2, c);
    string res;
    if (t.empty()) {
        res = "IMPOSSIBLE";
    } else {
        for (int i = 0; i < t.size(); i++)
            res += t[i] + (i + 1 < t.size() ? ", " : "");
        if (t.size() > 1)
            res = "{" + res + "}";
    }

    if (p1 == "?")
        p1 = res;
    else if (p2 == "?")
        p2 = res;
    else
        c = res;

    cout << "Case " << test << ": " << p1 << " " << p2 << " " << c << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}