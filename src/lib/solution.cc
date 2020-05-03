#include "solution.h"
#include <iostream>
#include <regex>
#include <algorithm>
#include <queue>

Publication::~Publication() //delete tree roots here
{
  for(int i=0;i<int(vroots.size());i++)
    delete(vroots[i]);
}

bool Publication::check_keyword(string keyword,string s)
{
  size_t pos = s.find(keyword); // search for the keyword pattern in the title
	if(pos != string::npos)
    return true;
  return false; 
}

void Publication::map_keyword_to_bst(vector<string>& v) //for my dataset of titles insert title to the proper tree 
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

Publication::Publication(vector<string>& initial_values) //insert titles from input file
{
  for(int i=0;i<int(vkeys.size());i++) //each keyword needs a corresponding root in the map keyword_root
  {
    TreeNode* root=nullptr; //initialize to avoid seg fault
    vroots.push_back(root); 
    keyword_root[vkeys[i]]=vroots[i]; //map keyword to root
  }
  map_keyword_to_bst(initial_values); //function to map keyword to bst-root and insert titles to their bst
}

void Publication::insert(TreeNode *&root, string v) { //insert title in BST
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

bool Publication::find(string v)
{
  transform(v.begin(),v.end(),v.begin(),::tolower);
  for(int i=0;i<int(vkeys.size());i++) //use all keywords to check which keyword is present in search title
  {
    if(check_keyword(vkeys[i],v)) //check pattern of keyword in title
    {
      if(search(keyword_root[vkeys[i]],v)) //search using root from map
      {
        return true; //true search only exact result returned
      }
      else //exact match not found then insert other results from tree after close results
      {
        append_others(keyword_root[vkeys[i]]); //insert other titles of this tree into results
      }
    }  
  }
  return false; //if no keyword present in input search or no exact match then title not found
}

bool Publication::search(TreeNode *root,string v) { //search title in BST
  if (root == nullptr) {
    return false;
  }
  else if (root->val == v) { //for exact match return the exact result
    results.clear();//delete previously inserted results
    title_freq[root->val]++; //increment frequency of appearance for the title
    results[title_freq[root->val]].push_back(title_url[root->val]); //only exact matching title returned as a result
    return true;
  }
  else if (v < root->val) {
    title_freq[root->val]++; 
    results[title_freq[root->val]].push_back(title_url[root->val]);//push close results matching its frequency
    return search(root->left, v);
  } 
  else // v > root->val
  {
    title_freq[root->val]++;
    results[title_freq[root->val]].push_back(title_url[root->val]);
    return search(root->right, v);
  }
}

void Publication::append_others(TreeNode* root) //insert unvisited titles in results 
{ 
  queue<TreeNode*> q;
  q.push(root);
  while(!q.empty())
  {
    TreeNode* node=q.front();
    if(title_freq.find(node->val)==title_freq.end()) //title_freq does not have title, title not visited in tree
    {
      title_freq[node->val]++;
      results[title_freq[node->val]].push_back(title_url[node->val]); //insert current title in result
    }  
    q.pop();
    if(node->left!=nullptr)
      q.push(node->left);

    if(node->right!=nullptr)
      q.push(node->right);  
  }
}