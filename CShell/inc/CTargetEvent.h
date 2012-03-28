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
#define EVENT_TYPE_WM_CHAR			4
#define EVENT_TYPE_WM_LBUTTONDOWN	5
#define EVENT_TYPE_WM_KILLFOCUS		6
#define	EVENT_TYPE_WM_SETFOCUS		7
#define EVENT_TYPE_NOTIFY_REFLECT	8
#define EVENT_TYPE_COMMAND_RANGE	9
#define EVENT_TYPE_WM_CREATE		10
#define EVENT_TYPE_COMMAND			11


//#define UDN_FIRST               (0U-721U)        // updown
//#define UDN_DELTAPOS            (UDN_FIRST - 1)

#define UDN_DELTAPOS            5555//(UDN_FIRST - 1)

#define WM_CHAR				0x0102
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

#define ON_COMMAND(ID, CALL) \
AddEventHandle(ID, (EventFun)(&ThisClass::CALL), EVENT_TYPE_COMMAND);

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
	
	CCmdTEHData m_mapEventHandle;
	
	virtual void AddEventHandle(int objID, EventFun fun, int eventType) = 0;
	virtual void AddEventHandle(void *obj, EventFun fun, int eventType) = 0;
	virtual BOOL SendEventHandle(int objID, void *sender, int eventType);
	
	virtual void FinaleSetup();
	
	CCmdTEHData* GetMapEventHandle();
	
	virtual void SetMessageMap();
	
protected:
	
};


#endif//CTAREGTEVENT_DEFINE