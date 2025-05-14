//
// Created by npgal on 5/12/2025.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

class FIFOcache {
  queue<string> q;
  unordered_map<string, string> cache;

  public:
    void addstring(string& key, string& population)
    {
      if (cache.find(key) != cache.end())
      {
        if (q.size() >= 10){
          string temp = q.front();
          q.pop();
          cache.erase(temp);
        }
        q.push(key);
      }
      cache[key] = population;
    }

    bool getstring(string& key, string& population)
    {
      if (cache.find(key) == cache.end())
      {
        population = cache[key];
        return true;
      }

      return false;
    }

    void display()
    {
      queue<string> temp = q;
      while (!temp.empty())
      {
        cout << temp.front() << " " << endl;
        temp.pop();
      }
    }

};