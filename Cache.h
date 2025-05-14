//
// Created by npgal on 5/13/2025.
//

#ifndef CACHE_H
#define CACHE_H

#include <string>
using namespace std;
class Cache
{
public:
    virtual bool getstring(string& key, string& population);
    virtual void addstring(string& key, string& population);
    virtual void display();
    virtual ~Cache();
};
#endif //CACHE_H
