#include <iostream>
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
int countNodes(TreeNode* root) {
    int level_1 = 0;
    int level_2 = 0;
    TreeNode* cur_node_1 = root;
    TreeNode* cur_node_2 = root;
    int ret = 1;
    while(cur_node_1 && cur_node_2){
        ++level_1;
        ++level_2;
        cur_node_1 = cur_node_1->left;
        cur_node_2 = cur_node_2->right;
        ret<<=1;
    }
    while(cur_node_1){
        ++level_1;
        cur_node_1 = cur_node_1->left;
    }
    if(level_1 == level_2){
        return ret-1;
    }
    return 1+countNodes(root->left)+countNodes(root->right);
}
int main(){
	TreeNode *root;
	createTree(root);
	showTree(root);
	cout<<countNodes(root)<<endl;
	return 0;
}
