#include "ticketingwindows.h"
#include "ui_ticketingwindows.h"
#include <QtDebug>
#include <QMessageBox>
#include "paywindows.h"

TicketingWindows::TicketingWindows(QWidget *parent) : QMainWindow(parent),
                                                      ui(new Ui::TicketingWindows)
{
    ui->setupUi(this);
    ui->FromText->setPlaceholderText("请输入起始站");
    ui->ToText->setPlaceholderText("请输入终点站");
    ui->NumText->setPlaceholderText("请输入需购买的票数");

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
    ui->FromText->setCompleter(myCompleter);
    ui->ToText->setCompleter(myCompleter);

    connect(ui->ConfirmBut, &QPushButton::clicked, this, &TicketingWindows::confirm);
    connect(ui->BackBut, &QPushButton::clicked, this, &TicketingWindows::close);
    this->resize(QSize(800,600));
}

void TicketingWindows::confirm()
{
    QString startStation_(ui->FromText->text());
    QString endStation_(ui->ToText->text());
    string startStation = startStation_.toStdString();
    string endStation = endStation_.toStdString();
    QString num(ui->NumText->text());
    int Num = num.toInt();
    ui->FromText->clear();
    ui->ToText->clear();
    ui->NumText->clear();
    auto stations = createStations();
    auto mypaths = findPath(stations, "END", startStation, endStation, startStation);
    auto changes = findLineChange(stations, mypaths.shortpath);
    auto changes_ = findLineChange(stations, mypaths.changlesspath);
    float money = sumIt(mypaths.shortpath) * Num;
    float money_ = sumIt(mypaths.changlesspath) * Num;
    bool flag1=true;
    bool flag2=true;
    for(int i = 0;i<78;i++){
        if (startStation_==word_list[i]){
            flag1=false;
        }
    }
    for(int i = 0;i<78;i++){
        if (endStation_==word_list[i]){
            flag2=false;
        }
    }
    if(flag1||flag2){
        QMessageBox::warning(this,"站名错误","输入站名有误",QMessageBox::Ok,QMessageBox::Ok);
        ui->NumText->setText("1");
        return;
    }
    string info;

    if (money == money_)
    {
        info += "应付金额： ";
        double c = (money_ + 0.05) * 10;
        int a = c;
        c = a / 10.0;
        info += std::to_string(c);
        info += ", 路径：\n";
        info += startStation;
        for (auto i = mypaths.changlesspath.begin(); i < mypaths.changlesspath.end(); i++)
        {
            info += "->";
            info += i->first;
        }
        info += "\n\n";
        for (auto i = changes_.begin(); i < changes_.end(); i++)
        {
            info += "请在";
            info += i->first;
            info += "站";
            info += "换乘地铁";
            info += std::to_string(i->second);
            info += "号线   ";
        }
        QString Title = QStringLiteral("购票确认");
        QString Info = QString::fromStdString(info);
        int choice = QMessageBox::information(this, Title, Info, QStringLiteral("确定购票"), QStringLiteral("重新购票"), QStringLiteral("关闭购票窗口"), 2);
        PayWindows * p = new PayWindows(this);
        p->resize(QSize(700,700));
        //p->show();
        switch (choice)
        {
        case 0:
            p->show();
            ui->NumText->setText("1");
            break;
        case 1:
            ui->NumText->setText("1");
            break;
        case 2:
            this->close();
            break;
        }
        qDebug()<<money;
    }
    else{
        info +="最少换乘优先，线路一：\n";
        info += "应付金额： ";
        double c = ((money_ + 0.05) * 10);
        int a = c;
        c = a / 10.0;
        info += std::to_string(c);
        info += ", 路径：\n";
        info += startStation;
        for (auto i = mypaths.changlesspath.begin(); i < mypaths.changlesspath.end(); i++)
        {
            info += "->";
            info += i->first;
        }
        info += "\n\n";
        for (auto i = changes_.begin(); i < changes_.end(); i++)
        {
            info += "请在";
            info += i->first;
            info += "站";
            info += "换乘地铁";
            info += std::to_string(i->second);
            info += "号线   ";
        }


        info +="\n\n**********************************************************\n\n最短长度（即最小金额）优先，线路二：\n";
        info += "应付金额： ";
        double d =((money + 0.05) * 10);
        int b = d;
        d = b / 10.0;
        info += std::to_string(d);
        info += ", 路径：\n";
        info += startStation;
        for (auto i = mypaths.shortpath.begin(); i < mypaths.shortpath.end(); i++)
        {
            info += "->";
            info += i->first;
        }
        info += "\n\n";
        for (auto i = changes.begin(); i < changes.end(); i++)
        {
            info += "请在";
            info += i->first;
            info += "站";
            info += "换乘地铁";
            info += std::to_string(i->second);
            info += "号线   ";
        }

        QString Title = QStringLiteral("购票确认");
        QString Info = QString::fromStdString(info);
        int choice = QMessageBox::information(this, Title, Info, QStringLiteral("最少换乘优先，线路一"), QStringLiteral("最段路径优先，线路二"), QStringLiteral("重新购票"), 2);
        PayWindows * p =new PayWindows(this);
        p->resize(QSize(700,700));
        switch (choice)
        {
        case 0:
        case 1:
            p->show();
        case 2:
            ui->NumText->setText("1");
        }
        qDebug()<<money_<<","<<money;
    }

}

TicketingWindows::~TicketingWindows()
{
    delete ui;
    delete myCompleter;
}
