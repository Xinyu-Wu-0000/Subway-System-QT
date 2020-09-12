#include <iostream>
#include "station.h"
#include "functions.h"
#include <fstream>

using std::cout, std::endl, std::cin, std::ofstream, std::ifstream, std::ios_base;
ofstream fout;
ifstream fin;

extern string stationNames[];
int main(int argc, char const *argv[])
{
    map<string, Station> stations = createStations();
    // for (int i = 0; i < 78; i++)
    // {
    //     string startStation(stationNames[i]);
    //     for (int k = 0; k < 78; k++)
    //     {
    //         if (i != k)
    //         {
    //             string endStation(stationNames[k]);
    //             auto paths = findPath(stations, "NULL", startStation, endStation);

    //             auto changes = findLineChange(stations, paths.shortpath);
    //             cout << "short: " << sumIt(paths.shortpath) << endl
    //                  << startStation;
    //             for (auto i = paths.shortpath.begin(); i < paths.shortpath.end(); i++)
    //             {
    //                 cout << "->" << i->first;
    //             }
    //             cout << endl;
    //             for (auto i = changes.begin(); i < changes.end(); i++)
    //             {
    //                 cout << "请在" << i->first << "站"
    //                      << "换乘地铁" << i->second << "号线，";
    //             }
    //             cout << endl;

    //             auto changes_ = findLineChange(stations, paths.changlesspath);
    //             cout << "changless: " << sumIt(paths.changlesspath) << endl
    //                  << startStation;
    //             for (auto i = paths.changlesspath.begin(); i < paths.changlesspath.end(); i++)
    //             {
    //                 cout << "->" << i->first;
    //             }
    //             cout << endl;
    //             for (auto i = changes_.begin(); i < changes_.end(); i++)
    //             {
    //                 cout << "请在" << i->first << "站"
    //                      << "换乘地铁" << i->second << "号线，";
    //             }
    //             cout << endl;
    //         }
    //     }
    // }

    auto paths = findPath(stations, "NULL", "罗湖",

                          "大学城", "大学城");
    float a = sumIt(paths.shortpath);
    float b = sumIt(paths.changlesspath);
    auto change = findLineChange(stations, paths.shortpath);
    auto change_ = findLineChange(stations, paths.changlesspath);
    return 0;
}