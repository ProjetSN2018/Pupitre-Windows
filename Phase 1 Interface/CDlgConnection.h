#pragma once

// Boîte de dialogue CDlgConnection

class CDlgConnection : public CDialogEx
{
public:
	CDlgConnection();   // constructeur de base

// Données de boîte de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONNECTION_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

private:
	CButton*	m_pBT_SEARCH;


protected:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()

public:
	virtual void OnCancel();
	afx_msg void OnBnClickedBtSearch();
};
