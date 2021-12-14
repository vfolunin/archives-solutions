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

    int emailCount;
    cin >> emailCount;

    set<string> emails;
    for (int i = 0; i < emailCount; i++) {
        string email;
        cin >> email;

        int at = email.find('@');
        string user = email.substr(0, at);
        user.erase(remove(user.begin(), user.end(), '.'), user.end());
        if (int plus = user.find('+'); plus != -1)
            user = user.substr(0, plus);

        emails.insert(user + email.substr(at));
    }

    cout << emails.size() << "\n";
}