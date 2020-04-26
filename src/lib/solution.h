#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct TreeNode {
string val;
TreeNode *left;
TreeNode *right;
TreeNode(string x) : val(x), left(NULL), right(NULL) {}
};

class BST {
public:
    BST();
    BST(std::vector<string>& initial_values); // Inserts elements of initial_values one by one into the Tree
    ~BST();
    void insert(TreeNode*&,string); // Inserts a key inside Tree
    bool search(TreeNode *,string v);
    bool find(string v);
    bool check_keyword(string&,string&);
    void map_keyword_to_bst(vector<string>& titles);
    vector<string> results;

private:
    TreeNode* apple_root_=nullptr;
    TreeNode* analytics_root_=nullptr;
    TreeNode* fpga_root_=nullptr;
    TreeNode* iot_root_=nullptr;
    vector<string> vkeys={"apple","analytics","fpga","iot"};
    unordered_map<string,TreeNode*> keyword_root;
    
};

/*const int alphabets=26;

struct TrieNode{

    vector<TrieNode*> child;
    bool endofword;
};

class Trie{
public:
    string paper_title;
    vector<vector<string>> store;
    TrieNode* getNode(void);
    void insert(TrieNode*,string);
    bool search(TrieNode*, string);
    map<int,vector<vector<string>>> title_search(vector<string>&);

};


};*/

#endif