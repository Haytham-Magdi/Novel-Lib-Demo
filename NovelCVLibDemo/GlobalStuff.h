#pragma once


#include <NovelCVLib\Ncpp\Common\commonLib_Misc.h>
#include <NovelCVLib\Ncpp\Math\mathLib.h>
#include <NovelCVLib\OpenCV\CvIncludes.h>
#include <NovelCVLib\OpenCV\Types.h>
#include <NovelCVLib\OpenCV\error.h>
#include <vector>
#include <NovelCVLib\OpenCV\Channel.h>
#include <NovelCVLib\OpenCV\Image.h>

//#include <NovelCVLib\Ncv\RegionSegmentor20.h>



class GlobalStuff
{
public:
	GlobalStuff(void);
	~GlobalStuff(void);


	static Ncv::F32ImageRef OrgImg;


	static void ResetLinePathImg()
	{
		m_linePathImgIndex = -1;
		m_linePathImgVect.ResetSize();

		SetLinePathImg( OrgImg );		
	}

	static void ShowLinePathImg( Ncv::F32ImageRef a_dspImg = NULL )
	//static void ShowLinePathImg( Ncv::F32ImageRef a_dspImg )
	{
		if( NULL == a_dspImg )
			a_dspImg = GlobalStuff::GetLinePathImg();

		ShowImage( a_dspImg, "LinePathImg" );
	}



	static Ncv::F32ImageRef GetLinePathImg( )
	{
		return m_linePathImgVect[ m_linePathImgIndex ];
	}

	static void SetLinePathImg( Ncv::F32ImageRef a_src )
	{
		m_linePathImgIndex++;
		m_linePathImgVect.SetSize( m_linePathImgIndex + 1 );

		m_linePathImgVect[ m_linePathImgIndex ] = a_src;
	}




	static bool UndoLinePathImg( )
	{
		if( m_linePathImgIndex <= 0 )
			return false;

		m_linePathImgIndex--;

		return true;
	}

	static bool RedoLinePathImg( )
	{
		if( m_linePathImgIndex >= m_linePathImgVect.GetSize() - 1 )
			return false;

		m_linePathImgIndex++;

		return true;
	}


	static Ncv::F32Point GetPoint0( )
	{
		return m_point0;
	}

	static Ncv::F32Point GetPoint1( )
	{
		return m_point1;
	}

	static void SetPoint0( Ncv::F32Point & a_pnt )
	{
		m_point0 = a_pnt;
	}

	static void SetPoint1( Ncv::F32Point & a_pnt )
	{
		m_point1 = a_pnt;
	}


	

public:

	//static int AprSize1D;
	static float AprSize1D;
	static int ScanDir;
	
	static int m_nLA_Index;

	static CString m_imgFilePath;
	

protected:

	//static Ncv::F32ImageRef LinePathImg;
	
	//static std::vector < Ncv::F32ImageRef > m_linePathImgVect;
	static Ncpp::FixedVector < Ncv::F32ImageRef > m_linePathImgVect;

	static int m_linePathImgIndex;

	static Ncv::F32Point m_point0;
	static Ncv::F32Point m_point1;


};
