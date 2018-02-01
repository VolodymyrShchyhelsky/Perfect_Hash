#include "HashTable.h"
#include <bits/stdc++.h>

using namespace std;

bool isprime(int x) {
    for(int i=2; i*i<=x; ++i) {
        if(x%i==0) return false;
    }
    return true;
}

int next_prime(int x) {
    int i=x+1;
    for(; !isprime(i); ++i);
    return i;
}

int HashTable::get_hash_function(int key) {
    return ((a*key+b) %p) %m;
}

int get_row_hash_func(hash_table_level_2 H, int key) {
    return ((H.a*key) %H.p) %H.m;
}

void HashTable::make_hash_raw(vector<data> v) {
    for(int i=0; i<m; ++i) keys[i].m=0;
    for(int i=0; i<v.size(); ++i)
        ++keys[get_hash_function(v[i].key)].m;
    for(int i=0; i<m; ++i) {
        if(keys[i].m) {
            keys[i].m*=keys[i].m;
            keys[i].value.resize(keys[i].m);
            if(keys[i].m==1) {
                keys[i].a=0;
                keys[i].b=0;
                keys[i].p=p;
            } else {
                keys[i].b=(rand() % keys[i].m);
                keys[i].a=(rand() % (keys[i].m-1)) + 1;
                keys[i].p=p;
            }
        }
    }
    add_elements(v);
}

void HashTable::add_elements(vector<data> v) {
    for(int i=0; i<v.size(); ++i) {
        int column=get_hash_function(v[i].key);
        int row=get_row_hash_func(keys[column],v[i].key);
        keys[column].value[row]=v[i].value;
    }
}

HashTable::HashTable(vector<data> v, int maxkey) {
    m=next_prime(v.size());
    keys.resize(m);
    p=next_prime(maxkey);
    srand(time(NULL));
    a=(rand() % (m-1)) + 1;
    b=rand() % m;
    make_hash_raw(v);
    add_elements(v);
}

string HashTable::Find(int k) {
        int column=get_hash_function(k);
        int row=get_row_hash_func(keys[column],k);
        return keys[column].value[row];
}
