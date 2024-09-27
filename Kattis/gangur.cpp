#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    int lCount = count(s.begin(), s.end(), '<');
    long long res = 0;

    for (char c : s) {
        if (c == '<')
            lCount--;
        else if (c == '>')
            res += lCount;
    }

    cout << res;
}