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
    cin >> s >> s;

    int a = count(s.begin(), s.end(), 'A');
    int d = s.size() - a;

    if (a > d)
        cout << "Anton";
    else if (a == d)
        cout << "Friendship";
    else
        cout << "Danik";
}