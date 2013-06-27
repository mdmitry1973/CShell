/*
 *  CWinApp.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/26/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#import <Cocoa/Cocoa.h>

#include "CDocTemplate.h"
#include "CDocument.h"
#include "CRecentFileList.h"

#include "CWinApp.h"

#import "CNSApplicationDelegate.h"

std::map<int, CShellBitmapInfo> g_mapBitmapInfo;
std::map<int, CShellBitmapInfo> g_mapIconInfo;

CNSApplicationDelegate	*pMainAppCocoa = nil;
CWinApp					*pMainApp = nil;	

CWinApp::CWinApp()
{
	pMainApp = this;
	m_pszAppName = _strdup(_T(""));
	((char *)m_pszAppName)[0] = 0;
	m_nCmdShow = SW_SHOWNORMAL;
}

CWinApp::~CWinApp()
{
	if (m_pszAppName)
	{
		free((void *)m_pszAppName);
	}
	
	for(int i = 0; i < m_arrDocTemplate.size(); i++)
	{
		delete m_arrDocTemplate[i];
	}
}

BOOL CWinApp::InitInstance()
{
	return true;
}

HICON CWinApp::LoadIcon(LPTSTR lpszResourceName) const
{
	CWinApp::LoadBitmapInfo();
	
	std::map<int,CShellBitmapInfo> &bmp_map =  CWinApp::GetIconInfoMap();
	std::map<int,CShellBitmapInfo>::iterator it;
	
	for(it = bmp_map.begin(); it != bmp_map.end(); it++)
	{
		if (it->second.idstr == lpszResourceName)
		{
			return LoadIcon(it->first);
		}
	}
	
	assert(false);
	
	return 0;
}

HICON CWinApp::LoadIcon(UINT nIDResource) const
{
	//NSImage *imageFromBundle = nil;
	NSString *resFilePath = nil;
	std::map<int,CShellBitmapInfo>::iterator it;
	
	CWinApp::LoadBitmapInfo();
	
	std::map<int,CShellBitmapInfo> &bmp_map =  CWinApp::GetIconInfoMap();
	
	if (nIDResource &&
		(it = bmp_map.find(nIDResource)) != bmp_map.end())
	{
		NSBundle *resBundle = [NSBundle mainBundle];
		
		if (resBundle)
		{
			NSString *strFullFileName = [NSString stringWithUTF8String: it->second.name.c_str()];
			NSString *strFileName = [strFullFileName stringByReplacingOccurrencesOfString: [strFullFileName pathExtension] withString: @""];
			
			strFileName = [strFileName stringByReplacingOccurrencesOfString: @"." withString: @""];
			
			//NSString *
			resFilePath = [resBundle pathForResource:strFileName ofType: [strFullFileName pathExtension]];
			//NSImage *imageFromBundle = [[NSImage alloc] initWithContentsOfFile:resFilePath];
			
			//if (!imageFromBundle)
			//{
			//	assert(false);					
			//}			
		}
		else 
		{
			assert(false);					
		}
	}
	
	return resFilePath;//imageFromBundle;
}

void CWinApp::EnableShellOpen()
{
	NSLog(@"TO DO CWinApp::EnableShellOpen");
}

void CWinApp::RegisterShellFileTypes(BOOL bCompat)
{
	NSLog(@"TO DO CWinApp::RegisterShellFileTypes");
}

BOOL CWinApp::Enable3dControls()
{
	return TRUE;
}

BOOL CWinApp::Enable3dControlsStatic()
{
	return TRUE;	
}

void CWinApp::SetRegistryKey(LPCTSTR lpszRegistryKey)
{
	NSLog(@"TO DO CWinApp::SetRegistryKey");
}

void CWinApp::SetRegistryKey(UINT nIDRegistryKey)
{
	NSLog(@"TO DO CWinApp::SetRegistryKey");
}

void CWinApp::LoadStdProfileSettings(UINT nMaxMRU)
{
	NSLog(@"TO DO CWinApp::LoadStdProfileSettings");
}

void CWinApp::ParseCommandLine(CCommandLineInfo& rCmdInfo)
{
	NSArray *args = [[NSProcessInfo processInfo] arguments];
	
	for(int i = 0; i < [args count]; i++)
	{
		NSString *str = [args objectAtIndex: i];
		BOOL bFlag = FALSE;
		
		if (i != 0)
		{
			if ([str hasPrefix:@"/"] ||
				[str hasPrefix:@"-"])
			{
				bFlag = TRUE;
				str = [str substringFromIndex:1];
			}
		}
		
		rCmdInfo.ParseParam([str UTF8String], bFlag, i == ([args count] - 1));
	}
}

BOOL CWinApp::ProcessShellCommand(CCommandLineInfo& rCmdInfo)
{
	BOOL bResult = TRUE;
	
	switch (rCmdInfo.m_nShellCommand)
	{
		case CCommandLineInfo::FileNew:
		{
			//??if (!AfxGetApp()->OnCmdMsg(ID_FILE_NEW, 0, NULL, NULL))
			OnFileNew();
			//??if (m_pMainWnd == NULL)
			 /* 
			CDocTemplate* pTemplate = NULL;
			   
			if (m_arrDocTemplate.size() > 1)//??need choose
			{
				NSLog(@"TO DO CWinApp::ProcessShellCommand");
			}
			else 
			{
				pTemplate = m_arrDocTemplate[0];
			}
			
			if (!pTemplate->OpenDocumentFile(NULL))
			{
				bResult = FALSE;
			}
			  */
		}
		break;
			
			// If we've been asked to open a file, call OpenDocumentFile()
			
		case CCommandLineInfo::FileOpen:
			//??if (!OpenDocumentFile(rCmdInfo.m_strFileName))
				bResult = FALSE;
			break;
			
			// If the user wanted to print, hide our main window and
			// fire a message to ourselves to start the printing
			
		case CCommandLineInfo::FilePrintTo:
		case CCommandLineInfo::FilePrint:
			//??m_nCmdShow = SW_HIDE;
			//??ASSERT(m_pCmdInfo == NULL);
			//??if(OpenDocumentFile(rCmdInfo.m_strFileName))
			//??{
			//??	m_pCmdInfo = &rCmdInfo;
			//??	ENSURE_VALID(m_pMainWnd);
			//??	m_pMainWnd->SendMessage(WM_COMMAND, ID_FILE_PRINT_DIRECT);
			//??	m_pCmdInfo = NULL;
			//??}
			bResult = FALSE;
			break;
			
			// If we're doing DDE, hide ourselves
			
		case CCommandLineInfo::FileDDE:
			//??m_pCmdInfo = (CCommandLineInfo*)(UINT_PTR)m_nCmdShow;
			//??m_nCmdShow = SW_HIDE;
			break;
			
			// If we've been asked to register, exit without showing UI.
			// Registration was already done in InitInstance().
		//??case CCommandLineInfo::AppRegister:
		//??{
			//??Register();            
		//??	bResult = FALSE;    // that's all we do
			
			// If nobody is using it already, we can use it.
			// We'll flag that we're unregistering and not save our state
			// on the way out. This new object gets deleted by the
			// app object destructor.
			
			//??if (m_pCmdInfo == NULL)
			//??{
			//??	m_pCmdInfo = new CCommandLineInfo;
			//??	m_pCmdInfo->m_nShellCommand = CCommandLineInfo::AppUnregister;
			//??}
		//??	break;
		//??}
			
			// If we've been asked to unregister, unregister and then terminate
		//??case CCommandLineInfo::AppUnregister:
		//??{
			//??BOOL bUnregistered = Unregister();
			
			// if you specify /EMBEDDED, we won't make an success/failure box
			// this use of /EMBEDDED is not related to OLE
			
			//??if (!rCmdInfo.m_bRunEmbedded)
			//??{
			//??	if (bUnregistered)
			//??		AfxMessageBox(AFX_IDP_UNREG_DONE);
			//??	else
			//??		AfxMessageBox(AFX_IDP_UNREG_FAILURE);
			//??}
		//??	bResult = FALSE;    // that's all we do
			
			// If nobody is using it already, we can use it.
			// We'll flag that we're unregistering and not save our state
			// on the way out. This new object gets deleted by the
			// app object destructor.
			
			//??if (m_pCmdInfo == NULL)
			//??{
			//??	m_pCmdInfo = new CCommandLineInfo;
			//??	m_pCmdInfo->m_nShellCommand = CCommandLineInfo::AppUnregister;
			//??}
		//??}
		//??break;
	}
	
	return bResult;
}

void CWinApp::AddEventHandle(int objID, EventFun fun, int eventType)
{
	CCmdTEHData			*p_mapEventHandle = &(m_mapEventHandle);
	CCmdTargetEventHandle handle;

	handle.tag			= objID;
	handle.fun			= fun;
	handle.eventType	= eventType;
	handle.control		= this;

	p_mapEventHandle->push_back(handle);
}

void CWinApp::AddEventRangeHandle(int objID1, int objID2, EventFun fun, int eventType)
{
	NSLog(@"TO DO CWinApp::AddEventRangeHandle(int objID1, int objID2, EventFun fun, int eventType)");
}

void CWinApp::AddEventHandle(void *obj, EventFun fun, int eventType)
{
	AddEventHandle([(NSView *)obj tag], fun, eventType);
}

void CWinApp::OnFileNew()
{
	//NSLog(@"TO DO CWinApp::OnFileNew");
	//??if (m_pDocManager != NULL)
	//??	m_pDocManager->OnFileNew();
	
	CDocTemplate* pTemplate = NULL;
	
	if (m_arrDocTemplate.size() > 1)//??need choose
	{
		NSLog(@"TO DO CWinApp::OnFileNew");
		
		//choose template
		// more than one document template to choose from
		// bring up dialog prompting user
		//CNewTypeDlg dlg(&m_templateList);
		//INT_PTR nID = dlg.DoModal();
		//if (nID == IDOK)
		///	pTemplate = dlg.m_pSelectedTemplate;
		//else
		//	return;     // none - cancel operation
	}
	else 
	{
		pTemplate = m_arrDocTemplate[0];
	}
	
	if (!pTemplate->OpenDocumentFile(NULL))
	{
		//bResult = FALSE;
	}
}

void CWinApp::OnFileOpen()
{
	NSLog(@"TO DO CWinApp::OnFileOpen");
}

void CWinApp::OnFilePrintSetup()
{
	NSLog(@"TO DO CWinApp::OnFilePrintSetup");
}

BOOL CWinApp::OnIdle(LONG lCount)
{
	NSLog(@"TO DO CWinApp::OnIdle");
}

void CWinApp::OnHelp()
{
	NSLog(@"TO DO CWinApp::OnHelp");
}

void CWinApp::AddDocTemplate(CDocTemplate* pTemplate)
{
	m_arrDocTemplate.push_back(pTemplate);
}

POSITION CWinApp::GetFirstDocTemplatePosition( ) const
{
	return (POSITION)-1;
}

CDocTemplate *CWinApp::GetNextDocTemplate(POSITION& pos ) const
{
	CDocTemplate *doc = (CDocTemplate *)pos;
	
	if ((long)doc == -1)
	{
		if (m_arrDocTemplate.size())
		{
			return *(m_arrDocTemplate.begin());
		}
		
		return 0;
	}
	
	for (std::vector<CDocTemplate *>::const_iterator it = m_arrDocTemplate.begin() ; it != m_arrDocTemplate.end(); ++it)
	{
		if (*it == doc)
		{
			if (it++ != m_arrDocTemplate.end())
			{
				return *(it++);
			}
			
			break; 
		}
	}
	
	return 0;
}

void CWinApp::CloseAllDocuments(BOOL bEndSession)
{
	NSLog(@"TO DO CWinApp::CloseAllDocuments");
}

CWinApp* AfxGetApp()
{
	return pMainApp;
}

void InitCommonControls(void)
{

}

void AfxEnableControlContainer()
{

}

CWnd* AfxGetMainWnd()
{
	return AfxGetApp()->m_pMainWnd;
}

int AfxMessageBox(LPCTSTR lpszText, UINT nType, UINT nIDHelp)
{
	int res = IDCANCEL;
	NSAlert *alert = nil;
	
	if (nType & (MB_DEFBUTTON1 | MB_DEFBUTTON2 | MB_DEFBUTTON3 | MB_DEFBUTTON4))
	{
		NSLog(@"TO DO AfxMessageBox not support MB_DEFBUTTON1 | MB_DEFBUTTON2 | MB_DEFBUTTON3 | MB_DEFBUTTON4");
	}
	
	if (nType & (MB_APPLMODAL | MB_SYSTEMMODAL | MB_TASKMODAL | MB_DEFAULT_DESKTOP_ONLY))
	{
		NSLog(@"TO DO AfxMessageBox not support MB_APPLMODAL | MB_SYSTEMMODAL | MB_TASKMODAL | MB_DEFAULT_DESKTOP_ONLY");
	}
	
	if (nType & (MB_RIGHT | MB_SETFOREGROUND))
	{
		NSLog(@"TO DO AfxMessageBox not support MB_RIGHT | MB_SETFOREGROUND");
	}			
	
	if (nType & MB_OK)
	{
		alert =[NSAlert alertWithMessageText:[NSString stringWithUTF8String: lpszText] 
						defaultButton:@"OK"
					  alternateButton:nil 
						  otherButton:nil
			informativeTextWithFormat:@""];
	}
	else 
	if (nType & MB_OKCANCEL)
	{
		alert =[NSAlert alertWithMessageText:[NSString stringWithUTF8String: lpszText] 
							   defaultButton:@"OK"
							 alternateButton:@"Cancel" 
								 otherButton:nil
				   informativeTextWithFormat:@""];
	}
	else 
	if (nType & MB_RETRYCANCEL)
	{
		alert =[NSAlert alertWithMessageText:[NSString stringWithUTF8String: lpszText] 
							   defaultButton:@"Retry"
							 alternateButton:@"Cancel" 
								 otherButton:nil
				   informativeTextWithFormat:@""];
	}
	else 
	if (nType & MB_YESNO)
	{
		alert =[NSAlert alertWithMessageText:[NSString stringWithUTF8String: lpszText] 
							   defaultButton:@"Yes"
							 alternateButton:@"No" 
								 otherButton:nil
				   informativeTextWithFormat:@""];
	}
	else 
	if (nType & MB_YESNOCANCEL)
	{
		alert =[NSAlert alertWithMessageText:[NSString stringWithUTF8String: lpszText] 
							   defaultButton:@"Yes"
							 alternateButton:@"No" 
								 otherButton:@"Cancel"
				   informativeTextWithFormat:@""];
	}
	else 
	if (nType & MB_ABORTRETRYIGNORE)
	{
		alert =[NSAlert alertWithMessageText:[NSString stringWithUTF8String: lpszText] 
							   defaultButton:@"Abort"
							 alternateButton:@"Retry" 
								 otherButton:@"Ignore"
				   informativeTextWithFormat:@""];
	}
	else 
	if (nType & MB_CANCELTRYCONTINUE)
	{
		alert =[NSAlert alertWithMessageText:[NSString stringWithUTF8String: lpszText] 
							   defaultButton:@"Cancel"
							 alternateButton:@"Try Again" 
								 otherButton:@"Continue"
				   informativeTextWithFormat:@""];
	}
	else 
	{
		alert =[NSAlert alertWithMessageText:[NSString stringWithUTF8String: lpszText] 
							   defaultButton:@"OK"
							 alternateButton:nil 
								 otherButton:nil
				   informativeTextWithFormat:@""];	
	}
	
	if (alert)
	{
		NSInteger result;
		
		if (nType & MB_ICONEXCLAMATION)
		{
			[alert setAlertStyle: NSWarningAlertStyle];
		}
		else
		if (nType & MB_ICONWARNING)
		{
			[alert setAlertStyle: NSWarningAlertStyle];
		}
		else
		if (nType & MB_ICONINFORMATION)
		{
			[alert setAlertStyle: NSInformationalAlertStyle];
		}
		else
		if (nType & MB_ICONASTERISK)
		{
			[alert setAlertStyle: NSInformationalAlertStyle];
		}
		else
		if (nType & MB_ICONQUESTION)
		{
			[alert setAlertStyle: NSInformationalAlertStyle];
		}
		else
		if (nType & MB_ICONSTOP)
		{
			[alert setAlertStyle: NSCriticalAlertStyle];
		}
		else
		if (nType & MB_ICONERROR)
		{
			[alert setAlertStyle: NSCriticalAlertStyle];
		}
		else
		if (nType & MB_ICONHAND)
		{
			[alert setAlertStyle: NSCriticalAlertStyle];
		}

		result = [alert runModal];
		
		if (nType & MB_OK)
		{
			res =  IDOK;
		}
		else 
		if (nType & MB_OKCANCEL)
		{
			res =  IDCANCEL;
			
			if (result == NSAlertDefaultReturn)
			{
				res =  IDOK;
			}
		}
		else 
		if (nType & MB_RETRYCANCEL)
		{
			res =  IDRETRY;
			
			if (result == NSAlertDefaultReturn)
			{
				res =  IDCANCEL;
			}
		}
		else 
		if (nType & MB_YESNO)
		{
			res =  IDNO;
			
			if (result == NSAlertDefaultReturn)
			{
				res =  IDYES;
			}
		}
		else 
		if (nType & MB_YESNOCANCEL)
		{
			res =  IDCANCEL;
			
			if (result == NSAlertDefaultReturn)
			{
				res =  IDYES;
			}
			else 
			if (result == NSAlertAlternateReturn)
			{
				res =  IDNO;
			}
		}
		else 
		if (nType & MB_ABORTRETRYIGNORE)
		{
			res =  IDIGNORE;
			
			if (result == NSAlertDefaultReturn)
			{
				res =  IDABORT;
			}
			else 
			if (result == NSAlertAlternateReturn)
			{
				res =  IDRETRY;
			}
		}
		else 
		if (nType & MB_CANCELTRYCONTINUE)
		{
			res =  IDCONTINUE;
			
			if (result == NSAlertDefaultReturn)
			{
				res =  IDCANCEL;
			}
			else 
			if (result == NSAlertAlternateReturn)
			{
				res =  IDTRYAGAIN;
			}
		}
	}
	
	return res;
}

BOOL CWinApp::LoadBitmapInfo()
{
	if (g_mapBitmapInfo.size() == 0)
	{		
		NSBundle *resBundle = [NSBundle mainBundle];
		
		if (resBundle)
		{
			NSString *resFilePath = [resBundle pathForResource: @"Resources" ofType:@"xml"];
			
			if (resFilePath)
			{
				NSError *error = nil;
				NSXMLDocument *doc = [[NSXMLDocument alloc] initWithData:[NSData dataWithContentsOfFile: resFilePath] options:NSXMLDocumentTidyXML error:&error];
				
				if (doc)
				{
					//<MFC_RESOURCE>
					//<BITMAPTABLE>
					//<BITMAP IDSTR="IDB_BITMAP1" ID="130" NAME="bitmap1.bmp"/>
					//</BITMAPTABLE>>
					
					NSString *xpath = [NSString stringWithFormat: @"/MFC_RESOURCE/BITMAPTABLE/BITMAP"];
					NSArray *arrWindowsNode = [doc nodesForXPath:xpath error:&error];
					
					for(int i = 0; i < [arrWindowsNode count]; i++)
					{
						NSXMLElement *StrNode = [arrWindowsNode objectAtIndex:i];	
						
						NSXMLNode *attrID = [StrNode attributeForName: @"ID"];
						NSXMLNode *attrIDSTR = [StrNode attributeForName: @"IDSTR"];
						NSXMLNode *attrNAME = [StrNode attributeForName: @"NAME"];
						int ID = -1;
						
						if (attrID)
						{
							ID = [[attrID stringValue] intValue];
						}
						
						if (ID != -1)
						{
							CShellBitmapInfo info;
							
							info.name = [[attrNAME stringValue] UTF8String];
							info.idstr = [[attrIDSTR stringValue] UTF8String];
							
							g_mapBitmapInfo[ID] = info;
						}
					}
					
					[doc dealloc];
				}
				else 
				{
					assert(false);
				}
			}
			else 
			{
				assert(false);
			}
		}
		else 
		{
			assert(false);
		}
		
	}
	
	return g_mapBitmapInfo.size();
}

std::map<int,CShellBitmapInfo> &CWinApp::GetBitmapInfoMap()
{
	return g_mapBitmapInfo;
}

HKEY CWinApp::GetAppRegistryKey()
{
	NSBundle *bundle = [NSBundle mainBundle];
	
	if (bundle)
	{
		NSString *str = [bundle bundleIdentifier];
		
		return createNSKey([str UTF8String]);
	}
	
	return HKEY_CURRENT_USER;
}

BOOL CWinApp::LoadIconInfo()
{
	if (g_mapIconInfo.size() == 0)
	{		
		NSBundle *resBundle = [NSBundle mainBundle];
		
		if (resBundle)
		{
			NSString *resFilePath = [resBundle pathForResource: @"Resources" ofType:@"xml"];
			
			if (resFilePath)
			{
				NSError *error = nil;
				NSXMLDocument *doc = [[NSXMLDocument alloc] initWithData:[NSData dataWithContentsOfFile: resFilePath] options:NSXMLDocumentTidyXML error:&error];
				
				if (doc)
				{
					//<MFC_RESOURCE>
					//<BITMAPTABLE>
					//<BITMAP IDSTR="IDB_BITMAP1" ID="130" NAME="bitmap1.bmp"/>
					//</BITMAPTABLE>>
					
					NSString *xpath = [NSString stringWithFormat: @"/MFC_RESOURCE/ICONTABLE/ICON"];
					NSArray *arrWindowsNode = [doc nodesForXPath:xpath error:&error];
					
					for(int i = 0; i < [arrWindowsNode count]; i++)
					{
						NSXMLElement *StrNode = [arrWindowsNode objectAtIndex:i];	
						
						NSXMLNode *attrID = [StrNode attributeForName: @"ID"];
						NSXMLNode *attrIDSTR = [StrNode attributeForName: @"IDSTR"];
						NSXMLNode *attrNAME = [StrNode attributeForName: @"NAME"];
						int ID = -1;
						
						if (attrID)
						{
							ID = [[attrID stringValue] intValue];
						}
						
						if (ID != -1)
						{
							CShellBitmapInfo info;
							
							info.name = [[attrNAME stringValue] UTF8String];
							info.idstr = [[attrIDSTR stringValue] UTF8String];
							
							g_mapIconInfo[ID] = info;
						}
					}
					
					[doc dealloc];
				}
				else 
				{
					assert(false);
				}
			}
			else 
			{
				assert(false);
			}
		}
		else 
		{
			assert(false);
		}
		
	}
	
	return g_mapIconInfo.size();
}

std::map<int,CShellBitmapInfo> &CWinApp::GetIconInfoMap()
{
	return g_mapIconInfo;
}

BOOL CWinApp::OnDDECommand(LPTSTR lpszCommand )
{
	NSLog(@"to do CWinApp::OnDDECommand");
	
	return 0;
}

int CWinApp::ExitInstance()
{
	NSLog(@"to do CWinApp::ExitInstance");
	
	return 0;
}

CDocument* CWinApp::OpenDocumentFile(LPCTSTR lpszFileName)
{
	NSLog(@"to do CWinApp::OpenDocumentFile");
	
	return 0;
}

BOOL CWinApp::SaveAllModified()
{
	NSLog(@"to do CWinApp::SaveAllModified");
	
	return FALSE;
}

int CWinApp::Run()
{
	NSLog(@"to do CWinApp::Run");
	
	return 0;
}

int AfxMessageBox(UINT nIDPrompt, UINT nType, UINT nIDHelp)
{
	CString msg;
	
	msg.LoadString(nIDPrompt);
	
	AfxMessageBox(msg, nType, nIDHelp);
	
	return MB_OKCANCEL;
}

void CShellLog(const char *str)
{
	NSLog([NSString stringWithUTF8String: str]);
}



