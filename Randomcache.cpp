//
// Created by npgal on 5/13/2025.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>
#include <random>
#include "Cache.h"
using namespace std;

class Randomcache : public Cache {
  unordered_map<string,string> cache;
  vector<string> keys;
  public:
    void addstring(string& key, string& population) override
    {
      if(cache.size() >= 10)
      {
        int index = rand() % 9;
        cache.erase(keys[index]);
        keys.erase(keys.begin() + index);
      }
      cache[key] = population;
      keys.push_back(key);
    }
    bool getstring(string& key, string& population) override
    {
      if(cache.find(key) != cache.end())
      {
        population = cache[key];
        return true;
      }
      return false;
    }
    void display() override
    {
      for (const auto& entry : keys)
      {
        cout << entry << " : " << cache[entry] << endl;
      }
    }
};