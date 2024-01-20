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
    getline(cin, s);

    int size = count(s.begin(), s.end(), 'a');
    if (size)
        cout << string(size, 'a');
    else
        cout << -1;
}