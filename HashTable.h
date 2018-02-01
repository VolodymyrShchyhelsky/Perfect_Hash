#include <vector>
#include <string>
#include "Data.h"

using namespace std;

struct hash_table_level_2 {
    int m,p,a,b;
    vector<string> value;
};

class HashTable {

private:
    int m,p,a,b;
    vector<hash_table_level_2> keys;
    void make_hash_raw(vector<data> v);
    void add_elements(vector<data> v);
    int get_hash_function(int key);

public:
    HashTable(vector<data> v,int maxkey);
    string Find(int key);
};
