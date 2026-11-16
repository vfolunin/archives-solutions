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

    string s;
    int opCount;
    cin >> s >> opCount;

    int resFrom = 0, count;
    for (int i = 0; i < opCount; i++) {
        int from;
        cin >> from >> count;

        resFrom += from;
    }

    cout << s.substr(resFrom, count);
}