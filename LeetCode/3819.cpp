class Solution {
public:
    vector<int> rotateElements(vector<int> &a, int shift) {
        vector<int> b;
        for (int value : a)
            if (value >= 0)
                b.push_back(value);
        
        if (!b.empty())
            rotate(b.begin(), b.begin() + shift % b.size(), b.end());

        for (int ai = 0, bi = 0; ai < a.size(); ai++)
            if (a[ai] >= 0)
                a[ai] = b[bi++];
        return a;
    }
};