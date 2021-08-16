#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void toUpper(string &s) {
    for (char &c : s)
        c = toupper(c);
}

bool compare(string &a, string &b) {
    if (a.size() != b.size())
        return a.size() > b.size();
    return a < b;
}

void rec(vector<string> &topics, int index, set<pair<string, string>> &pairs, vector<string> &set, int setSize) {
    if (set.size() == setSize) {
        for (int i = 0; i < set.size(); i++)
            cout << set[i] << (i + 1 < set.size() ? " " : "\n");
        return;
    }

    if (index == topics.size())
        return;

    bool ok = 1;
    for (string &topic : set) {
        if (pairs.count({ topic, topics[index] })) {
            ok = 0;
            break;
        }
    }

    if (ok) {
        set.push_back(topics[index]);
        rec(topics, index + 1, pairs, set, setSize);
        set.pop_back();
    }
    rec(topics, index + 1, pairs, set, setSize);
}

void solve(int test) {
    int topicCount, pairCount, setSize;
    cin >> topicCount >> pairCount >> setSize;

    vector<string> topics(topicCount);
    for (string &topic : topics) {
        cin >> topic;
        toUpper(topic);
    }
    sort(topics.begin(), topics.end(), compare);

    set<pair<string, string>> pairs;
    for (int i = 0; i < pairCount; i++) {
        string a, b;
        cin >> a >> b;
        toUpper(a);
        toUpper(b);
        if (!compare(a, b))
            swap(a, b);
        pairs.insert({ a, b });
    }

    cout << "Set " << test << ":\n";
    vector<string> set;
    rec(topics, 0, pairs, set, setSize);
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}