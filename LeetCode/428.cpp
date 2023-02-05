class Codec {
    void serialize(Node *n, stringstream &ss) {
        ss << n->val;
        for (Node *child : n->children) {
            ss << " ";
            serialize(child, ss);
        }
        ss << "#";
    }
    
    Node *deserialize(stringstream &ss) {
        int val;
        ss >> val;
        Node *n = new Node(val);
        while (ss.get() != '#')
            n->children.push_back(deserialize(ss));
        return n;
    }
    
public:
    string serialize(Node *root) {
        if (!root)
            return "";

        stringstream ss;
        serialize(root, ss);
        return ss.str();
    }

    Node *deserialize(const string &s) {
        if (s.empty())
            return 0;
            
        stringstream ss(s);
        return deserialize(ss);
    }
};