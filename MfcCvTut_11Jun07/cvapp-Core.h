#if !defined IMAGEPROCESSOR

#define IMAGEPROCESSOR


#pragma warning(disable : 4996)


#include <stdio.h>

#include <math.h>

#include <string.h>

//#include "cv.h"      // include core library interface
//#include "cxcore.h"      
//#include "cvcompat.h"    
//#include "cvaux.h"
//
//#include "highgui.h" // include GUI library interface


//#include <opencv.hpp>
//#include <D:\HthmWork_D\OpenCV-2.3.1-win-superpack\opencv\build\include\opencv2\opencv.hpp>


#include "GlobalStuff.h"


#include <Lib\Novel\Ncv\Image.h>


void InitLibs(void);


class ImageProcessor {

 

	Ncv::U8ImageRef img;

 

  public:

    ImageProcessor()
	{
		Create();
		
		Init_FixedVectorDebug();
	}

	void Init_FixedVectorDebug()
	{
		m_fixedVectorDebug_AllocSizeTot = 0;

		s_pProc = this;

		//Ncpp::FixedVectorDebug::pFunc_Update = this->Update_FixedVectorDebug;
		Ncpp::FixedVectorDebug::pFunc_Update = ImageProcessor::S_Update_FixedVectorDebug;
	}


	static void S_Update_FixedVectorDebug()
	{
		s_pProc->Update_FixedVectorDebug();
	}
	static ImageProcessor * s_pProc;


	void Update_FixedVectorDebug()
	{
		int nOldVal = m_fixedVectorDebug_AllocSizeTot;

		m_fixedVectorDebug_AllocSizeTot =
			Ncpp::FixedVectorDebug::AllocSizeTot;

		if( m_fixedVectorDebug_AllocSizeTot - nOldVal > 50000000 )
			m_fixedVectorDebug_AllocSizeTot = m_fixedVectorDebug_AllocSizeTot;

		if( m_fixedVectorDebug_AllocSizeTot > 200000000 )
			m_fixedVectorDebug_AllocSizeTot = m_fixedVectorDebug_AllocSizeTot;

		if( m_fixedVectorDebug_AllocSizeTot > 400000000 )
			m_fixedVectorDebug_AllocSizeTot = m_fixedVectorDebug_AllocSizeTot;

		if( m_fixedVectorDebug_AllocSizeTot > 800000000 )
			m_fixedVectorDebug_AllocSizeTot = m_fixedVectorDebug_AllocSizeTot;

		if( m_fixedVectorDebug_AllocSizeTot > 1200000000 )
			m_fixedVectorDebug_AllocSizeTot = m_fixedVectorDebug_AllocSizeTot;
	}

	LONGLONG m_fixedVectorDebug_AllocSizeTot;


    ImageProcessor(CString filename, bool display=true) 
	{
		Init_FixedVectorDebug();
    
		//auto v1 = cvvLoadImage(filename);

		img = new Ncv::U8Image(
		  cvvLoadImage( filename )); // load image

		GlobalStuff::m_imgFilePath = filename;
 

      if (display) {


		  {

				Ncv::F32ImageRef src = GenF32FromS16Image(
					GenS16FromU8Image(img));
				Ncv::F32ImageRef res = src;

				if( false )
				{
					Ncv::F32ColorVal * srcBuf = 
						(Ncv::F32ColorVal *)src->GetPixAt( 0, 0 );

					CvSize srcSiz = src->GetSize();

					int nSrcSiz1D = srcSiz.width * srcSiz.height;

					for( int i=0; i < nSrcSiz1D; i++ )
					{
						Ncv::F32ColorVal & rColor = srcBuf[ i ];

						if( rColor.val0 > 30 )
							i = i;

						rColor.val0 = 0;
						rColor.val2 = 0;
					}


				}

				GlobalStuff::OrgImg = res;

				
				GlobalStuff::ResetLinePathImg();

				//GlobalStuff::SetLinePathImg(
					//GlobalStuff::OrgImg->Clone() );



		  }
 
        //cvvNamedWindow( "Original Image", 1 );  
        //cvvShowImage( "Original Image", img->GetIplImagePtr() );  

        cvvNamedWindow( "LinePathImg", 1 );  
        cvvShowImage( "LinePathImg", img->GetIplImagePtr() );  


		//ShowImage(img->GetIplImagePtr(), "Original Image" );  

      }

    }

 

    void display() {

 

      cvvNamedWindow( "Resulting Image", 1 );  

      cvvShowImage( "Resulting Image", img->GetIplImagePtr() );  

    }

 

    void execute();
    void Sobel();
    void Try1();
    void Try2();
    void Try3();
    void Try4();
    void Try5();
    void Try6();
    void Try7();	
    void Clusters();	
    void Try8();	
    void Try9();	
    void Try10();	
    void FastAvg();	
    void MaxMinEdge();	
    void Try11();	
    void Try12();	
    void Try13();	
    void Try14();	
    void Try15();	
    void EdgeDir2();		
    void EdgeDir();	
    void Try16();	
    void Try17();	
    void Try18();	
    void Try19();		
    void Try20();	
    void Try22();	
    void Try23();	
    void Try24();	
    void Try25();	
	void Try26_0();
	void Try26();
	void Try26_1();
	void Try26_2();
	void Try26_3();
	void Try26_4();
	void Try26_5();
    void TryRS20();	
    void Undo();	
    void Redo();	
	void DrawLinePath();
	void CircPntOfLinePathImg( int a_x, int a_y );
	void CircPntOfLinePathImg2( int a_x, int a_y );
	void CircPntOfLinePathImg3( int a_x, int a_y );

	void ClipLinePathImg();
	void AvgColorsOfLinePathImg();
	void AvgLinePathImg(int a_nAprSiz);
	void FastAvgLinePathImg(int a_nAprSiz);
	void MorphGradLinePathImg(int a_nAprSiz);
	void MorphG1S2LinePathImg(int a_nAprSiz);
	void MultByNumLinePathImg(float a_num);
	void MedianLinePathImg(int a_nAprSiz);
	void DilateLinePathImg(int a_nAprSiz);
	void ErodeLinePathImg(int a_nAprSiz);
	void SizeUpLinePathImg(int a_val);
	void SizeDownLinePathImg(int a_val);
	void SaveLinePathImg(char * a_fileName);
	void ThresholdLinePathImg(float a_val);
	void ConvToGrayLinePathImg();


	void EqualizeHistLinePathImg();

	void ResetLinePathImg();
    void SobelMax();		
    void Create();

 

    ~ImageProcessor() {

 

      //cvReleaseImage( &img ); 

    }

};

 

extern ImageProcessor *proc;

 

#endif

 

 
