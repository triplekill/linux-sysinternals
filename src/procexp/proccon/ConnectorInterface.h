/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -p ConnectorInterface -c ConnectorInterface connector.xml
 *
 * qdbusxml2cpp is Copyright (C) 2015 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef CONNECTORINTERFACE_H
#define CONNECTORINTERFACE_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

/*
 * Proxy class for interface org.proccon
 */
class ConnectorInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.proccon"; }

public:
    ConnectorInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~ConnectorInterface();

public Q_SLOTS: // METHODS
Q_SIGNALS: // SIGNALS
    void exec(int process_pid, int process_tgid);
    void exit(int process_pid, int process_tgid, int exit_code);
    void fork(int parent_pid, int parent_tgid, int child_pid, int child_tgid);
    void gid(int process_pid, int process_tgid, int rgid, int egid);
    void uid(int process_pid, int process_tgid, int ruid, int euid);
};

namespace org {
  typedef ::ConnectorInterface proccon;
}
#endif
