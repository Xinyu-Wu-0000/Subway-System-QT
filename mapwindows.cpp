#include "mapwindows.h"
#include "ui_mapwindows.h"
#include <QtDebug>
#include <string>
#include <QFile>
#include <QMessageBox>
using std::string;

MapWindows::MapWindows(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MapWindows)
{
    ui->setupUi(this);
    ui->SearchEdit->setPlaceholderText("请输入待查询站点名称");


    word_list << "罗湖"
              << "国贸"
              << "老街"
              << "大剧院"
              << "科学馆"
              << "华强路"
              << "岗厦"
              << "会展中心"
              << "购物公园"
              << "香蜜湖"
              << "车公庙"
              << "竹子林"
              << "侨城东"
              << "华侨城"
              << "世界之窗"
              << "白石洲"
              << "高新园"
              << "深大"
              << "桃园"
              << "大新"
              << "鲤鱼门"
              << "前海湾"
              << "新安"
              << "宝安中心"
              << "宝体"
              << "坪洲"
              << "西乡"
              << "固戍"
              << "后瑞"
              << "机场东"
              << "赤湾"
              << "荔湾"
              << "铁路公园"
              << "妈湾"
              << "前湾公园"
              << "前湾"
              << "桂湾"
              << "临海"
              << "宝华"
              << "翻身"
              << "灵芝"
              << "洪浪北"
              << "兴东"
              << "留仙洞"
              << "西丽"
              << "大学城"
              << "塘朗"
              << "长岭陂"
              << "深圳北"
              << "民治"
              << "五和"
              << "坂田"
              << "杨美"
              << "上水径"
              << "下水径"
              << "长龙"
              << "布吉"
              << "百鸽笼"
              << "布心"
              << "太安"
              << "怡景"
              << "黄贝岭"
              << "福田"
              << "红树湾南"
              << "后海"
              << "南山"
              << "宝安"
              << "碧海湾"
              << "机场"
              << "机场北"
              << "福永"
              << "桥头"
              << "塘尾"
              << "马安山"
              << "沙井"
              << "后亭"
              << "松岗"
              << "碧头";
    myCompleter = new QCompleter(word_list, this);

    ui->SearchEdit->setCompleter(myCompleter);

    connect(ui->SearchBut, &QPushButton::clicked, this, &MapWindows::search);
    connect(ui->ExitBut, &QPushButton::clicked, this, &MapWindows::close);
    this->resize(QSize(1300,800));
}

void MapWindows::search()
{
    QString searchStation = ui->SearchEdit->text();
    bool flag = true;
    for(int i=0;i<78;i++){
        if(searchStation==word_list[i])
            flag=false;
    }
    if(flag){
        QMessageBox::warning(this,"站名错误","输入站名有误",QMessageBox::Ok,QMessageBox::Ok);
        return;
    }
    ui->SearchEdit->clear();
    ui->textBrowser->setSearchPaths(QStringList() << ":/images" << ":/html");
    QFile aFile(":/html/pythonHtmlCreator/"+searchStation+".html");
    aFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QString html__=aFile.readAll();
    aFile.close();
    ui->textBrowser->setHtml(html__);
}

MapWindows::~MapWindows()
{
    delete myCompleter;
    delete ui;
}
