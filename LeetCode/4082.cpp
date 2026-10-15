struct Penalties {
    multiset<long long> lessPenalties, greaterPenalties;
    long long limit = 0, cost = 0;

    int size() {
        return lessPenalties.size() + greaterPenalties.size();
    }

    void merge(Penalties &that) {
        for (long long thatPenalty : that.lessPenalties)
            lessPenalties.insert(thatPenalty - that.limit + limit);

        for (long long thatPenalty : that.greaterPenalties)
            greaterPenalties.insert(thatPenalty + that.limit - limit);

        limit++;
        cost += that.cost;
    }

    void addValue(long long value) {
        lessPenalties.insert(value + limit);
        greaterPenalties.insert(value - limit);

        while (!lessPenalties.empty() && !greaterPenalties.empty()) {
            auto lessIt = prev(lessPenalties.end());
            auto greaterIt = greaterPenalties.begin();

            if (*lessIt - limit <= *greaterIt + limit)
                break;

            cost += *lessIt - *greaterIt - 2 * limit;

            lessPenalties.insert(*greaterIt + 2 * limit);
            greaterPenalties.insert(*lessIt - 2 * limit);

            lessPenalties.erase(lessIt);
            greaterPenalties.erase(greaterIt);
        }
    }
};

class Solution {
    Penalties rec(TreeNode *node) {
        if (!node)
            return {};

        Penalties leftPenalties = rec(node->left);
        Penalties rightPenalties = rec(node->right);

        if (leftPenalties.size() < rightPenalties.size())
            swap(leftPenalties, rightPenalties);
        leftPenalties.merge(rightPenalties);

        leftPenalties.addValue(node->val);
        
        return leftPenalties;
    }

public:
    long long stabilizeBinaryTree(TreeNode *root) {
        return rec(root).cost;
    }
};