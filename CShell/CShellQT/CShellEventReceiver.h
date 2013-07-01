/*
 *  CShellEventReceiver.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CSHELLEVENTRECEIVER_DEFINE
#define CSHELLEVENTRECEIVER_DEFINE 1

#include <QObject>

#include "CDef.h"
#include "CTargetEvent.h"

class CWnd;

class CSHELL_LIB_EXPORT CShellEventReceiver : public QObject
{
    Q_OBJECT

public:
    CShellEventReceiver();
    virtual ~CShellEventReceiver();

    void setWindow(CWnd* receiver);

    CCmdTargetEventHandle   mReceiverData;

public slots:

    void eventFunction();
    void eventIndexFunction(int index);

private:

    CWnd*                   mReceiver;

};

#endif //CSHELLEVENTRECEIVER_DEFINE
