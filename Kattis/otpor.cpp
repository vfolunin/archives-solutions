#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double eval(string &s, int l, int r, vector<double> &a) {
    int depth = 0, posPar = -1, posSeq = -1;
    for (int i = l; i <= r; i++) {
        if (s[i] == '(')
            depth++;
        if (s[i] == ')')
            depth--;
        if (!depth) {
            if (s[i] == '-')
                posSeq = i;
            if (s[i] == '|')
                posPar = i;
        }
    }
    if (posSeq != -1)
        return eval(s, l, posSeq - 1, a) + eval(s, posSeq + 1, r, a);
    if (posPar != -1)
        return 1 / (1 / eval(s, l, posPar - 1, a) + 1 / eval(s, posPar + 1, r, a));
    if (s[l] == '(' && s[r] == ')')
        return eval(s, l + 1, r - 1, a);
    return a[stoi(s.substr(l + 1, r - l)) - 1];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<double> a(size);
    for (double &value : a)
        cin >> value;

    string s;
    cin >> s;

    cout << fixed << eval(s, 0, s.size() - 1, a);
}