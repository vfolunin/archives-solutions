class SegmentTree {
    struct Data {
        char leftChar, rightChar;
        int size = 1, maxSize = 1, leftSize = 1, rightSize = 1;
        
        Data() {}
        
        Data(char c) : leftChar(c), rightChar(c) {}
        
        Data(const Data &a, const Data &b) {
            leftChar = a.leftChar;
            rightChar = b.rightChar;
            
            size = a.size + b.size;
            
            maxSize = max(a.maxSize, b.maxSize);
            if (a.rightChar == b.leftChar)
                maxSize = max(maxSize, a.rightSize + b.leftSize);
            
            leftSize = a.leftSize;
            if (leftSize == a.size && a.rightChar == b.leftChar)
                leftSize += b.leftSize;
            
            rightSize = b.rightSize;
            if (a.rightChar == b.leftChar && rightSize == b.size)
                rightSize += a.rightSize;
        }
    };
    
    vector<Data> t;
    int size;

    void build(int v, int vl, int vr, string &s) {
        if (vl == vr) {
            t[v] = Data(s[vl]);
            return;
        }
        
        int vm = vl + (vr - vl) / 2;
        
        build(2 * v + 1, vl, vm, s);
        build(2 * v + 2, vm + 1, vr, s);
        
        t[v] = Data(t[2 * v + 1], t[2 * v + 2]);
    }

    void modify(int v, int vl, int vr, int index, char c) {
        if (vr < index || index < vl)
            return;
        
        if (vl == vr) {
            t[v] = Data(c);
            return;
        }
        
        int vm = vl + (vr - vl) / 2;
        
        modify(2 * v + 1, vl, vm, index, c);
        modify(2 * v + 2, vm + 1, vr, index, c);
        
        t[v] = Data(t[2 * v + 1], t[2 * v + 2]);
    }

public:
    SegmentTree(string &s) {
        size = s.size();
        t.resize(4 * size);
        build(0, 0, size - 1, s);
    }

    int getMaxSize(int index, char c) {
        modify(0, 0, size - 1, index, c);
        return t[0].maxSize;
    }
};

class Solution {
public:
    vector<int> longestRepeating(string &s, string &chars, vector<int> &indexes) {
        SegmentTree st(s);
        vector<int> res(chars.size());
        
        for (int i = 0; i < chars.size(); i++)
            res[i] = st.getMaxSize(indexes[i], chars[i]);
        
        return res;
    }
};