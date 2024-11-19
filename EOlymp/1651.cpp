#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Trie {
    struct Node {
        int next[2] = { -1, -1 };
    };
    vector<Node> nodes;
    int nodeCount = 1;

    Trie() : nodes(6e6) {}

    void insert(long long value) {
        int nodeIndex = 0;
        for (int bit = 60; bit >= 0; bit--) {
            if (nodes[nodeIndex].next[(value >> bit) & 1] == -1)
                nodes[nodeIndex].next[(value >> bit) & 1] = nodeCount++;
            nodeIndex = nodes[nodeIndex].next[(value >> bit) & 1];
        }
    }

    long long getMaxXorArg(long long value) {
        int nodeIndex = 0;
        long long res = 0;
        for (int bit = 60; bit >= 0; bit--) {
            long long bitValue = (value >> bit) & 1;
            if (nodes[nodeIndex].next[bitValue ^ 1] != -1) {
                res |= (bitValue ^ 1) << bit;
                nodeIndex = nodes[nodeIndex].next[bitValue ^ 1];
            } else {
                res |= bitValue << bit;
                nodeIndex = nodes[nodeIndex].next[bitValue];
            }
        }
        return res;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int size, queryCount;
    cin >> size >> queryCount;

    Trie trie;
    for (int i = 0; i < size; i++) {
        long long value;
        cin >> value;

        trie.insert(value);
    }

    for (int i = 0; i < queryCount; i++) {
        long long value;
        cin >> value;

        cout << trie.getMaxXorArg(value) << "\n";
    }
}