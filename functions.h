#ifndef FUNCTIONS_H_H
#define FUNCTIONS_H_H

#include <vector>
#include "station.h"

using std::vector, std::pair;

struct paths
{
    vector<pair<string, float>> shortpath;
    vector<pair<string, float>> changlesspath;
};

map<string, Station> createStations();
float sumIt(vector<pair<string, float>> path);
paths findPath(map<string, Station> &stations, string prenode, string startStation, string endStation, string enterStation);
vector<pair<string, int>> findLineChange(map<string, Station> &stations, vector<pair<string, float>> path);
#endif // !FUNCTIONS_H_H
