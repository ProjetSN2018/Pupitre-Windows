
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
	ON_BN_CLICKED(IDC_RD_STOP, &CDlg::OnBnClickedRdStop)
	ON_BN_CLICKED(IDC_RD_CLOSE, &CDlg::OnBnClickedRdClose)
	ON_BN_CLICKED(IDC_RD_CTRL, &CDlg::OnBnClickedRdCtrl)
	ON_BN_CLICKED(IDC_RD_FREE, &CDlg::OnBnClickedRdFree)
	ON_BN_CLICKED(IDC_RD_URGENCY, &CDlg::OnBnClickedRdUrgency)
	ON_BN_CLICKED(IDC_BT_D1, &CDlg::OnBnClickedBtD1)
	ON_BN_CLICKED(IDC_BT_D2, &CDlg::OnBnClickedBtD2)
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

	m_pBT_P1 = (CButton*)GetDlgItem(IDC_BT_D1);
	m_pBT_P2 = (CButton*)GetDlgItem(IDC_BT_D2);
	m_pBT_DENY = (CButton*)GetDlgItem(IDC_BT_DENY);

	m_pST_LOG = (CStatic*)GetDlgItem(IDC_ST_LOG);
	m_pED_LOG = (CEdit*)GetDlgItem(IDC_ED_LOG);

	OnBnClickedRdStop();
	m_pRD_STOP->SetCheck(MF_CHECKED);

	//m_pRD_STOP->SetBitmap();

	return TRUE;  // retourne TRUE, sauf si vous avez d�fini le focus sur un contr�le
}

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
	m_pRD_STOP->EnableWindow(false);
	
	m_pRD_CLOSE->EnableWindow();
	m_pRD_CTRL->EnableWindow();
	m_pRD_FREE->EnableWindow();
	m_pRD_URGENCY->EnableWindow();

	m_pBT_P1->EnableWindow(false);
	m_pBT_P2->EnableWindow(false);
	m_pED_LOG->ReplaceSel(_T("---------------------------------------------------------------------------------------------------\r\n"
		"# Mode Arr�t\r\n\r\n"));
	m_pED_LOG->ReplaceSel(_T("- Syst�me arr�t�\r\n"
		"- Cartes �lectroniques non aliment�es\r\n"
		"---------------------------------------------------------------------------------------------------\r\n"));
}

//----- Agence ferm�e -----//
void CDlg::OnBnClickedRdClose()
{
	m_pRD_CLOSE->EnableWindow(false);

	m_pRD_STOP->EnableWindow();
	m_pRD_CTRL->EnableWindow();
	m_pRD_FREE->EnableWindow();
	m_pRD_URGENCY->EnableWindow();

	m_pED_LOG->ReplaceSel(_T("---------------------------------------------------------------------------------------------------\r\n"
		"# Mode Agence ferm�e\r\n\r\n"));
	m_pED_LOG->ReplaceSel(_T("- Interdiction de rentrer depuis BP1Ext\r\n"
		"- Pas de contr�le pour BP1Int & BP2Int\r\n"
		"- Contr�le pour BP2Ext\r\n"
		"---------------------------------------------------------------------------------------------------\r\n"));
}

//----- Contr�le des portes en entr�e ET sortie -> Chaque ouverture de porte doit �tre autoris�e par le pupitre -----//
void CDlg::OnBnClickedRdCtrl()
{
	m_pRD_CTRL->EnableWindow(false);

	m_pRD_STOP->EnableWindow();
	m_pRD_CLOSE->EnableWindow();
	m_pRD_FREE->EnableWindow();
	m_pRD_URGENCY->EnableWindow();

	m_pBT_P1->EnableWindow();
	m_pBT_P2->EnableWindow();
	m_pED_LOG->ReplaceSel(_T("---------------------------------------------------------------------------------------------------\r\n"
		"# Mode Contr�le P1 et P2 (Entr�e & Sortie)\r\n\r\n"));
	m_pED_LOG->ReplaceSel(_T("- Demande d'autorisation pour chaque porte en entr�e et en sortie\r\n"
		"---------------------------------------------------------------------------------------------------\r\n"));
}

//----- Mode libre -> un simple appuie sur la platine d'appel suffit -----//
void CDlg::OnBnClickedRdFree()
{
	m_pRD_FREE->EnableWindow(false);

	m_pRD_STOP->EnableWindow();
	m_pRD_CLOSE->EnableWindow();
	m_pRD_CTRL->EnableWindow();
	m_pRD_URGENCY->EnableWindow();

	m_pBT_P1->EnableWindow(false);
	m_pBT_P2->EnableWindow(false);
	m_pED_LOG->ReplaceSel(_T("---------------------------------------------------------------------------------------------------\r\n"
		"# Mode Libre\r\n\r\n"));
	m_pED_LOG->ReplaceSel(_T("- Pas de contr�le pour les portes P1 & P2\r\n"
		"- Une porte ouverte � la fois\r\n"
		"---------------------------------------------------------------------------------------------------\r\n"));
}

//----- Ouverture de toutes les portes -> urgence -----//
void CDlg::OnBnClickedRdUrgency()
{
	m_pRD_URGENCY->EnableWindow(false);

	m_pRD_STOP->EnableWindow();
	m_pRD_CLOSE->EnableWindow();
	m_pRD_CTRL->EnableWindow();
	m_pRD_FREE->EnableWindow();

	m_pED_LOG->ReplaceSel(_T("---------------------------------------------------------------------------------------------------\r\n"
		"# Mode Urgence\r\n\r\n"));
	m_pED_LOG->ReplaceSel(_T("- Ouverture de toutes les portes\r\n"
		"---------------------------------------------------------------------------------------------------\r\n"));
}



////------------------ Boutons portes ------------------////

//----- Porte 1 -----//
void CDlg::OnBnClickedBtD1()
{
}

//----- Porte 2 -----//
void CDlg::OnBnClickedBtD2()
{
}
