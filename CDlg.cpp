
// CDlg.cpp : fichier d'impl�mentation
//

#include "stdafx.h"
#include "Pupitre.h"
#include "CDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// bo�te de dialogue CDlg



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

	// D�finir l'ic�ne de cette bo�te de dialogue.  L'infrastructure effectue cela automatiquement
	//  lorsque la fen�tre principale de l'application n'est pas une bo�te de dialogue
	SetIcon(m_hIcon, TRUE);			// D�finir une grande ic�ne
	SetIcon(m_hIcon, FALSE);		// D�finir une petite ic�ne

	////////////////////////////////////////////////////////////
	m_pRD_STOP = (CButton*)GetDlgItem(IDC_RD_STOP);
	m_pRD_CLOSE = (CButton*)GetDlgItem(IDC_RD_CLOSE);
	m_pRD_CTRL = (CButton*)GetDlgItem(IDC_RD_CTRL);
	m_pRD_FREE = (CButton*)GetDlgItem(IDC_RD_FREE);
	m_pRD_URGENCY = (CButton*)GetDlgItem(IDC_RD_URGENCY);

	m_pBT_P1 = (CButton*)GetDlgItem(IDC_BT_P1);
	m_pBT_P2 = (CButton*)GetDlgItem(IDC_BT_P2);

	return TRUE;  // retourne TRUE, sauf si vous avez d�fini le focus sur un contr�le
}

// Si vous ajoutez un bouton R�duire � votre bo�te de dialogue, vous devez utiliser le code ci-dessous
//  pour dessiner l'ic�ne.  Pour les applications MFC utilisant le mod�le Document/Vue,
//  cela est fait automatiquement par l'infrastructure.

void CDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // contexte de p�riph�rique pour la peinture

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrer l'ic�ne dans le rectangle client
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dessiner l'ic�ne
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Le syst�me appelle cette fonction pour obtenir le curseur � afficher lorsque l'utilisateur fait glisser
//  la fen�tre r�duite.
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

//----- Cartes �lectroniques non aliment�es -> rien ne se passe -----//
void CDlg::OnBnClickedRdStop()
{
}

//----- Agence ferm�e -----//
void CDlg::OnBnClickedRdClose()
{
}

//----- Contr�le des portes en entr�e ET sortie -> Chaque ouverture de porte doit �tre autoris�e par le pupitre -----//
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
