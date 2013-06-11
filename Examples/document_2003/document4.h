// document4.h : main header file for the document4 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols


// Cdocument4App:
// See document4.cpp for the implementation of this class
//

class Cdocument4App : public CWinApp
{
public:
	Cdocument4App();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cdocument4App theApp;