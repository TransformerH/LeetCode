//
//  LeetCode95.cpp
//  LeetCode
//
//  Created by 韩雪滢 on 2018/5/5.
//  Copyright © 2018 韩雪滢. All rights reserved.
//

#include "LeetCode95.hpp"
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};


TreeNode* addDiff(TreeNode* subTree, int diff){
    if(!subTree)
        return subTree;
    TreeNode* newSub = new TreeNode(subTree->val + diff);
    newSub->left = addDiff(subTree->left, diff);
    newSub->right = addDiff(subTree->right, diff);
    return newSub;
}

// dynamic prgramming 的最小问题
vector<TreeNode*> generateTrees(int n) {
    if(n == 0)
        return vector<TreeNode*>();
    vector<vector<TreeNode*>> result;
    result.push_back(vector<TreeNode*>());
    result[0].push_back(NULL);
    for(int i = 1;i <= n; i++){
        result.push_back(vector<TreeNode*>());
        for(int j = 1; j <= i; j++){
            // l: 1...j-1
            // r: j+1...n   =>  1...n-j
            for(int l = 0; l < result[j-1].size(); l++){
                for(int r = 0; r < result[i-j].size(); r++){
                    TreeNode* newSub = new TreeNode(j);
                    newSub->left = addDiff(result[j-1][l], 0);
                    newSub->right = addDiff(result[i-j][r], j);
                    result[i].push_back(newSub);
                }
            }
        }
    }
    
    return result[n];
}
