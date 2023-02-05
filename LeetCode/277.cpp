class Solution {
public:
    int findCelebrity(int vertexCount) {
        int res = 0;

        for (int v = 0; v < vertexCount; v++)
            if (res != v && knows(res, v))
                res = v;
        
        for (int v = 0; v < vertexCount; v++)
            if (res != v && (knows(res, v) || !knows(v, res)))
                return -1;

        return res;
    }
};