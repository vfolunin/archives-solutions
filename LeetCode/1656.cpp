class OrderedStream {
    vector<string> values;
    int i = 0;
    
public:
    OrderedStream(int n) : values(n) {}
    
    vector<string> insert(int idKey, string value) {
        values[idKey - 1] = value;
        vector<string> res;
        for (; i != values.size() && !values[i].empty(); i++)
            res.push_back(values[i]);
        return res;
    }
};