#include <iostream>
#include <memory.h>
#include <string>
using namespace std;
class TrieNode{
public:
	char word;
	int count; 
	bool is_word;
	TrieNode* nextBranch[26];
	TrieNode()
	{
		word = 0;
		memset(nextBranch,NULL,sizeof(TrieNode*)*26);
	}
};
class Trie {	
public:
	TrieNode* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* tmp = root;
        int i,j,index;
		for(i=0;i<word.length();i++)
		{
			index = word[i]-'a';
			if(tmp->nextBranch[index]!=NULL)
			{				
				tmp = tmp->nextBranch[index];
			}
			else //not included in current nextBranch
			{
				TrieNode* node = new TrieNode();
				node->word = word[i];
				node->is_word=false;
				tmp->nextBranch[index] = node;
				tmp = node;
			}
		}
		tmp->is_word=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* tmp = root;
        int i,j,index;
		for(i=0;i<word.length();i++)
		{
			index=word[i]-'a';
			if(tmp->nextBranch[index]!=NULL)
				tmp = tmp->nextBranch[index];
			else
				return false;
		}
		if(tmp->is_word)
			return true;
		else
			return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* tmp = root;
        int i,j,index;
		for(i=0;i<prefix.length();i++)
		{	
			index = prefix[i]-'a';
			if(tmp->nextBranch[index]!=NULL)
				tmp = tmp->nextBranch[index];
			else
				return false;
		}
		return true;
    }
};
 
/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
 
 int main()
 {
 	Trie root = Trie();
	root.insert("abc");
	cout<<root.search("abc")<<endl;
	cout<<root.search("ab")<<endl;
	root.insert("ab");
	cout<<root.search("ab")<<endl;
	return 0;
 }
