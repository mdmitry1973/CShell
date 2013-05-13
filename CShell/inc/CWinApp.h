/*
 *  CWinApp.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/26/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */


#ifndef CWINAPP_DEFINE
#define CWINAPP_DEFINE 1

#include <assert.h>

#include "CDef.h"
#include "CTargetEvent.h"
#include "CString.h"
#include "CDataExchange.h"
#include "CMenu.h"
#include "CWnd.h"
#include "CDialogEx.h"
#include "CCommandLineInfo.h"

class CDocTemplate;

struct CShellBitmapInfo
{
	std::string name;
	std::string idstr;
};

class CWinApp : public CCmdTarget
{
	
public:
	
	CWinApp();
	virtual ~CWinApp();
	
	virtual BOOL InitInstance();
	
	HICON LoadIcon(LPCTSTR lpszResourceName) const;
	HICON LoadIcon(UINT nIDResource) const;
	
	virtual void OnHelp();
	
	BOOL Enable3dControls();
	BOOL Enable3dControlsStatic();
	
	void SetRegistryKey(LPCTSTR lpszRegistryKey);
	void SetRegistryKey(UINT nIDRegistryKey);
	
	void LoadStdProfileSettings(UINT nMaxMRU = _AFX_MRU_COUNT);
	
	void OnFileNew();
	void OnFileOpen();
	void OnFilePrintSetup();
	
	void AddDocTemplate(CDocTemplate* pTemplate);
	void CloseAllDocuments(BOOL bEndSession);
	
	void ParseCommandLine(CCommandLineInfo& rCmdInfo);
	BOOL ProcessShellCommand(CCommandLineInfo& rCmdInfo);
	
	virtual void AddEventHandle(int objID, EventFun fun, int eventType);
	virtual void AddEventHandle(void *obj, EventFun fun, int eventType);
	
	CWnd	*m_pMainWnd;
	
	static BOOL LoadBitmapInfo();
	static std::map<int,CShellBitmapInfo> &GetBitmapInfoMap();
	
	static BOOL LoadIconInfo();
	static std::map<int,CShellBitmapInfo> &GetIconInfoMap();
	
	std::vector<CDocTemplate*> m_arrDocTemplate;
	
	HKEY GetAppRegistryKey();
	
	LPCTSTR m_pszRegistryKey;
	LPCTSTR m_pszProfileName;
};

CWinApp* AfxGetApp();

void InitCommonControls(void);
void AfxEnableControlContainer();

int AfxMessageBox(LPCTSTR lpszText, UINT nType = MB_OK, UINT nIDHelp = 0 );
int AfxMessageBox(UINT nIDPrompt, UINT nType = MB_OK, UINT nIDHelp = (UINT)-1);
CWnd* AfxGetMainWnd();

BOOL PeekMessage(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg);

void CShellLog(const char *);

#define TRACE0(x) CShellLog(x)

#endif//CWINAPP_DEFINE
