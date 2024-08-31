#ifndef EGMPROTOBUFWIN_H
#define EGMPROTOBUFWIN_H

#include <QMainWindow>
#include <QUdpSocket>

#include "egm.pb.h"
using namespace abb::egm;
#pragma comment(lib, "Ws2_32.lib")      // socket lib

QT_BEGIN_NAMESPACE
namespace Ui {
class EgmProtobufWin;
}
QT_END_NAMESPACE

class EgmProtobufWin : public QMainWindow
{
    Q_OBJECT
public:
    EgmProtobufWin(QWidget *parent = nullptr);
    ~EgmProtobufWin();
signals:
    void appendUdpLog1(QString);
    void appendUdpLog2(QString);
public slots:
    void onAppendUdpLog1(const QString &log);
    void onAppendUdpLog2(const QString &log);
    void onUdp1ReadPendingData();
    void onUdp2ReadPendingData();
private slots:
    // Udp1 Function
    void on_btnUdpUnbind1_clicked();
    void on_btnUdpBind1_clicked();
    void on_btnSendUdp1EgmData_clicked();
    void on_btnSendUdp1_clicked();
    // Udp2 Function
    void on_btnUdpUnbind2_clicked();
    void on_btnUdpBind2_clicked();
    void on_btnSendUdp2EgmData_clicked();
    void on_btnSendUdp2_clicked();
private:
    void createEgmSensorMsg(EgmSensor *sensorMsg);
    void createEgmRobotMsg(EgmRobot *robotMsg);
private:
    Ui::EgmProtobufWin *ui;
    QUdpSocket *m_udp1{nullptr};
    QUdpSocket *m_udp2{nullptr};
};
#endif // EGMPROTOBUFWIN_H
