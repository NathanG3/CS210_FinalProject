//
// Created by npgal on 4/22/2025.
//
#include <iostream>
#include <fstream>
#include <memory>
#include <sstream>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>
#include "trie.cpp"
#include "FIFOcache.cpp"
#include "Randomcache.cpp"

using namespace std;

struct CacheValue
{
    string key;
    string population;
};

vector<CacheValue> cache;

void addToCache(string& key, string& population)
{
    cache.insert(cache.begin(), {key, population});

    if (cache.size() > 10)
    {
        cache.pop_back();
    }
}
bool searchCache(string& key, string& population)
{
    for (int i = 0; i < cache.size(); i++)
    {
        if (cache[i].key == key)
        {
            population = cache[i].population;
            return true;
        }
    }
    return false;
}


string searchData(string& country_code, string& city_name)
{
    string filename = "world_cities.csv";
    ifstream file;
    file.open(filename);

    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return "";
    }

    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string country, city, population;
        if (getline(ss, country, ',') && getline(ss, city, ',') && getline(ss, population))
        {
            if (city == city_name && country == country_code)
            {
                return population;
            }
        }
    }
    return "not found";
}
int main()
{
    NameTrie trie;
    Cache* cache;
    cout << "Select cache type(1 = FIFO, 2 = Randomcache):" << endl;
    int choice;
    cin >> choice;
    if (choice == 1)
        cache = new FIFOcache();
    else if (choice == 2)
        cache = new Randomcache();

    string filename = "world_cities.csv";
    ifstream file;
    file.open(filename);

    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
    }

    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string country, city, population;
        if (getline(ss, country, ',') && getline(ss, city, ',') && getline(ss, population))
        {
            trie.insert(city, country, population);
        }
    }
    file.close();

    while (true)
    {
        string country_code, city_name;
        cout << "Enter country code (or 'quit' to stop): ";
        cin >> country_code;
        if (country_code == "quit")
            break;
        cin.ignore();
        cout << "Enter city name: ";
        getline(cin, city_name);
        string key = country_code + "," + city_name;
        string population;
        if (cache->getstring(key, population))
        {
            cout << "Cache: " << population << endl;
        }
        else
        {
            if (trie.search(city_name, country_code, population))
            {
                cout << "trie: " << population << endl;
            }
            cache->addstring(key, population);
        }

        cache->display();

    }
    // string country_code, city_name;
    //
    // cout << "Enter country code: ";
    // cin >> country_code;
    // cin.ignore();
    // cout << "Enter city name: ";
    // getline(cin, city_name);
    //
    // ifstream file;
    // file.open(filename);
    //
    // if (!file.is_open()) {
    //     cerr << "Failed to open file: " << filename << endl;
    //     return 1;
    // }
    // string line;
    // bool found = false;
    //
    // while (getline(file, line)) {
    //     stringstream ss(line);
    //     string country, city, population;
    //     if (getline(ss, country, ',') && getline(ss, city, ',') && getline(ss, population))
    //     {
    //         if (city == city_name && country == country_code)
    //         {
    //             cout << "Population: " << population <<
    //                 "\nCity Name: " << city <<
    //                     "\nCountry Code: " << country_code << endl;
    //             found = true;
    //             break;
    //         }
    //     }
    //
    //
    // }
    // if (!found) {
    //     cout << "Not found";
    // }


}