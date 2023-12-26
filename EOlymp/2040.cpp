#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> readCount() {
    string s;
    if (!getline(cin, s))
        return {};

    vector<int> count(26);
    for (char c : s)
        count[c - 'a']++;

    return count;
}

string makeString(vector<int> &countA, vector<int> &countB) {
    string res;
    for (int i = 0; i < countA.size(); i++)
        res += string(min(countA[i], countB[i]), i + 'a');
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (1) {
        vector<int> countA = readCount();
        vector<int> countB = readCount();
        if (countA.empty() && countB.empty())
            break;

        cout << makeString(countA, countB) << "\n";
    }
}