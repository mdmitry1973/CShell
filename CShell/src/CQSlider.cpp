//
//  CQSlider.cpp
//  CShell
//
//  Created by Dmitry Mikhaevich on 1/19/12.
//  Copyright 2012 Dmitry Mikhaevich. All rights reserved.
//

#include <QDebug>
#include "CDef.h"
#include "CWnd.h"

#include "CQSlider.h"

CQSlider::CQSlider(QWidget * parent) : QSlider(parent)
{
   init();
}

CQSlider::CQSlider(Qt::Orientation orientation, QWidget * parent) : QSlider(orientation, parent)
{
    init();
}

CQSlider::~CQSlider()
{
    disconnect(this, 0, 0, 0);
}

void CQSlider::init()
{
    m_pWnd = 0;
    m_pParent = 0;
}

void CQSlider::sliderMoved(int value)
{
    if (m_pWnd)
    {
        m_pWnd->SendEventHandle(0, this, EVENT_TYPE_WM_HSCROLL);
    }

    if (m_pParent)
    {
        m_pParent->SendEventHandle(0, this, EVENT_TYPE_WM_HSCROLL);
    }
}

void CQSlider::setEventConnection()
{
    QMetaObject::Connection handle = connect(qobject_cast<QAbstractSlider *>(this), &QAbstractSlider::valueChanged, this, &CQSlider::sliderMoved);

    if (handle == false)
    {
        qDebug() << "QMetaObject::Connection handle == false";
    }
}
