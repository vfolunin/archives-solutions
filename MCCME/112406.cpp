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

    int from = s.find('R');
    if (from == -1)
        from = s.size();

    string res = s;
    res.erase(remove(res.begin() + from, res.end(), 'B'), res.end());

    cout << res << "\n";
    cout << s.size() - res.size();
}