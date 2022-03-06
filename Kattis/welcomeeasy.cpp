#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    string line;
    getline(cin, line);

    string target = "welcome to code jam";
    vector<vector<int>> ways(line.size() + 1, vector<int>(target.size() + 1));
    ways[0][0] = 1;

    for (int i = 1; i <= line.size(); i++) {
        for (int len = 0; len <= target.size(); len++) {
            ways[i][len] = ways[i - 1][len];
            if (len && line[i - 1] == target[len - 1])
                ways[i][len] = (ways[i][len] + ways[i - 1][len - 1]) % 10000;
        }
    }

    cout << "Case #" << test << ": " << setw(4) << setfill('0') << ways[line.size()][target.size()] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    cin.ignore();

    for (int test = 1; test <= n; test++)
        solve(test);
}