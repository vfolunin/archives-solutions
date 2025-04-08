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

    int sum = count(s.begin(), s.end(), 'A');

    int res = 1;
    while ((res + 1) * (res + 2) / 2 <= sum)
        res++;

    cout << res;
}