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

class Publication{
public:
    Publication();
    Publication(vector<string>& initial_values);
    ~Publication();
    void insert(TreeNode*&,string);
    bool search(TreeNode *,string v);
    bool find(string v);
    bool check_keyword(string,string);
    void map_keyword_to_bst(vector<string>& titles);
    void append_others(TreeNode*);
    map<int,vector<pair<string,string>>> results;

private:    
    vector<string> vkeys={"apple","analytics","fpga","iot"}; //chosen keywords
    vector<TreeNode*> vroots; //roots for different keywords
    unordered_map<string,TreeNode*> keyword_root; //keyword mapped with root of tree
    unordered_map<string,pair<string,string>> title_url; //<lowercase,<originalcase,url>>
    unordered_map<string,int> title_freq;//title and its frequency 
};

#endif