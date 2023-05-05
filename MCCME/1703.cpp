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

    string a, b;
    cin >> a >> b;

    int bulls = 0, cows = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i])
            bulls++;
        else
            cows += count(a.begin(), a.end(), b[i]);
    }

    cout << bulls << " " << cows;
}