#include "solution.h"
#include <iostream>
#include <regex>
#include <algorithm>

BST::~BST()
{
    delete(apple_root_);
    delete(analytics_root_);
    delete(fpga_root_);
    delete(iot_root_);
}

BST::BST()
{
    TreeNode* apple_root_=nullptr;
    TreeNode* analytics_root_=nullptr;
    TreeNode* fpga_root_=nullptr;
    TreeNode* iot_root_=nullptr;
}

bool BST::check_keyword(string keyword,string s)
{
  size_t pos = s.find(keyword); // search for the keyword pattern in the title
	if(pos != string::npos)
    return true;
  return false; 
}

void BST::map_keyword_to_bst(vector<string>& v) //for my dataset of titles insert title to the proper tree 
{
  string title;
  string url;
  pair<string,pair<string,string>> p;
  pair<string,string> p1;
  for(auto i:v)
  {
	  regex regex("->"); //split title and url
	  vector<string> out(
					sregex_token_iterator(i.begin(), i.end(), regex, -1),
					sregex_token_iterator()
					);
    if(int(out.size())==2) //avoids seg fault for blank lines or invalid lines with no regex 
    {     
      title=out[0];
      url=out[1];
      p1.first=title; //original 
      p1.second=url; //url of title
      transform(title.begin(),title.end(),title.begin(),::tolower);
      p.first=title; //lowercase for removing case sensitivity while searching title
      p.second=p1;
      title_url.insert(p);
    }
  }
  keyword_root[vkeys[0]]=apple_root_;
  keyword_root[vkeys[1]]=analytics_root_;
  keyword_root[vkeys[2]]=fpga_root_;
  keyword_root[vkeys[3]]=iot_root_;
  for(auto it=title_url.begin();it!=title_url.end();it++)
  {
    for(int i=0;i<int(vkeys.size());i++) //check which keyword is in the title
    {
      if(check_keyword(vkeys[i],(*it).first)) //title has keyword then add this title to the same index root bst
      {
          insert(keyword_root[vkeys[i]],(*it).first); //use root for insert from map 
      }
    }  
  }
}

BST::BST(vector<string>& initial_values)
{
  TreeNode* apple_root_=nullptr;
  TreeNode* analytics_root_=nullptr;
  TreeNode* fpga_root_=nullptr;
  TreeNode* iot_root_=nullptr;
  map_keyword_to_bst(initial_values); //function to map keyword to bst-root and insert titles to their bst
}

void BST::insert(TreeNode *&root, string v) { //insert title in BST
if (root == nullptr) {
  root = new TreeNode(v);
} 
else if (v < root->val) {
  insert(root->left, v);
} 
else if (v > root->val) {
  insert(root->right, v);
}
}

bool BST::find(string v)
{
  transform(v.begin(),v.end(),v.begin(),::tolower);
  for(int i=0;i<int(vkeys.size());i++) //use all keywords to check which keyword is present in search title
  {
    if(check_keyword(vkeys[i],v))
      return search(keyword_root[vkeys[i]],v); //search using root from map
  }
  return false;
}

bool BST::search(TreeNode *root,string v) { //search title in BST
if (root == nullptr) {
  return false;
}
else if (root->val == v) {
  //results.push_back(title_url[root->val]);
  results.clear();
  results.push_back(title_url[root->val]); //only exact matching title returned as a result
  return true;
}
else if (v < root->val) {
  results.push_back(title_url[root->val]);//push close results in vector
  return search(root->left, v);
} 
else // v > root->val
{
  results.push_back(title_url[root->val]); //push close results in vector
  return search(root->right, v);
}
}

