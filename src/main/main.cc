#include <iostream>
#include <fstream>
#include "src/lib/solution.h"
#include <algorithm>
#include <string.h>

int main()
{
    vector<string> lines;
    string s;   
    ifstream myfile("/home/mahindar/EE_599/project/src/main/title_url.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,s) )
        {
            cout<<s<<endl;
            lines.push_back(s);
        }
    myfile.close();
    }
    else cout<<"unable to open file";

    BST b(lines);
    cout<<"Enter search title"<<endl;
    getline(cin,s);
    b.find(s)?cout<<"matching title found\n":cout<<"matching title not found\n";
    vector<pair<string,string>> v=b.results;

    cout<<int(v.size())<<" close search results found"<<endl;
    for(auto it=v.rbegin();it!=v.rend();it++)
    {
        cout<<"Title : "<<(*it).first<<"  URL : "<<(*it).second<<endl;
    }
    
    return EXIT_SUCCESS; 
}








