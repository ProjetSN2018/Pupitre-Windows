
// CDlg.h : fichier d'en-tête
//

#pragma once


// boîte de dialogue CDlg
class CDlg : public CDialogEx
{
// Construction
public:
	CDlg(CWnd* pParent = NULL);	// constructeur standard

// Données de boîte de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PUPITRE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Prise en charge de DDX/DDV


// Implémentation

private:
	CButton* m_pRD_STOP;
	CButton* m_pRD_CLOSE;
	CButton* m_pRD_CTRL;
	CButton* m_pRD_FREE;
	CButton* m_pRD_URGENCY;

	CButton* m_pBT_P1;
	CButton* m_pBT_P2;
	
protected:
	HICON m_hIcon;

	// Fonctions générées de la table des messages
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnCancel();
	afx_msg void OnBnClickedRdCtrl();
	afx_msg void OnBnClickedRdFree();
	afx_msg void OnBnClickedRdUrgency();
	afx_msg void OnBnClickedBtP1();
	afx_msg void OnBnClickedBtP2();
	afx_msg void OnBnClickedRdStop();
	afx_msg void OnBnClickedRdClose();
};
