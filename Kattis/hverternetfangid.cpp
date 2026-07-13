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

    string email;
    cin >> email >> email;

    int atPos = email.find('@');
    string user = email.substr(0, atPos);
    user = user.substr(0, user.find('+'));
    string domain = email.substr(atPos + 1);

    cout << user << "@" << domain;
}