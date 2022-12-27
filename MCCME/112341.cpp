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
 
    string res, word;

    while (cin >> word)
        if (res.size() < word.size())
            res = word;

    cout << res << "\n" << res.size();
}