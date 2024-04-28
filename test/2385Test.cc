#include "../src/Tree/2385.hh"

int main() {
    vector<int> nodes = {1,0,2,3,4,0,5};//{1,5,3,0,4,10,6,9,2};
    queue<TreeNode*> fathers;
    TreeNode* root = new TreeNode(nodes[0]);
    fathers.push(root);
    int index = 1;
    while (!fathers.empty() && index<nodes.size()) {
        TreeNode* father = fathers.front();
        fathers.pop();
        if (nodes[index]) {
            TreeNode* son_left = new TreeNode(nodes[index]);
            fathers.push(son_left);
            father->left = son_left;
            // son_left->father = father;
        }
        if (++index < nodes.size()) {
            if (nodes[index]) {
                TreeNode* son_right = new TreeNode(nodes[index]);
                fathers.push(son_right);
                father->right = son_right;
                // son_right->father = father;
            }            
        }
        index++;
    }
    Solution opt;
    cout << opt.amountOfTime(root, 4);
    return 0;  
}