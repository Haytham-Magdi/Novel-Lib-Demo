// NovelCVLibDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NovelCVLibDemo.h"
#include "NovelCVLibDemoDlg.h"
#include "cvapp.h"

#include <NovelCVLib\OpenCV\funcs1.h>

#include <NovelCVLib\Ncpp\Common\FixedVector.h>

#include <NovelCVLib\Ncpp\Common\FilePathMgr.h>




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


// CNovelCVLibDemoDlg dialog




CNovelCVLibDemoDlg::CNovelCVLibDemoDlg(CWnd* pParent /*=NULL*/)
: CDialog(CNovelCVLibDemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNovelCVLibDemoDlg::DoDataExchange(CDataExchange* pDX)
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





BEGIN_MESSAGE_MAP(CNovelCVLibDemoDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_OPEN_IMAGE_BTN, &CNovelCVLibDemoDlg::OnBnClickedOpenImageBtn)
	ON_BN_CLICKED(IDC_PROCESS_IMAGE_BTN, &CNovelCVLibDemoDlg::OnBnClickedProcessImageBtn)
	ON_BN_CLICKED(IDC_CREATE_BTN, &CNovelCVLibDemoDlg::OnBnClickedCreateBtn)

	ON_BN_CLICKED(IDC_FAST_AVG_BTN, &CNovelCVLibDemoDlg::OnBnClickedFastAvgBtn)

	//	ON_LBN_SELCHANGE(IDC_LIST2, &CNovelCVLibDemoDlg::OnLbnSelchangeList2)
	ON_BN_CLICKED(IDC_TRY_MOUSE_BTN, &CNovelCVLibDemoDlg::OnBnClickedTryMouseBtn)
	ON_BN_CLICKED(IDC_CLEAR_IO, &CNovelCVLibDemoDlg::OnBnClickedClearIo)
	ON_BN_CLICKED(IDC_DRAW_LINE_PATH, &CNovelCVLibDemoDlg::OnBnClickedDrawLinePath)
	ON_BN_CLICKED(IDC_AVG_BTN, &CNovelCVLibDemoDlg::OnBnClickedAvgBtn)
	ON_BN_CLICKED(IDC_RESET_BTN, &CNovelCVLibDemoDlg::OnBnClickedResetBtn)
	ON_BN_CLICKED(IDC_SIZE_UP_BTN, &CNovelCVLibDemoDlg::OnBnClickedSizeUpBtn)
	ON_BN_CLICKED(IDC_SIZE_DOWN_BTN, &CNovelCVLibDemoDlg::OnBnClickedSizeDownBtn)
	ON_BN_CLICKED(IDC_SAVE_TO_FILE_BTN, &CNovelCVLibDemoDlg::OnBnClickedSaveToFileBtn)
	ON_BN_CLICKED(IDC_CLIP_BTN, &CNovelCVLibDemoDlg::OnBnClickedClipBtn)
	ON_BN_CLICKED(IDC_THRESHOLD_BTN, &CNovelCVLibDemoDlg::OnBnClickedThresholdBtn)
	ON_BN_CLICKED(IDC_UNDO_BTN, &CNovelCVLibDemoDlg::OnBnClickedUndoBtn)
	ON_BN_CLICKED(IDC_REDO_BTN, &CNovelCVLibDemoDlg::OnBnClickedRedoBtn)
	ON_BN_CLICKED(IDC_DILATE_BTN, &CNovelCVLibDemoDlg::OnBnClickedDilateBtn)
	ON_BN_CLICKED(IDC_ERODE_BTN, &CNovelCVLibDemoDlg::OnBnClickedErodeBtn)
	ON_BN_CLICKED(IDC_MEDIAN_BTN, &CNovelCVLibDemoDlg::OnBnClickedMedianBtn)
	ON_BN_CLICKED(IDC_EQUALIZE_HIST_BTN, &CNovelCVLibDemoDlg::OnBnClickedEqualizeHistBtn)
	ON_BN_CLICKED(IDC_GRAY_BTN, &CNovelCVLibDemoDlg::OnBnClickedGrayBtn)
	ON_BN_CLICKED(IDC_MULT_BY_BTN, &CNovelCVLibDemoDlg::OnBnClickedMultByBtn)
	ON_BN_CLICKED(IDC_TRY26_BTN, &CNovelCVLibDemoDlg::OnBnClickedTry26Btn)
END_MESSAGE_MAP()


// CNovelCVLibDemoDlg message handlers

BOOL CNovelCVLibDemoDlg::OnInitDialog()
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

void CNovelCVLibDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CNovelCVLibDemoDlg::OnPaint()
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
HCURSOR CNovelCVLibDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CNovelCVLibDemoDlg::OnBnClickedOpenImageBtn()
{
	//if (false)
	{
		CString sFolder =
			//"E:\\HthmWork\\Lib\\Projects\\Images";
			//"E:\\HthmWork\\Computer-Vision\\Car-Dent-Detection\\Images";
			"E:\\HthmWork\\Computer-Vision\\Images";
			//"E:\\HthmWork\\Computer-Vision\\Images\\Filtered-Images";
			//"E:\\HthmWork\\Computer-Vision\\Images\\Filtered-Images\\white-balance-output";

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

		//CString sFile = "bin_images_2.jpg";
		//CString sFile = "image_20151117_081741_2.jpg";
		//CString sFile = "IMG_20151117_075234_2.jpg";
		//CString sFile = "shapes1.png";
		//CString sFile = "shapes1-2.png";
		//CString sFile = "shapes1.jpg";
		//CString sFile = "shapes2.png";

		CString sFile = "desktop-part.png";

		//CString sFile = "grey128_mf.jpeg";
		//CString sFile = "colorBars03_mf.jpeg";
		//CString sFile = "colorBars05_rgb128_mf.jpeg";
		//CString sFile = "colorBars06_rgb128_mf.jpeg";
		//CString sFile = "colorBars01_mf.jpeg";
		
		//CString sFile = "savedImage.jpeg";
		
		//CString sFile = "black_mf.jpeg";
		//CString sFile = "white_mf.jpeg";
		//CString sFile = "yellow_mf.jpeg";
		//CString sFile = "yellow128_mf.jpeg";

		

		//CString sFile = "savedImage.jpeg";
		
		
		//CString sFile = "colorBars05_rgb128.png";
		//CString sFile = "colorBars05_rgb128_wb_t100.jpeg";
		//CString sFile = "colorBars05_rgb128_wb_t50.jpeg";
		//CString sFile = "colorBars05_rgb128_wb_tm50.jpeg";
		//CString sFile = "colorBars05_rgb128_wb_tm100.jpeg";

		//CString sFile = "colorBars05_rgb128_wb_n100.jpeg";

		//CString sFile = "colorBars06_rgb128_wb_t100.jpeg";
		//CString sFile = "colorBars06_rgb128_wb_tm100.jpeg";
		//CString sFile = "colorBars06_rgb128_wb_n100.jpeg";
		

		//CString sFile = "grey128_wb_t100.jpeg";
		//CString sFile = "grey128_wb_n100.jpeg";

		//CString sFile = "white_wb_t100.jpeg";
		//CString sFile = "white_wb_n100.jpeg";

		//CString sFile = "colorBars02_wb_t100.jpeg";



		//CString sFile = "Bitmap_inverse_pattern_from_Bitmap_led_mapping_phase_images_balanced_02(2)_by2.png";
		//CString sFile = "Bitmap_inverse_pattern_from_Bitmap_led_mapping_phase_images_balanced_02(2)_by2.jpg";
		//CString sFile = "Bitmap_inverse_pattern_from_Bitmap_led_mapping_phase_images_balanced_02(2)_by2.jpg";
		//CString sFile = "car-dent_balanced_02.jpg";


		//CString sFile = "bin_images_3.jpg";
		//CString sFile = "Fig-3-1-Binarization-using-Otsu's-method-2-smooth-operation-3-second-binarization.png";

		//CString sFile = "Hydrangeas.jpg";

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

void CNovelCVLibDemoDlg::OnBnClickedProcessImageBtn()
{
	if (proc != 0)
	{
		// process and display

		proc->execute();

		proc->display();

	}

}

void CNovelCVLibDemoDlg::OnBnClickedCreateBtn()
{
	//if (proc != 0) 

	if (proc != 0)
		delete proc;

	// Create and display

	proc = new ImageProcessor();

	proc->Create();

	proc->display();

}


void CNovelCVLibDemoDlg::OnBnClickedFastAvgBtn()
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

void CNovelCVLibDemoDlg::OnLbnSelchangeList2()
{
	// TODO: Add your control notification handler code here
}



void CNovelCVLibDemoDlg::InitIOValues()
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



void CNovelCVLibDemoDlg::ReadString(char * a_sKey, char * a_buff)
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


bool CNovelCVLibDemoDlg::ValueExists(char * a_sKey)
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


void CNovelCVLibDemoDlg::LinePath_Mouse_Callback(
	int a_event, int a_x, int a_y, int a_flags, void* a_param)
{

	CNovelCVLibDemoDlg * pDlg = (CNovelCVLibDemoDlg *)a_param;


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
		else
		{
			proc->DrawPntOnLinePathImg();
		}


	}


}



//void CNovelCVLibDemoDlg::RgnSgmImg_Mouse_Callback(
//	int a_event, int a_x, int a_y, int a_flags, void* a_param)
//{
//	CNovelCVLibDemoDlg * pDlg = (CNovelCVLibDemoDlg *)a_param;
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









void CNovelCVLibDemoDlg::OnBnClickedTryMouseBtn()
{
	//cvSetMouseCallback( "avgImg", LinePath_Mouse_Callback, (void*) this );
}

void CNovelCVLibDemoDlg::OnBnClickedClearIo()
{
	DoClearIo();
}

void CNovelCVLibDemoDlg::DoClearIo()
{
	while (m_listKeys.GetCount() > 0)
		m_listKeys.DeleteString(0);

	while (m_listValues.GetCount() > 0)
		m_listValues.DeleteString(0);

	this->m_nMouseLBCnt = 0;
}

void CNovelCVLibDemoDlg::OnBnClickedDrawLinePath()
{
	if (proc != 0)
	{
		// process and display

		proc->DrawLinePath();

		//proc->display();

	}
}

void CNovelCVLibDemoDlg::OnBnClickedAvgBtn()
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

void CNovelCVLibDemoDlg::OnBnClickedResetBtn()
{

	if (proc != 0)
	{
		// process and display

		proc->ResetLinePathImg();

		//proc->display();

	}
}

void CNovelCVLibDemoDlg::OnBnClickedSizeUpBtn()
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

void CNovelCVLibDemoDlg::OnBnClickedSizeDownBtn()
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

void CNovelCVLibDemoDlg::OnBnClickedSaveToFileBtn()
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

void CNovelCVLibDemoDlg::OnBnClickedClipBtn()
{
	// TODO: Add your control notification handler code here

	if (proc != 0)
	{
		// process and display

		proc->ClipLinePathImg();

		//proc->display();

	}
}


void CNovelCVLibDemoDlg::OnBnClickedThresholdBtn()
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

void CNovelCVLibDemoDlg::OnBnClickedUndoBtn()
{
	// TODO: Add your control notification handler code here

	if (proc != 0)
	{
		// process and display

		proc->Undo();

		//proc->display();

	}

}

void CNovelCVLibDemoDlg::OnBnClickedRedoBtn()
{
	// TODO: Add your control notification handler code here

	if (proc != 0)
	{
		// process and display

		proc->Redo();

		//proc->display();

	}

}

void CNovelCVLibDemoDlg::OnBnClickedDilateBtn()
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

void CNovelCVLibDemoDlg::OnBnClickedErodeBtn()
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

void CNovelCVLibDemoDlg::OnBnClickedMedianBtn()
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

void CNovelCVLibDemoDlg::OnBnClickedEqualizeHistBtn()
{

	if (proc != 0)
	{
		// process and display

		proc->EqualizeHistLinePathImg();

		//proc->display();

	}
}

void CNovelCVLibDemoDlg::OnBnClickedGrayBtn()
{
	// TODO: Add your control notification handler code here

	if (proc != 0)
	{
		// process and display

		proc->ConvToGrayLinePathImg();

		//proc->display();

	}
}


void CNovelCVLibDemoDlg::OnBnClickedMultByBtn()
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


void CNovelCVLibDemoDlg::OnBnClickedTry26Btn_0()
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
void CNovelCVLibDemoDlg::OnBnClickedTry26Btn()
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


