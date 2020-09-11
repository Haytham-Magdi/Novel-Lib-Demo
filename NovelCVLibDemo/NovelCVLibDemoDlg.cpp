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
		std::string sFolder =
			//"E:\\HthmWork\\Lib\\Projects\\Images";
			//"E:\\HthmWork\\Computer-Vision\\Car-Dent-Detection\\Images";
			// "E:\\HthmWork\\Computer-Vision\\Images";
		//"E:\\HthmWork\\Computer-Vision\\Images\\Filtered-Images";
		//"E:\\HthmWork\\Computer-Vision\\Images\\Filtered-Images2\\Vignette";
			//"E:\\HthmWork\\Computer-Vision\\Images\\Filtered-Images\\white-balance-output";

			"E:\\HthmWork2\\New-Vision-Work\\Healing\\Images";

		// std::string sFile = "\\face-2.png";
		std::string sFile = "\\face-2-part.png";

		////std::string sFile = "h4_3C_3_Dn.jpg";
		////std::string sFile = "h4_3C_3_Dn_By2.jpg";
		////std::string sFile = "diamond_1_Dn_By2.jpg";
		//std::string sFile = "41004.jpg";
		////std::string sFile = "24004.jpg";
		////std::string sFile = "clrpic1_U.jpg";
		////std::string sFile = "clrpic1.jpg";
		////std::string sFile = "White-All.png";

		//std::string sFile = "patternReflection2.png";
		//std::string sFile = "patternReflection2_2.jpg";

		//std::string sFile = "patternReflection1_2.jpg";


		//std::string sFile = "Image_0005_d0.png";
		//std::string sFile = "Image_0005_d0_2.png";
		
		//std::string sFile = "Bitmap_inverse_pattern_from_Bitmap_led_mapping_phase_images_balanced_02 (2).png";
		//std::string sFile = "Bitmap_inverse_pattern_from_Bitmap_led_mapping_phase_images_balanced_02 (2)_2.png";

		//std::string sFile = "paint_1.png";
		//std::string sFile = "paint_filled_1.png";

		//std::string sFile = "bin_images_1.jpg";

		//std::string sFile = "bin_images_2.jpg";
		//std::string sFile = "image_20151117_081741_2.jpg";
		//std::string sFile = "IMG_20151117_075234_2.jpg";
		//std::string sFile = "shapes1.png";
		//std::string sFile = "shapes1-2.png";
		//std::string sFile = "shapes1.jpg";
		// std::string sFile = "shapes2.png";

		//std::string sFile = "hair1.jpg";
		//std::string sFile = "images10.jpg";
		

		//std::string sFile = "desktop-part.png";

		//std::string sFile = "checker-board-16.png";

		//std::string sFile = "grey128_mf.jpeg";
		//std::string sFile = "colorBars03_mf.jpeg";
		//std::string sFile = "colorBars05_rgb128_mf.jpeg";
		//std::string sFile = "colorBars06_rgb128_mf.jpeg";
		//std::string sFile = "colorBars01_mf.jpeg";
		
		//std::string sFile = "\\color-output\\1579460520384.jpg";
		//std::string sFile = "\\color-output\\1579461176026.jpg";
		//std::string sFile = "\\color-output\\1579462261731.jpg";
		
		//std::string sFile = "\\color-output\\1579462670891.jpg";
		//std::string sFile = "\\color-output\\1579462710282.jpg";

		//std::string sFile = "\\color-output\\1579500328813.jpg";
		
		//std::string sFile = "\\color-output\\1579675990833.jpg";
		//std::string sFile = "\\color-output\\1579716916112.jpg";
		
		//std::string sFile = "\\color-output\\1579779178005.jpg";
		//std::string sFile = "\\color-output\\1579779481370.jpg";
		//std::string sFile = "\\color-output\\1579780392833.jpg";
		//std::string sFile = "\\color-output\\1579812542028.jpg";
		
		//std::string sFile = "\\color-output\\1579841895225.jpg";
		//std::string sFile = "\\color-output\\1579841907200.jpg";
		
		//std::string sFile = "\\color-output\\1579842364047.jpg";
		//std::string sFile = "\\color-output\\1579842382585.jpg";
		//std::string sFile = "\\color-output\\1579842982182.jpg";
		
		//std::string sFile = "\\color-output\\1579893546059.jpg";
		//std::string sFile = "\\color-output\\1579894972372.jpg";
		//std::string sFile = "\\color-output\\1579895139964.jpg";
		//std::string sFile = "\\color-output\\1579948777902.jpg";
		//std::string sFile = "\\color-output\\1579951473438.jpg";
		//std::string sFile = "\\color-output\\1579951573618.jpg";

		//std::string sFile = "\\color-output\\1579968834916.jpg";
		//std::string sFile = "\\color-output\\1579977436421.jpg";
		//std::string sFile = "\\color-output\\1579977697702.jpg";
		
		//std::string sFile = "\\color-output\\1580013379540.jpg";
		//std::string sFile = "\\color-output\\1580015533276.jpg";

		//std::string sFile = "\\color-output\\1580017497693.jpg";
		
		//std::string sFile = "\\color-output\\1580118992211.jpg";
		//std::string sFile = "\\color-output\\1580130136255.jpg";
		
		//std::string sFile = "\\color-output\\1580142532506.jpg";
		//std::string sFile = "\\color-output\\1580148277403.jpg";
		//std::string sFile = "\\color-output\\1580148875533.jpg";
		
		//std::string sFile = "\\color-output\\1580219775502.jpg";
		//std::string sFile = "\\color-output\\1580284643054.jpg";

		//std::string sFile = "\\color-output\\1580297096527.jpg";
		//std::string sFile = "\\color-output\\1580299376402.jpg";

		//std::string sFile = "\\color-output\\1580308486796.jpg";
		//std::string sFile = "\\color-output\\1580311030608.jpg";
		
		//std::string sFile = "\\color-output\\1580311272499.jpg";
		//std::string sFile = "\\color-output\\1580311546591.jpg";
				
		//std::string sFile = "\\color-output\\1580311899802.jpg";

		//std::string sFile = "\\color-output\\1580312259410.jpg";
		//std::string sFile = "\\color-output\\1580323169522.jpg";

		//std::string sFile = "\\color-output\\1580335880997.jpg";
		//std::string sFile = "\\color-output\\1580337118565.jpg";
		
		//std::string sFile = "\\color-output\\1580337735794.jpg";
		
		//std::string sFile = "\\color-output\\1580338108170.jpg";
		//std::string sFile = "\\color-output\\1580338747914.jpg";
		
		//std::string sFile = "\\color-output\\1580369771901.jpg";
		//std::string sFile = "\\color-output\\1580370496761.jpg";
				
		//std::string sFile = "\\color-output\\1580481146329.jpg";
		//std::string sFile = "\\color-output\\1580487698126.jpg";
		//std::string sFile = "\\color-output\\1580495182200.jpg";
		
		//std::string sFile = "\\color-output\\1580496141665.jpg";
		//std::string sFile = "\\color-output\\1580496784879.jpg";


		//std::string sFile = "\\lr\\lr_all-hues-sats (13).jpg";

		//std::string sFile = "\\lr\\lr_all-hues-sats (15).jpg";
		//std::string sFile = "\\lr\\lr_all-hues-sats (16).jpg";
		//std::string sFile = "\\lr\\lr_all-hues-sats (17).jpg";


		//std::string sFile = "\\color-output\\1580560127590.jpg";
		//std::string sFile = "\\color-output\\1580587605460.jpg";
		//std::string sFile = "\\color-output\\1580588078341.jpg";
		//std::string sFile = "\\color-output\\1580588799019.jpg";
		//std::string sFile = "\\color-output\\1580589206589.jpg";
		////std::string sFile = "\\color-output\\1580589676528.jpg";
		
		//std::string sFile = "\\color-output\\1580658074648.jpg";
		////std::string sFile = "\\color-output\\1580675140158.jpg";
		
	
		//	tuning saturation.

		//std::string sFile = "\\lr\\lr_all-hues-sats (14).jpg";
		
		//std::string sFile = "\\color-output\\1580701608787.jpg";
		//std::string sFile = "\\color-output\\1580708074741.jpg";
		//std::string sFile = "\\color-output\\1580708420283.jpg";

		//std::string sFile = "\\color-output\\1580758486413.jpg";
		//std::string sFile = "\\color-output\\1580759115326.jpg";
		//std::string sFile = "\\color-output\\1580759437925.jpg";
		//std::string sFile = "\\color-output\\1580759784192.jpg";

		// // work on rgb

		//std::string sFile = "\\color-output\\1580783289146.jpg";
		//std::string sFile = "\\color-output\\1580783311005.jpg";

		//std::string sFile = "\\color-output\\1580820667490.jpg";
		//std::string sFile = "\\color-output\\1580820690285.jpg";

		//	//		

		//std::string sFile = "\\color-output\\1580829309121.jpg";
		//std::string sFile = "\\color-output\\1580829871398.jpg";
		//std::string sFile = "\\color-output\\1580830899418.jpg";

		//std::string sFile = "\\color-output\\1580861681041.jpg";
		
		//std::string sFile = "\\color-output\\1580882679116.jpg";
		//std::string sFile = "\\color-output\\1580884848816.jpg";
		//std::string sFile = "\\color-output\\1580886464584.jpg";
		//std::string sFile = "\\color-output\\1580889393428.jpg";
		
		//std::string sFile = "\\color-output\\1580976451943.jpg";

		//std::string sFile = "\\color-output\\1581059903233.jpg";
		//std::string sFile = "\\color-output\\1581061115961.jpg";
		//std::string sFile = "\\color-output\\1581061500095.jpg";
		
		//std::string sFile = "\\color-output\\1581081143702.jpg";
		
		//std::string sFile = "\\color-output\\1581159792691.jpg";
		//std::string sFile = "\\color-output\\1581160588308.jpg";
		
		//std::string sFile = "\\color-output\\1581161097080.jpg";
		//std::string sFile = "\\color-output\\1581161749819.jpg";
		
		//std::string sFile = "\\color-output\\1581161972188.jpg";
		//std::string sFile = "\\color-output\\1581163475320.jpg";

		//std::string sFile = "\\color-output\\1581250781009.jpg";
		//std::string sFile = "\\color-output\\1581252075591.jpg";
		
		//std::string sFile = "\\color-output\\1581260788690.jpg";
		//std::string sFile = "\\color-output\\1581276615383.jpg";
		//std::string sFile = "\\color-output\\1581277171470.jpg";
		//std::string sFile = "\\color-output\\1581277798444.jpg";
		//std::string sFile = "\\color-output\\1581278876650.jpg";

		//std::string sFile = "\\color-output\\1581296536489.jpg";
		//std::string sFile = "\\color-output\\1581297146274.jpg";
		//std::string sFile = "\\color-output\\1581298050097.jpg";


		

		//std::string sFile = "test1.jpg";


		//std::string sFile = "savedImage.png";

		//std::string sFile = "lr\\lr_all-hues-sats.jpg";
		//std::string sFile = "lr\\lr_all-hues-sats (1).jpg";
		//std::string sFile = "lr\\lr_all-hues-sats (2).jpg";
		//std::string sFile = "lr\\lr_all-hues-sats (3).jpg";

		//std::string sFile = "lr\\lr_all-hues-sats (4).jpg";
		//std::string sFile = "lr\\lr_all-hues-sats (5).jpg";
		//std::string sFile = "lr\\lr_all-hues-sats (6).jpg";
		//std::string sFile = "lr\\lr_all-hues-sats (7).jpg";
		//std::string sFile = "lr\\lr_all-hues-sats (8).jpg";
		//std::string sFile = "lr\\lr_all-hues-sats (9).jpg";
		//std::string sFile = "lr\\lr_all-hues-sats (10).jpg";
		//std::string sFile = "lr\\lr_all-hues-sats (11).jpg";
		//std::string sFile = "lr\\lr_all-hues-sats (12).jpg";
		
		//std::string sFile = "lr\\lr_all-hues-sats-and-brightnesses.jpg";

		
		
		//std::string sFile = "savedImage.jpeg";
		
		//std::string sFile = "black_mf.jpeg";
		//std::string sFile = "white_mf.jpeg";
		//std::string sFile = "yellow_mf.jpeg";
		//std::string sFile = "yellow128_mf.jpeg";

		

		//std::string sFile = "savedImage.jpeg";
		
		
		//std::string sFile = "colorBars05_rgb128.png";
		//std::string sFile = "colorBars05_rgb128_wb_t100.jpeg";
		//std::string sFile = "colorBars05_rgb128_wb_t50.jpeg";
		//std::string sFile = "colorBars05_rgb128_wb_tm50.jpeg";
		//std::string sFile = "colorBars05_rgb128_wb_tm100.jpeg";

		//std::string sFile = "colorBars05_rgb128_wb_n100.jpeg";

		//std::string sFile = "colorBars06_rgb128_wb_t100.jpeg";
		//std::string sFile = "colorBars06_rgb128_wb_tm100.jpeg";
		//std::string sFile = "colorBars06_rgb128_wb_n100.jpeg";
		

		//std::string sFile = "grey128_wb_t100.jpeg";
		//std::string sFile = "grey128_wb_n100.jpeg";

		//std::string sFile = "white_wb_t100.jpeg";
		//std::string sFile = "white_wb_n100.jpeg";

		//std::string sFile = "colorBars02_wb_t100.jpeg";


		//std::string sFile = "grey128_vign_inr_50.jpeg";
		//std::string sFile = "grey128_vign_inr_100.jpeg";
		//std::string sFile = "grey128_vign_inr_m100.jpeg";
		
		//std::string sFile = "grey128_vign_out_50.jpeg";

		//std::string sFile = "black_vign_inr_50.jpeg";
		//std::string sFile = "black_vign_out_50.jpeg";
		//std::string sFile = "black_vign_out_m50.jpeg";

		//std::string sFile = "grey64_vign_inr_50.jpeg";
		//std::string sFile = "grey64_vign_inr_m50.jpeg";
		//std::string sFile = "grey64_vign_out_50.jpeg";
		//std::string sFile = "grey64_vign_out_m50.jpeg";

		//std::string sFile = "white_vign_out_50.jpeg";
		//std::string sFile = "white_vign_out_m50.jpeg";
		//std::string sFile = "white_vign_inr_m100.jpeg";

		//std::string sFile = "grey128_vign_out_m25.jpeg";
		//std::string sFile = "grey128_vign_out_m50.jpeg";
		//std::string sFile = "grey128_vign_out_m75.jpeg";
		//std::string sFile = "grey128_vign_out_m100.jpeg";

		//std::string sFile = "Not-Used-Temp\\grey128_vign_out_m50_inr_m50.jpeg";
		

		//std::string sFile = "blue128_vign_out_m50.jpeg";
		//std::string sFile = "green128_vign_out_m50.jpeg";
		//std::string sFile = "red128_vign_out_m50.jpeg";



		//std::string sFile = "Bitmap_inverse_pattern_from_Bitmap_led_mapping_phase_images_balanced_02(2)_by2.png";
		//std::string sFile = "Bitmap_inverse_pattern_from_Bitmap_led_mapping_phase_images_balanced_02(2)_by2.jpg";
		//std::string sFile = "Bitmap_inverse_pattern_from_Bitmap_led_mapping_phase_images_balanced_02(2)_by2.jpg";
		//std::string sFile = "car-dent_balanced_02.jpg";


		//std::string sFile = "bin_images_3.jpg";
		//std::string sFile = "Fig-3-1-Binarization-using-Otsu's-method-2-smooth-operation-3-second-binarization.png";

		//std::string sFile = "Hydrangeas.jpg";

		std::string path = sFolder + "\\" + sFile;

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
		std::string path = dlg.GetPathName().GetBuffer(0);

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

			std::string sTmp2 = sTmp.Trim().GetBuffer(0);

			nAprSiz = atoi(sTmp2.c_str());
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

		GlobalStuff::AprSize1D = atoi(sTmp2.GetBuffer(0));
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
//						cv::Circle (
//						img1->GetMat(),
//						cv::Point( a_x, a_y ),
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


