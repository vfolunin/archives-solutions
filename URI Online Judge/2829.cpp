#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool compare(string &a, string &b) {
    for (int i = 0; i < a.size() && i < b.size(); i++)
        if (tolower(a[i]) != tolower(b[i]))
            return tolower(a[i]) < tolower(b[i]);

    if (a.size() != b.size())
        return a.size() < b.size();

    for (int i = 0; i < a.size(); i++)
        if (a[i] != b[i])
            return a[i] < b[i];

    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<string> s(size);
    for (string &s : s)
        cin >> s;

    sort(s.begin(), s.end(), compare);

    for (string &s : s)
        cout << s << "\n";
}