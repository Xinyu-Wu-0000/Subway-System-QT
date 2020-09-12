#include "functions.h"
#include "station.h"
string lineOneNames[] = {
    "罗湖",
    "国贸",
    "老街",
    "大剧院",
    "科学馆",
    "华强路",
    "岗厦",
    "会展中心",
    "购物公园",
    "香蜜湖",
    "车公庙",
    "竹子林",
    "侨城东",
    "华侨城",
    "世界之窗",
    "白石洲",
    "高新园",
    "深大",
    "桃园",
    "大新",
    "鲤鱼门",
    "前海湾",
    "新安",
    "宝安中心",
    "宝体",
    "坪洲",
    "西乡",
    "固戍",
    "后瑞",
    "机场东"};
string lineFiveNames[] = {
    "赤湾",
    "荔湾",
    "铁路公园",
    "妈湾",
    "前湾公园",
    "前湾",
    "桂湾",
    "前海湾",
    "临海",
    "宝华",
    "宝安中心",
    "翻身",
    "灵芝",
    "洪浪北",
    "兴东",
    "留仙洞",
    "西丽",
    "大学城",
    "塘朗",
    "长岭陂",
    "深圳北",
    "民治",
    "五和",
    "坂田",
    "杨美",
    "上水径",
    "下水径",
    "长龙",
    "布吉",
    "百鸽笼",
    "布心",
    "太安",
    "怡景",
    "黄贝岭"};
string lineElevenNames[] = {
    "福田",
    "车公庙",
    "红树湾南",
    "后海",
    "南山",
    "前海湾",
    "宝安",
    "碧海湾",
    "机场",
    "机场北",
    "福永",
    "桥头",
    "塘尾",
    "马安山",
    "沙井",
    "后亭",
    "松岗",
    "碧头"};
string stationNames[] = {
    "罗湖",
    "国贸",
    "老街",
    "大剧院",
    "科学馆",
    "华强路",
    "岗厦",
    "会展中心",
    "购物公园",
    "香蜜湖",
    "车公庙",
    "竹子林",
    "侨城东",
    "华侨城",
    "世界之窗",
    "白石洲",
    "高新园",
    "深大",
    "桃园",
    "大新",
    "鲤鱼门",
    "前海湾",
    "新安",
    "宝安中心",
    "宝体",
    "坪洲",
    "西乡",
    "固戍",
    "后瑞",
    "机场东",
    "赤湾",
    "荔湾",
    "铁路公园",
    "妈湾",
    "前湾公园",
    "前湾",
    "桂湾",
    "临海",
    "宝华",
    "翻身",
    "灵芝",
    "洪浪北",
    "兴东",
    "留仙洞",
    "西丽",
    "大学城",
    "塘朗",
    "长岭陂",
    "深圳北",
    "民治",
    "五和",
    "坂田",
    "杨美",
    "上水径",
    "下水径",
    "长龙",
    "布吉",
    "百鸽笼",
    "布心",
    "太安",
    "怡景",
    "黄贝岭",
    "福田",
    "红树湾南",
    "后海",
    "南山",
    "宝安",
    "碧海湾",
    "机场",
    "机场北",
    "福永",
    "桥头",
    "塘尾",
    "马安山",
    "沙井",
    "后亭",
    "松岗",
    "碧头"};
float lineOneMoney[] = {
    0.2,
    0.3,
    0.4,
    0.5,
    0.4,
    0.4,
    0.5,
    0.2,
    0.5,
    0.3,
    0.2,
    0.3,
    0.4,
    0.5,
    0.4,
    0.4,
    0.5,
    0.2,
    0.5,
    0.3,
    0.2,
    0.3,
    0.4,
    0.5,
    0.4,
    0.4,
    0.5,
    0.2,
    0.5};
float lineFiveMoney[] = {
    0.2,
    0.3,
    0.4,
    0.5,
    0.4,
    0.4,
    0.5,
    0.2,
    0.5,
    0.3,
    0.2,
    0.3,
    0.4,
    0.5,
    0.4,
    0.4,
    0.5,
    0.2,
    0.5,
    0.3,
    0.2,
    0.3,
    0.4,
    0.5,
    0.4,
    0.4,
    0.5,
    0.2,
    0.5,
    0.3,
    0.4,
    0.3,
    0.2};
float lineElevenMoney[] = {
    0.2,
    0.3,
    0.4,
    0.5,
    0.4,
    0.4,
    0.5,
    0.2,
    0.5,
    0.3,
    0.2,
    0.3,
    0.4,
    0.5,
    0.4,
    0.4,
    0.5};

map<string, Station> createStations()
{
    map<string, Station> stations;
    for (auto i = &stationNames[0]; i < &stationNames[0] + 78; i++)
    {
        stations.insert(pair<string, Station>(*i, Station(*i)));
    }
    for (int i = 0; i < 30; i++)
    {
        if (i - 1 >= 0)
        {
            stations[lineOneNames[i]].addConnection(pair<string, float>(lineOneNames[i - 1], lineOneMoney[i - 1]));
        }
        if (i + 1 < 30)
        {
            stations[lineOneNames[i]].addConnection(pair<string, float>(lineOneNames[i + 1], lineOneMoney[i]));
        }
        stations[lineOneNames[i]].line.push_back(1);
    }
    for (int i = 0; i < 34; i++)
    {
        if (i - 1 >= 0)
        {
            stations[lineFiveNames[i]].addConnection(pair<string, float>(lineFiveNames[i - 1], lineFiveMoney[i - 1]));
        }
        if (i + 1 < 34)
        {
            stations[lineFiveNames[i]].addConnection(pair<string, float>(lineFiveNames[i + 1], lineFiveMoney[i]));
        }
        stations[lineFiveNames[i]].line.push_back(5);
    }
    for (int i = 0; i < 18; i++)
    {
        if (i - 1 >= 0)
        {
            stations[lineElevenNames[i]].addConnection(pair<string, float>(lineElevenNames[i - 1], lineElevenMoney[i - 1]));
        }
        if (i + 1 < 18)
        {
            stations[lineElevenNames[i]].addConnection(pair<string, float>(lineElevenNames[i + 1], lineElevenMoney[i]));
        }
        stations[lineElevenNames[i]].line.push_back(11);
    }
    return stations;
}

float sumIt(vector<pair<string, float>> path)
{
    float sum = 0;
    for (auto i = path.begin(); i < path.end(); i++)
    {
        sum += i->second;
    }
    return sum;
}

paths findPath(map<string, Station> &stations, string prenode, string startStation, string endStation, string enterStation)
{
    paths thePath;
    thePath.shortpath.push_back(pair<string, float>("END", 10000));
    for (int i = 0; i < 10; i++)
    {
        thePath.changlesspath.push_back(pair<string, float>("鲤鱼门", 0));
        thePath.changlesspath.push_back(pair<string, float>("前海湾", 0));
        thePath.changlesspath.push_back(pair<string, float>("赤湾", 0));
    }
    //i是起点的下一站的名称价格对
    for (auto i = stations[startStation].connections.begin(); i < stations[startStation].connections.end(); i++)
    {
        bool changeLine = true;
        for (auto m = stations[i->first].line.begin(); m < stations[i->first].line.end(); m++)
        {
            for (auto n = stations[enterStation].line.begin(); n < stations[enterStation].line.end(); n++)
            {
                if (*m == *n)
                    changeLine = false;
            }
        }
        vector<pair<string, float>> tem;
        paths nextPath;
        bool flag = true;
        pair<string, float> now = *i;
        pair<string, float> prenow;
        do
        {
            if (now.first == endStation)
            {
                tem.push_back(now);
                flag = false;
            }
            else if (now.first == prenode || stations[now.first].connections.size() == 1)
            {

                tem.push_back(pair<string, float>("END", 10000));
                flag = false;
            }
            else if (stations[now.first].connections.size() > 2)
            {
                tem.push_back(now);
                nextPath = findPath(stations, startStation, now.first, endStation, prenow.first);
                flag = false;
            }
            else if (stations[now.first].connections.size() == 2)
            {
                tem.push_back(now);
                for (auto k = stations[now.first].connections.begin(); k < stations[now.first].connections.end(); k++)
                {
                    if (k->first != startStation && k->first != prenow.first)
                    {
                        prenow = now;
                        now = *k;
                        break;
                    }
                }
            }
        } while (flag);
        auto tem_ = tem;
        tem.insert(tem.end(), nextPath.shortpath.begin(), nextPath.shortpath.end());
        tem_.insert(tem_.end(), nextPath.changlesspath.begin(), nextPath.changlesspath.end());

        if (sumIt(tem) < sumIt(thePath.shortpath))
        {
            thePath.shortpath = tem;
        }
        bool changless = findLineChange(stations, tem_).size() + changeLine <= findLineChange(stations, thePath.changlesspath).size();
        if ((tem_.end() - 1)->first != "END" && changless)
        {
            if (findLineChange(stations, tem_).size() + changeLine == findLineChange(stations, thePath.changlesspath).size())
            {
                if (sumIt(tem_) < sumIt(thePath.changlesspath))
                    thePath.changlesspath = tem_;
            }
            else
            {
                thePath.changlesspath = tem_;
            }
        }
    }
    return thePath;
}

vector<pair<string, int>> findLineChange(map<string, Station> &stations, vector<pair<string, float>> path)
{
    vector<pair<string, int>> changes;
    for (auto i = path.begin(); i < path.end(); i++)
    {
        if (stations[i->first].connections.size() > 2 && i > path.begin() && i < (path.end() - 1))
        {
            if (stations[(i - 1)->first].line[0] != stations[(i + 1)->first].line[0])
            {
                changes.push_back(pair<string, int>(i->first, stations[(i + 1)->first].line[0]));
            }
        }
    }
    return changes;
}
