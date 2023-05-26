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

    string inbox, sent;
    cin >> inbox >> sent;

    cout << stoi(inbox.substr(6, inbox.size() - 7)) + stoi(sent.substr(5, sent.size() - 6));
}