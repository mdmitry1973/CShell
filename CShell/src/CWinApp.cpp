/*
 *  CWinApp.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/26/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include <QDebug>
#include <QCoreApplication>
#include <QtWidgets/QMessageBox>

#include "CDef.h"
#include "CWnd.h"
#include "CDocTemplate.h"

#include "CWinApp.h"

std::map<int, CShellBitmapInfo> g_mapBitmapInfo;
std::map<int, CShellBitmapInfo> g_mapIconInfo;

CSHELL_LIB_EXPORT CWinApp *pMainApp = NULL;

CWinApp::CWinApp()
{
    pMainApp = this;
    m_pszAppName = wcsdup(_T(""));
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
    /*
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
    */

    return 0;
}

void CWinApp::EnableShellOpen()
{
	qDebug() << "TO DO CWinApp::EnableShellOpen";
}

void CWinApp::RegisterShellFileTypes(BOOL bCompat)
{
	qDebug() << "TO DO CWinApp::RegisterShellFileTypes";
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
    qDebug() << "TO DO CWinApp::SetRegistryKey";
}

void CWinApp::SetRegistryKey(UINT nIDRegistryKey)
{
    qDebug() << "TO DO CWinApp::SetRegistryKey";
}

void CWinApp::LoadStdProfileSettings(UINT nMaxMRU)
{
    qDebug() << "TO DO CWinApp::LoadStdProfileSettings";
}

void CWinApp::ParseCommandLine(CCommandLineInfo& rCmdInfo)
{
    QStringList cmdline_args = QCoreApplication::arguments();
	
    for(int i = 0; i < cmdline_args.size(); i++)
	{
        QString str = cmdline_args[i];
		BOOL bFlag = FALSE;
		
		if (i != 0)
		{
            if (str.startsWith("/") ||
                str.startsWith("-"))
			{
				bFlag = TRUE;
                str = str.mid(1);
			}
		}
		
        rCmdInfo.ParseParam((const char *)str.unicode(), bFlag, i == (cmdline_args.size() - 1));
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
    qDebug() << "TO DO CWinApp::AddEventRangeHandle(int objID1, int objID2, EventFun fun, int eventType)";
}

void CWinApp::AddEventHandle(void *obj, EventFun fun, int eventType)
{
    //AddEventHandle([(NSView *)obj tag], fun, eventType);
}

void CWinApp::OnFileNew()
{
	//NSLog(@"TO DO CWinApp::OnFileNew");
	//??if (m_pDocManager != NULL)
	//??	m_pDocManager->OnFileNew();
	
	CDocTemplate* pTemplate = NULL;
	
	if (m_arrDocTemplate.size() > 1)//??need choose
	{
        qDebug() << "TO DO CWinApp::OnFileNew";
		
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
    qDebug() << "TO DO CWinApp::OnFileOpen";
}

void CWinApp::OnFilePrintSetup()
{
    qDebug() << "TO DO CWinApp::OnFilePrintSetup";
}

BOOL CWinApp::OnIdle(LONG lCount)
{
    qDebug() << "TO DO CWinApp::OnIdle";
}

void CWinApp::OnHelp()
{
    qDebug() << "TO DO CWinApp::OnHelp";
}

void CWinApp::AddDocTemplate(CDocTemplate* pTemplate)
{
	m_arrDocTemplate.push_back(pTemplate);
}

POSITION CWinApp::GetFirstDocTemplatePosition( ) const
{
    qDebug() << "TO DO CWinApp::GetFirstDocTemplatePosition";
}

CDocTemplate *CWinApp::GetNextDocTemplate(POSITION& pos ) const
{
    qDebug() << "TO DO CWinApp::GetNextDocTemplate";
}

void CWinApp::CloseAllDocuments(BOOL bEndSession)
{
    qDebug() << "TO DO CWinApp::CloseAllDocuments";
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

CSHELL_LIB_EXPORT int AfxMessageBox(LPCTSTR lpszText, UINT nType, UINT nIDHelp)
{
	int res = IDCANCEL;
    QMessageBox msgBox;
	
	if (nType & (MB_DEFBUTTON1 | MB_DEFBUTTON2 | MB_DEFBUTTON3 | MB_DEFBUTTON4))
	{
        qDebug() << "TO DO AfxMessageBox not support MB_DEFBUTTON1 | MB_DEFBUTTON2 | MB_DEFBUTTON3 | MB_DEFBUTTON4";
	}
	
	if (nType & (MB_APPLMODAL | MB_SYSTEMMODAL | MB_TASKMODAL | MB_DEFAULT_DESKTOP_ONLY))
	{
        qDebug() << "TO DO AfxMessageBox not support MB_APPLMODAL | MB_SYSTEMMODAL | MB_TASKMODAL | MB_DEFAULT_DESKTOP_ONLY";
	}
	
	if (nType & (MB_RIGHT | MB_SETFOREGROUND))
	{
        qDebug() << "TO DO AfxMessageBox not support MB_RIGHT | MB_SETFOREGROUND";
    }

    QMessageBox::StandardButtons messageType = QMessageBox::Ok;
    QMessageBox::Icon icon_id = QMessageBox::NoIcon;

	if (nType & MB_OK)
	{
        messageType = messageType | QMessageBox::Ok;
	}
	else 
	if (nType & MB_OKCANCEL)
	{
        messageType = messageType | QMessageBox::Cancel | QMessageBox::Ok;
	}
	else 
	if (nType & MB_RETRYCANCEL)
	{
        messageType = messageType | QMessageBox::Cancel | QMessageBox::Retry;
	}
	else 
	if (nType & MB_YESNO)
	{
        messageType = messageType | QMessageBox::Yes | QMessageBox::No;
	}
	else 
	if (nType & MB_YESNOCANCEL)
	{
        messageType = messageType | QMessageBox::Cancel | QMessageBox::Yes;
	}
	else 
	if (nType & MB_ABORTRETRYIGNORE)
	{
        messageType = messageType | QMessageBox::Ignore | QMessageBox::Retry | QMessageBox::Abort;
	}
	else 
	if (nType & MB_CANCELTRYCONTINUE)
	{
        messageType = messageType | QMessageBox::Cancel | QMessageBox::Retry;
        msgBox.addButton("Continue", QMessageBox::AcceptRole);
    }

    if (nType & MB_ICONEXCLAMATION)
    {
        icon_id = QMessageBox::Warning;
    }
    else
    if (nType & MB_ICONWARNING)
    {
        icon_id = QMessageBox::Warning;
    }
    else
    if (nType & MB_ICONINFORMATION)
    {
        icon_id = QMessageBox::Information;
    }
    else
    if (nType & MB_ICONASTERISK)
    {
        icon_id = QMessageBox::Information;
    }
    else
    if (nType & MB_ICONQUESTION)
    {
        icon_id = QMessageBox::Question;
    }
    else
    if (nType & MB_ICONSTOP)
    {
        icon_id = QMessageBox::Critical;
    }
    else
    if (nType & MB_ICONERROR)
    {
        icon_id = QMessageBox::Critical;
    }
    else
    if (nType & MB_ICONHAND)
    {
        icon_id = QMessageBox::Critical;
    }

    msgBox.setText(QString::fromWCharArray(lpszText));
   // msgBox.setInformativeText(lpszText);
    msgBox.setStandardButtons(messageType);
    msgBox.setDefaultButton(QMessageBox::Save);
    msgBox.setIcon(icon_id);
    int result = msgBox.exec();
	
    if (nType & MB_OK)
    {
        res =  IDOK;
    }
    else
    if (nType & MB_OKCANCEL)
    {
        res =  IDCANCEL;

        if (result == QMessageBox::Ok)
        {
            res =  IDOK;
        }
    }
    else
    if (nType & MB_RETRYCANCEL)
    {
        res =  IDRETRY;

        if (result == QMessageBox::Cancel)
        {
            res =  IDCANCEL;
        }
    }
    else
    if (nType & MB_YESNO)
    {
        res =  IDNO;

        if (result == QMessageBox::Yes)
        {
            res =  IDYES;
        }
    }
    else
    if (nType & MB_YESNOCANCEL)
    {
        res =  IDCANCEL;

        if (result == QMessageBox::Yes)
        {
            res =  IDYES;
        }
        else
        if (result == QMessageBox::No)
        {
            res =  IDNO;
        }
    }
    else
    if (nType & MB_ABORTRETRYIGNORE)
    {
        res =  IDIGNORE;

        if (result == QMessageBox::Abort)
        {
            res =  IDABORT;
        }
        else
        if (result == QMessageBox::Retry)
        {
            res =  IDRETRY;
        }
    }
    else
    if (nType & MB_CANCELTRYCONTINUE)
    {
        res =  IDCONTINUE;

        if (result == QMessageBox::Cancel)
        {
            res =  IDCANCEL;
        }
        else
        if (result == QMessageBox::Retry)
        {
            res =  IDTRYAGAIN;
        }
    }
	
	return res;
}

BOOL CWinApp::LoadBitmapInfo()
{
    /*
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
    */

    return 0;
}

std::map<int,CShellBitmapInfo> &CWinApp::GetBitmapInfoMap()
{
	return g_mapBitmapInfo;
}

HKEY CWinApp::GetAppRegistryKey()
{
	
}

BOOL CWinApp::LoadIconInfo()
{
    /*
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
    */
    return 0;
}

std::map<int,CShellBitmapInfo> &CWinApp::GetIconInfoMap()
{
	return g_mapIconInfo;
}

BOOL CWinApp::OnDDECommand(LPTSTR lpszCommand )
{
    qDebug() << "to do CWinApp::OnDDECommand";
	
	return 0;
}

int CWinApp::ExitInstance()
{
    qDebug() << "to do CWinApp::ExitInstance";
	
	return 0;
}

CDocument* CWinApp::OpenDocumentFile(LPCTSTR lpszFileName)
{
    qDebug() << "to do CWinApp::OpenDocumentFile";
	
	return 0;
}

BOOL CWinApp::SaveAllModified()
{
    qDebug() << "to do CWinApp::SaveAllModified";
	
	return FALSE;
}

int CWinApp::Run()
{
    qDebug() << "to do CWinApp::Run";
	
	return 0;
}

CSHELL_LIB_EXPORT int AfxMessageBox(UINT nIDPrompt, UINT nType, UINT nIDHelp)
{
	CString msg;
	
	msg.LoadString(nIDPrompt);
	
	AfxMessageBox(msg, nType, nIDHelp);
	
	return MB_OKCANCEL;
}

void CShellLog(const char *str)
{
    qDebug() << str;
}



