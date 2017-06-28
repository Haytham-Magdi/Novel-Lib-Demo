// MfcCvTut_11Jun07Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MfcCvTut_11Jun07.h"
#include "MfcCvTut_11Jun07Dlg.h"
#include "cvapp.h"

#include <Lib\Novel\Ncv\OpenCV\funcs1.h>

#include <Lib\Novel\Ncpp\Common\FixedVector.h>

#include <Lib\Novel\Ncpp\Common\FilePathMgr.h>




#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

	// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CMfcCvTut_11Jun07Dlg dialog




CMfcCvTut_11Jun07Dlg::CMfcCvTut_11Jun07Dlg(CWnd* pParent /*=NULL*/)
: CDialog(CMfcCvTut_11Jun07Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMfcCvTut_11Jun07Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_KEYS, m_listKeys);
	DDX_Control(pDX, IDC_LIST2_VALUES, m_listValues);
	DDX_Control(pDX, IDC_TXT_BX_AVG, edtAvg);
	DDX_Control(pDX, IDC_TXT_BX_SIZE_UP, edtSizeUp);
	DDX_Control(pDX, IDC_TXT_BX_SIZE_DOWN, edtSizeDown);
	DDX_Control(pDX, IDC_TXT_BX_SAVE_TO_FILE, edtSaveToFile);
	DDX_Control(pDX, IDC_TXT_BX_THRESHOLD, edtThreshold);
	DDX_Control(pDX, IDC_TXT_BX_DILATE, edtDilate);
	DDX_Control(pDX, IDC_TXT_BX_ERODE, edtErode);
	DDX_Control(pDX, IDC_TXT_BX_MEDIAN, edtMedian);
	DDX_Control(pDX, IDC_TXT_BX_APR_SIZE_1D, edtAprSize1D);
	DDX_Control(pDX, IDC_TXT_BX_DIR_1D, edtScanDir1D);
}





BEGIN_MESSAGE_MAP(CMfcCvTut_11Jun07Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_OPEN_IMAGE_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedOpenImageBtn)
	ON_BN_CLICKED(IDC_PROCESS_IMAGE_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedProcessImageBtn)
	ON_BN_CLICKED(IDC_CREATE_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedCreateBtn)
	ON_BN_CLICKED(IDC_SOBEL_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedSobelBtn)
	ON_BN_CLICKED(IDC_TRY1_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedTry1Btn)
	ON_BN_CLICKED(IDC_TRY2_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedTry2Btn)
	ON_BN_CLICKED(IDC_TRY3_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedTry3Btn)
	ON_BN_CLICKED(IDC_TRY4_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedTry4Btn)
	ON_BN_CLICKED(IDC_TRY5_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedTry5Btn)
	ON_BN_CLICKED(IDC_TRY6_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedTry6Btn)
	ON_BN_CLICKED(IDC_TRY7_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedTry7Btn)
	ON_BN_CLICKED(IDC_CLUSTERS_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedClustersBtn)
	ON_BN_CLICKED(IDC_TRY8_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedTry8Btn)
	ON_BN_CLICKED(IDC_TRY9_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedTry9Btn)
	ON_BN_CLICKED(IDC_TRY10_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedTry10Btn)
	ON_BN_CLICKED(IDC_FAST_AVG_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedFastAvgBtn)
	ON_BN_CLICKED(IDC_MAX_MIN_EDGE_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedMaxMinEdgeBtn)
	ON_BN_CLICKED(IDC_TRY11_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedTry11Btn)
	ON_BN_CLICKED(IDC_TRY12_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedTry12Btn)
	ON_BN_CLICKED(IDC_TRY13_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedTry13Btn)
	ON_BN_CLICKED(IDC_TRY14_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedTry14Btn)
	ON_BN_CLICKED(IDC_SOBEL_MAX_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedSobelMaxBtn)
	ON_BN_CLICKED(IDC_TRY15_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedTry15Btn)
	ON_BN_CLICKED(IDC_EDGE_DIR_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedEdgeDirBtn)
	ON_BN_CLICKED(IDC_TRY16_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedTry16Btn)
	ON_BN_CLICKED(IDC_EDGE_DIR2_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedEdgeDir2Btn)
	ON_BN_CLICKED(IDC_TRY17_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedTry17Btn)
	ON_BN_CLICKED(IDC_TRY18_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedTry18Btn)
	ON_BN_CLICKED(IDC_TRY19_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedTry19Btn)
	//	ON_LBN_SELCHANGE(IDC_LIST2, &CMfcCvTut_11Jun07Dlg::OnLbnSelchangeList2)
	ON_BN_CLICKED(IDC_TRY_MOUSE_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedTryMouseBtn)
	ON_BN_CLICKED(IDC_CLEAR_IO, &CMfcCvTut_11Jun07Dlg::OnBnClickedClearIo)
	ON_BN_CLICKED(IDC_DRAW_LINE_PATH, &CMfcCvTut_11Jun07Dlg::OnBnClickedDrawLinePath)
	ON_BN_CLICKED(IDC_AVG_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedAvgBtn)
	ON_BN_CLICKED(IDC_RESET_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedResetBtn)
	ON_BN_CLICKED(IDC_SIZE_UP_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedSizeUpBtn)
	ON_BN_CLICKED(IDC_SIZE_DOWN_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedSizeDownBtn)
	ON_BN_CLICKED(IDC_SAVE_TO_FILE_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedSaveToFileBtn)
	ON_BN_CLICKED(IDC_CLIP_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedClipBtn)
	ON_BN_CLICKED(IDC_TRY20_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedTry20Btn)
	ON_BN_CLICKED(IDC_THRESHOLD_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedThresholdBtn)
	ON_BN_CLICKED(IDC_UNDO_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedUndoBtn)
	ON_BN_CLICKED(IDC_REDO_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedRedoBtn)
	ON_BN_CLICKED(IDC_DILATE_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedDilateBtn)
	ON_BN_CLICKED(IDC_ERODE_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedErodeBtn)
	ON_BN_CLICKED(IDC_MEDIAN_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedMedianBtn)
	ON_BN_CLICKED(IDC_EQUALIZE_HIST_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedEqualizeHistBtn)
	ON_BN_CLICKED(IDC_TRYRS20_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedTryrs20Btn)
	ON_BN_CLICKED(IDC_GRAY_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedGrayBtn)
	ON_BN_CLICKED(IDC_MGRAD_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedMgradBtn)
	ON_BN_CLICKED(IDC_MULT_BY_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedMultByBtn)
	ON_BN_CLICKED(IDC_MGRAD_1S2_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedMgrad1s2Btn)
	ON_BN_CLICKED(IDC_TRY22_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedTry22Btn)
	ON_BN_CLICKED(IDC_TRY23_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedTry23Btn)
	ON_BN_CLICKED(IDC_TRY24_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedTry24Btn)
	ON_BN_CLICKED(IDC_TRY25_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedTry25Btn)
	ON_BN_CLICKED(IDC_TRY26_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedTry26Btn)
	ON_BN_CLICKED(IDC_CBIS_BERK_EXECUTE, &CMfcCvTut_11Jun07Dlg::OnBnClickedCbisBerkExecute)
	ON_BN_CLICKED(IDC_FAST_AVG_COLORS_BTN, &CMfcCvTut_11Jun07Dlg::OnBnClickedFastAvgColorsBtn)
END_MESSAGE_MAP()


// CMfcCvTut_11Jun07Dlg message handlers

BOOL CMfcCvTut_11Jun07Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//edtAvg.SetWindowTextA( "5" );
	edtAvg.SetWindowTextA("7");
	//edtAvg.SetWindowTextA( "11" );
	//edtAvg.SetWindowTextA( "25" );
	//edtAvg.SetWindowTextA( "45" );

	edtSizeUp.SetWindowTextA("1");
	edtSizeDown.SetWindowTextA("1");
	edtSaveToFile.SetWindowTextA("currImg.jpg");
	edtThreshold.SetWindowTextA("128");
	edtDilate.SetWindowTextA("3");
	edtErode.SetWindowTextA("3");
	edtMedian.SetWindowTextA("5");

	//edtAprSize1D.SetWindowTextA( "25" );
	//edtAprSize1D.SetWindowTextA( "15" );
	//edtAprSize1D.SetWindowTextA( "65" );
	//edtAprSize1D.SetWindowTextA( "11" );
	//edtAprSize1D.SetWindowTextA( "7" );
	//edtAprSize1D.SetWindowTextA( "17" );
	edtAprSize1D.SetWindowTextA("23");
	//edtAprSize1D.SetWindowTextA( "9" );
	//edtAprSize1D.SetWindowTextA( "45" );


	edtScanDir1D.SetWindowTextA("4");


	Ncv::IOMgr::SetCore(this);

	this->InitIOValues();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMfcCvTut_11Jun07Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMfcCvTut_11Jun07Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMfcCvTut_11Jun07Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMfcCvTut_11Jun07Dlg::OnBnClickedOpenImageBtn()
{
	//if (false)
	{
		CString sFolder =
			//"E:\\HthmWork\\Lib\\Projects\\Images";
			//"E:\\HthmWork\\Computer-Vision\\Car-Dent-Detection\\Images";
		"E:\\HthmWork\\Computer-Vision\\Images";

		////CString sFile = "h4_3C_3_Dn.jpg";
		////CString sFile = "h4_3C_3_Dn_By2.jpg";
		////CString sFile = "diamond_1_Dn_By2.jpg";
		//CString sFile = "41004.jpg";
		////CString sFile = "24004.jpg";
		////CString sFile = "clrpic1_U.jpg";
		////CString sFile = "clrpic1.jpg";
		////CString sFile = "White-All.png";

		//CString sFile = "patternReflection2.png";
		//CString sFile = "patternReflection2_2.jpg";

		//CString sFile = "patternReflection1_2.jpg";


		//CString sFile = "Image_0005_d0.png";
		//CString sFile = "Image_0005_d0_2.png";
		
		//CString sFile = "Bitmap_inverse_pattern_from_Bitmap_led_mapping_phase_images_balanced_02 (2).png";
		//CString sFile = "Bitmap_inverse_pattern_from_Bitmap_led_mapping_phase_images_balanced_02 (2)_2.png";

		//CString sFile = "paint_1.png";
		//CString sFile = "paint_filled_1.png";

		//CString sFile = "bin_images_1.jpg";
		CString sFile = "bin_images_2.jpg";
		//CString sFile = "bin_images_3.jpg";
		//CString sFile = "Fig-3-1-Binarization-using-Otsu's-method-2-smooth-operation-3-second-binarization.png";


		CString path = sFolder + "\\" + sFile;

		proc = new ImageProcessor(path);
		//proc = new ImageProcessor(
		//	//"E:\\HthmWork\\Computer - Vision\\Image - Data - Sets\\RSDataset - Stuff\\RSDataset\\Residential\\residential_24.jpg");
		//	"E:\\residential_24.jpg");



		return;
	}

	CFileDialog dlg(TRUE, _T("*.bmp"), "",
		OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY,
		"image files (*.bmp; *.jpg) |*.bmp;*.jpg| AVI files (*.avi) |*.avi|All Files (*.*)|*.*||",
		NULL);



	char title[] = { "Open Image" };

	dlg.m_ofn.lpstrTitle = title;


	if (dlg.DoModal() == IDOK)
	{
		CString path = dlg.GetPathName();

		if (proc != 0)
			delete proc;

		proc = new ImageProcessor(path);
	}
}

void CMfcCvTut_11Jun07Dlg::OnBnClickedProcessImageBtn()
{
	if (proc != 0)
	{
		// process and display

		proc->execute();

		proc->display();

	}

}

void CMfcCvTut_11Jun07Dlg::OnBnClickedCreateBtn()
{
	//if (proc != 0) 

	if (proc != 0)
		delete proc;

	// Create and display

	proc = new ImageProcessor();

	proc->Create();

	proc->display();

}

void CMfcCvTut_11Jun07Dlg::OnBnClickedSobelBtn()
{
	if (proc != 0)
	{
		// process and display

		proc->Sobel();

		proc->display();

	}

}

void CMfcCvTut_11Jun07Dlg::OnBnClickedTry1Btn()
{
	if (proc != 0)
	{
		// process and display

		proc->Try1();

		proc->display();

	}

}
void CMfcCvTut_11Jun07Dlg::OnBnClickedTry2Btn()
{
	if (proc != 0)
	{
		// process and display

		proc->Try2();

		proc->display();

	}
}

void CMfcCvTut_11Jun07Dlg::OnBnClickedTry3Btn()
{
	if (proc != 0)
	{
		// process and display

		proc->Try3();

		//proc->display();

	}
}

void CMfcCvTut_11Jun07Dlg::OnBnClickedTry4Btn()
{
	if (proc != 0)
	{
		// process and display

		proc->Try4();

		//proc->display();

	}
}

void CMfcCvTut_11Jun07Dlg::OnBnClickedTry5Btn()
{
	if (proc != 0)
	{
		// process and display

		proc->Try5();

		//proc->display();

	}
}

void CMfcCvTut_11Jun07Dlg::OnBnClickedTry6Btn()
{
	if (proc != 0)
	{
		// process and display

		proc->Try6();

		//proc->display();

	}
}

void CMfcCvTut_11Jun07Dlg::OnBnClickedTry7Btn()
{
	if (proc != 0)
	{
		// process and display

		proc->Try7();

		//proc->display();

	}
}



void CMfcCvTut_11Jun07Dlg::OnBnClickedFastAvgBtn()
{
	// TODO: Add your control notification handler code here

	if (proc != 0)
	{
		// process and display

		int nAprSiz = -1;
		{
			CString sTmp;

			edtAvg.GetWindowTextA(sTmp);

			CString sTmp2 = sTmp.Trim();

			nAprSiz = atoi(sTmp2.GetBuffer());
		}

		proc->FastAvgLinePathImg(nAprSiz);

		//proc->display();
	}

}

void CMfcCvTut_11Jun07Dlg::OnBnClickedMaxMinEdgeBtn()
{
	if (proc != 0)
	{
		// process and display

		proc->MaxMinEdge();

		//proc->display();

	}
}

void CMfcCvTut_11Jun07Dlg::OnBnClickedTry11Btn()
{
	if (proc != 0)
	{
		// process and display

		proc->Try11();

		//proc->display();

	}
}

void CMfcCvTut_11Jun07Dlg::OnBnClickedTry12Btn()
{
	if (proc != 0)
	{
		// process and display

		proc->Try12();

		//proc->display();

	}
}

void CMfcCvTut_11Jun07Dlg::OnBnClickedTry13Btn()
{
	if (proc != 0)
	{
		// process and display

		proc->Try13();

		//proc->display();

	}
}

void CMfcCvTut_11Jun07Dlg::OnBnClickedTry14Btn()
{
	if (proc != 0)
	{
		// process and display

		proc->Try14();

		//proc->display();

	}
}

void CMfcCvTut_11Jun07Dlg::OnBnClickedSobelMaxBtn()
{
	if (proc != 0)
	{
		// process and display

		proc->SobelMax();

		//proc->display();

	}
}

void CMfcCvTut_11Jun07Dlg::OnBnClickedTry15Btn()
{
	if (proc != 0)
	{
		// process and display

		proc->Try15();

		//proc->display();

	}
}

void CMfcCvTut_11Jun07Dlg::OnBnClickedEdgeDirBtn()
{
	if (proc != 0)
	{
		// process and display

		proc->EdgeDir();

		//proc->display();

	}
}

void CMfcCvTut_11Jun07Dlg::OnBnClickedTry16Btn()
{
	if (proc != 0)
	{
		// process and display

		proc->Try16();

		//proc->display();

	}
}

void CMfcCvTut_11Jun07Dlg::OnBnClickedEdgeDir2Btn()
{
	if (proc != 0)
	{
		// process and display

		proc->EdgeDir2();

		//proc->display();

	}
}

void CMfcCvTut_11Jun07Dlg::OnBnClickedTry17Btn()
{
	if (proc != 0)
	{
		// process and display

		proc->Try17();

		//proc->display();

	}
}

void CMfcCvTut_11Jun07Dlg::OnBnClickedTry18Btn()
{
	if (proc != 0)
	{
		// process and display

		proc->Try18();

		//proc->display();

	}
}

void CMfcCvTut_11Jun07Dlg::OnBnClickedTry19Btn()
{
	if (proc != 0)
	{
		// process and display

		proc->Try19();

		//proc->display();

	}
}

void CMfcCvTut_11Jun07Dlg::OnLbnSelchangeList2()
{
	// TODO: Add your control notification handler code here
}



void CMfcCvTut_11Jun07Dlg::InitIOValues()
{
	m_nMouseLBCnt = 0;


	//HCV_CALL( cvNamedWindow( "Original Image", 1 ) );
	HCV_CALL(cvNamedWindow("LinePathImg", 1));
	HCV_CALL(cvNamedWindow("Signals", 1));
	HCV_CALL(cvNamedWindow("RgnSgmImg", 1));


	//cvSetMouseCallback( "Original Image", LinePath_Mouse_Callback, (void*) this );
	cvSetMouseCallback("LinePathImg", LinePath_Mouse_Callback, (void*) this);

	//cvSetMouseCallback("RgnSgmImg", RgnSgmImg_Mouse_Callback, (void*) this);


}



void CMfcCvTut_11Jun07Dlg::ReadString(char * a_sKey, char * a_buff)
{
	strcpy(a_buff, "Test");

	static char tmpBuf[100];

	//int a = this->m_listKeys.GetCount(); 

	for (int i = 0; i < m_listKeys.GetCount(); i++)
	{
		m_listKeys.GetText(i, tmpBuf);

		if (0 == strcmp(a_sKey, (char *)tmpBuf))
		{
			m_listValues.GetText(i, a_buff);
			return;
		}
	}

	return;
}


bool CMfcCvTut_11Jun07Dlg::ValueExists(char * a_sKey)
{
	static char tmpBuf[100];

	for (int i = 0; i < m_listKeys.GetCount(); i++)
	{
		m_listKeys.GetText(i, tmpBuf);

		if (0 == strcmp(a_sKey, (char *)tmpBuf))
		{
			return true;
		}
	}

	return false;
}


void CMfcCvTut_11Jun07Dlg::LinePath_Mouse_Callback(
	int a_event, int a_x, int a_y, int a_flags, void* a_param)
{

	CMfcCvTut_11Jun07Dlg * pDlg = (CMfcCvTut_11Jun07Dlg *)a_param;


	static char buff[100];

	//static char bufX[20];
	//static char bufY[20];


	{
		CString sTmp;

		pDlg->edtAprSize1D.GetWindowTextA(sTmp);

		CString sTmp2 = sTmp.Trim();

		GlobalStuff::AprSize1D = atoi(sTmp2.GetBuffer());
		//GlobalStuff::AprSize1D = 7;
	}

	{
		CString sTmp;

		pDlg->edtScanDir1D.GetWindowTextA(sTmp);

		CString sTmp2 = sTmp.Trim();

		GlobalStuff::ScanDir = atoi(sTmp2.GetBuffer());
	}



	if (CV_EVENT_LBUTTONUP == a_event)
	{
		if (pDlg->ValueExists("x2"))
		{
			pDlg->DoClearIo();
		}

		pDlg->m_nMouseLBCnt++;


		sprintf(buff, "x%d", pDlg->m_nMouseLBCnt);

		//this->m_listKeys.AddString("x1");
		pDlg->m_listKeys.AddString(buff);

		sprintf(buff, "%d", a_x);

		//this->m_listValues.AddString("68");
		//this->m_listValues.AddString("127");
		pDlg->m_listValues.AddString(buff);




		sprintf(buff, "y%d", pDlg->m_nMouseLBCnt);

		//this->m_listKeys.AddString("y1");
		pDlg->m_listKeys.AddString(buff);

		sprintf(buff, "%d", a_y);

		//this->m_listValues.AddString("86");
		//this->m_listValues.AddString("99");
		pDlg->m_listValues.AddString(buff);


		if (pDlg->ValueExists("x2"))
		{
			proc->DrawLinePath();
		}


	}


}



//void CMfcCvTut_11Jun07Dlg::RgnSgmImg_Mouse_Callback(
//	int a_event, int a_x, int a_y, int a_flags, void* a_param)
//{
//	CMfcCvTut_11Jun07Dlg * pDlg = (CMfcCvTut_11Jun07Dlg *)a_param;
//
//	static char buff[100];
//
//	if (CV_EVENT_RBUTTONUP == a_event)
//	{
//		Ncv::IRegionSegmentor20Ref rs1 = GlobalStuff::GetRegionSegmentor();
//
//		if (NULL == rs1)
//			return;
//
//		//rs1->ShowValleyPath( a_x, a_y );
//		rs1->ShowSrcPath(a_x, a_y);
//
//
//		return;
//	}
//
//	if (CV_EVENT_LBUTTONUP == a_event)
//	{
//		if (pDlg->ValueExists("x2"))
//		{
//			pDlg->DoClearIo();
//		}
//
//		pDlg->m_nMouseLBCnt++;
//
//
//		sprintf(buff, "x%d", pDlg->m_nMouseLBCnt);
//
//		//this->m_listKeys.AddString("x1");
//		pDlg->m_listKeys.AddString(buff);
//
//		sprintf(buff, "%d", a_x);
//
//		//this->m_listValues.AddString("68");
//		//this->m_listValues.AddString("127");
//		pDlg->m_listValues.AddString(buff);
//
//
//
//
//		sprintf(buff, "y%d", pDlg->m_nMouseLBCnt);
//
//		//this->m_listKeys.AddString("y1");
//		pDlg->m_listKeys.AddString(buff);
//
//		sprintf(buff, "%d", a_y);
//
//		//this->m_listValues.AddString("86");
//		//this->m_listValues.AddString("99");
//		pDlg->m_listValues.AddString(buff);
//
//
//		if (pDlg->ValueExists("x2"))
//		{
//			Ncv::IRegionSegmentor20Ref rs1 = GlobalStuff::GetRegionSegmentor();
//
//			if (NULL == rs1)
//				return;
//
//			rs1->ShowEdgeOfConflict();
//
//			/*
//						Ncv::S16ImageRef img1 = rs1->GenSegmentedImage(false);
//
//						img1 = img1->Clone();
//
//
//						HCV_CALL(
//
//						cvCircle (
//						img1->GetIplImagePtr(),
//						cvPoint( a_x, a_y ),
//						3,
//						//CV_RGB( a_color.val2, a_color.val1, a_color.val0 ),
//						CV_RGB( 255, 0, 0 ),
//						-1 // CV_FILL
//						) );
//
//
//
//
//						ShowImage(img1, "RgnSgmImg");
//						//proc->DrawLinePath();
//
//						*/
//		}
//
//	}
//
//
//
//
//
//
//}
//









void CMfcCvTut_11Jun07Dlg::OnBnClickedTryMouseBtn()
{
	//cvSetMouseCallback( "avgImg", LinePath_Mouse_Callback, (void*) this );
}

void CMfcCvTut_11Jun07Dlg::OnBnClickedClearIo()
{
	DoClearIo();
}

void CMfcCvTut_11Jun07Dlg::DoClearIo()
{
	while (m_listKeys.GetCount() > 0)
		m_listKeys.DeleteString(0);

	while (m_listValues.GetCount() > 0)
		m_listValues.DeleteString(0);

	this->m_nMouseLBCnt = 0;
}

void CMfcCvTut_11Jun07Dlg::OnBnClickedDrawLinePath()
{
	if (proc != 0)
	{
		// process and display

		proc->DrawLinePath();

		//proc->display();

	}
}

void CMfcCvTut_11Jun07Dlg::OnBnClickedAvgBtn()
{
	// TODO: Add your control notification handler code here

	if (proc != 0)
	{
		// process and display

		int nAprSiz = -1;
		{
			CString sTmp;

			edtAvg.GetWindowTextA(sTmp);

			CString sTmp2 = sTmp.Trim();

			nAprSiz = atoi(sTmp2.GetBuffer());
		}

		proc->AvgLinePathImg(nAprSiz);

		//proc->display();

	}

}

void CMfcCvTut_11Jun07Dlg::OnBnClickedResetBtn()
{

	if (proc != 0)
	{
		// process and display

		proc->ResetLinePathImg();

		//proc->display();

	}
}

void CMfcCvTut_11Jun07Dlg::OnBnClickedSizeUpBtn()
{
	// TODO: Add your control notification handler code here

	if (proc != 0)
	{
		// process and display

		int val = -1;
		{
			CString sTmp;

			edtSizeUp.GetWindowTextA(sTmp);

			CString sTmp2 = sTmp.Trim();

			val = atoi(sTmp2.GetBuffer());
		}

		proc->SizeUpLinePathImg(val);

	}

}

void CMfcCvTut_11Jun07Dlg::OnBnClickedSizeDownBtn()
{
	// TODO: Add your control notification handler code here

	if (proc != 0)
	{
		// process and display

		int val = -1;
		{
			CString sTmp;

			edtSizeUp.GetWindowTextA(sTmp);

			CString sTmp2 = sTmp.Trim();

			val = atoi(sTmp2.GetBuffer());
		}

		proc->SizeDownLinePathImg(val);

	}

}

void CMfcCvTut_11Jun07Dlg::OnBnClickedSaveToFileBtn()
{
	// TODO: Add your control notification handler code here

	if (proc != 0)
	{
		// process and display

		CString sTmp;

		edtSaveToFile.GetWindowTextA(sTmp);

		CString sTmp2 = sTmp.Trim();

		proc->SaveLinePathImg(sTmp2.GetBuffer());
	}

}

void CMfcCvTut_11Jun07Dlg::OnBnClickedClipBtn()
{
	// TODO: Add your control notification handler code here

	if (proc != 0)
	{
		// process and display

		proc->ClipLinePathImg();

		//proc->display();

	}
}

void CMfcCvTut_11Jun07Dlg::OnBnClickedTry20Btn()
{
	// TODO: Add your control notification handler code here

	//if (proc != 0) 
	{
		// process and display


		{
			CString sTmp;

			this->edtAprSize1D.GetWindowTextA(sTmp);

			CString sTmp2 = sTmp.Trim();

			GlobalStuff::AprSize1D = atoi(sTmp2.GetBuffer());
		}


		proc->Try20();

		//proc->display();

	}

}

void CMfcCvTut_11Jun07Dlg::OnBnClickedThresholdBtn()
{
	// TODO: Add your control notification handler code here

	if (proc != 0)
	{
		// process and display

		float val = -1;
		{
			CString sTmp;

			edtThreshold.GetWindowTextA(sTmp);

			CString sTmp2 = sTmp.Trim();

			val = atoi(sTmp2.GetBuffer());
		}

		proc->ThresholdLinePathImg(val);

		//proc->display();

	}

}

void CMfcCvTut_11Jun07Dlg::OnBnClickedUndoBtn()
{
	// TODO: Add your control notification handler code here

	if (proc != 0)
	{
		// process and display

		proc->Undo();

		//proc->display();

	}

}

void CMfcCvTut_11Jun07Dlg::OnBnClickedRedoBtn()
{
	// TODO: Add your control notification handler code here

	if (proc != 0)
	{
		// process and display

		proc->Redo();

		//proc->display();

	}

}

void CMfcCvTut_11Jun07Dlg::OnBnClickedDilateBtn()
{
	// TODO: Add your control notification handler code here

	if (proc != 0)
	{
		// process and display

		int nAprSiz = -1;
		{
			CString sTmp;

			edtDilate.GetWindowTextA(sTmp);

			CString sTmp2 = sTmp.Trim();

			nAprSiz = atoi(sTmp2.GetBuffer());
		}

		proc->DilateLinePathImg(nAprSiz);

		//proc->display();

	}

}

void CMfcCvTut_11Jun07Dlg::OnBnClickedErodeBtn()
{
	// TODO: Add your control notification handler code here

	if (proc != 0)
	{
		// process and display

		int nAprSiz = -1;
		{
			CString sTmp;

			edtErode.GetWindowTextA(sTmp);

			CString sTmp2 = sTmp.Trim();

			nAprSiz = atoi(sTmp2.GetBuffer());
		}

		proc->ErodeLinePathImg(nAprSiz);

		//proc->display();

	}

}

void CMfcCvTut_11Jun07Dlg::OnBnClickedMedianBtn()
{
	// TODO: Add your control notification handler code here

	if (proc != 0)
	{
		// process and display

		int nAprSiz = -1;
		{
			CString sTmp;

			edtMedian.GetWindowTextA(sTmp);

			CString sTmp2 = sTmp.Trim();

			nAprSiz = atoi(sTmp2.GetBuffer());
		}

		proc->MedianLinePathImg(nAprSiz);

		//proc->display();

	}

}

void CMfcCvTut_11Jun07Dlg::OnBnClickedEqualizeHistBtn()
{

	if (proc != 0)
	{
		// process and display

		proc->EqualizeHistLinePathImg();

		//proc->display();

	}
}

void CMfcCvTut_11Jun07Dlg::OnBnClickedTryrs20Btn()
{
	if (proc != 0)
	{
		// process and display

		{
			CString sTmp;

			this->edtAprSize1D.GetWindowTextA(sTmp);

			CString sTmp2 = sTmp.Trim();

			GlobalStuff::AprSize1D = atoi(sTmp2.GetBuffer());
		}

		proc->TryRS20();

		//proc->display();

	}
}

void CMfcCvTut_11Jun07Dlg::OnBnClickedGrayBtn()
{
	// TODO: Add your control notification handler code here

	if (proc != 0)
	{
		// process and display

		proc->ConvToGrayLinePathImg();

		//proc->display();

	}
}

void CMfcCvTut_11Jun07Dlg::OnBnClickedMgradBtn()
{
	if (proc != 0)
	{
		// process and display

		{
			CString sTmp;

			this->edtAprSize1D.GetWindowTextA(sTmp);

			CString sTmp2 = sTmp.Trim();

			GlobalStuff::AprSize1D = atoi(sTmp2.GetBuffer());
		}

		proc->MorphGradLinePathImg(GlobalStuff::AprSize1D);

		//proc->display();

	}
}

void CMfcCvTut_11Jun07Dlg::OnBnClickedMultByBtn()
{
	if (proc != 0)
	{
		// process and display

		float num;
		{
			CString sTmp;

			this->edtAprSize1D.GetWindowTextA(sTmp);

			CString sTmp2 = sTmp.Trim();

			//GlobalStuff::AprSize1D = atoi( sTmp2.GetBuffer() );
			num = atof(sTmp2.GetBuffer());
		}

		proc->MultByNumLinePathImg(num);

		//proc->display();

	}
}

void CMfcCvTut_11Jun07Dlg::OnBnClickedMgrad1s2Btn()
{
	if (proc != 0)
	{
		// process and display

		{
			CString sTmp;

			this->edtAprSize1D.GetWindowTextA(sTmp);

			CString sTmp2 = sTmp.Trim();

			GlobalStuff::AprSize1D = atoi(sTmp2.GetBuffer());
		}

		proc->MorphG1S2LinePathImg(GlobalStuff::AprSize1D);

		//proc->display();

	}
}

void CMfcCvTut_11Jun07Dlg::OnBnClickedTry22Btn()
{
	// TODO: Add your control notification handler code here

	if (proc != 0)
	{
		// process and display


		{
			CString sTmp;

			this->edtAprSize1D.GetWindowTextA(sTmp);

			CString sTmp2 = sTmp.Trim();

			GlobalStuff::AprSize1D = atoi(sTmp2.GetBuffer());
		}


		proc->Try22();

		//proc->display();

	}

}

void CMfcCvTut_11Jun07Dlg::OnBnClickedTry23Btn()
{
	// TODO: Add your control notification handler code here

	if (proc != 0)
	{
		// process and display


		{
			CString sTmp;

			this->edtAprSize1D.GetWindowTextA(sTmp);

			CString sTmp2 = sTmp.Trim();

			GlobalStuff::AprSize1D = atoi(sTmp2.GetBuffer());
		}


		proc->Try23();

		//proc->display();

	}

}

void CMfcCvTut_11Jun07Dlg::OnBnClickedTry24Btn()
{
	// TODO: Add your control notification handler code here

	if (proc != 0)
	{
		// process and display


		{
			CString sTmp;

			this->edtAprSize1D.GetWindowTextA(sTmp);

			CString sTmp2 = sTmp.Trim();

			GlobalStuff::AprSize1D = atoi(sTmp2.GetBuffer());
		}


		proc->Try24();

		//proc->display();

	}

}

void CMfcCvTut_11Jun07Dlg::OnBnClickedTry25Btn()
{
	// TODO: Add your control notification handler code here

	if (proc != 0)
	{
		// process and display


		{
			CString sTmp;

			this->edtAprSize1D.GetWindowTextA(sTmp);

			CString sTmp2 = sTmp.Trim();

			GlobalStuff::AprSize1D = atoi(sTmp2.GetBuffer());
		}


		proc->Try25();

		//proc->display();

	}

}

void CMfcCvTut_11Jun07Dlg::OnBnClickedTry26Btn_0()
{
	// TODO: Add your control notification handler code here

	if (proc != 0)
	{
		// process and display


		{
			CString sTmp;

			this->edtAprSize1D.GetWindowTextA(sTmp);

			CString sTmp2 = sTmp.Trim();

			//GlobalStuff::AprSize1D = atoi( sTmp2.GetBuffer() );
			GlobalStuff::AprSize1D = atof(sTmp2.GetBuffer());
		}


		proc->Try26();

		//proc->display();

	}

}


//	This is the TRUE OnBnClickedTry26Btn()
void CMfcCvTut_11Jun07Dlg::OnBnClickedTry26Btn()
{
	// TODO: Add your control notification handler code here

	if (proc != 0)
	{
		// process and display


		{
			CString sTmp;

			this->edtAprSize1D.GetWindowTextA(sTmp);

			CString sTmp2 = sTmp.Trim();

			//GlobalStuff::AprSize1D = atoi( sTmp2.GetBuffer() );
			GlobalStuff::AprSize1D = atof(sTmp2.GetBuffer());
		}


		proc->Try26();

		//proc->display();

	}

}


void CMfcCvTut_11Jun07Dlg::OnBnClickedCbisBerkExecute()
{
	// TODO: Add your control notification handler code here

	//Ncpp::FixedVector< int > aprSiz_Arr;

	//aprSiz_Arr.PushBack( 11 );
	//aprSiz_Arr.PushBack( 17 );
	//aprSiz_Arr.PushBack( 23 );
	//aprSiz_Arr.PushBack( 29 );
	//aprSiz_Arr.PushBack( 35 );
	//aprSiz_Arr.PushBack( 41 );
	//aprSiz_Arr.PushBack( 47 );
	//aprSiz_Arr.PushBack( 53 );
	//aprSiz_Arr.PushBack( 59 );
	//aprSiz_Arr.PushBack( 65 );

	int aprSiz_Arr[] =
	{ 11, 17, 23, 29, 35, 41, 47, 53, 59, 65 };

	int nofAprSizes = sizeof(aprSiz_Arr) / sizeof(int);

	for (int k = 0; k < nofAprSizes; k++)
	{
		{
			char sTmp[100];

			sprintf(sTmp, "%d", aprSiz_Arr[k]);

			this->edtAprSize1D.SetWindowTextA(sTmp);
		}


		{
		CString sTmp;

		this->edtAprSize1D.GetWindowTextA(sTmp);

		CString sTmp2 = sTmp.Trim();

		GlobalStuff::AprSize1D = atoi(sTmp2.GetBuffer());
	}

		Ncpp::FixedVector< CString > dirPath_Arr(50);


		dirPath_Arr.PushBack(
			//CString sPathTrain = 
			"D:\\HthmWork_D\\Berkeley-Image-DataSet\\BSDS-300\\Final-Extracted\\BSDS300-images\\BSDS300\\images\\train"
			);

		dirPath_Arr.PushBack(
			//CString sPathTest = 
			"D:\\HthmWork_D\\Berkeley-Image-DataSet\\BSDS-300\\Final-Extracted\\BSDS300-images\\BSDS300\\images\\test"
			);


		Ncpp::FixedVector< CString > filePath_Arr(500);

		for (int i = 0; i < dirPath_Arr.GetSize(); i++)
		{
			CString sDirPath = dirPath_Arr[i];

			CFileFind hFile;
			BOOL bFound = hFile.FindFile(sDirPath + _T("\\*.*"));

			while (bFound)
			{
				bFound = hFile.FindNextFile();

				CString sPath_1 = hFile.GetFilePath();

				if ((!hFile.IsDots()) && (!hFile.IsDirectory()))
				{

					///////


					{
						char sAprSize[100];
						sprintf(sAprSize, "%d", (int)GlobalStuff::AprSize1D);

						CString sFilePath =

							//"E:\\HthmWork\\Lib\\BSDS_300_2\\CBIS\\CBIS_" +
							"E:\\HthmWork\\Lib\\BSDS_300_2\\CBIS\\AprSiz" +
							CString(sAprSize) +
							CString("\\Segms\\");

						//Ncv::FilePathMgr fpm1( GlobalStuff::m_imgFilePath.GetBuffer() );
						Ncv::FilePathMgr fpm1(sPath_1.GetBuffer());

						Ncpp::FixedVector< char > fileTitle_Arr;

						fpm1.GetFileTitle(fileTitle_Arr);

						sFilePath +=
							CString(fileTitle_Arr.GetHeadPtr()) + ".seg2";

						CFileFind hFile_2;

						BOOL bFound_2 = hFile_2.FindFile(sFilePath);

						if (bFound_2)
						{
							continue;
						}
						else
						{
							filePath_Arr.PushBack(sPath_1);
						}
					}



					/////////

				}
			}
		}



		int nOld_AllocCnt = Ncpp::FixedVectorDebug::AllocCnt;

		int nOld_AllocCnt_2 = Ncpp::FixedVectorDebug::AllocCnt_2;

		int nOld_AllocSizeTot = Ncpp::FixedVectorDebug::AllocSizeTot;

		int nOld_FixedVectorID = Ncpp::FixedVectorDebug::FixedVectorID++;

		for (int i = 0; i < filePath_Arr.GetSize(); i++)
		{
			//CString sFilePath = sPathTrain + "\\" +
			//"2092.jpg";

			//Ncpp::FixedVectorDebug::Reset_ID_Arr();


			CString sFilePath = filePath_Arr[i];

			if (proc != 0)
				delete proc;

			proc = new ImageProcessor(sFilePath);

			//Ncpp::FixedVectorDebug::CycleNum++;

			proc->TryRS20();

			int a = Ncpp::FixedVectorDebug::AllocCnt;

			int aa = Ncpp::FixedVectorDebug::AllocCnt_2;


			int a2 = Ncpp::FixedVectorDebug::AllocSizeTot;

			int a3 = Ncpp::FixedVectorDebug::FixedVectorID++;

			int nActCnt = 0;

			int nDeactCnt = 0;

			for (int i = 0;
				i < Ncpp::FixedVectorDebug::FixedVectorID_Arr_Size; i++)
				//i < Ncpp::FixedVectorDebug::MaxID_Activated; i++ )
			{
				//if( i >= nOld_FixedVectorID )
				if (Ncpp::FixedVectorDebug::FixedVectorID_Cycle_Arr[i] >=
					Ncpp::FixedVectorDebug::CycleNum)
				{
					if (-1 != Ncpp::FixedVectorDebug::FixedVectorID_Arr[i])
					{
						nActCnt++;

						i = i;
					}
					else
					{
						nDeactCnt++;

						i = i;
					}
				}
			}


			nOld_AllocCnt = a;

			nOld_AllocCnt_2 = aa;

			nOld_AllocSizeTot = a2;

			nOld_FixedVectorID = a3;


		}



		//CBIS_Berkeley_Execute

	}


}

void CMfcCvTut_11Jun07Dlg::OnBnClickedFastAvgColorsBtn()
{
	// TODO: Add your control notification handler code here

	if (proc != 0)
	{
		// process and display

		proc->AvgColorsOfLinePathImg();

		//proc->display();

	}
}
