#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Tree {
    struct Data {
        int open = 0, close = 0;

        Data() {}

        Data(char c) {
            if (c == '(')
                open = 1;
            else
                close = 1;
        }

        Data(Data &l, Data &r) {
            int common = min(l.open, r.close);
            open = l.open + r.open - common;
            close = l.close + r.close - common;
        }

        void flip() {
            swap(open, close);
        }

        bool isGood() {
            return !open && !close;
        }
    };

    vector<Data> t;
    int size;

    void build(int v, int vl, int vr, string &s) {
        if (vl == vr) {
            t[v] = Data(s[vl]);
            return;
        }
        int vm = vl + (vr - vl) / 2;
        build(2 * v + 1, vl, vm, s);
        build(2 * v + 2, vm + 1, vr, s);
        t[v] = Data(t[2 * v + 1], t[2 * v + 2]);
    }

    void modify(int v, int vl, int vr, int index) {
        if (vl == vr) {
            t[v].flip();
            return;
        }
        int vm = vl + (vr - vl) / 2;
        if (index <= vm)
            modify(2 * v + 1, vl, vm, index);
        else
            modify(2 * v + 2, vm + 1, vr, index);
        t[v] = Data(t[2 * v + 1], t[2 * v + 2]);
    }

    Tree(string &s) {
        size = s.size();
        t.resize(4 * size);
        build(0, 0, size - 1, s);
    }

    bool isCorrect() {
        return t[0].isGood();
    }

    void modify(int index) {
        modify(0, 0, size - 1, index);
    }
};

void solve(int test) {
    int size;
    string s;
    cin >> size >> s;

    Tree tree(s);

    int queryCount;
    cin >> queryCount;

    cout << "Test " << test << ":\n";
    for (int i = 0; i < queryCount; i++) {
        int query;
        cin >> query;

        if (query)
            tree.modify(query - 1);
        else
            cout << (tree.isCorrect() ? "YES\n" : "NO\n");
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; test <= 10; test++)
        solve(test);
}