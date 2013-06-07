/*
 *  CDC.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CDC_DEFINE
#define CDC_DEFINE 1

#include "CDef.h"
#include "windows.h"
#include "CObject.h"
#include "CWnd.h"
#include "CBrush.h"
#include "CPen.h"
#include "CFont.h"
#include "CSize.h"
#include "CPoint.h"
#include "CBitmap.h"

class CWnd;

class CDC : public CObject
{
	
public:
	
	CDC();
	virtual ~CDC();
	
	HDC m_hAttribDC;
	HDC m_hDC;
	
public:
	
	// Attributes
	//HDC m_hDC;          // The output DC (must be first data member)
	//HDC m_hAttribDC;    // The Attribute DC
	operator HDC() const;
	HDC GetSafeHdc() const; // Always returns the Output DC
	CWnd* GetWindow() const;
	
	static CDC* FromHandle(HDC hDC);
	static void DeleteTempMap();
	BOOL Attach(HDC hDC);   // Attach/Detach affects only the Output DC
	HDC Detach();
	
	virtual void SetAttribDC(HDC hDC);  // Set the Attribute DC
	virtual void SetOutputDC(HDC hDC);  // Set the Output DC
	virtual void ReleaseAttribDC();     // Release the Attribute DC
	virtual void ReleaseOutputDC();     // Release the Output DC
	
	BOOL IsPrinting() const;            // TRUE if being used for printing
	
	CPen* GetCurrentPen() const;
	CBrush* GetCurrentBrush() const;
	//CPalette* GetCurrentPalette() const;
	CFont* GetCurrentFont() const;
	CBitmap* GetCurrentBitmap() const;
	
	// for bidi and mirrored localization
	DWORD GetLayout() const;
	DWORD SetLayout(DWORD dwLayout);
	
	// Constructors
	//CDC();
	BOOL CreateDC(LPCTSTR lpszDriverName, LPCTSTR lpszDeviceName,
				  LPCTSTR lpszOutput, const void* lpInitData);
	BOOL CreateIC(LPCTSTR lpszDriverName, LPCTSTR lpszDeviceName,
				  LPCTSTR lpszOutput, const void* lpInitData);
	BOOL CreateCompatibleDC(CDC* pDC);
	
	BOOL DeleteDC();
	
	// Device-Context Functions
	virtual int SaveDC();
	virtual BOOL RestoreDC(int nSavedDC);
	int GetDeviceCaps(int nIndex) const;
	UINT SetBoundsRect(LPCRECT lpRectBounds, UINT flags);
	UINT GetBoundsRect(LPRECT lpRectBounds, UINT flags);
	//BOOL ResetDC(const DEVMODE* lpDevMode);
	
	// Drawing-Tool Functions
	CPoint GetBrushOrg() const;
	CPoint SetBrushOrg(int x, int y);
	CPoint SetBrushOrg(POINT point);
	int EnumObjects(int nObjectType,
					int (CALLBACK* lpfn)(LPVOID, LPARAM), LPARAM lpData);
	
	// Type-safe selection helpers
public:
	virtual CGdiObject* SelectStockObject(int nIndex);
	CPen* SelectObject(CPen* pPen);
	CBrush* SelectObject(CBrush* pBrush);
	virtual CFont* SelectObject(CFont* pFont);
	CBitmap* SelectObject(CBitmap* pBitmap);
	//int SelectObject(CRgn* pRgn);       // special return for regions
	CGdiObject* SelectObject(CGdiObject* pObject);
	// CGdiObject* provided so compiler doesn't use SelectObject(HGDIOBJ)
	
	// Color and Color Palette Functions
	COLORREF GetNearestColor(COLORREF crColor) const;
	//CPalette* SelectPalette(CPalette* pPalette, BOOL bForceBackground);
	UINT RealizePalette();
	void UpdateColors();
	
	// Drawing-Attribute Functions
	COLORREF GetBkColor() const;
	int GetBkMode() const;
	int GetPolyFillMode() const;
	int GetROP2() const;
	int GetStretchBltMode() const;
	COLORREF GetTextColor() const;
	
	virtual COLORREF SetBkColor(COLORREF crColor);
	int SetBkMode(int nBkMode);
	int SetPolyFillMode(int nPolyFillMode);
	int SetROP2(int nDrawMode);
	int SetStretchBltMode(int nStretchMode);
	virtual COLORREF SetTextColor(COLORREF crColor);
	
	//BOOL GetColorAdjustment(LPCOLORADJUSTMENT lpColorAdjust) const;
	//BOOL SetColorAdjustment(const COLORADJUSTMENT* lpColorAdjust);
	
//#if (_WIN32_WINNT >= 0x0500)
	
	COLORREF GetDCBrushColor() const;
	COLORREF SetDCBrushColor(COLORREF crColor);
	
	COLORREF GetDCPenColor() const;
	COLORREF SetDCPenColor(COLORREF crColor);
	
//#endif
	
	// Graphics mode
	int SetGraphicsMode(int iMode);
	int GetGraphicsMode() const;
	
	// World transform
	//BOOL SetWorldTransform(const XFORM* pXform);
	//BOOL ModifyWorldTransform(const XFORM* pXform,DWORD iMode);
	//BOOL GetWorldTransform(XFORM* pXform) const;
	
	// Mapping Functions
	int GetMapMode() const;
	CPoint GetViewportOrg() const;
	virtual int SetMapMode(int nMapMode);
	// Viewport Origin
	virtual CPoint SetViewportOrg(int x, int y);
	CPoint SetViewportOrg(POINT point);
	virtual CPoint OffsetViewportOrg(int nWidth, int nHeight);
	
	// Viewport Extent
	CSize GetViewportExt() const;
	virtual CSize SetViewportExt(int cx, int cy);
	CSize SetViewportExt(SIZE size);
	virtual CSize ScaleViewportExt(int xNum, int xDenom, int yNum, int yDenom);
	
	// Window Origin
	CPoint GetWindowOrg() const;
	CPoint SetWindowOrg(int x, int y);
	CPoint SetWindowOrg(POINT point);
	CPoint OffsetWindowOrg(int nWidth, int nHeight);
	
	// Window extent
	CSize GetWindowExt() const;
	virtual CSize SetWindowExt(int cx, int cy);
	CSize SetWindowExt(SIZE size);
	virtual CSize ScaleWindowExt(int xNum, int xDenom, int yNum, int yDenom);
	
	// Coordinate Functions
	void DPtoLP(LPPOINT lpPoints, int nCount = 1) const;
	void DPtoLP(LPRECT lpRect) const;
	void DPtoLP(LPSIZE lpSize) const;
	void LPtoDP(LPPOINT lpPoints, int nCount = 1) const;
	void LPtoDP(LPRECT lpRect) const;
	void LPtoDP(LPSIZE lpSize) const;
	
	// Special Coordinate Functions (useful for dealing with metafiles and OLE)
	void DPtoHIMETRIC(LPSIZE lpSize) const;
	void LPtoHIMETRIC(LPSIZE lpSize) const;
	void HIMETRICtoDP(LPSIZE lpSize) const;
	void HIMETRICtoLP(LPSIZE lpSize) const;
	
	// Region Functions
	//BOOL FillRgn(CRgn* pRgn, CBrush* pBrush);
	//BOOL FrameRgn(CRgn* pRgn, CBrush* pBrush, int nWidth, int nHeight);
	//BOOL InvertRgn(CRgn* pRgn);
	//BOOL PaintRgn(CRgn* pRgn);
	
	// Clipping Functions
	virtual int GetClipBox(LPRECT lpRect) const;
	virtual BOOL PtVisible(int x, int y) const;
	BOOL PtVisible(POINT point) const;
	virtual BOOL RectVisible(LPCRECT lpRect) const;
	//int SelectClipRgn(CRgn* pRgn);
	int ExcludeClipRect(int x1, int y1, int x2, int y2);
	int ExcludeClipRect(LPCRECT lpRect);
	//int ExcludeUpdateRgn(CWnd* pWnd);
	int IntersectClipRect(int x1, int y1, int x2, int y2);
	int IntersectClipRect(LPCRECT lpRect);
	//int OffsetClipRgn(int x, int y);
	//int OffsetClipRgn(SIZE size);
	//int SelectClipRgn(CRgn* pRgn, int nMode);
	
	// Line-Output Functions
	CPoint GetCurrentPosition() const;
	CPoint MoveTo(int x, int y);
	CPoint MoveTo(POINT point);
	BOOL LineTo(int x, int y);
	BOOL LineTo(POINT point);
	BOOL Arc(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
	BOOL Arc(LPCRECT lpRect, POINT ptStart, POINT ptEnd);
	BOOL Polyline(const POINT* lpPoints, int nCount);
	
	BOOL AngleArc(int x, int y, int nRadius, float fStartAngle, float fSweepAngle);
	BOOL ArcTo(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
	BOOL ArcTo(LPCRECT lpRect, POINT ptStart, POINT ptEnd);
	int GetArcDirection() const;
	int SetArcDirection(int nArcDirection);
	
	BOOL PolyDraw(const POINT* lpPoints, const BYTE* lpTypes, int nCount);
	BOOL PolylineTo(const POINT* lpPoints, int nCount);
	BOOL PolyPolyline(const POINT* lpPoints,
					  const DWORD* lpPolyPoints, int nCount);
	
	BOOL PolyBezier(const POINT* lpPoints, int nCount);
	BOOL PolyBezierTo(const POINT* lpPoints, int nCount);
	
	// Simple Drawing Functions
	void FillRect(LPCRECT lpRect, CBrush* pBrush);
	void FrameRect(LPCRECT lpRect, CBrush* pBrush);
	void InvertRect(LPCRECT lpRect);
	BOOL DrawIcon(int x, int y, HICON hIcon);
	BOOL DrawIcon(POINT point, HICON hIcon);
	BOOL DrawState(CPoint pt, CSize size, HBITMAP hBitmap, UINT nFlags,
				   HBRUSH hBrush = NULL);
	BOOL DrawState(CPoint pt, CSize size, CBitmap* pBitmap, UINT nFlags,
				   CBrush* pBrush = NULL);
	//BOOL DrawState(CPoint pt, CSize size, HICON hIcon, UINT nFlags,
	//			   HBRUSH hBrush = NULL);
	BOOL DrawState(CPoint pt, CSize size, HICON hIcon, UINT nFlags,
				   CBrush* pBrush = NULL);
	BOOL DrawState(CPoint pt, CSize size, LPCTSTR lpszText, UINT nFlags,
				   BOOL bPrefixText = TRUE, int nTextLen = 0, HBRUSH hBrush = NULL);
	BOOL DrawState(CPoint pt, CSize size, LPCTSTR lpszText, UINT nFlags,
				   BOOL bPrefixText = TRUE, int nTextLen = 0, CBrush* pBrush = NULL);
	//BOOL DrawState(CPoint pt, CSize size, DRAWSTATEPROC lpDrawProc,
	//			   LPARAM lData, UINT nFlags, HBRUSH hBrush = NULL);
	//BOOL DrawState(CPoint pt, CSize size, DRAWSTATEPROC lpDrawProc,
	//			   LPARAM lData, UINT nFlags, CBrush* pBrush = NULL);
	
	// Ellipse and Polygon Functions
	BOOL Chord(int x1, int y1, int x2, int y2, int x3, int y3,
			   int x4, int y4);
	BOOL Chord(LPCRECT lpRect, POINT ptStart, POINT ptEnd);
	void DrawFocusRect(LPCRECT lpRect);
	BOOL Ellipse(int x1, int y1, int x2, int y2);
	BOOL Ellipse(LPCRECT lpRect);
	BOOL Pie(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
	BOOL Pie(LPCRECT lpRect, POINT ptStart, POINT ptEnd);
	BOOL Polygon(const POINT* lpPoints, int nCount);	
	BOOL PolyPolygon(const POINT* lpPoints, const int* lpPolyCounts, int nCount);
	BOOL Rectangle(int x1, int y1, int x2, int y2);
	BOOL Rectangle(LPCRECT lpRect);
	BOOL RoundRect(int x1, int y1, int x2, int y2, int x3, int y3);
	BOOL RoundRect(LPCRECT lpRect, POINT point);
	
	// Bitmap Functions
	BOOL PatBlt(int x, int y, int nWidth, int nHeight, DWORD dwRop);
	BOOL BitBlt(int x, int y, int nWidth, int nHeight, CDC* pSrcDC,
				int xSrc, int ySrc, DWORD dwRop);
	BOOL StretchBlt(int x, int y, int nWidth, int nHeight, CDC* pSrcDC,
					int xSrc, int ySrc, int nSrcWidth, int nSrcHeight, DWORD dwRop);
	COLORREF GetPixel(int x, int y) const;
	COLORREF GetPixel(POINT point) const;
	COLORREF SetPixel(int x, int y, COLORREF crColor);
	COLORREF SetPixel(POINT point, COLORREF crColor);
	BOOL FloodFill(int x, int y, COLORREF crColor);
	BOOL ExtFloodFill(int x, int y, COLORREF crColor, UINT nFillType);
	BOOL MaskBlt(int x, int y, int nWidth, int nHeight, CDC* pSrcDC,
				 int xSrc, int ySrc, CBitmap& maskBitmap, int xMask, int yMask,
				 DWORD dwRop);
	BOOL PlgBlt(LPPOINT lpPoint, CDC* pSrcDC, int xSrc, int ySrc,
				int nWidth, int nHeight, CBitmap& maskBitmap, int xMask, int yMask);
	BOOL SetPixelV(int x, int y, COLORREF crColor);
	BOOL SetPixelV(POINT point, COLORREF crColor);
	//BOOL GradientFill(TRIVERTEX* pVertices, ULONG nVertices, 
	//				  void* pMesh, ULONG nMeshElements, DWORD dwMode);
	BOOL TransparentBlt(int xDest, int yDest, int nDestWidth, int nDestHeight,
						CDC* pSrcDC, int xSrc, int ySrc, int nSrcWidth, int nSrcHeight, 
						UINT clrTransparent);
	//BOOL AlphaBlend(int xDest, int yDest, int nDestWidth, int nDestHeight,
	//				CDC* pSrcDC, int xSrc, int ySrc, int nSrcWidth, int nSrcHeight, 
	//				BLENDFUNCTION blend);
	
	// Text Functions
	virtual BOOL TextOut(int x, int y, LPCTSTR lpszString, int nCount);
	BOOL TextOut(int x, int y, const CString& str);
	virtual BOOL ExtTextOut(int x, int y, UINT nOptions, LPCRECT lpRect,
							LPCTSTR lpszString, UINT nCount, LPINT lpDxWidths);
	BOOL ExtTextOut(int x, int y, UINT nOptions, LPCRECT lpRect,
					const CString& str, LPINT lpDxWidths);
	virtual CSize TabbedTextOut(int x, int y, LPCTSTR lpszString, int nCount,
								int nTabPositions, LPINT lpnTabStopPositions, int nTabOrigin);
	CSize TabbedTextOut(int x, int y, const CString& str,
						int nTabPositions, LPINT lpnTabStopPositions, int nTabOrigin);
	
//#pragma push_macro("DrawText")
//#pragma push_macro("DrawTextEx")
//#undef DrawText
//#undef DrawTextEx
	//virtual int _AFX_FUNCNAME(DrawText)(LPCTSTR lpszString, int nCount, LPRECT lpRect,
	//									UINT nFormat);
	//int _AFX_FUNCNAME(DrawText)(const CString& str, LPRECT lpRect, UINT nFormat);
	//
	//virtual int _AFX_FUNCNAME(DrawTextEx)(LPTSTR lpszString, int nCount, LPRECT lpRect,
	//									  UINT nFormat, LPDRAWTEXTPARAMS lpDTParams);
	//int _AFX_FUNCNAME(DrawTextEx)(const CString& str, LPRECT lpRect, UINT nFormat, LPDRAWTEXTPARAMS lpDTParams);
	//
	int DrawText(LPCTSTR lpszString, int nCount, LPRECT lpRect,
				 UINT nFormat);
	int DrawText(const CString& str, LPRECT lpRect, UINT nFormat);
	
	//int DrawTextEx(LPTSTR lpszString, int nCount, LPRECT lpRect,
	//			   UINT nFormat, LPDRAWTEXTPARAMS lpDTParams);
	//int DrawTextEx(const CString& str, LPRECT lpRect, UINT nFormat, LPDRAWTEXTPARAMS lpDTParams);
//#//pragma pop_macro("DrawText")
//#pragma pop_macro("DrawTextEx")
	
	CSize GetTextExtent(LPCTSTR lpszString, int nCount) const;
	CSize GetTextExtent(const CString& str) const;
	CSize GetOutputTextExtent(LPCTSTR lpszString, int nCount) const;
	CSize GetOutputTextExtent(const CString& str) const;
	CSize GetTabbedTextExtent(LPCTSTR lpszString, int nCount,
							  int nTabPositions, LPINT lpnTabStopPositions) const;
	CSize GetTabbedTextExtent(const CString& str,
							  int nTabPositions, LPINT lpnTabStopPositions) const;
	CSize GetOutputTabbedTextExtent(LPCTSTR lpszString, int nCount,
									int nTabPositions, LPINT lpnTabStopPositions) const;
	CSize GetOutputTabbedTextExtent(const CString& str,
									int nTabPositions, LPINT lpnTabStopPositions) const;
	//virtual BOOL GrayString(CBrush* pBrush,
	////						BOOL (CALLBACK* lpfnOutput)(HDC, LPARAM, int), LPARAM lpData,
	//						int nCount, int x, int y, int nWidth, int nHeight);
	UINT GetTextAlign() const;
	UINT SetTextAlign(UINT nFlags);
	int GetTextFace( int nCount,  LPTSTR lpszFacename) const;
	int GetTextFace(CString& rString) const;
//#pragma push_macro("GetTextMetrics")
//#undef GetTextMetrics
//	BOOL _AFX_FUNCNAME(GetTextMetrics)(LPTEXTMETRIC lpMetrics) const;
//	BOOL GetTextMetrics(LPTEXTMETRIC lpMetrics) const;
//#pragma pop_macro("GetTextMetrics")
	//BOOL GetOutputTextMetrics(LPTEXTMETRIC lpMetrics) const;
	int SetTextJustification(int nBreakExtra, int nBreakCount);
	int GetTextCharacterExtra() const;
	int SetTextCharacterExtra(int nCharExtra);
	
	//DWORD GetCharacterPlacement(LPCTSTR lpString, int nCount, int nMaxExtent, LPGCP_RESULTS lpResults, DWORD dwFlags) const;
	//DWORD GetCharacterPlacement(CString& str, int nMaxExtent, LPGCP_RESULTS lpResults, DWORD dwFlags) const;
	
	
	//BOOL GetTextExtentExPointI(LPWORD pgiIn, int cgi, int nMaxExtent, LPINT lpnFit, LPINT alpDx,  LPSIZE lpSize) const;
	//BOOL GetTextExtentPointI(LPWORD pgiIn, int cgi,  LPSIZE lpSize) const;
	
	// Advanced Drawing
	BOOL DrawEdge(LPRECT lpRect, UINT nEdge, UINT nFlags);
	BOOL DrawFrameControl(LPRECT lpRect, UINT nType, UINT nState);
	
	// Scrolling Functions
	//BOOL ScrollDC(int dx, int dy, LPCRECT lpRectScroll, LPCRECT lpRectClip,
	//			  CRgn* pRgnUpdate, LPRECT lpRectUpdate);
	
	// Font Functions
	//BOOL GetCharWidth(UINT nFirstChar, UINT nLastChar, LPINT lpBuffer) const;
	//BOOL GetOutputCharWidth(UINT nFirstChar, UINT nLastChar, LPINT lpBuffer) const;
	DWORD SetMapperFlags(DWORD dwFlag);
	CSize GetAspectRatioFilter() const;
	
	//BOOL GetCharABCWidths(UINT nFirstChar, UINT nLastChar, LPABC lpabc) const;
	//DWORD GetFontData(DWORD dwTable, DWORD dwOffset, LPVOID lpData, DWORD cbData) const;
	//int GetKerningPairs(int nPairs, LPKERNINGPAIR lpkrnpair) const;
	//UINT GetOutlineTextMetrics(UINT cbData, LPOUTLINETEXTMETRIC lpotm) const;
	//DWORD GetGlyphOutline(UINT nChar, UINT nFormat, LPGLYPHMETRICS lpgm,
	//					  DWORD cbBuffer, LPVOID lpBuffer, const MAT2* lpmat2) const;
	
	//BOOL GetCharABCWidths(UINT nFirstChar, UINT nLastChar,
	//					  LPABCFLOAT lpABCF) const;
	BOOL GetCharWidth(UINT nFirstChar, UINT nLastChar,
					  float* lpFloatBuffer) const;
	
	DWORD GetFontLanguageInfo() const;
	
//#if (_WIN32_WINNT >= 0x0500)
//	
//	BOOL GetCharABCWidthsI(UINT giFirst, UINT cgi, LPWORD pgi, LPABC lpabc) const;
//	BOOL GetCharWidthI(UINT giFirst, UINT cgi, LPWORD pgi, LPINT lpBuffer) const;
//	
//#endif
	
	// Printer/Device Escape Functions
	virtual int Escape( int nEscape,  int nCount, LPCSTR lpszInData,  LPVOID lpOutData);
	int Escape( int nEscape,  int nInputSize,  LPCSTR lpszInputData,
			    int nOutputSize,  LPSTR lpszOutputData);
	int DrawEscape(int nEscape, int nInputSize, LPCSTR lpszInputData);
	
	// Escape helpers
	int StartDoc(LPCTSTR lpszDocName);  // old Win3.0 version
	int StartDoc(LPDOCINFO lpDocInfo);
	int StartPage();
	int EndPage();
	//int SetAbortProc(BOOL (CALLBACK* lpfn)(HDC, int));
	int AbortDoc();
	int EndDoc();
	
	// MetaFile Functions
	//BOOL PlayMetaFile(HMETAFILE hMF);
	//BOOL PlayMetaFile(HENHMETAFILE hEnhMetaFile, LPCRECT lpBounds);
	//BOOL AddMetaFileComment(UINT nDataSize, const BYTE* pCommentData);
	// can be used for enhanced metafiles only
	
	// Path Functions
	BOOL AbortPath();
	BOOL BeginPath();
	BOOL CloseFigure();
	BOOL EndPath();
	BOOL FillPath();
	BOOL FlattenPath();
	BOOL StrokeAndFillPath();
	BOOL StrokePath();
	BOOL WidenPath();
	float GetMiterLimit() const;
	BOOL SetMiterLimit(float fMiterLimit);
	int GetPath(LPPOINT lpPoints, LPBYTE lpTypes, int nCount) const;
	BOOL SelectClipPath(int nMode);
	
	// Misc Helper Functions
	static CBrush* GetHalftoneBrush();
	void DrawDragRect(LPCRECT lpRect, SIZE size,
					  LPCRECT lpRectLast, SIZE sizeLast,
					  CBrush* pBrush = NULL, CBrush* pBrushLast = NULL);
	void FillSolidRect(LPCRECT lpRect, COLORREF clr);
	void FillSolidRect(int x, int y, int cx, int cy, COLORREF clr);
	void Draw3dRect(LPCRECT lpRect, COLORREF clrTopLeft, COLORREF clrBottomRight);
	void Draw3dRect(int x, int y, int cx, int cy,
					COLORREF clrTopLeft, COLORREF clrBottomRight);

	// advanced use and implementation
	BOOL m_bPrinting;
	HGDIOBJ SelectObject(HGDIOBJ);      // do not use for regions

};

#endif//CDC_DEFINE