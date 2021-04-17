#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

map<long long, int> getFibIndex() {
    vector<long long> fib = { 1, 2 };
    for (int i = 2; fib.back() < 3e9; i++)
        fib.push_back(fib[i - 1] + fib[i - 2]);
    
    map<long long, int> fibIndex;
    for (int i = 0; i < fib.size(); i++)
        fibIndex[fib[i]] = i;
    return fibIndex;
}

void solve() {
    int fibCount;
    cin >> fibCount;

    vector<long long> fib(fibCount);
    for (long long &f : fib)
        cin >> f;

    string letters;
    getline(cin, letters);
    getline(cin, letters);

    static map<long long, int> fibIndex = getFibIndex();

    string text(50, ' ');
    for (int i = 0, j = 0; i < fibCount; i++) {
        while (!isupper(letters[j]))
            j++;
        text[fibIndex[fib[i]]] = letters[j++];
    }

    while (text.back() == ' ')
        text.pop_back();

    cout << text << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}