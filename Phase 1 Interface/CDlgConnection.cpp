// CDlgConnection.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "Pupitre.h"
#include "CDlgConnection.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Boîte de dialogue CDlgConnection
CDlgConnection::CDlgConnection()
	: CDialogEx(IDD_CONNECTION_DIALOG)
{
}

void CDlgConnection::OnPaint()
{
}

void CDlgConnection::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDlgConnection, CDialogEx)
	ON_BN_CLICKED(IDC_BT_SEARCH, &CDlgConnection::OnBnClickedBtSearch)
END_MESSAGE_MAP()


// Gestionnaires de messages de CDlgConnection

BOOL CDlgConnection::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_pBT_SEARCH = (CButton*)GetDlgItem(IDC_BT_SEARCH);
	return TRUE;
}


void CDlgConnection::OnCancel()
{
		CDialogEx::OnCancel();
}

void CDlgConnection::OnBnClickedBtSearch()
{
}
