#include "station.h"

Station::Station()
{
}
Station::Station(string name_)
{
    name = name_;
}
Station::~Station()
{
}
void Station::addConnection(pair<string, float> connection)
{
    connections.push_back(connection);
}