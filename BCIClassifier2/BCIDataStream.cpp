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
#include "BCIDataStream.h"

#include <QCoreApplication>
#include <QJsonArray>
#include <QJsonDocument>
#include <QtDebug>
#include "ConsoleThread.h"
#include "sharedmemory.h"

//STATES:
#define DO_NOTHING 0
#define PRINT 1
#define RECORD 2
#define CLASSIFY 3





BCIDataStream::BCIDataStream(QString userId, QString pass,QObject *parent) : QObject(parent), creator(userId,pass) {
    state = DO_NOTHING;
    successfulSubscriptions = 0;
    connect(&client, &CortexClient::connected, this, &BCIDataStream::onConnected);
    connect(&finder, &HeadsetFinder::headsetsFound, this, &BCIDataStream::onHeadsetsFound);
    connect(&creator, &SessionCreator::sessionCreated, this, &BCIDataStream::onSessionCreated);
    connect(&client, &CortexClient::subscribeOk, this, &BCIDataStream::onSubscribeOk);
    connect(&client, &CortexClient::streamDataReceived, this, &BCIDataStream::onStreamDataReceived);

    connect(&client, &CortexClient::disconnected, this, &BCIDataStream::onDisconnected);
    connect(&client, &CortexClient::unsubscribeOk, this, &BCIDataStream::onUnsubscribeOk);
    connect(&client, &CortexClient::closeSessionOk, this, &BCIDataStream::onCloseSessionOk);

    connect(&client, &CortexClient::errorReceived, this, &BCIDataStream::onErrorReceived);
}

void BCIDataStream::start(QString license) {
    this->license = license;
    //nextDataTime = 0;
    //timerId = 0;
    client.open();
}

void BCIDataStream::onConnected() {
    qInfo() << "Connected to Cortex.";
    finder.findHeadsets(&client);
}

void BCIDataStream::onDisconnected() {
    qInfo() << "Disconnected.";
    QCoreApplication::quit();
}

void BCIDataStream::onErrorReceived(QString method, int code, QString error) {
    qCritical() << "Cortex returned an error:";
    qCritical() << "\t" << method << code << error;
    QCoreApplication::quit();
}

void BCIDataStream::onHeadsetsFound(const QList<Headset> &headsets) {
    finder.clear();

    // we take the first headset
    // TODO in a real application, you should ask the user to choose a headset from the list
    this->headsetId = headsets.first().id;

    // next step: create a session for this headset
    creator.createSession(&client, headsetId, license);
}

void BCIDataStream::onSessionCreated(QString token, QString sessionId) {
    creator.clear();
    this->token = token;
    this->sessionId = sessionId;

    // next step: subscribe to a data stream
    client.subscribe(token, sessionId, "met");
    client.subscribe(token, sessionId, "pow");
}



void BCIDataStream::onSubscribeOk(QString sid) {

    std::lock_guard<std::mutex> guard(global_mutex);

    successfulSubscriptions++;

    if(successfulSubscriptions==2){

        qInfo() << "Subscription successful, sid" << sid;


        ConsoleThread* thread = new ConsoleThread(this);
        thread->start();
    }

    //timerId = startTimer(30*1000);
}



//void BCIDataStream::timerEvent(QTimerEvent *event) {
//    if (event->timerId() == timerId) {
//        killTimer(timerId);

//    }
//}

void BCIDataStream::onUnsubscribeOk(QString msg) {
    qInfo() << "Subscription cancelled:" << msg;
    client.closeSession(token, sessionId);
}

void BCIDataStream::onCloseSessionOk() {
    qInfo() << "Session closed.";
    client.close();
}



int classify_filter_met(double coefs[]){
   return -1;
}


int classify_filter_pow(double coefs[]){
   return -1;
}

void BCIDataStream::onStreamDataReceived(
        QString sessionId, QString stream, double time, const QJsonArray &data) {
    Q_UNUSED(sessionId);
    // a data stream can publish a lot of data
    // we display only a few data per second

//    if (time >= nextDataTime) {
//        nextDataTime = time + 0.25;
//    }



    if(stream == "met"){

        #define NUM_VARS 7
        //GET COEFFICIENTS
        double coefs[NUM_VARS];
        for(int i=0 ; i<NUM_VARS; i++){
            coefs[i] = data[i].toDouble(-1);
        }

        QString str = QString::number(coefs[0]);
        for(int i=1;i<NUM_VARS;i++) str += "," + QString::number(coefs[i]);


        std::lock_guard<std::mutex> guard(global_mutex);

        switch (state) {
        case RECORD:{
            qInfo() <<  "met: " + str;

            QTextStream stream( fileMet );
            stream << str << endl;

            break;
        }
        case PRINT:
            qInfo() << "met: " + str;
            break;
        case CLASSIFY:
            qInfo() <<  "met: " + str;
            int filter_id = classify_filter_met(coefs);
            smWriteId(filter_id);
            break;
        }


    }else if(stream=="pow"){
        //GET COEFFICIENTS
        #define NUM_VARS_POW 25
        double coefs[NUM_VARS_POW];
        for(int i=0 ; i<NUM_VARS_POW; i++){
            coefs[i] = data[i].toDouble(-1);
        }

        QString strFile = QString::number(coefs[0]);
        for(int i=1;i<NUM_VARS_POW;i++) strFile += "," + QString::number(coefs[i]);

        QString strStdout = QString::number(coefs[0]);
        for(int i=1;i<5;i++) strStdout += "," + QString::number(coefs[i]);
        for(int i=NUM_VARS_POW-5;i<NUM_VARS_POW;i++) strStdout += "," + QString::number(coefs[i]);


        std::lock_guard<std::mutex> guard(global_mutex);

        switch (state) {
        case RECORD:{
            qInfo() << strStdout;

            QTextStream stream( filePow );
            stream << strFile << endl;

            break;
        }
        case PRINT:
            qInfo() << strStdout;
            break;
        case CLASSIFY:
            qInfo() << strStdout;
            int filter_id = classify_filter_pow(coefs);
            smWriteId(filter_id);
            break;
        }
    }








}


//SATE FUNCTIONS

void BCIDataStream::printData(){
    std::lock_guard<std::mutex> guard(global_mutex);
    state = PRINT;

}
void BCIDataStream::record(QString fileName){

    std::lock_guard<std::mutex> guard(global_mutex);
    fileMet = new QFile(fileName + "Met.txt");
    filePow = new QFile(fileName + "Pow.txt");
    fileMet->open(QIODevice::WriteOnly);
    filePow->open(QIODevice::WriteOnly);
    state = RECORD;


}
void BCIDataStream::classify(){

    if(initSharedMemory()==0){
        std::lock_guard<std::mutex> guard(global_mutex);
        state = CLASSIFY;

    }else{
        qInfo() << "ERROR - CAN NOT OPEN SHARED MEMORY";
    }



}
void BCIDataStream::doNothing(){
    std::lock_guard<std::mutex> guard(global_mutex);
    if(state == RECORD){
        fileMet->close();
        filePow->close();
        fileMet = nullptr;
        filePow = nullptr;
        qInfo() << "\nSaved file...\n";
    }else if(state == CLASSIFY){
        closeSharedMemory();
    }

    state = DO_NOTHING;
}

void BCIDataStream::exit(){
    client.unsubscribe(token, sessionId, "met");
    client.unsubscribe(token, sessionId, "pow");
}
