#include "mainwindow.h"
#include <QApplication>
#include"ctp_manager.h"
#include"tactic.h"

#include"../gpp_qt/cfg/cfg.h"
#include"../gpp_qt/wtimer/wtimer.h"

cfg cfg_info;
wtimer timer;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    MainWindow * mw=&w;
    mw->set_qa(&a);

    //reg metatype
    qRegisterMetaType<string>("std::string");
    qRegisterMetaType<shared_ptr<CThostFtdcDepthMarketDataField> >("std::shared_ptr<CThostFtdcDepthMarketDataField>");

    //load simu para
    cfg_info.setcfgfile("c:/cfg/simu_trade.cfg");

    ctp_manager *cm=new ctp_manager;
    cm->init();

    w.init();
    w.show();
    return a.exec();
}
