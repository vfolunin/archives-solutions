struct Node {
    string value;
    Node *left, *right;

    Node(string &value, Node *left = 0, Node *right = 0) :
        value(value), left(left), right(right) {}

    int evaluate() {
        if (isdigit(value[0]))
            return stoi(value);
        
        int a = left->evaluate();
        int b = right->evaluate();

        if (value == "+")
            return a + b;
        else if (value == "-")
            return a - b;
        else if (value == "*")
            return a * b;
        else
            return a / b;
    };
};

struct TreeBuilder {
    Node *buildTree(vector<string> &postfix) {
        string value = postfix.back();
        postfix.pop_back();

        if (isdigit(value[0])) {
            return new Node(value);
        } else {
            Node *right = buildTree(postfix);
            Node *left = buildTree(postfix);
            return new Node(value, left, right);
        }
    }
};