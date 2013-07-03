
// SimpleDialog2Dlg.h : header file
//

#pragma once

#include "NumSpinCtrl.h"

// CSimpleDialog2Dlg dialog
class CSimpleDialog2Dlg : public CDialogEx
{
// Construction
public:
	CSimpleDialog2Dlg(CWnd* pParent = NULL);	// standard constructor

    virtual ~CSimpleDialog2Dlg();

// Dialog Data
	enum { IDD = IDD_SIMPLEDIALOG2_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

    CComboBox	m_cob_test;

    CNumSpinCtrl		m_spin_Data;
    CNumEdit			m_edit_Data;

    CSliderCtrl			m_slider;
    CProgressCtrl		m_progress;

    CListBox			m_listBox;

	int indexComboBox;
	BOOL indexCheckBox;

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	virtual void OnHScroll(UINT /*nSBCode*/, UINT /*nPos*/, CScrollBar* /*pScrollBar*/);
};
