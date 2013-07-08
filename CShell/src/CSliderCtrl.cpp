/*
 *  CSliderCtrl.mm
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include <QSlider>

#include "CSliderCtrl.h"
#include "CQSlider.h"

CSliderCtrl::CSliderCtrl() : CWnd()
{
	
}

CSliderCtrl::~CSliderCtrl()
{
    if (m_hWnd)
    {
        CQSlider *slider = (CQSlider *)m_hWnd;
        slider->m_pWnd = NULL;
    }
}

BOOL CSliderCtrl::Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)
{
	return CreateEx(0, dwStyle, rect, pParentWnd, nID);
}

BOOL CSliderCtrl::CreateEx(DWORD dwExStyle, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)
{
    QWidget *parentView = (QWidget *)pParentWnd->GetNSWindow();
    CQSlider *slider = new CQSlider(parentView);
    QRect contentRect(rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top);

    slider->move (contentRect.x(), contentRect.y());
    slider->resize(contentRect.width(), contentRect.height());
    slider->setOrientation(Qt::Horizontal);

    slider->setAccessibleName(QString().setNum(nID));
    slider->m_pParent = pParentWnd;
    slider->m_pWnd = this;
    slider->setEventConnection();

    m_hWnd = slider;
    mParentWin = pParentWnd;

    return TRUE;
}

void CSliderCtrl::SetRange(short nLower, short nUpper)
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
        QSlider *slider = (QSlider *)m_hWnd;

        slider->setMaximum(nUpper);
        slider->setMinimum(nLower);
	}
}

void CSliderCtrl::SetRange32(int nLower, int nUpper)
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
        QSlider *slider = (QSlider *)m_hWnd;

        slider->setMaximum(nUpper);
        slider->setMinimum(nLower);
	}
}

int CSliderCtrl::SetPos(int nPos)
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
        QSlider *slider = (QSlider *)m_hWnd;

        slider->setSliderPosition(nPos);
	}
	
	return 0;
}

int CSliderCtrl::GetPos()
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
        QSlider *slider = (QSlider *)m_hWnd;

        return slider->sliderPosition();
	}
	
	return 0;
}
