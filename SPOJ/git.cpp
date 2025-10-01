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

    string op;
    cin >> op;

    if (op == "send")
        cout << "git add -A\ngit commit -m \"Some changes\"\ngit pull\ngit push\n";
    else if (op == "receive")
        cout << "git add -A\ngit stash\ngit pull\ngit stash pop\n";
    else
        cout << "git status -s\n";
}