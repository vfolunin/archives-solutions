class ZigzagIterator {
    vector<int> values;
    int i = 0;

public:
    ZigzagIterator(vector<int> &a, vector<int> &b) {
        for (int ai = 0, bi = 0; ai < a.size() || bi < b.size(); ai++, bi++) {
            if (ai < a.size())
                values.push_back(a[ai]);
            if (bi < b.size())
                values.push_back(b[bi]);
        }
    }

    int next() {
        return values[i++];
    }

    bool hasNext() {
        return i < values.size();
    }
};