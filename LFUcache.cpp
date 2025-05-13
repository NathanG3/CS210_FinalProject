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

using namespace std;

class LFUcache{

  struct CacheValue
  {
    string population;
    int frequency;
    int age;
  };

  unordered_map<string, CacheValue> cache;
  int tick = 0;

  public:
    void addstring(string population, int frequency, int age);