#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Trie {
    struct Node {
        int next[2] = { -1, -1 }, index;
    };
    vector<Node> nodes;
    int nodeCount = 1;

    Trie() : nodes(6e6) {}

    void insert(long long value, int index) {
        int nodeIndex = 0;
        for (int bit = 60; bit >= 0; bit--) {
            if (nodes[nodeIndex].next[(value >> bit) & 1] == -1)
                nodes[nodeIndex].next[(value >> bit) & 1] = nodeCount++;
            nodeIndex = nodes[nodeIndex].next[(value >> bit) & 1];
        }
        nodes[nodeIndex].index = index;
    }

    pair<long long, int> getMaxXor(long long value) {
        int nodeIndex = 0;
        long long maxXor = 0;
        for (int bit = 60; bit >= 0; bit--) {
            int bitValue = (value >> bit) & 1;
            if (nodes[nodeIndex].next[bitValue ^ 1] != -1) {
                maxXor |= 1LL << bit;
                nodeIndex = nodes[nodeIndex].next[bitValue ^ 1];
            } else {
                nodeIndex = nodes[nodeIndex].next[bitValue];
            }
        }
        return { maxXor, nodes[nodeIndex].index };
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    long long xorSum = 0;
    Trie trie;
    trie.insert(xorSum, 0);

    long long bestXor = -1;
    int bestL, bestR;
    for (int i = 1; i <= size; i++) {
        long long value;
        cin >> value;

        xorSum ^= value;
        auto [maxXor, maxL] = trie.getMaxXor(xorSum);
        if (bestXor < maxXor) {
            bestXor = maxXor;
            bestL = maxL + 1;
            bestR = i;
        }

        trie.insert(xorSum, i);
    }

    cout << bestL << " " << bestR << " " << bestXor;
}