#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int peopleCount;
    if (!(cin >> peopleCount))
        return 0;

    vector<string> names(peopleCount);
    for (string &name : names)
        cin >> name;

    map<string, int> money;
    for (int i = 0; i < peopleCount; i++) {
        string gifterName;
        int price, recipientCount;
        cin >> gifterName >> price >> recipientCount;

        if (!recipientCount)
            continue;

        int pricePerRecipient = price / recipientCount;
        money[gifterName] -= pricePerRecipient * recipientCount;

        for (int j = 0; j < recipientCount; j++) {
            string recipientName;
            cin >> recipientName;
            money[recipientName] += pricePerRecipient;
        }
    }
    
    if (test)
        cout << "\n";
    for (string &name : names)
        cout << name << " " << money[name] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}