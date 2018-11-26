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
#ifndef SESSIONCREATOR_H
#define SESSIONCREATOR_H

#include <QObject>
#include "CortexClient.h"

/*
 * Create a session for a headset.
 *
 * It takes care of login/authorize and then create a session.
 * This class doesn't handle errors from the CortexClient object.
 *
 */
class SessionCreator : public QObject
{
    Q_OBJECT

public:
    explicit SessionCreator(QString userId,QString userPass,QObject *parent = nullptr);

    // create a session for a headset
    void createSession(CortexClient* client, QString headsetId, QString license);

    // break all connections between this object and the Cortex client
    void clear();

signals:
    void sessionCreated(QString token, QString sessionId);

private slots:
    void onGetUserLoginOk(const QStringList &usernames);
    void onLogoutOk();
    void onLoginOk();
    void onAuthorizeOk(QString token);
    void onCreateSessionOk(QString sessionId);

private:
    CortexClient* client;
    QString headsetId;
    QString license;
    QString token;
};

#endif // SESSIONCREATOR_H
