#ifndef STATION_H_H
#define STATION_H_H

#include <string>
#include <vector>
#include <map>

using std::string, std::vector, std::map, std::pair;

class Station
{
private:
public:
    string name;
    vector<int> line;
    vector<pair<string, float>> connections;
    void addConnection(pair<string, float>);
    Station();
    Station(string name_);
    ~Station();
};
#endif // !STATION_H_H