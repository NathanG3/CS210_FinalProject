//
// Created by npgal on 4/22/2025.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

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
    string filename = "world_cities.csv";
    string country_code, city_name;

    cout << "Enter country code: ";
    cin >> country_code;
    cin.ignore();
    cout << "Enter city name: ";
    getline(cin, city_name);

    ifstream file;
    file.open(filename);

    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return 1;
    }
    string line;
    bool found = false;

    while (getline(file, line)) {
        stringstream ss(line);
        string country, city, population;
        if (getline(ss, country, ',') && getline(ss, city, ',') && getline(ss, population))
        {
            if (city == city_name && country == country_code)
            {
                cout << "Population: " << population <<
                    "\nCity Name: " << city <<
                        "\nCountry Code: " << country_code << endl;
                found = true;
                break;
            }
        }


    }
    if (!found) {
        cout << "Not found";
    }


}