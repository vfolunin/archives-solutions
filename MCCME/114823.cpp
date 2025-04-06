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
    int res = 0;

    while (sum > res) {
        res++;
        sum -= res;
    }

    cout << res;
}