/*
 *  CTargetEvent.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/13/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CTAREGTEVENT_DEFINE
#define CTAREGTEVENT_DEFINE 1

#include <map>
#include <vector>

#include "CObject.h"

class CCmdTarget;
class CWnd;

typedef void (CCmdTarget::*EventFun)();
typedef void (CCmdTarget::*EventNotifyFun)(NMHDR* pNMHDR, LRESULT* pResult);

#define EVENT_TYPE_BN_CLICKED		0
#define EVENT_TYPE_CBN_SELCHANGE	1
#define EVENT_TYPE_EN_CHANGE		2
#define EVENT_TYPE_LBN_SELCHANGE	3
#define EVENT_TYPE_LBN_DBLCLK		4 //need to do
#define EVENT_TYPE_WM_CHAR			5
#define EVENT_TYPE_WM_LBUTTONDOWN	6
#define EVENT_TYPE_WM_KILLFOCUS		7
#define	EVENT_TYPE_WM_SETFOCUS		8
#define EVENT_TYPE_NOTIFY_REFLECT	9
#define EVENT_TYPE_COMMAND_RANGE	10
#define EVENT_TYPE_WM_CREATE		11
#define EVENT_TYPE_COMMAND			12
#define EVENT_TYPE_COMMAND_UI		13
#define EVENT_TYPE_WM_CONTEXTMENU	14
#define EVENT_TYPE_WM_TIMER			15
#define EVENT_TYPE_MESSAGE			16
#define EVENT_TYPE_WM_SIZE			17
#define EVENT_TYPE_WM_RBUTTONDOWN	18
#define EVENT_TYPE_WM_LBUTTONUP		19
#define EVENT_TYPE_WM_MOUSEMOVE		20
#define EVENT_TYPE_WM_SETCURSOR		21
#define EVENT_TYPE_WM_ERASEBKGND	22
#define EVENT_TYPE_WM_KEYDOWN		23
#define EVENT_TYPE_WM_MOUSEWHEEL	24
#define EVENT_TYPE_WM_RBUTTONUP		25
#define EVENT_TYPE_WM_KEYUP			26
#define EVENT_TYPE_WM_LBUTTONDBLCLK	27

//#define UDN_FIRST               (0U-721U)        // updown
//#define UDN_DELTAPOS            (UDN_FIRST - 1)

#define UDN_DELTAPOS            5555//(UDN_FIRST - 1)

#define NM_CUSTOMDRAW		1000

#define PM_NOREMOVE	0x0000
#define PM_REMOVE	0x0001
#define PM_NOYIELD	0x0002 

#define DECLARE_MESSAGE_MAP() virtual void SetMessageMap();

#define BEGIN_MESSAGE_MAP(theClass, BaseClass) \
void theClass::SetMessageMap()\
{\
typedef theClass ThisClass;\


#define ON_WM_SYSCOMMAND()
#define ON_WM_PAINT()
#define ON_WM_QUERYDRAGICON()

#define ON_BN_CLICKED(ID, CALL) \
AddEventHandle(ID, (EventFun)(&ThisClass::CALL), EVENT_TYPE_BN_CLICKED);

#define ON_CBN_SELCHANGE(ID, CALL) \
AddEventHandle(ID, (EventFun)(&ThisClass::CALL), EVENT_TYPE_CBN_SELCHANGE);

#define ON_EN_CHANGE(ID, CALL) \
AddEventHandle(ID, (EventFun)(&ThisClass::CALL), EVENT_TYPE_EN_CHANGE);

#define ON_LBN_SELCHANGE(ID, CALL) \
AddEventHandle(ID, (EventFun)(&ThisClass::CALL), EVENT_TYPE_LBN_SELCHANGE);

#define ON_LBN_DBLCLK(ID, CALL) \
AddEventHandle(ID, (EventFun)(&ThisClass::CALL), EVENT_TYPE_LBN_DBLCLK);

#define ON_COMMAND(ID, CALL) \
AddEventHandle(ID, (EventFun)(&ThisClass::CALL), EVENT_TYPE_COMMAND);

#define ON_UPDATE_COMMAND_UI(ID, CALL) \
AddEventHandle(ID, (EventFun)(&ThisClass::CALL), EVENT_TYPE_COMMAND_UI);

#define ON_MESSAGE(ID, CALL) \
AddEventHandle(ID, (EventFun)(&ThisClass::CALL), EVENT_TYPE_MESSAGE);

#define ON_COMMAND_EX_RANGE(ID1, ID2, CALL) \
AddEventRangeHandle(ID1, ID2, (EventFun)(&ThisClass::CALL), EVENT_TYPE_COMMAND);

#define ON_NOTIFY_REFLECT(NOTIFY_CODE, CALL) \
AddEventHandle(m_hWnd, (EventFun)(&ThisClass::CALL), NOTIFY_CODE);

#define ON_NOTIFY(NOTIFY_CODE, ID, CALL )\
AddEventHandle(ID, (EventFun)(&ThisClass::CALL), NOTIFY_CODE);

#define ON_COMMAND_RANGE(ID_MIN, ID_MAX, CALL )\
for(int i = ID_MIN; i <= ID_MAX; i++)\
{\
	AddEventHandle(i, (EventFun)(&ThisClass::CALL), EVENT_TYPE_COMMAND_RANGE);\
}\

#define END_MESSAGE_MAP() }


struct AFX_CMDHANDLERINFO
{
	CCmdTarget* pTarget;
	void (CCmdTarget::*pmf)(void);
};

struct CCmdTargetEventHandle{
	
	int			tag;
	EventFun	fun;
	int			eventType;
	void		*control;
};

typedef std::vector<CCmdTargetEventHandle> CCmdTEHData;

class CCmdTarget : public CObject
{
	
public:
	
	CCmdTarget();
	
	virtual ~CCmdTarget();
	
	void EnableAutomation();
	
	void BeginWaitCursor();
	void EndWaitCursor();
	void RestoreWaitCursor();
	
	CCmdTEHData m_mapEventHandle;
	
	virtual void AddEventHandle(int objID, EventFun fun, int eventType) = 0;
	virtual void AddEventRangeHandle(int objID1, int objID2, EventFun fun, int eventType) = 0;
	virtual void AddEventHandle(void *obj, EventFun fun, int eventType) = 0;
	virtual BOOL SendEventHandle(int objID, void *sender, int eventType);
	
	virtual void FinaleSetup();
	
	CCmdTEHData* GetMapEventHandle();
	
	virtual void SetMessageMap();
	
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo){ return FALSE;}
	
protected:
	
};


#endif//CTAREGTEVENT_DEFINE