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
    cin >> s;

    string stack;
    for (char c : s) {
        if (islower(c)) {
            stack.push_back(c);
        } else if (isupper(c)) {
            while (!stack.empty() && stack.back() != tolower(c))
                stack.pop_back();

            if (stack.empty()) {
                cout << "Neibb";
                return 0;
            }

            stack.pop_back();
        }
    }

    for (char c : { 'p', 'g', 'o' })
        cout << count(stack.begin(), stack.end(), c) << "\n";
}