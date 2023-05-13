#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

char get(string &s, int index) {
    return index < s.size() ? s[index] : '0';
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int index;
    cin >> index;
    index--;

    string res;
    for (string s; cin >> s; )
        if (res.empty() || get(res, index) < get(s, index))
            res = s;
    
    cout << res;
}