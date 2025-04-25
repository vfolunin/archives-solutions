#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isShift(char c) {
    static string shifted = "!?$()";
    return isupper(c) || shifted.find(c) != -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    getline(cin, s);
    getline(cin, s);

    int res = 0, shift = 0;
    for (char c : s) {
        if (isShift(c)) {
            res += !shift;
            shift = 1;
        } else if (c != ' ') {
            shift = 0;
        }
        res++;
    }

    cout << res;
}