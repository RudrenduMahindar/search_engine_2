#include "solution.h"
#include <iostream>
#include <regex>
#include <algorithm>

BST::~BST()
{
    TreeNode* apple_root_=nullptr;//delete
    TreeNode* analytics_root_=nullptr;
    TreeNode* fpga_root_=nullptr;
    TreeNode* iot_root_=nullptr;
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
  unordered_set<string> title_words;
  string word = ""; 
  for (auto& x : s) //words in string
  { 
       if (x ==' ') 
       { 
          title_words.insert(word); //words before last word
          word = ""; 
       } 
       else {
          word = word + x;}
  }        
  title_words.insert(word); //last word
  if(title_words.count(keyword)) //title has that keyword
    return true;
  return false;  
}

void BST::map_keyword_to_bst(vector<string>& v) //for my local storage of titles 
{
  string title;
  string url;
  pair<string,pair<string,string>> p;
  pair<string,string> p1;
  for(auto i:v)
  {
	  regex regex("->");
	  vector<string> out(
					sregex_token_iterator(i.begin(), i.end(), regex, -1),
					sregex_token_iterator()
					);
    if(int(out.size())==2) //avoids seg fault for blank lines or invalid lines with no regex 
    {     
      title=out[0];
      url=out[1];
      p1.first=title; //original 
      p1.second=url;
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

void BST::insert(TreeNode *&root, string v) {
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
  for(int i=0;i<int(vkeys.size());i++)
  {
    if(check_keyword(vkeys[i],v))
      return search(keyword_root[vkeys[i]],v); //search using root from map
  }
  return false;
}

bool BST::search(TreeNode *root,string v) {
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
  results.push_back(title_url[root->val]);
  return search(root->left, v);
} 
else // v > root->val
{
  results.push_back(title_url[root->val]);
  return search(root->right, v);
}
}

/*TrieNode* Trie::getNode(void) 
{ 
    TrieNode *node =  new TrieNode;   
    node->endofword = false; 
    for (int i = 0; i < alphabets; i++) 
        node->child.push_back(nullptr); 
    return node; 
} 

void Trie::insert(TrieNode* root, string key_word)
{
  TrieNode* travel=root;
  for(int i=0;i<key_word.length();i++)
  {
      int index=key_word[i]-'a';
      if(!travel->child[index]) //child not present
      {
        travel->child[index]=getNode();
      }

      travel=travel->child[index];
  }

  travel->endofword=true; //marks end of word
}

bool Trie::search(TrieNode *root, string key_word) 
{ 
    TrieNode *travel = root; 
  
    for (int i = 0; i < key_word.length(); i++) 
    { 
        int index = key_word[i] - 'a'; 
        if (!travel->child[index]) //next character not present
            return false; 
  
        travel = travel->child[index]; 
    } 
  
    return (travel != nullptr && travel->endofword); //last travelled character should be present and be the end 
}*/ 

/*map<int,vector<vector<string>>> Trie::title_search(vector<string>& v)
{
  map<int,vector<vector<string>>> m;
  vector<string> v1={"iot","based","home","automation"};
  vector<string> v2={"designing","and","building","parallel","programs"};
  vector<string> v3={"data","science","and","prediction"};
  vector<string> v4={"big","data","analytics","with","business"};
  store.push_back(v1);
  store.push_back(v2);
  store.push_back(v3);
  store.push_back(v4);
  vector<TrieNode*> vroots; //store root for eacht title
  for(int i=0;i<int(store.size());i++)
  {
    TrieNode *root = getNode();
    for(int j=0;j<int(store[i].size());j++)
      insert(root, store[i][j]);
    vroots.push_back(root);  
  } */   
  
/*  TrieNode *root1 = getNode(); 
  for(int i = 0; i < v1.size(); i++) 
    insert(root1, v1[i]);

  TrieNode *root2 = getNode(); 
  for(int i = 0; i < v2.size(); i++) 
    insert(root2, v2[i]);
  
  TrieNode *root3 = getNode(); 
  for(int i = 0; i < v3.size(); i++) 
    insert(root3, v3[i]);    

  TrieNode *root4 = getNode(); 
  for(int i = 0; i < v4.size(); i++) 
    insert(root4, v4[i]); */

 // vector<TrieNode*> vroots={root1,root2,root3,root4};
  /*vector<int> count_freq(int(vroots.size()),0);
  for(int i=0;i<v.size();i++)
  {
    for(int j=0;j<vroots.size();j++)
    {
      if(search(vroots[j],v[i])) //search for each word of given title in each of my local titles 
        count_freq[j]++;  //how many words of given search title match with words of each local title
    }
  }
  for(int i=0;i<count_freq.size();i++)
  {
    if(count_freq[i]>0)
      m[count_freq[i]].push_back(store[i]);
  }
  return m;
}*/
