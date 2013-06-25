/*
 *  CWnd.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CWIN_DEFINE
#define CWIN_DEFINE 1

#include <map>
#include <vector>

#include "winuser.h"
#include "CRect.h"
#include "CDC.h"
#include "CObject.h"
#include "CTargetEvent.h"
#include "CDataExchange.h"
#include "CString.h"
#include "CMenu.h"
#include "CFont.h"
#include "CPoint.h"

typedef void* PtrNSWindowController;
typedef void* PtrNSWindow;
typedef void* PtrNSWindowDelegate;
typedef void* PtrNSWindowHandle;
typedef void* PtrNSXMLElement;

class CDC;

#define ON_WM_CHAR() \
AddEventHandle(0, (EventFun)(&ThisClass::OnChar), EVENT_TYPE_WM_CHAR);

#define ON_WM_LBUTTONDOWN() \
AddEventHandle(0, (EventFun)(&ThisClass::OnLButtonDown), EVENT_TYPE_WM_LBUTTONDOWN);

#define ON_WM_KILLFOCUS() \
AddEventHandle(0, (EventFun)(&ThisClass::OnKillFocus), EVENT_TYPE_WM_KILLFOCUS);

#define ON_WM_SETFOCUS() \
AddEventHandle(0, (EventFun)(&ThisClass::OnSetFocus), EVENT_TYPE_WM_SETFOCUS);

#define ON_WM_CREATE()\
AddEventHandle(0, (EventFun)(&ThisClass::OnCreate), EVENT_TYPE_WM_CREATE);

#define ON_WM_CONTEXTMENU()\
AddEventHandle(0, (EventFun)(&ThisClass::OnCreate), EVENT_TYPE_WM_CONTEXTMENU);

#define ON_WM_TIMER()\
AddEventHandle(0, (EventFun)(&ThisClass::OnCreate), EVENT_TYPE_WM_TIMER);

#define ON_WM_SIZE()\
AddEventHandle(0, (EventFun)(&ThisClass::OnCreate), EVENT_TYPE_WM_SIZE);

#define ON_WM_RBUTTONDOWN()\
AddEventHandle(0, (EventFun)(&ThisClass::OnCreate), EVENT_TYPE_WM_RBUTTONDOWN);

#define ON_WM_LBUTTONUP()\
AddEventHandle(0, (EventFun)(&ThisClass::OnCreate), EVENT_TYPE_WM_LBUTTONUP);

#define ON_WM_MOUSEMOVE()\
AddEventHandle(0, (EventFun)(&ThisClass::OnCreate), EVENT_TYPE_WM_MOUSEMOVE);

#define ON_WM_SETCURSOR()\
AddEventHandle(0, (EventFun)(&ThisClass::OnCreate), EVENT_TYPE_WM_SETCURSOR);

#define ON_WM_CREATE()\
AddEventHandle(0, (EventFun)(&ThisClass::OnCreate), EVENT_TYPE_WM_CREATE);

#define ON_WM_ERASEBKGND()\
AddEventHandle(0, (EventFun)(&ThisClass::OnCreate), EVENT_TYPE_WM_ERASEBKGND);

#define ON_WM_KEYDOWN()\
AddEventHandle(0, (EventFun)(&ThisClass::OnCreate), EVENT_TYPE_WM_KEYDOWN);

#define ON_WM_KEYUP()\
AddEventHandle(0, (EventFun)(&ThisClass::OnCreate), EVENT_TYPE_WM_KEYUP);

#define ON_WM_MOUSEWHEEL()\
AddEventHandle(0, (EventFun)(&ThisClass::OnCreate), EVENT_TYPE_WM_MOUSEWHEEL);

#define ON_WM_RBUTTONUP()\
AddEventHandle(0, (EventFun)(&ThisClass::OnCreate), EVENT_TYPE_WM_RBUTTONUP);

#define ON_WM_LBUTTONDBLCLK()\
AddEventHandle(0, (EventFun)(&ThisClass::OnCreate), EVENT_TYPE_WM_LBUTTONDBLCLK);

#define CSHELL_DEF_STANDARD_VAL \
CWnd *mWndParent; \
CWnd *mWnd;

#define CSHELL_DEF_STANDARD_METHOD \
-(void)setParentWnd:(CWnd *)wnd;\
-(void)setWnd:(CWnd *)wnd;\
-(CWnd *)getParentWnd;\
-(CWnd *)getWnd;

#define CSHELL_IMPL_CONTROL_STANDARD_METHOD \
- (void)drawRect:(NSRect)dirtyRect {\
if (mWnd)\
{\
mWnd->SendEventHandle([self tag], self, NM_CUSTOMDRAW);\
}\
[super drawRect: dirtyRect];\
}

#define CSHELL_IMPL_STANDARD_METHOD \
-(void)setParentWnd:(CWnd *)wnd \
{ \
mWndParent = wnd;\
}\
-(void)setWnd:(CWnd *)wnd\
{\
mWnd = wnd;\
}\
-(CWnd *)getParentWnd \
{ \
	return mWndParent;\
}\
-(CWnd *)getWnd\
{\
	return mWnd;\
}

#define CSHELL_IMPL_STANDARD_EVENTS \
- (void)mouseDown:(NSEvent *)theEvent\
{\
	[super mouseDown: theEvent];\
	if (mWnd)\
	{\
		CPoint point;\
		point.x = [theEvent locationInWindow].x;\
		point.y = [theEvent locationInWindow].y;\
		mWnd->OnLButtonDown(MK_LBUTTON, point);\
	}\
}\
- (void)rightMouseDown:(NSEvent *)theEvent\
{\
	[super rightMouseDown: theEvent];\
	if (mWnd)\
	{\
		CPoint point;\
		point.x = [theEvent locationInWindow].x;\
		point.y = [theEvent locationInWindow].y;\
		mWnd->OnRButtonDown(MK_LBUTTON, point);\
	}\
}\
- (void)mouseUp:(NSEvent *)theEvent\
{\
	[super mouseDown: theEvent];\
	if (mWnd)\
	{\
		CPoint point;\
		point.x = [theEvent locationInWindow].x;\
		point.y = [theEvent locationInWindow].y;\
		mWnd->OnLButtonUp(MK_LBUTTON, point);\
	}\
}\
- (void)rightMouseUp:(NSEvent *)theEvent\
{\
	[super rightMouseDown: theEvent];\
	if (mWnd)\
	{\
		CPoint point;\
		point.x = [theEvent locationInWindow].x;\
		point.y = [theEvent locationInWindow].y;\
		mWnd->OnRButtonUp(MK_LBUTTON, point);\
	}\
}

class CSHELL_LIB_EXPORT CWnd : public CCmdTarget
{
	DECLARE_DYNAMIC(CWnd)
	
public:
	
	CWnd();
	
	virtual ~CWnd();
	
	virtual BOOL Create(LPCTSTR lpszClassName, 
						LPCTSTR lpszWindowName,
						DWORD dwStyle,
						const RECT& rect,
						CWnd* pParentWnd,
						UINT nID,
						CCreateContext* pContext = NULL
						);
	
	virtual void DoDataExchange(CDataExchange* pDX);
	
	CMenu* GetSystemMenu(BOOL bRevert);// const;
	
	virtual void DDX_Control(CDataExchange *pDX, int nIDC, CWnd &control);
	virtual void DDX_Radio(CDataExchange* pDX, int nIDC, int& value);
	virtual void DDX_Text(CDataExchange* pDX, int nIDC, CString& value);
	virtual void DDX_CBIndex(CDataExchange *pDX, int nIDC, int &index);
	virtual void DDX_Check(CDataExchange *pDX, int nIDC, BOOL &value);
	virtual	void DDV_MaxChars(CDataExchange* pDX, CString const& value, int nChars);
	
	BOOL UpdateData(BOOL bSaveAndValidate = TRUE);
	
	CWnd* GetDlgItem(int nID);// const;
	
	virtual void SetWindowText(LPCTSTR lpszString );
	virtual int GetWindowText(LPTSTR lpszStringBuf, int nMaxCount) const;
	virtual void GetWindowText(CString& rString ) const;
	
	HICON SetIcon(HICON hIcon, BOOL bBigIcon);
	
	BOOL ModifyStyle(DWORD dwRemove, DWORD dwAdd, UINT nFlags = 0);
	
	CFont* GetFont() const;
	void SetFont(CFont* pFont, BOOL bRedraw = TRUE);
	
	DWORD GetStyle() const;
	
	int GetDlgCtrlID() const;
	
	CWnd* GetParent() const;
	
	void GetWindowRect(LPRECT lpRect) const;
	void GetClientRect(LPRECT lpRect) const;
	
	CWnd* GetFocus();
	CWnd* SetFocus();
	
	virtual BOOL ShowWindow(int nCmdShow);
	virtual BOOL EnableWindow(BOOL bEnable = TRUE);
	
	BOOL IsIconic() const;
	
	BOOL SetWindowPos(const CWnd* pWndInsertAfter, int x, int y, int cx, int cy, UINT nFlags);
	void ScreenToClient(LPPOINT lpPoint) const;
	void ScreenToClient(LPRECT lpRect) const;
	void MoveWindow(int x, int y, int nWidth, int nHeight, BOOL bRepaint = TRUE);
	void MoveWindow(LPCRECT lpRect, BOOL bRepaint = TRUE);
	
	LRESULT SendMessage(UINT message, WPARAM wParam = 0,LPARAM lParam = 0);
	BOOL PostMessage(UINT message, WPARAM wParam = 0, LPARAM lParam = 0);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual void PreSubclassWindow();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	
	void UpdateWindow();
	
	int MessageBox(LPCTSTR lpszText, LPCTSTR lpszCaption = NULL, UINT nType = MB_OK);
	
	BOOL SetMenu(CMenu* pMenu);	
	
	void DrawMenuBar();
	
	void DragAcceptFiles(BOOL bAccept = TRUE);
	BOOL SetWindowPlacement(const WINDOWPLACEMENT*lpwndpl); 
	
	CDC* GetDC();
	
	UINT_PTR SetTimer(UINT_PTR nIDEvent, UINT nElapse, void (* lpfnTimer)(HWND, UINT, UINT_PTR, DWORD));
	BOOL KillTimer(UINT_PTR nIDEvent);
	
	BOOL EnableToolTips(BOOL bEnable = TRUE);
	
	void Invalidate(BOOL bErase = TRUE);
	void InvalidateRect(LPCRECT lpRect, BOOL bErase = TRUE);
	
	//mfc dialog
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	virtual void OnTimer(UINT nIDEvent);
	
	virtual void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual void OnLButtonDown(UINT nFlags, CPoint point);
	virtual void OnRButtonDown(UINT nFlags, CPoint point);
	virtual void OnLButtonUp(UINT nFlags, CPoint point);
	virtual void OnRButtonUp(UINT nFlags, CPoint point);
	virtual void OnKillFocus(CWnd* pNewWnd);
	virtual void OnSetFocus(CWnd* pOldWnd);
	virtual void OnPaint();
	virtual int	OnCreate(LPCREATESTRUCT lpCreateStruct);
	
	virtual void OnSysCommand(UINT nID, LPARAM lParam);
	
	//not mfc methods
	BOOL CreatFromResFile(UINT nIDTemplate, BOOL bView, CWnd *parentWnd = NULL);
	BOOL CreatFromResFile(LPCTSTR lpszTemplateName, BOOL bView, CWnd *parentWnd = NULL);
	
	virtual void AddEventHandle(int objID, EventFun fun, int eventType);
	virtual void AddEventRangeHandle(int objID1, int objID2, EventFun fun, int eventType);
	virtual void AddEventHandle(void *obj, EventFun fun, int eventType);
	virtual void FinaleSetup();
	
	bool CreateButton(PtrNSXMLElement controlNode, void *nsView);
	bool CreateStaticText(PtrNSXMLElement controlNode, void *nsView);
	bool CreateComboBox(PtrNSXMLElement controlNode, void *nsView);
	bool CreateControl(PtrNSXMLElement controlNode, void *nsView);
	bool CreateGroupBox(PtrNSXMLElement controlNode, void *nsView);
	bool CreateEditText(PtrNSXMLElement controlNode, void *nsView);									
	bool CreateListBox(PtrNSXMLElement controlNode, void *nsView);
	
	PtrNSWindow GetControlByIDC(int IDC);
	
	BOOL InitControl(int nIDC, CWnd *win);
	
	virtual BOOL IsDialog();
	
	PtrNSWindowDelegate GetWindowDelegate();
	PtrNSWindow			GetNSWindow();
	
	//static CMenu* GetMenu(CWnd *);
	
	static CWnd wndBottom;
	static CWnd wndTop;
	static CWnd wndTopMost;
	static CWnd wndNoTopMost;
	
protected:
	
	PtrNSWindowController	mWindowController;
	PtrNSWindow				m_hWnd;
	PtrNSWindowDelegate		mWindowDelegate;
	PtrNSWindowHandle		mWindowHandle;	
	
	CDataExchange			mDX;
	
	CWnd					*mParentWin;
	
	BOOL					mMainWindow;
	BOOL					mFinished;
	
	CMenu					mMenu;
	
	std::map<int, CWnd*>		mMapControls;
	
	CString			mCaptionStr;
	
	std::vector<void*> mTimerArr;
};



#endif//CWIN_DEFINE