//
// Created by npgal on 5/13/2025.
//
#include <string>
using namespace std;
class Cache
{
  public:
    virtual bool getstring(string& key, string& population);
    virtual void addstring(string& key, string& population);
    virtual void display();
};