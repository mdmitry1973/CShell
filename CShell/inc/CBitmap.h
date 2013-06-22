/*
 *  CBitmap.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CBITMAP_DEFINE
#define CBITMAP_DEFINE 1

#include "CDef.h"

#include "CSize.h"
#include "wingdi.h"

class CBitmap
{

public:
	
	CBitmap();
	virtual ~CBitmap();
	
	BOOL LoadBitmap(LPCTSTR lpszResourceName);
	BOOL LoadBitmap(UINT nIDResource);
	BOOL LoadOEMBitmap(UINT nIDBitmap); // for OBM_/OCR_/OIC_
	
	BOOL CreateBitmap(int nWidth, int nHeight, UINT nPlanes, UINT nBitcount, const void* lpBits);
	
	BOOL Attach(HGDIOBJ hObject);
	HGDIOBJ Detach();
	
	operator HBITMAP() const;
	int GetBitmap(BITMAP* pBitMap);
	
	// Operations
	DWORD SetBitmapBits(DWORD dwCount, const void* lpBits);
	DWORD GetBitmapBits(DWORD dwCount, LPVOID lpBits) const;
	CSize SetBitmapDimension(int nWidth, int nHeight);
	CSize GetBitmapDimension() const;
	
};

#endif//CBITMAP_DEFINE