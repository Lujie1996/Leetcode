#include <iostream>
#include <vector>
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
void inOrderTraverse(TreeNode* root, vector<int>& nums, int k){
	if(root!=NULL&&nums.size()!=k){
		inOrderTraverse(root->left,nums,k);
		nums.push_back(root->val);
		if(nums.size()==k)
			return;
		inOrderTraverse(root->right,nums,k);
	}
}
int kthSmallest(TreeNode* root, int k){
    vector<int> nums;
    inOrderTraverse(root,nums,k);
    return nums[k-1];
}
int main(){
	TreeNode* root;
	createTree(root);
	showTree(root); 
	int k;
	cout<<"kthSmallest"<<endl;
	while(cin>>k)
		cout<<kthSmallest(root,k)-('0'-0)<<endl;
	return 0;
}
