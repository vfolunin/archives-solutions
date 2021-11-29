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

    int visitorCount;
    cin >> visitorCount;
    cin.ignore();

    vector<string> stack = { "F A C E" };
    int winnerCount = 0;

    for (int i = 0; i < visitorCount; i++) {
        string s;
        getline(cin, s);

        string r = s;
        reverse(r.begin(), r.end());

        if (stack.back() == r) {
            winnerCount++;
            stack.pop_back();
            if (stack.empty())
                stack.push_back("F A C E");
        } else {
            stack.push_back(s);
        }
    }

    cout << winnerCount << "\n";
}