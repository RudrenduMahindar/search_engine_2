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
    BST(vector<string>& initial_values); // Inserts elements of initial_values one by one into the Tree
    ~BST();
    void insert(TreeNode*&,string); // Inserts a key inside Tree
    bool search(TreeNode *,string v);
    bool find(string v);
    bool check_keyword(string,string);
    void map_keyword_to_bst(vector<string>& titles);
    vector<pair<string,string>> results;

private:
    TreeNode* apple_root_=nullptr; //insert roots in a vector
    TreeNode* analytics_root_=nullptr;
    TreeNode* fpga_root_=nullptr;
    TreeNode* iot_root_=nullptr;
    vector<string> vkeys={"apple","analytics","fpga","iot"};
    unordered_map<string,TreeNode*> keyword_root;
    unordered_map<string,pair<string,string>> title_url; //<lower,<orig,url>>
    
};


#endif