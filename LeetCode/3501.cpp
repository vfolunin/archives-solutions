class SparseTable {
    vector<int> lg;
    vector<vector<int>> st;

public:
    SparseTable(vector<int> &a) {
        lg.resize(a.size() + 1);
        for (int i = 2; i <= a.size(); i++)
            lg[i] = lg[i / 2] + 1;

        st.push_back(a);
        for (int level = 1, levelWidth = 2; levelWidth <= a.size(); level++, levelWidth *= 2) {
            st.emplace_back();
            for (int i = 0; i + levelWidth <= a.size(); i++)
                st[level].push_back(max(st[level - 1][i], st[level - 1][i + levelWidth / 2]));
        }
    }

    int getMax(int l, int r) {
        int level = lg[r - l + 1], levelWidth = 1 << level;
        return max(st[level][l], st[level][r - levelWidth + 1]);
    }
};

struct Block {
    int sIndex, size, blockPairIndex;
};

int getBlockIndex(vector<Block> &blocks, int sIndex) {
    int l = -1, r = blocks.size();
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (blocks[m].sIndex <= sIndex)
            l = m;
        else
            r = m;
    }
    return l;
}

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string &s, vector<vector<int>> &queries) {
        vector<Block> blocks;
        for (int i = 0; i < s.size(); i++) {
            if (!i || s[i - 1] != s[i])
                blocks.push_back({ i, 1, -1 });
            else
                blocks.back().size++;
        }

        vector<int> blockPairs;
        for (int i = 0; i + 2 < blocks.size(); i++) {
            if (s[blocks[i].sIndex] == '0') {
                blocks[i].blockPairIndex = blockPairs.size();
                blockPairs.push_back(blocks[i].size + blocks[i + 2].size);
            }
        }

        SparseTable sparseTable(blockPairs);

        vector<int> res(queries.size(), count(s.begin(), s.end(), '1'));
        for (int i = 0; i < res.size(); i++) {
            int l = queries[i][0], r = queries[i][1];
            int lBlockIndex = getBlockIndex(blocks, l), rBlockIndex = getBlockIndex(blocks, r);

            if (lBlockIndex + 2 > rBlockIndex || lBlockIndex + 2 == rBlockIndex && s[blocks[lBlockIndex].sIndex] == '1')
                continue;
            
            if (lBlockIndex + 2 == rBlockIndex) {
                res[i] += r - l + 1 - blocks[lBlockIndex + 1].size;
                continue;
            }
            
            int lZeros = 0;
            if (s[blocks[lBlockIndex].sIndex] == '0') {
                lZeros = blocks[lBlockIndex].sIndex + blocks[lBlockIndex].size - l + blocks[lBlockIndex + 2].size;
                lBlockIndex += 2;
            } else {
                lBlockIndex++;
            }
            
            int rZeros = 0;
            if (s[blocks[rBlockIndex].sIndex] == '0') {
                rZeros = blocks[rBlockIndex - 2].size + r - blocks[rBlockIndex].sIndex + 1;
                rBlockIndex -= 4;
            } else {
                rBlockIndex -= 3;
            }

            int zeros = 0;
            if (lBlockIndex <= rBlockIndex)
                zeros = sparseTable.getMax(blocks[lBlockIndex].blockPairIndex, blocks[rBlockIndex].blockPairIndex);
            
            res[i] += max({ lZeros, rZeros, zeros });
        }
        return res;
    }
};