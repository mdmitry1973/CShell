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

#include "CDef.h"

#include <assert.h>

#include "CTargetEvent.h"
#include "CString.h"
#include "CDataExchange.h"
#include "CMenu.h"
#include "CWnd.h"
#include "CDialogEx.h"
#include "CCommandLineInfo.h"
#include "CDocManager.h"

class CDocTemplate;
class CDocument;
class CRecentFileList;
class CDocManager;

struct CShellBitmapInfo
{
    stdString name;
    stdString idstr;
};

class CSHELL_LIB_EXPORT CWinApp : public CCmdTarget
{
	
public:
	
	CWinApp();
	virtual ~CWinApp();
	
	virtual BOOL InitInstance();
	
    HICON LoadIcon(LPTSTR lpszResourceName) const;
	HICON LoadIcon(UINT nIDResource) const;
	
	BOOL Enable3dControls();
	BOOL Enable3dControlsStatic();
	void EnableShellOpen();
	
	void SetRegistryKey(LPCTSTR lpszRegistryKey);
	void SetRegistryKey(UINT nIDRegistryKey);
	
	void RegisterShellFileTypes(BOOL bCompat = FALSE);
	
	void LoadStdProfileSettings(UINT nMaxMRU = _AFX_MRU_COUNT);
	
	virtual BOOL SaveAllModified();
	
	virtual void OnHelp();
	virtual void OnFileNew();
	virtual void OnFileOpen();
	virtual void OnFilePrintSetup();
	
	virtual BOOL OnDDECommand(LPTSTR lpszCommand );
	
	virtual BOOL OnIdle(LONG lCount);
	
	virtual CDocument* OpenDocumentFile(LPCTSTR lpszFileName);
	
	virtual int Run( );
	virtual int ExitInstance();
	
	void AddDocTemplate(CDocTemplate* pTemplate);
	void CloseAllDocuments(BOOL bEndSession);
	POSITION GetFirstDocTemplatePosition( ) const;
	CDocTemplate* GetNextDocTemplate(POSITION& pos ) const;
	
	void ParseCommandLine(CCommandLineInfo& rCmdInfo);
	BOOL ProcessShellCommand(CCommandLineInfo& rCmdInfo);
	
	virtual void AddEventHandle(int objID, EventFun fun, int eventType);
	virtual void AddEventRangeHandle(int objID1, int objID2, EventFun fun, int eventType);
	virtual void AddEventHandle(void *obj, EventFun fun, int eventType);
	
	CWnd		*m_pMainWnd;
	CDocManager	*m_pDocManager;
	
    LPTSTR m_pszAppName;
	int m_nCmdShow;
	
	static BOOL LoadBitmapInfo();
	static std::map<int,CShellBitmapInfo> &GetBitmapInfoMap();
	
	static BOOL LoadIconInfo();
	static std::map<int,CShellBitmapInfo> &GetIconInfoMap();
	
	std::vector<CDocTemplate*> m_arrDocTemplate;
	
	HKEY GetAppRegistryKey();
	
	LPCTSTR m_pszRegistryKey;
	LPCTSTR m_pszProfileName;
	CRecentFileList* m_pRecentFileList;
};

#define CWinAppEx CWinApp

CSHELL_LIB_EXPORT CWinApp* AfxGetApp();

void InitCommonControls(void);
void AfxEnableControlContainer();

int AfxMessageBox(LPCTSTR lpszText, UINT nType = MB_OK, UINT nIDHelp = 0 );
int AfxMessageBox(UINT nIDPrompt, UINT nType = MB_OK, UINT nIDHelp = (UINT)-1);
CWnd* AfxGetMainWnd();

void CShellLog(const char *);

#define TRACE0(x) CShellLog(x)

#endif//CWINAPP_DEFINE
