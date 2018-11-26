/***************
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>
***************/
#ifndef BCIDataStream_H
#define BCIDataStream_H

#include <QObject>
#include "CortexClient.h"
#include "HeadsetFinder.h"
#include "SessionCreator.h"
#include "Headset.h"
#include <atomic>
#include <mutex>
#include <fstream>
#include <QFile>

/*
 * Connects to a headset and displays the data from a stream.
 *
 */
class BCIDataStream : public QObject
{
    Q_OBJECT

public:
    explicit BCIDataStream(QString user, QString id,QObject *parent = nullptr);

    // you need a license if you want to get the EEG data
    void start( QString license = "");

    void printData();
    void record(QString);
    void classify();
    void doNothing();

    void exit();

private slots:
    void onConnected();
    void onDisconnected();
    void onErrorReceived(QString method, int code, QString error);

    void onHeadsetsFound(const QList<Headset> &headsets);
    void onSessionCreated(QString token, QString sessionId);

    void onSubscribeOk(QString sid);
    void onUnsubscribeOk(QString msg);

    void onStreamDataReceived(QString sessionId, QString stream,
                              double time, const QJsonArray &data);

    void onCloseSessionOk();

protected:
    //void timerEvent(QTimerEvent *event);

private:
    CortexClient client;
    HeadsetFinder finder;
    SessionCreator creator;


    QString license;
    QString headsetId;
    QString token;
    QString sessionId;
    //double nextDataTime;
    //int timerId;

    int state;
    std::mutex global_mutex;
    int successfulSubscriptions;
    QFile*  fileMet;
    QFile*  filePow;
};

#endif // BCIDataStream_H
