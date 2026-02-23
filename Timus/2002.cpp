#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int queryCount;
    cin >> queryCount;

    unordered_map<string, string> userPassword;
    unordered_set<string> online;

    for (int i = 0; i < queryCount; i++) {
        string type;
        cin >> type;

        if (type == "register") {
            string user, password;
            cin >> user >> password;

            if (userPassword.count(user)) {
                cout << "fail: user already exists\n";
            } else {
                userPassword[user] = password;
                cout << "success: new user added\n";
            }
        } else if (type == "login") {
            string user, password;
            cin >> user >> password;

            if (!userPassword.count(user)) {
                cout << "fail: no such user\n";
            } else if (userPassword[user] != password) {
                cout << "fail: incorrect password\n";
            } else if (online.count(user)) {
                cout << "fail: already logged in\n";
            } else {
                online.insert(user);
                cout << "success: user logged in\n";
            }
        } else {
            string user;
            cin >> user;

            if (!userPassword.count(user)) {
                cout << "fail: no such user\n";
            } else if (!online.count(user)) {
                cout << "fail: already logged out\n";
            } else {
                online.erase(user);
                cout << "success: user logged out\n";
            }
        }
    }
}