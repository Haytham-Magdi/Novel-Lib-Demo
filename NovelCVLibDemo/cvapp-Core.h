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


#include <NovelCVLib\OpenCV\Image.h>


void InitLibs(void);


class ImageProcessor {

 

	Ncv::U8ImageRef img;

	//LONGLONG m_fixedVectorDebug_AllocSizeTot;
	long long m_fixedVectorDebug_AllocSizeTot;



  public:

    ImageProcessor()
	{
		Create();
		
		Init_FixedVectorDebug();
	}

	static void S_Update_FixedVectorDebug()
	{
		s_pProc->Update_FixedVectorDebug();
	}
	static ImageProcessor * s_pProc;


	void Init_FixedVectorDebug()
	{
		m_fixedVectorDebug_AllocSizeTot = 0;

		s_pProc = this;

		////Ncpp::FixedVectorDebug::pFunc_Update = this->Update_FixedVectorDebug;
		Ncpp::FixedVectorDebug::pFunc_Update = ImageProcessor::S_Update_FixedVectorDebug;
	}


	void Update_FixedVectorDebug()
	{
		//LONGLONG nOldVal = m_fixedVectorDebug_AllocSizeTot;
		long long nOldVal = m_fixedVectorDebug_AllocSizeTot;

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



    ImageProcessor(std::string filename, bool display=true) 
	{
		Init_FixedVectorDebug();
    
		//auto v1 = cvvLoadImage(filename);

		Ncv::CvMatRef matRef = new cv::Mat();
		*matRef = cv::imread(filename);

		img = new Ncv::U8Image(
			//cvvLoadImage(filename)); // load image
				matRef
			); // load image

		GlobalStuff::m_imgFilePath = filename;
 

      if (display) {


		  {

			  //Ncv::F32ImageRef src = GenF32FromS16Image(
				 // GenS16FromU8Image(img));


				Ncv::S16ImageRef src16 = GenS16FromU8Image(img);
				
				Ncv::F32ImageRef src = GenF32FromS16Image(src16);

				Ncv::F32ImageRef res = src;

				if( false )
				{
					Ncv::F32ColorVal * srcBuf = 
						(Ncv::F32ColorVal *)src->GetPixAt( 0, 0 );

					cv::Size srcSiz = src->GetSize();

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
 
        cv::namedWindow("LinePathImg", 1 );  
        cv::imshow( "LinePathImg",  img->GetMat());  

	  }	//	end if

    }

 

    void display() {
		cv::namedWindow("Resulting Image", 1);
		cv::imshow("Resulting Image", img->GetMat() );  
    }

 

    void execute();
    void Sobel();

	void FastAvg();	
    void MaxMinEdge();	

	void EdgeDir2();		
    void EdgeDir();	

	void Try26_0();
	void Try26();
	void Try26_1();
	void Try26_2();
	void Try26_3();
	void Try26_4();
	void Try26_5();
	
	void Try26_10();
    
	void Undo();	
    void Redo();	
	void DrawLinePath();
	void DrawPntOnLinePathImg();

	void ClipLinePathImg();
	//void AvgColorsOfLinePathImg();
	void AvgLinePathImg(int a_nAprSiz);
	void FastAvgLinePathImg(int a_nAprSiz);
	//void MorphGradLinePathImg(int a_nAprSiz);
	//void MorphG1S2LinePathImg(int a_nAprSiz);
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

 

 
