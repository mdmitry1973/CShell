/*
 *  CQSlider.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDef.h"

#include "QSlider.h"


#ifndef CQSLIDER_DEFINE
#define CQSLIDER_DEFINE 1

class CWnd;

class CSHELL_LIB_EXPORT CQSlider : public QSlider
{
	
public:
	
    CQSlider(QWidget * parent = 0);
    CQSlider(Qt::Orientation orientation, QWidget * parent = 0);
    virtual ~CQSlider();

    void init();
    void setEventConnection();

    void	sliderMoved(int value);

    CWnd *m_pWnd;
    CWnd *m_pParent;
};


#endif//CQSLIDER_DEFINE
