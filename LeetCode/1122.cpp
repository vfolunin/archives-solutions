class Solution {
public:
    vector<int> relativeSortArray(vector<int> &arr, vector<int> &part) {
        map<int, int> posInPart;
        for (int i = 0; i < part.size(); i++)
            posInPart[part[i]] = i;
        
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            int pa = posInPart.count(a) ? posInPart[a] : part.size();
            int pb = posInPart.count(b) ? posInPart[b] : part.size();
            if (pa != pb)
                return pa < pb;
            return a < b;
        });
        return arr;
    }
};