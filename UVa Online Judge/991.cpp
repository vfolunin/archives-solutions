#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<long long>> getC() {
    vector<vector<long long>> c(21, vector<long long>(21));
    for (int i = 0; i < c.size(); i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++)
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }
    return c;
}

vector<long long> getCatalan() {
    static vector<vector<long long>> c = getC();
    vector<long long> catalan(11);
    for (int i = 1; i < catalan.size(); i++)
        catalan[i] = c[2 * i][i] / (i + 1);
    return catalan;
}

bool solve(int test) {
    int n;
    if (!(cin >> n))
        return 0;

    static vector<long long> catalan = getCatalan();
    
    if (test)
        cout << "\n";
    cout << catalan[n] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}