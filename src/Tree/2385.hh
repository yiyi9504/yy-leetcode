#include "../../include/common.hh"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    // TreeNode *father;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        find_start(root, start);
        return max((int)path.size(), dfs(root, 0, 0, true, 0));
    }

private:
    int dfs(TreeNode* node, int deep, int gap, bool samepath, int max_deepth) {
        if (gap > max_deepth) max_deepth = gap;
        if (node->left) {
            if (samepath) {
                if (deep<path.size() && path[deep] == 0) {
                    max_deepth = max(max_deepth, dfs(node->left, deep+1, gap, samepath, max_deepth));
                } else {
                    max_deepth = max(max_deepth, dfs(node->left, deep+1, path.size()-deep+1, false, max_deepth));
                }
            } else {
                max_deepth = max(max_deepth, dfs(node->left, deep+1, gap+1, samepath, max_deepth));
            }
        }
        if (node->right) {
            if (samepath) {
                if (deep<path.size() && path[deep] == 1) {
                    max_deepth = max(max_deepth, dfs(node->right, deep+1, gap, samepath, max_deepth));
                } else {
                    max_deepth = max(max_deepth, dfs(node->right, deep+1, path.size()-deep+1, false, max_deepth));
                }
            } else {
                max_deepth = max(max_deepth, dfs(node->right, deep+1, gap+1, samepath, max_deepth));
            }
        }
        return max_deepth;        
    }

    TreeNode* find_start(TreeNode* node, int start) {
        TreeNode* start_node = nullptr;
        if (node->val == start) return node;
        if (node->left) {
            path.push_back(0);
            TreeNode* start_left = find_start(node->left, start);
            if (start_left) {
                return start_left;
            } else {
                path.pop_back();
            }          
        }
        if (node->right) {
            path.push_back(1);
            TreeNode* start_right = find_start(node->right, start);
            if (start_right) {
                return start_right;
            } else {
                path.pop_back();
            }
        }
        return start_node;
    }
    vector<int> path;
};

// class Solution {
// public:
//     int amountOfTime(TreeNode* root, int start) {
//         TreeNode* start_node = find_start(root, start);
//         queue<pair<TreeNode*, int>> nodes;
//         pair<TreeNode*, int> p{start_node, 0};
//         nodes.push(p);
//         flag_[start] = 1;
//         int max_deepth = 0;
//         while(!nodes.empty()) {
//             auto node = nodes.front();
//             //cout << node.first->val << ' ';
//             nodes.pop();
//             if (node.second > max_deepth) max_deepth = node.second;
//             if(node.first->father) {
//                 auto father = node.first->father;
//                 if (flag_[father->val] == 0) {
//                     pair<TreeNode*, int> p_next{father, node.second+1};
//                     nodes.push(p_next);
//                     flag_[father->val] = 1;
//                 }
//             }
//             if(node.first->left) {
//                 auto son_left = node.first->left;
//                 if (flag_[son_left->val] == 0) {
//                     pair<TreeNode*, int> p_next{son_left, node.second+1};
//                     nodes.push(p_next);
//                     flag_[son_left->val] = 1;
//                 }
//             }
//             if(node.first->right) {
//                 auto son_right = node.first->right;
//                 if (flag_[son_right->val] == 0) {
//                     pair<TreeNode*, int> p_next{son_right, node.second+1};
//                     nodes.push(p_next);
//                     flag_[son_right->val] = 1;
//                 }
//             }                        
//         }
//         return max_deepth;
//     }

// private:
//     TreeNode* find_start(TreeNode* node, int start) {
//         TreeNode* start_node = nullptr;
//         if (node->val == start) return node;
//         if (node->left) {
//             TreeNode* start_left = find_start(node->left, start);
//             if (start_left) return start_left;            
//         }
//         if (node->right) {
//             TreeNode* start_right = find_start(node->right, start);
//             if (start_right) return start_right;
//         }
//         return start_node;
//     }
//     int flag_[100100] = {0};     
// };