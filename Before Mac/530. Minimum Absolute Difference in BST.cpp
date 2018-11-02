#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
struct TreeNode{
	char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
void createTree(TreeNode*& t){//preorder create node
	char ch;
    cin>>ch;
    if(ch=='#')
    {
        t=NULL;
    }
    else
    {
        t=(TreeNode*)malloc(sizeof(TreeNode));
        t->val=ch;
        createTree(t->left);
        createTree(t->right);
    }
}
void showTree(TreeNode* root){//preorder 
	if(root!=NULL){
		cout<<root->val<<endl;
		showTree(root->left);
		showTree(root->right);
	}
}
void inOrderTraverse(TreeNode* root,vector<int>& nums){
	if(root!=NULL){
		inOrderTraverse(root->left,nums);
		nums.push_back(root->val);
		inOrderTraverse(root->right,nums);	
	}
}
int getMinimumDifference(TreeNode* root){
    vector<int> nums;
    inOrderTraverse(root,nums);
    int m=INT_MAX;
    int dif;
    for(int i=0;i<nums.size()-1;i++)
    {
    	dif=nums[i]>nums[i+1]?nums[i]-nums[i+1]:nums[i+1]-nums[i];
    	m=min(m,dif);
	}
	return m;
}
int main(){
	TreeNode* root;
	createTree(root);
	//showTree(root); 
	cout<<getMinimumDifference(root)<<endl;
	return 0;
}
/*
空间复杂度为O(n)的方案：
	int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX, pre = -1;
        inorder(root, pre, res);
        return res;
    }
    void inorder(TreeNode* root, int& pre, int& res) {
        if (!root) return;
        inorder(root->left, pre, res);
        if (pre != -1) res = min(res, root->val - pre);
        pre = root->val;
        inorder(root->right, pre, res);
    } 
*/
