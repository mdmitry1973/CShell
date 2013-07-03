/*
 *  afxwin.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef AFX_WIN
#define AFX_WIN 1

#define __AFXWIN_H__

#include "CDef.h"
#include <algorithm>
#include "afxext.h"
#ifndef Q_CC_MINGW
#include "windows.h"
#endif
#include "CDumpContext.h"
#include "CSize.h"
#include "CPoint.h"
#include "CRect.h"
#include "CStringArray.h"
#include "CArray.h"
#include "CException.h"
#include "CFileException.h"
#include "CTime.h"
#include "CFile.h"
#include "CFileFind.h"
#include "CMemFile.h"
#include "CWnd.h"
#include "CDC.h"
#include "CTargetEvent.h"
#include "COleDataObject.h"
#include "CRecentFileList.h"
#include "CWinApp.h"
#include "CButton.h"
#include "CWaitCursor.h"
#include "CComboBox.h"
#include "CStatic.h"
#include "CEdit.h"
#include "CSpinButtonCtrl.h"
#include "CProgressCtrl.h"
#include "CSliderCtrl.h"
#include "CListBox.h"
#include "CTabCtrl.h"
#include "CObArray.h"
#include "CPaintDC.h"
#include "CPropertyPage.h"
#include "CPropertySheet.h"
#include "CFrameWnd.h"
#include "CStatusBar.h"
#include "CToolBar.h"
#include "CDocument.h"
#include "CView.h"
#include "CPrintInfo.h"
#include "CPrintDialog.h"
#include "CDocTemplate.h"
#include "CSingleDocTemplate.h"
#include "CMultiDocTemplate.h"
#include "CCommandLineInfo.h"
#include "CPtrArray.h"
#include "CMapPtrToPtr.h"
#include "CArchiveException.h"
#include "CArchive.h"
#include "CMDIFrameWnd.h"
#include "CDockState.h"
#include "CCmdUI.h"
#include "CPen.h"
#include "CBrush.h"
#include "CImageList.h"
#include "CTreeCtrl.h"
#include "CToolTipCtrl.h"
#include "CScrollView.h"
#include "CDocItem.h"
#include "COleDropTarget.h"
#include "CDocObjectServer.h"
#include "COleServerItem.h"
#include "CRuntimeClass.h"
#include "CPreviewView.h"
#include "COleServerDoc.h"
#include "CObList.h"
#include "COleTemplateServer.h"
#include "CStringList.h"
#include "CBitmap.h"
#include "COleResizeBar.h"
#include "COleDocIPFrameWnd.h"
#include "CToolBarCtrl.h"
#include "CMDIChildWnd.h"
#include "COleMessageFilter.h"
#include "COleIPFrameWnd.h"
#include "COleClientItem.h"
#include "CDocObjectServerItem.h"
#include "COleDataSource.h"
#include "CTypedPtrArray.h"
#include "CWinThread.h"
#include "CFileDialog.h"
#include "CSingleLock.h"
#include "COleDocument.h"
#include "CDocManager.h"
#include "CMFCMenuBar.h"
#include "CMFCToolBarImages.h"
#include "CPalette.h"
#include "CRgn.h"
#include "CPreviewDC.h"
#include "CMutex.h"
#include "CScrollBar.h"

CSHELL_LIB_EXPORT int AfxMessageBox(LPCTSTR lpszText, UINT nType = MB_OK, UINT nIDHelp = 0 );
CSHELL_LIB_EXPORT int AfxMessageBox(UINT nIDPrompt, UINT nType = MB_OK, UINT nIDHelp = (UINT)-1);

#endif//AFX_WIN
