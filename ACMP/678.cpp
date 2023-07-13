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

    string ops;
    cin >> ops;
    
    string s = ".  ";

    for (char op : ops) {
        if (op == 'A')
            swap(s[0], s[1]);
        else if (op == 'B')
            swap(s[1], s[2]);
        else
            swap(s[0], s[2]);
    }

    cout << s.find('.') + 1;
}