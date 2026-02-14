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

    int tokenCount;
    cin >> tokenCount;

    int prev = 0;
    for (int i = 0; i < tokenCount; i++) {
        string token;
        cin >> token;

        if (token == "mumble") {
            prev++;
            continue;
        }

        int cur = stoi(token);
        if (prev + 1 == cur) {
            prev = cur;
            continue;
        }

        cout << "something is fishy";
        return 0;
    }

    cout << "makes sense";
}