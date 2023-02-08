class Solution {
    int rec(int v, vector<int> &flip, int curFlip) {
        if (v >= flip.size())
            return 0;

        curFlip ^= flip[v];
        int l = rec(2 * v, flip, curFlip);
        int r = rec(2 * v + 1, flip, curFlip);
        return curFlip + l + r; 
    }
    
public:
    int numberOfNodes(int vertexCount, vector<int> &queries) {
        vector<int> flip(vertexCount + 1);
        for (int v : queries)
            flip[v] ^= 1;
        return rec(1, flip, 0);
    }
};