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
           // cout<<s<<endl; //prints each line of your dataset
            lines.push_back(s);
        }
    myfile.close();
    }
    else cout<<"unable to open file";

    Publication b(lines);
    cout<<"Enter search title"<<endl;
    getline(cin,s);
    b.find(s)?cout<<"matching title found\n":cout<<"matching title not found\n";
    map<int,vector<pair<string,string>>> m=b.results;

    unordered_set<string> display_title; //record displayed titles here
    for(auto it=m.rbegin();it!=m.rend();it++) //titles with higher freq displayed first
    {
        for(auto it1:((*it).second))
        {
            if(!display_title.count((it1).first)) //title has not been displayed yet
            {
                cout<<"Title : "<<((it1).first)<<"  URL : "<<((it1).second)<<endl;
                display_title.insert((it1).first);
            }
        }
    
    }
    
    return EXIT_SUCCESS; 
}








