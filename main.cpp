#include <vector>
#include <iostream>
#include "HashTable.h"
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout<<"Enter the number of strings"<<endl;
    int n;
    scanf("%d",&n);
    vector<data> v;
    int maxkey=0;
    cout<<"Enter keys and strings"<<endl;
    for(int i=0; i<n; ++i) {
        string value;
        int key;
        cin>>key>>value;
        if(key>maxkey) maxkey=key;
        data d(key,value);
        v.push_back(d);
    }
    HashTable table(v,maxkey);
    cout<<"Enter keys to see the data"<<endl;
    for(int i=0; i<n; ++i) {
        int key;
        cin>>key;
        cout<<table.Find(key)<<endl;
    }
    return 0;
}
