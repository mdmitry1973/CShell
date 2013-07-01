/*
 *  CSpinButtonCtrl.mm
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include <QDebug>
#include <QSpinBox>

#include "CSpinButtonCtrl.h"

CSpinButtonCtrl::CSpinButtonCtrl() : CWnd()
{
	m_pWndBuddy = 0;
}

BOOL CSpinButtonCtrl::Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)
{
	return CreateEx(0, dwStyle, rect, pParentWnd, nID);
}

BOOL CSpinButtonCtrl::CreateEx(DWORD dwExStyle, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)
{
    QWidget *parentView = (QWidget *)pParentWnd->GetNSWindow();
    QSpinBox *spin = new QSpinBox(parentView);
    QRect contentRect(rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top);

    spin->move (contentRect.x(), contentRect.y());
    spin->resize(contentRect.width(), contentRect.height());

    spin->setAccessibleName(QString().setNum(nID));

    m_hWnd = spin;
    mParentWin = pParentWnd;

	return TRUE;
}

void CSpinButtonCtrl::SetRange(short nLower, short nUpper)
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
        QSpinBox *spin = (QSpinBox *)m_hWnd;
        //[((NSStepper *)m_hWnd) setMinValue: nLower];
        //[((NSStepper *)m_hWnd) setMaxValue: nUpper];
	}
}

void CSpinButtonCtrl::SetRange32(int nLower, int nUpper)
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
        QSpinBox *spin = (QSpinBox *)m_hWnd;
        //[((NSStepper *)m_hWnd) setMinValue: nLower];
        //[((NSStepper *)m_hWnd) setMaxValue: nUpper];
	}
}

int CSpinButtonCtrl::GetPos() const
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
        QSpinBox *spin = (QSpinBox *)m_hWnd;
        return 0;//[((NSStepper *)m_hWnd) intValue];
	}
	
	return 0;
}

int CSpinButtonCtrl::GetPos32(LPBOOL lpbError ) const
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
        QSpinBox *spin = (QSpinBox *)m_hWnd;
        return 0;//[((NSStepper *)m_hWnd) intValue];
	}
	
	return 0;
}

int CSpinButtonCtrl::SetPos(int nPos )
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
        QSpinBox *spin = (QSpinBox *)m_hWnd;
        //[((NSStepper *)m_hWnd) setIntValue:nPos];
        return 0;//[((NSStepper *)m_hWnd) intValue];
	}
	
	return 0;
}

int CSpinButtonCtrl::SetPos32(int nPos )
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
        QSpinBox *spin = (QSpinBox *)m_hWnd;
        //[((NSStepper *)m_hWnd) setIntValue:nPos];
        return 0;//[((NSStepper *)m_hWnd) intValue];
	}
	
	return 0;
}

CWnd* CSpinButtonCtrl::GetBuddy() const
{
	return m_pWndBuddy;
}

CWnd* CSpinButtonCtrl::SetBuddy(CWnd* pWndBuddy )
{
	m_pWndBuddy = pWndBuddy;
	
	return m_pWndBuddy;
}
