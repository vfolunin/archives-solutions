#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <random>
using namespace std;

int ask(const string &s) {
    cout << s << endl;

    int ans;
    cin >> ans;

    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    string letters = "AIPZ";
    string res;

    while (res.size() < size) {
        static minstd_rand generator;
        shuffle(letters.begin(), letters.end(), generator);

        for (int i = 0; i < letters.size(); i++) {
            if (i + 1 == letters.size()) {
                res += letters[i];
                break;
            }

            int ans = ask(res + letters[i]);

            if (ans == 1) {
                res += letters[i];
                break;
            } else if (ans == 2) {
                return 0;
            }
        }
    }

    ask(res);
}