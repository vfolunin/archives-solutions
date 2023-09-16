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

    string num;
    int den;
    cin >> num >> den;

    long long res = 0;
    for (char c : num)
        res = (res * 10 + c - '0') % den;

    cout << res;
}