class Solution {
public:
    int videoStitching(vector<vector<int>> &segments, int width) {
        sort(segments.begin(), segments.end());
        
        int to = 0, res = 0;
        for (int i = 0; i < segments.size() && to < width; ) {
            int nextTo = -1;
            for ( ; i < segments.size() && segments[i][0] <= to; i++)
                nextTo = max(nextTo, segments[i][1]);
            
            if (nextTo == -1)
                return -1;
            res++;
            to = nextTo;
        }
        
        return to >= width ? res : -1;
    }
};