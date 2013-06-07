/*
 *  CWinThread.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */


#ifndef CWINTHREAD_DEFINE
#define CWINTHREAD_DEFINE 1

#include "CDef.h"

class CException;
class CWnd;

typedef UINT (*AFX_THREADPROC)(LPVOID);

class CWinThread
{
	
public:
	
	CWinThread();
	CWinThread(AFX_THREADPROC pfnThreadProc, LPVOID pParam);
	~CWinThread();
	
	BOOL CreateThread(DWORD dwCreateFlags = 0, UINT nStackSize = 0,
					  LPSECURITY_ATTRIBUTES lpSecurityAttrs = NULL);
	
	// Attributes
	CWnd* m_pMainWnd;       // main window (usually same AfxGetApp()->m_pMainWnd)
	CWnd* m_pActiveWnd;     // active main window (may not be m_pMainWnd)
	BOOL m_bAutoDelete;     // enables 'delete this' after thread termination
	
	// only valid while running
	HANDLE m_hThread;       // this thread's HANDLE
	operator HANDLE() const;
	DWORD m_nThreadID;      // this thread's ID
	
	int GetThreadPriority();
	BOOL SetThreadPriority(int nPriority);
	
	// Operations
	DWORD SuspendThread();
	DWORD ResumeThread();
	BOOL PostThreadMessage(UINT message, WPARAM wParam, LPARAM lParam);
	
	// Overridables
	// thread initialization
	virtual BOOL InitInstance();
	
	// running and idle processing
	virtual int Run();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL PumpMessage();     // low level message pump
	virtual BOOL OnIdle(LONG lCount); // return TRUE if more idle processing
	virtual BOOL IsIdleMessage(MSG* pMsg);  // checks for special messages
	
	// thread termination
	virtual int ExitInstance(); // default will 'delete this'
	
	// Advanced: exception handling
	virtual LRESULT ProcessWndProcException(CException* e, const MSG* pMsg);
	
	// Advanced: handling messages sent to message filter hook
	virtual BOOL ProcessMessageFilter(int code, LPMSG lpMsg);
	
	// Advanced: virtual access to m_pMainWnd
	virtual CWnd* GetMainWnd();
	
	// Implementation
//public:
//	virtual ~CWinThread();
//#ifdef _DEBUG
//	virtual void AssertValid() const;
//	virtual void Dump(CDumpContext& dc) const;
//#endif
//	void CommonConstruct();
//	virtual void Delete();
	// 'delete this' only if m_bAutoDelete == TRUE
	
//public:
	// constructor used by implementation of AfxBeginThread
//	CWinThread(AFX_THREADPROC pfnThreadProc, LPVOID pParam);
	
	// valid after construction
//	LPVOID m_pThreadParams; // generic parameters passed to starting function
//	AFX_THREADPROC m_pfnThreadProc;
	
	// set after OLE is initialized
//	void (AFXAPI* m_lpfnOleTermOrFreeLib)(BOOL, BOOL);
//	COleMessageFilter* m_pMessageFilter;
	
//protected:
//	BOOL DispatchThreadMessageEx(MSG* msg);  // helper
//	void DispatchThreadMessage(MSG* msg);  // obsolete
};


#endif//CWINTHREAD_DEFINE