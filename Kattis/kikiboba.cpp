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

    int bCount = count(s.begin(), s.end(), 'b');
    int kCount = count(s.begin(), s.end(), 'k');

    if (!bCount && !kCount)
        cout << "none";
    else if (bCount > kCount)
        cout << "boba";
    else if (bCount < kCount)
        cout << "kiki";
    else
        cout << "boki";
}