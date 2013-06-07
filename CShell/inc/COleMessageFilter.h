/*
 *  COleMessageFilter.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */


#ifndef COLEMESSAGEFILTER_DEFINE
#define COLEMESSAGEFILTER_DEFINE 1

#include "CDef.h"

class COleMessageFilter
{
	
public:
	
	COleMessageFilter();
	
	virtual ~COleMessageFilter();
	
	// Operations
	BOOL Register();
	void Revoke();
	
	// for controlling the busy state of the server application (called app)
	virtual void BeginBusyState();
	virtual void EndBusyState();
	//void SetBusyReply(SERVERCALL nBusyReply);
	
	// for controlling actions taken against rejected/retried calls
	void SetRetryReply(DWORD nRetryReply = 0);
	// only used when the "not responding" dialog is disabled
	void SetMessagePendingDelay(DWORD nTimeout = 5000);
	// used to determine amount of time before significant message
	void EnableBusyDialog(BOOL bEnableBusy = TRUE);
	void EnableNotRespondingDialog(BOOL bEnableNotResponding = TRUE);
	// used to enable/disable the two types of busy dialogs
	
	// Overridables
	virtual BOOL OnMessagePending(const MSG* pMsg);
	// return TRUE to eat the message (usually only if processed)
	
	
	/*
	virtual BOOL IsSignificantMessage(MSG* pMsg);
	// determine if any significant messages are present in the queue
	virtual int OnBusyDialog(HTASK htaskBusy);
	virtual int OnNotRespondingDialog(HTASK htaskBusy);
	// these functions display the busy dialog
	
protected:
	BOOL m_bRegistered;
	LONG m_nBusyCount;  // for BeginBusyState & EndBusyState
	BOOL m_bEnableBusy;
	BOOL m_bEnableNotResponding;
	BOOL m_bUnblocking;
	DWORD m_nRetryReply;    // only used if m_bEnableNotResponding == FALSE
	DWORD m_nBusyReply;
	DWORD m_nTimeout;
	
	// Interface Maps
public:
	BEGIN_INTERFACE_PART(MessageFilter, IMessageFilter)
	INIT_INTERFACE_PART(COleMessageFilter, MessageFilter)
	STDMETHOD_(DWORD, HandleInComingCall)(DWORD, HTASK, DWORD,
										  LPINTERFACEINFO);
	STDMETHOD_(DWORD, RetryRejectedCall)(HTASK, DWORD, DWORD);
	STDMETHOD_(DWORD, MessagePending)(HTASK, DWORD, DWORD);
	END_INTERFACE_PART(MessageFilter)
	
	DECLARE_INTERFACE_MAP()
	*/
};


#endif//COLEMESSAGEFILTER_DEFINE