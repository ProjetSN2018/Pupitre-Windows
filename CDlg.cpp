
// CDlg.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "Pupitre.h"
#include "CDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// boîte de dialogue CDlg



CDlg::CDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PUPITRE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RD_CTRL, &CDlg::OnBnClickedRdCtrl)
	ON_BN_CLICKED(IDC_RD_FREE, &CDlg::OnBnClickedRdFree)
	ON_BN_CLICKED(IDC_RD_URGENCY, &CDlg::OnBnClickedRdUrgency)
	ON_BN_CLICKED(IDC_BT_P1, &CDlg::OnBnClickedBtP1)
	ON_BN_CLICKED(IDC_BT_P2, &CDlg::OnBnClickedBtP2)
END_MESSAGE_MAP()


// gestionnaires de messages pour CDlg

BOOL CDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Définir l'icône de cette boîte de dialogue.  L'infrastructure effectue cela automatiquement
	//  lorsque la fenêtre principale de l'application n'est pas une boîte de dialogue
	SetIcon(m_hIcon, TRUE);			// Définir une grande icône
	SetIcon(m_hIcon, FALSE);		// Définir une petite icône

	////////////////////////////////////////////////////////////
	m_pRD_STOP = (CButton*)GetDlgItem(IDC_RD_STOP);
	m_pRD_CLOSE = (CButton*)GetDlgItem(IDC_RD_CLOSE);
	m_pRD_CTRL = (CButton*)GetDlgItem(IDC_RD_CTRL);
	m_pRD_FREE = (CButton*)GetDlgItem(IDC_RD_FREE);
	m_pRD_URGENCY = (CButton*)GetDlgItem(IDC_RD_URGENCY);

	m_pBT_P1 = (CButton*)GetDlgItem(IDC_BT_P1);
	m_pBT_P2 = (CButton*)GetDlgItem(IDC_BT_P2);

	return TRUE;  // retourne TRUE, sauf si vous avez défini le focus sur un contrôle
}

// Si vous ajoutez un bouton Réduire à votre boîte de dialogue, vous devez utiliser le code ci-dessous
//  pour dessiner l'icône.  Pour les applications MFC utilisant le modèle Document/Vue,
//  cela est fait automatiquement par l'infrastructure.

void CDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // contexte de périphérique pour la peinture

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrer l'icône dans le rectangle client
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dessiner l'icône
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Le système appelle cette fonction pour obtenir le curseur à afficher lorsque l'utilisateur fait glisser
//  la fenêtre réduite.
HCURSOR CDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CDlg::OnCancel()
{
	//Verification si l'utilisateur veut quitter
	int quit = MessageBox(_T("Voulez vous quitter l'application ?"), _T("EXIT"), MB_ICONQUESTION | MB_YESNO);
	//Si oui, on quitte
	if(quit == 6) 
	CDialogEx::OnCancel();
}

////------------------ Modes de fontionnement ------------------////

//----- Cartes électroniques non alimentées -> rien ne se passe -----//
void CDlg::OnBnClickedRdStop()
{
}

//----- Agence fermée -----//
void CDlg::OnBnClickedRdClose()
{
}

//----- Contrôle des portes en entrée ET sortie -> Chaque ouverture de porte doit être autorisée par le pupitre -----//
void CDlg::OnBnClickedRdCtrl()
{
}

//----- Mode libre -> un simple appuie sur la platine d'appel suffit -----//
void CDlg::OnBnClickedRdFree()
{
}

//----- Ouverture de toutes les portes -> urgence -----//
void CDlg::OnBnClickedRdUrgency()
{
}



////------------------ Boutons portes ------------------////

//----- Porte 1 -----//
void CDlg::OnBnClickedBtP1()
{
}

//----- Porte 2 -----//
void CDlg::OnBnClickedBtP2()
{
}
