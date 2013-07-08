/*
 *  CShellEventReceiver.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include <QDebug>
#include <QObject>
#include <QAction>

#include "CWnd.h"

#include "CShellEventReceiver.h"

CShellEventReceiver::CShellEventReceiver(): QObject()
{
    mReceiver = NULL;
}

CShellEventReceiver::~CShellEventReceiver()
{

}

void CShellEventReceiver::setReceiver(CCmdTarget* receiver)
{
   mReceiver = receiver;
}

void CShellEventReceiver::eventFunction()
{
    if (mReceiver)
    {
        mReceiver->SendEventHandle(mReceiverData.tag, mReceiverData.control, mReceiverData.eventType);
    }
}

void CShellEventReceiver::eventIndexFunction(int index)
{
    if (mReceiver)
    {
        mReceiver->SendEventHandle(mReceiverData.tag, mReceiverData.control, mReceiverData.eventType);
    }
}

void CShellEventReceiver::menuSelection(QAction *action)
{
    if (action)
    {
        QVariant var = action->data();
        QMenu *menu = action->menu();

        mReceiver->SendEventHandle(var.toInt(), menu, EVENT_TYPE_COMMAND);
    }
}
