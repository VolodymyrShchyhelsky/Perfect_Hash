#include <string>

using namespace std;

struct data {
    int key;
    string value;
    data(int k, string v) : key(k) , value(v) {}
    data() : key(0) , value(0) {}
};
