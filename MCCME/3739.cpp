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

    int l = s.find('f'), r = s.rfind('f');

    if (l != -1) {
        cout << l;
        if (l != r)
            cout << " " << r;
    }
}