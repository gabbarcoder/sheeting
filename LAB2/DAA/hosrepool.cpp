#include<bits/stdc++.h>

using namespace std;



int main (){
    string txt;
    getline(cin,txt);
    
    string pat;

    cin>>pat;

    size_t found = txt.find(pat);

    if(found!=string::npos)
        cout<<"first occurance is : " <<found<<endl;

}