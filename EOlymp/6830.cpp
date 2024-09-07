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

    int limit;
    string s;
    cin >> limit >> s;

    int balance = 0, res = 0;
    char wait = ' ';

    for (int i = 0; i < s.size(); ) {
        if (wait == 'M' && balance < limit) {
            wait = ' ';
            balance++;
            res++;
        } else if (wait == 'W' && balance > -limit) {
            wait = ' ';
            balance--;
            res++;
        } else if (s[i] == 'M' && balance < limit) {
            i++;
            balance++;
            res++;
        } else if (s[i] == 'W' && balance > -limit) {
            i++;
            balance--;
            res++;
        } else if (wait == ' ') {
            wait = s[i];
            i++;
        } else {
            break;
        }
    }

    cout << res << "\n";
}