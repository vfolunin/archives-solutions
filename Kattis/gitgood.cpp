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

    int opCount;
    cin >> opCount;

    vector<string> path;
    set<string> adds;

    for (int i = 0; i < opCount; i++) {
        string op, arg;
        cin >> op >> arg;

        if (op == "cd") {
            if (arg == "..")
                path.pop_back();
            else
                path.push_back(arg);
        } else {
            string dirs;
            for (string dir : path)
                dirs += dir + "/";
            adds.insert(dirs + arg);
        }
    }

    for (const string &add : adds)
        cout << "git add " << add << "\n";
    cout << "git commit\n";
    cout << "git push";
}