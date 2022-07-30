class Solution {
    bool intersects(vector<int> &a, vector<int> &b) {
        return a[0] <= b[1] && b[0] <= a[1];
    }
    
    void merge(vector<int> &a, vector<int> &b) {
        b[0] = min(b[0], a[0]);
        b[1] = max(b[1], a[1]);
    }
    
public:
    vector<vector<int>> insert(vector<vector<int>> &segments, vector<int> &segment) {
        int l = -1, r = -1;
        
        for (int i = 0; i < segments.size(); i++) {
            if (intersects(segments[i], segment)) {
                if (l == -1)
                    l = i;
                r = i;
                merge(segments[i], segment);
            }
        }
        
        if (l != -1)
            segments.erase(segments.begin() + l, segments.begin() + r + 1);
        segments.push_back(segment);
        sort(segments.begin(), segments.end());
        
        return segments;
    }
};