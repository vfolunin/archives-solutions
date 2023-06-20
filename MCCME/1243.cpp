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

    string res;

    while (cin.peek() != '\n' && cin.peek() != EOF) {
        int count = 1;
        if (isdigit(cin.peek()))
            cin >> count;
        
        char c;
        cin >> c;

        res += string(count, c);
    }

    for (int from = 0; from < res.size(); from += 40)
        cout << res.substr(from, 40) << "\n";
}