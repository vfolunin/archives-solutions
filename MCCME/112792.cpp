#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Trie {
    struct Node {
        map<int, Node> next;
    } root;

    void insert(int value) {
        Node *n = &root;
        for (int bit = 30; bit >= 0; bit--)
            n = &n->next[(value >> bit) & 1];
    }

    long long getMaxXorArg(int value) {
        Node *n = &root;
        int res = 0;
        for (int bit = 30; bit >= 0; bit--) {
            int bitValue = (value >> bit) & 1;
            if (n->next.count(bitValue ^ 1)) {
                res |= (bitValue ^ 1) << bit;
                n = &n->next[bitValue ^ 1];
            } else {
                res |= bitValue << bit;
                n = &n->next[bitValue];
            }
        }
        return res;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    Trie trie;
    for (int i = 0; i < size; i++) {
        long long value;
        cin >> value;

        trie.insert(value);
    }

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        long long value;
        cin >> value;

        cout << trie.getMaxXorArg(value) << " ";
    }
}