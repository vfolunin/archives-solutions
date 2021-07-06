#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<unsigned long long> getFact() {
    vector<unsigned long long> fact = { 1 };
    for (int i = 1; i <= 20; i++)
        fact.push_back(fact[i - 1] * i);
    return fact;
}

void solve(int test) {
    string s;
    unsigned long long index;
    cin >> s >> index;

    index--;
    static vector<unsigned long long> fact = getFact();
    vector<int> pos;
    for (int i = 0; i < s.size(); i++)
        pos.push_back(i);

    string res(s.size(), ' ');
    for (int i = 0, groupSize = s.size() - 1; i < s.size(); i++, groupSize--) {
        int group = index / fact[groupSize];
        res[pos[group]] = s[i];
        pos.erase(pos.begin() + group);
        index %= fact[groupSize];
    }

    cout << "Case " << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}