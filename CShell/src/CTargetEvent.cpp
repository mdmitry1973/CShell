/*
 *  CTargetEvent.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/13/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include <QDebug>

#include "CDef.h"

#include "CTargetEvent.h"
#include "CWnd.h"

#define TCN_FIRST               (0U-550U)
#define TCN_LAST                (0U-580U)
#define TCN_KEYDOWN             (TCN_FIRST - 0)
#define TCN_SELCHANGE           (TCN_FIRST - 1)
#define TCN_SELCHANGING         (TCN_FIRST - 2)
#define TCN_GETOBJECT           (TCN_FIRST - 3)
#define TCN_FOCUSCHANGE         (TCN_FIRST - 4)

CCmdTarget::CCmdTarget()
{

}

CCmdTarget::~CCmdTarget()
{
	
}

void CCmdTarget::EnableAutomation()
{
    qDebug() << "TO DO CCmdTarget::EnableAutomation";
}

void CCmdTarget::BeginWaitCursor()
{
    qDebug() << "TO DO CCmdTarget::BeginWaitCursor";
}

void CCmdTarget::EndWaitCursor()
{
    qDebug() << "TO DO CCmdTarget::EndWaitCursor";
}

void CCmdTarget::RestoreWaitCursor()
{
    qDebug() << "TO DO CCmdTarget::RestoreWaitCursor";
}

void CCmdTarget::SetMessageMap()
{
	
}

void CCmdTarget::FinaleSetup()
{
	SetMessageMap();
}

BOOL CCmdTarget::SendEventHandle(int objID, void *sender, int eventType)
{
	int index = -1;
	BOOL res = FALSE;
	
	for(int i = 0; i < m_mapEventHandle.size(); i++)
	{
		if (m_mapEventHandle[i].tag == objID &&
			((eventType != -1 && m_mapEventHandle[i].eventType == eventType) ||
			 eventType == -1))
			{
				index = i;
				break;
			}
	}
	
	if (index != -1)
	{
		CCmdTargetEventHandle &it = m_mapEventHandle[index];
		
		//(NMHDR* pNMHDR, LRESULT* pResult)
		//HWND     hwndFrom;
		//UINT_PTR idFrom;
		//UINT     code;
		
		if (it.eventType == UDN_DELTAPOS)//ON_NOTIFY_REFLECT)
		{						
			//UDN_DELTAPOS
			//typedef struct _NM_UPDOWN {
			//	NMHDR hdr;
			//	int   iPos;
			//	int   iDelta;
			//} NMUPDOWN, *LPNMUPDOWN;
			
			EventNotifyFun fun = (EventNotifyFun)it.fun;
			
			if (fun)
			{
				NM_UPDOWN	nmhdr;
				LRESULT	result = 0;
				
                nmhdr.hdr.hwndFrom	= (HWND)sender;
				
				nmhdr.hdr.idFrom	= 0;
				nmhdr.hdr.code		= 1;
				
				nmhdr.iPos = 0;
				nmhdr.iDelta = 0;

                /*
                QObject *obj = dynamic_cast<QS>(QObject *)sender;

                if (dynamic_cast)//[obj isKindOfClass:[NSStepper class]])
				{
					CNSStepper *stepper = (CNSStepper *)obj;
					
					nmhdr.hdr.idFrom = [stepper intValue];
					nmhdr.iPos = [stepper intValue];
					nmhdr.iDelta = [stepper increment];
					
					double preVal = [stepper getStoreValue];
					
					if (nmhdr.iPos < preVal)
					{
						nmhdr.iDelta = -nmhdr.iDelta;
					}
					
					[stepper resetStoreValue];
				}
                */
				
				(((CCmdTarget *)(it.control))->*fun)((NMHDR *)&nmhdr, &result);
				res = TRUE;
			}
		}
		else
		if (it.eventType == NM_CUSTOMDRAW)//ON_NOTIFY)
		{
			//NM_CUSTOMDRAW
			//typedef struct tagNMCUSTOMDRAWINFO
			//{
			//	NMHDR hdr;
			//	DWORD dwDrawStage;
			//	HDC hdc;
			//	RECT rc;
			//	DWORD_PTR dwItemSpec;  
			//	UINT  uItemState;
			//	LPARAM lItemlParam;
			//} NMCUSTOMDRAW
			//
			//return code
			//CDRF_DODEFAULT The control will draw itself. It will not send any additional NM_CUSTOMDRAW notification codes for this paint cycle. This occurs when dwDrawStage equals CDDS_PREPAINT.
			//CDRF_DOERASE Windows Vista. The control will not draw the focus rectangle around an item.
			//CDRF_NOTIFYITEMDRAW The control will notify the parent of any item-related drawing operations. It will send NM_CUSTOMDRAW notification codes before and after drawing items. This occurs when dwDrawStage equals CDDS_PREPAINT.
			//CDRF_NOTIFYPOSTERASE The control will notify the parent after erasing an item. This occurs when dwDrawStage equals CDDS_PREPAINT.
			//CDRF_NOTIFYPOSTPAINT The control will notify the parent after painting an item. This occurs when dwDrawStage equals CDDS_PREPAINT.
			//CDRF_NEWFONT The application specified a new font for the item; the control will use the new font. For more information about changing fonts, see Changing fonts and colors. This occurs when dwDrawStage equals CDDS_ITEMPREPAINT.
			//CDRF_NOTIFYSUBITEMDRAW Version 4.71. Your application will receive an NM_CUSTOMDRAW control code with dwDrawStage set to CDDS_ITEMPREPAINT | CDDS_SUBITEM before each list-view subitem is drawn. You can then specify font and color for each subitem separately or return CDRF_DODEFAULT for default processing. This occurs when dwDrawStage equals CDDS_ITEMPREPAINT.
			//CDRF_SKIPDEFAULT The application drew the item manually. The control will not draw the item. This occurs when dwDrawStage equals CDDS_ITEMPREPAINT.
			//CDRF_SKIPPOSTPAINT Windows Vista. The control will only paint the background. 
			
			EventNotifyFun fun = (EventNotifyFun)it.fun;
			
			if (fun)
			{
				NMCUSTOMDRAW	nmcustomdraw;
				LRESULT			result = 0;
				
                nmcustomdraw.hdr.hwndFrom	= (HWND)sender;
				nmcustomdraw.hdr.idFrom		= 0;
				nmcustomdraw.hdr.code		= 0;
				nmcustomdraw.dwDrawStage	= 0;
				nmcustomdraw.hdc			= 0;
				//nmcustomdraw.rc;
				//nmcustomdraw.dwItemSpec;  
				//nmcustomdraw.uItemState;
				//nmcustomdraw.lItemlParam		= 1;
				
				//NSObject *obj = (NSObject *)sender;
				
				//if ([obj isKindOfClass:[NSStepper class]])
				//{
				//	NSStepper *stepper = (NSStepper *)obj;
				//	
				//	nmhdr.idFrom = [stepper intValue];
				//}
				
				(((CCmdTarget *)(it.control))->*fun)((NMHDR *)(&nmcustomdraw), &result);
				res = TRUE;
			}
		}
		else
		if (it.eventType == TCN_SELCHANGE)
		{
			EventNotifyFun fun = (EventNotifyFun)it.fun;
			
			if (fun)
			{
				NMHDR	hdr;
				LRESULT	result = 0;
				
                hdr.hwndFrom	= (HWND)sender;
				hdr.idFrom		= 0;
				hdr.code		= 0;
								
				(((CCmdTarget *)(it.control))->*fun)((NMHDR *)(&hdr), &result);
				res = TRUE;
			}
		}
		else
		{
			EventFun fun = it.fun;
		
			if (fun)
			{
                /*
				NSObject *obj = (NSObject *)sender;
				
				//call standard method need for RadioButton
				if (obj &&
					[obj respondsToSelector:@selector(eventHandle:)])
				{
					[obj eventHandle: sender];					
				}
                */

				(((CCmdTarget *)(it.control))->*fun)();	
				res = TRUE;			
			}
		}
	}
	
	return res;
}

CCmdTEHData* CCmdTarget::GetMapEventHandle()
{
	return &m_mapEventHandle;
}

