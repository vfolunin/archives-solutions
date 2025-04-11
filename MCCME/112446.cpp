#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string ask(long long m) {
    cout << m << endl;
    string ans;
    getline(cin, ans);
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    long long l = 1, r;
    cin >> r;
    cin.ignore();

    while (1) {
        long long m = l + (r - l) / 2;
        string ans = ask(m);
        if (ans == "Mrs. Hudson is here")
            break;
        else if (ans == "A woman")
            r = m - 1;
        else
            l = m + 1;
    }
}