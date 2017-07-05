//#include <vector.h>

#include "cvapp.h"
//#include <Novel-Lib\Ncv\SignalOneDim.h>
#include "GlobalStuff.h"

#include <Novel-Lib\Ncv\TempImageAccessor.h>
#include <Novel-Lib\Ncv\VectorVal.h>
#include <Novel-Lib\Ncv\ImgSizeRotationColl.h>

//#include <Novel-Lib\Ncv\CircleContourOfPix.h>

using namespace Ncpp;
using namespace Ncv;
using namespace Ncv::Image_Operations;
using namespace Ncv::ImageAccessorOperations;
//using namespace Ncv::Ns;

//using namespace Ncpp::MfcEx;


class Base;

void Try11(Base * a_pBase);
void Try12(PtrRef<Base> br);


//fdgfdgdfg

// A global variable

ImageProcessor *proc = 0;



// the function that processes the image

void process(U8ImageRef img)
{


	int j = 1;

	for (int i = 0; i < 1; i++)
	{
		cvErode(img->GetIplImagePtr(),
			img->GetIplImagePtr(), 0, j);

		//	   cvDilate( img->GetIplImagePtr(), 
		//		   img->GetIplImagePtr(), 0, j );

	}
}

class Obj2 : FRM_Object
{
};


class Base// : FRM_Object
{
public:
	int b;
};

class Derived : public Base
{
public:
	int d;
};

void Try1()
{
	/*	PixelTypeInfo * ptiU8 = GetPixTInfo((Uint8)0);
		PixelTypeInfo * ptiI16 = GetPixTInfo((Int16)0);
		PixelTypeInfo * ptiI32 = GetPixTInfo((Int32)0);
		PixelTypeInfo * ptiF = GetPixTInfo((Float)0);

		PixelTypeInfo * ptiS8 = GetPixTInfo((char)0);*/

	int nDId = NCV_DEPTH_ID(Uint8);

	int a = 0;

	//ObjRef<Base> br;
	//ObjRef<Derived> dr = new Derived();

	//PtrRef<Derived> dr = new Derived();
	//PtrRef<Derived> dr2 = dr;

	//PtrRef<Base> br;
	//PtrRef<Derived> br;
	//PtrRef<Derived> dr = new Derived();

	//Try12((Base*)dr);
	//Try12( GenRef<Base, Derived>(dr) );
	//Try12( br );

	//br = dr;


	//ObjRef<Obj2> o2r = new Obj2();
	//ObjRef<Obj2> o2r2 = o2r;

	//int * pInt = new int;
	//float * pFloat = new float;

	//PtrRef<int> pInt = new int;	
	//PtrRef<float> pFloat = new float;

	//Ncpp::KillObj(pInt);
	//Ncpp::KillObj(pFloat);

}

void Try11(Base * a_pBase)
{
}

void Try12(PtrRef<Base> br)
{
}




void ImageProcessor::EqualizeHistLinePathImg()
{
	GlobalStuff::SetLinePathImg(
		GenCvEqualizeHistImg(GlobalStuff::GetLinePathImg()));

	ShowImage(GlobalStuff::GetLinePathImg(), "LinePathImg");
}



void ImageProcessor::ResetLinePathImg()
{
	GlobalStuff::ResetLinePathImg();

	ShowImage(GlobalStuff::GetLinePathImg(), "LinePathImg");
}

void ImageProcessor::SizeUpLinePathImg(int a_val)
{
	GlobalStuff::SetLinePathImg(GenPyrUpImg(
		GlobalStuff::GetLinePathImg(), a_val));

	ShowImage(GlobalStuff::GetLinePathImg(), "LinePathImg");
}

void ImageProcessor::SaveLinePathImg(char * a_fileName)
{
	SaveImage(GlobalStuff::GetLinePathImg(), a_fileName);
}

void ImageProcessor::SizeDownLinePathImg(int a_val)
{
	GlobalStuff::SetLinePathImg(GenPyrDownImg(
		GlobalStuff::GetLinePathImg(), a_val));

	ShowImage(GlobalStuff::GetLinePathImg(), "LinePathImg");
}

void ImageProcessor::ThresholdLinePathImg(float a_val)
{
	F32ImageRef res = GlobalStuff::GetLinePathImg();

	res = GenThresholdImg(res, a_val);

	GlobalStuff::SetLinePathImg(res);

	ShowImage(GlobalStuff::GetLinePathImg(), "LinePathImg");
}





void ImageProcessor::DilateLinePathImg(int a_nAprSiz)
{
	GlobalStuff::SetLinePathImg(GenCvDilateCircleImg(
		GlobalStuff::GetLinePathImg(), a_nAprSiz));

	ShowImage(GlobalStuff::GetLinePathImg(), "LinePathImg");
}


void ImageProcessor::ErodeLinePathImg(int a_nAprSiz)
{
	GlobalStuff::SetLinePathImg(GenCvErodeCircleImg(
		GlobalStuff::GetLinePathImg(), a_nAprSiz));

	ShowImage(GlobalStuff::GetLinePathImg(), "LinePathImg");
}


void ImageProcessor::MedianLinePathImg(int a_nAprSiz)
{
	GlobalStuff::SetLinePathImg(GenCvMedianImg(
		GlobalStuff::GetLinePathImg(), a_nAprSiz));

	ShowImage(GlobalStuff::GetLinePathImg(), "LinePathImg");
}




void ImageProcessor::MultByNumLinePathImg(float a_num)
{
	GlobalStuff::SetLinePathImg(GenMultByNumImg(
		GlobalStuff::GetLinePathImg(), a_num));

	ShowImage(GlobalStuff::GetLinePathImg(), "LinePathImg");
}



void ImageProcessor::AvgLinePathImg(int a_nAprSiz)
{
	GlobalStuff::SetLinePathImg(GenCvSmoothedImg(
		GlobalStuff::GetLinePathImg(), a_nAprSiz));

	ShowImage(GlobalStuff::GetLinePathImg(), "LinePathImg");
}


void ImageProcessor::FastAvgLinePathImg(int a_nAprSiz)
{
	GlobalStuff::SetLinePathImg(GenFastAvgImg(
		GlobalStuff::GetLinePathImg(), a_nAprSiz));

	ShowImage(GlobalStuff::GetLinePathImg(), "LinePathImg");
}




void ImageProcessor::DrawLinePath()
{
	/*	F32ImageRef src = GenF32FromS16Image(
			GenS16FromU8Image(img));
			F32ImageRef res = src;

			//GlobalStuff::OrgImg = res;
			*/


	F32ImageRef img1 = GlobalStuff::GetLinePathImg();





	//img1 = GenCvSmoothedImg( img1, 5 );

	//U8ImageRef img1Dsp = GenU8FromF32Image( img1 );

	//F32ImageRef img1Dsp = img1->Clone();


	float x1 = IOMgr::ReadInt("x1");
	float y1 = IOMgr::ReadInt("y1");
	float x2 = IOMgr::ReadInt("x2");
	float y2 = IOMgr::ReadInt("y2");

	/*
		float x1;
		float y1;
		float x2;
		float y2;
		*/
	bool bSomePoint = false;

	if (bSomePoint)
	{
		F32Point pt1(316, 131);

		if (pt1.x > pt1.y)
		{
			x1 = pt1.x - pt1.y;
			y1 = 0;
		}
		else
		{
			x1 = 0;
			y1 = pt1.y - pt1.x;
		}

		CvSize siz1 = img1->GetSize();

		if (siz1.width - x1 > siz1.height - y1)
		{
			x2 = x1 + siz1.height - 1 - y1;
			y2 = siz1.height - 1;
		}
		else
		{
			x2 = siz1.width - 1;
			y2 = y1 + siz1.width - 1 - x1;
		}
	}


	//LinePathRef lp = new LinePath( x1, y1, x2, y2 );
	//LinePathRef lp = new LinePath( x1, y1, x2, y1 );
	LinePathRef lp = new LinePathInt(x1, y1, x2, y2);

	////ImageLineViewerRef ilv1 = new ImageLineViewer( img1, lp ); 
	//ImageLineViewer2Ref ilv1 = new ImageLineViewer2(img1, lp);
	////ImageLineViewer3Ref ilv1 = new ImageLineViewer3( img1, lp ); 

	//ConflictScannerRef ilv1 = new ConflictScanner( img1 ); 
	//ilv1->ProcessLine( lp ); 

	//
	//{
	//F32ColorVal color1 = { 0, 180, 0 };


	//{
	//F32ColorVal * pix1 =
	//(F32ColorVal *)img1Dsp->GetPixAt( x1, y1 );

	//*pix1 = color1;
	//}

	//{
	//F32ColorVal * pix88 =
	//(F32ColorVal *)img1Dsp->GetPixAt( x2, y2 );

	//*pix88 = color1;
	//}


	//Filter1DPosAccum fpa1;


	//IIterator_REF( F32Point ) iter1 = lp;

	//LinearColorFilter1DRef cf1 = new LinearColorFilter1D(
	//LinearAvgFilter1D::Create( GlobalStuff::AprSize1D ) );

	////const int nShiftCf1 = cf1->GetShift();
	////const int nShiftCf1 = 0;

	//fpa1.Add( cf1->GetLength() - 1, cf1->GetShift() );

	////		Signal1DBuilderRef sigBuilder0 = new Signal1DBuilder( 300, nShiftCf1 );
	////		Signal1DBuilderRef sigBuilder1 = new Signal1DBuilder( 300, nShiftCf1 );
	////		Signal1DBuilderRef sigBuilder2 = new Signal1DBuilder( 300, nShiftCf1 );

	//Signal1DBuilderRef sigBuilder0 = new Signal1DBuilder( 300, fpa1.GetAnchPos() );
	//Signal1DBuilderRef sigBuilder1 = new Signal1DBuilder( 300, fpa1.GetAnchPos() );
	//Signal1DBuilderRef sigBuilder2 = new Signal1DBuilder( 300, fpa1.GetAnchPos() );



	//LinearColorFilter1DRef cf2 = new LinearColorFilter1D(
	//LinearDiffFilter1D::Create( cf1->GetLength() ) );

	////const int nShiftCf2 = nShiftCf1 + cf2->GetShift();
	//fpa1.Add( cf2->GetLength() - 1, cf2->GetShift() );


	//IFilter1DRef flt1 = LinearAvgFilter1D::Create( 15 );

	//Signal1DBuilderRef sbDif1_2 = new Signal1DBuilder( 300, fpa1.GetAnchPos() + flt1->GetShift() );



	////Signal1DBuilderRef sbDif = new Signal1DBuilder(300, nShiftCf2 );
	//Signal1DBuilderRef sbDif = new Signal1DBuilder( 300, fpa1.GetAnchPos() );





	//LinearColorFilter1DRef cf3 = new LinearColorFilter1D(
	//LinearDiffFilter1D::Create( cf2->GetLength() ) );

	////const int nShiftCf3 = nShiftCf2 + cf3->GetShift();
	//fpa1.Add( cf3->GetLength() - 1, cf3->GetShift() );



	////Signal1DBuilderRef sbDif2 = new Signal1DBuilder(300, nShiftCf3 );

	//Signal1DBuilderRef sbDif2 = new Signal1DBuilder( 300, fpa1.GetAnchPos() );


	////int cnt = 0;

	//F32ColorVal * pix2 = NULL;

	//F32ColorVal drv1;

	//F32ColorVal pix21;
	//F32ColorVal pix22;

	//float maxVal = 0;

	//do
	//{
	////F32Point cp = lp->GetCurrent();
	//F32Point cp = iter1->GetCurrent();


	//pix2 = (F32ColorVal *)img1->GetPixAt( (int)cp.x, (int)cp.y );

	//pix21 = *pix2;


	//{
	//F32ColorVal * pix88 =
	//(F32ColorVal *)img1Dsp->GetPixAt( (int)cp.x, (int)cp.y );


	//*pix88 = color1;
	//}


	//cf1->InputVal( pix21 );

	//if( cf1->HasOutput() )
	//{
	////pix21 = cf1->CalcOutput();
	//cf1->CalcOutput();
	//pix21 = cf1->GetLastOutput();

	//cf2->InputVal( pix21 );

	//sigBuilder0->AddValue( pix21.val0 );
	//sigBuilder1->AddValue( pix21.val1 );
	//sigBuilder2->AddValue( pix21.val2 );

	//if( cf2->HasOutput() )
	//{
	//cf2->CalcOutput();
	//pix22 = cf2->GetLastOutput();

	//{
	//const float drv1Val = pix22.CalcMag();

	//if( drv1Val > maxVal )
	//maxVal = drv1Val;

	//sbDif->AddValue( 0.5 * drv1Val );
	////sbDif->AddValue( drv1Val );

	//flt1->InputVal( drv1Val );

	//if( flt1->HasOutput() )
	//{
	//flt1->CalcOutput();

	//sbDif1_2->AddValue( 0.5 * flt1->GetLastOutput() );
	////sbDif1_2->AddValue( flt1->GetLastOutput() );
	//}

	//}

	//cf3->InputVal( pix22 );

	//if( cf3->HasOutput() )
	//{
	//cf3->CalcOutput();
	//F32ColorVal pix23 = cf3->GetLastOutput();

	//const float drv2Val = pix23.CalcMag();

	//sbDif2->AddValue( 0.5 * drv2Val );
	////sbDif2->AddValue( drv2Val );
	//}

	//}
	//}


	////}while(lp->MoveNext());
	//}while(iter1->MoveNext());

	//Signal1DViewerRef sv1 = new Signal1DViewer();

	//sv1->AddSignal( sigBuilder0->GetResult(), u8ColorVal(200, 0, 0) );
	//sv1->AddSignal( sigBuilder1->GetResult(), u8ColorVal(0, 180, 0) );
	//sv1->AddSignal( sigBuilder2->GetResult(), u8ColorVal(0, 0, 255) );

	////sv1->AddSignal( sigBuilder0->GetResult(), u8ColorVal(255, 255, 255) );
	////sv1->AddSignal( sigBuilder1->GetResult(), u8ColorVal(255, 255, 255) );
	////sv1->AddSignal( sigBuilder2->GetResult(), u8ColorVal(255, 255, 255) );

	//sv1->AddSignal( sbDif->GetResult(), u8ColorVal(255, 255, 255) );
	//sv1->AddSignal( sbDif2->GetResult(), u8ColorVal(160, 0, 160) );

	//sv1->AddSignal( sbDif1_2->GetResult(), u8ColorVal(0, 128, 255) );


	//ShowImage( sv1->GenDisplayImage(), "Signals" );


	//}
	//

	//ShowImage(ilv1->GetSignalDspImg(), "Signals");





	//ShowImage(img1Dsp, "LinePathImg");

	//ShowImage(ilv1->GetResultImg(), "LinePathImg");
}






void ImageProcessor::ClipLinePathImg()
{
	F32Point p1, p2;

	p1.x = IOMgr::ReadInt("x1");
	p1.y = IOMgr::ReadInt("y1");
	p2.x = IOMgr::ReadInt("x2");
	p2.y = IOMgr::ReadInt("y2");


	GlobalStuff::SetLinePathImg(GenClipedImg(
		GlobalStuff::GetLinePathImg(), p1, p2));


	ShowImage(GlobalStuff::GetLinePathImg(), "LinePathImg");
}


//void ImageProcessor::AvgColorsOfLinePathImg()
//{
//	F32Point p1, p2;
//
//	p1.x = IOMgr::ReadInt("x1");
//	p1.y = IOMgr::ReadInt("y1");
//	p2.x = IOMgr::ReadInt("x2");
//	p2.y = IOMgr::ReadInt("y2");
//
//	F32ImageRef avgColorImg = GenAvgColorsImg(
//		GlobalStuff::GetLinePathImg(), p1, p2);
//
//	//GlobalStuff::SetLinePathImg(  );
//
//
//	ShowImage(avgColorImg, "avgColorImg");
//}



void ImageProcessor::ConvToGrayLinePathImg()
{
	GlobalStuff::SetLinePathImg(GenTriChGrayImg(
		GlobalStuff::GetLinePathImg()));

	ShowImage(GlobalStuff::GetLinePathImg(), "LinePathImg");
}


void ImageProcessor::Undo()
{
	GlobalStuff::UndoLinePathImg();

	ShowImage(GlobalStuff::GetLinePathImg(), "LinePathImg");
}


void ImageProcessor::Redo()
{
	GlobalStuff::RedoLinePathImg();

	ShowImage(GlobalStuff::GetLinePathImg(), "LinePathImg");
}





void ImageProcessor::Try26_1()
{
	F32ImageRef src = GlobalStuff::GetLinePathImg();


	ImgSizeRotationCollRef rotColl1 = new  ImgSizeRotationColl(src->GetSize(), 4);
	//Ns_Binarization::RotationMgrCollRef rotColl1 = new  Ns_Binarization::RotationMgrColl(src, 8);

	//ImgRotationMgrRef rot33 = rotColl1->GetRotAt(0);
	//ImageItrMgrRef imgItr33 = rot33->GetImageItrMgr();
	//ImageLineItrProvider & imgLineItrPorv33 = imgItr33->GetItrProvAt(1);
	//FixedVector< ImageLineItr > & lineItrArr33 = imgLineItrPorv33.GetLineItrArr();
	//ImageLineItr & lineItr33 = lineItrArr33[0];
	//ShowImage(rotColl1->GetRotAt(3)->GetResImg(), "Rot1_3");

	//return;

	Ns_Binarization::AngleDirMgrCollRef angleDirColl = new Ns_Binarization::AngleDirMgrColl(src, rotColl1);
	//Ns_Binarization::ImgAngleDirMgrRef 
	//imagean

	//ShowImage(rotColl1->GetRotAt(0)->GetResImg(), "Rot1_0");
	//ShowImage(rotColl1->GetRotAt(1)->GetResImg(), "Rot1_1");
	//ShowImage(rotColl1->GetRotAt(2)->GetResImg(), "Rot1_2");
	//ShowImage(rotColl1->GetRotAt(3)->GetResImg(), "Rot1_3");

	//ShowImage(rotColl1->GetRotAt(4)->GetResImg(), "Rot1_4");
	//ShowImage(rotColl1->GetRotAt(5)->GetResImg(), "Rot1_5");
	//ShowImage(rotColl1->GetRotAt(6)->GetResImg(), "Rot1_6");
	//ShowImage(rotColl1->GetRotAt(7)->GetResImg(), "Rot1_7");

	//ImgRotationMgrRef rotMgr1 = new ImgRotationMgr(src, 45);
	//ImgRotationMgrRef rotMgr1 = rotColl1->GetRotAt(1);

	//F32ImageRef res1 = rotMgr1->GetResImg();

	//CircDiff2Ref cd1 = new CircDiff2( src, nRadius );

	//ShowImage(res1, "Rot1");

	//ShowImage( cd1->GetDifAngleImg(), "Diff Angle" );

	//ShowImage( cd1->GenColorShowImg(), "Color Show Img" );

	//F32ImageRef difMagImg = cd1->GetDifMagImg();
	//ShowImage( difMagImg, "Diff Mag" );

	//GlobalStuff::SetLinePathImg( difMagImg );
	//GlobalStuff::ShowLinePathImg();

}

void ImageProcessor::Try26_2()
{
	//{
	//	F32ImageRef src = GlobalStuff::GetLinePathImg();
	//	F32ImageAccessor3C_Ref org_Img = new F32ImageAccessor3C(src);

	//	F32ImageAccessor1C_Ref weight_Img = new F32ImageAccessor1C(org_Img->GetOffsetCalc());
	//	float wt1 = 200;
	//	//float wt1 = 1;
	//	FillImage(weight_Img->GetMemAccessor(), wt1);
	//	//ShowImage(weight_Img->GetSrcImg(), "weight_Img->GetSrcImg()");


	//	Window<int> avgWin = Window<int>::New(-30, 30, -30, 30);

	//	F32ImageAccessor3C_Ref avg_Img = org_Img->CloneAccAndImage();
	//	//AvgImage(org_Img->GetMemAccessor(), avg_Img->GetMemAccessor(), avgWin);
	//	AvgImage_Weighted(org_Img->GetMemAccessor(), weight_Img->GetMemAccessor(), avg_Img->GetMemAccessor(), avgWin);

	//	ShowImage(avg_Img->GetSrcImg(), "avg_Img->GetSrcImg()");

	//	return;
	//}

	F32ImageAccessor1C_Ref mag_Img;
	{
		F32ImageRef src = GlobalStuff::GetLinePathImg();
		F32ImageAccessor3C_Ref org_Img = new F32ImageAccessor3C(src);

		mag_Img = new F32ImageAccessor1C(org_Img->GetOffsetCalc());

		F32ImageAccessor1C_Ref magImg_0 = new F32ImageAccessor1C(org_Img->GetOffsetCalc());
		CalcMagImage(org_Img->GetMemAccessor(), magImg_0->GetMemAccessor());

		Window<int> avgWin_0 = Window<int>::New(-1, 1, -1, 1);

		AvgImage(magImg_0->GetMemAccessor(), mag_Img->GetMemAccessor(), avgWin_0);
	}


	ShowImage(mag_Img->GetSrcImg(), "mag_Img->GetSrcImg()");

	//Window<int> avgWin = Window<int>::New(-1, 1, -5, 5);
	//Window<int> avgWin = Window<int>::New(-2, 2, -2, 2);
	Window<int> avgWin = Window<int>::New(-1, 1, -1, 1);

	//Window<int> avgWin = Window<int>::New(-2, 2, -2, 2);

	F32ImageAccessor1C_Ref avg_Img = mag_Img->CloneAccAndImage();
	AvgImage(mag_Img->GetMemAccessor(), avg_Img->GetMemAccessor(), avgWin);

	//ShowImage(avg_Img->GetSrcImg(), "avg_Img->GetSrcImg()");

	F32ImageAccessor1C_Ref magSqr_Img = new F32ImageAccessor1C(mag_Img->GetOffsetCalc());
	CalcMagSqrImage(mag_Img->GetMemAccessor(), magSqr_Img->GetMemAccessor());

	F32ImageAccessor1C_Ref avg_MagSqr_Img = new F32ImageAccessor1C(mag_Img->GetOffsetCalc());
	AvgImage(magSqr_Img->GetMemAccessor(), avg_MagSqr_Img->GetMemAccessor(), avgWin);

	F32ImageAccessor1C_Ref standev_Img = new F32ImageAccessor1C(mag_Img->GetOffsetCalc());
	CalcStandevImage(avg_Img->GetMemAccessor(), avg_MagSqr_Img->GetMemAccessor(),
		standev_Img->GetMemAccessor());

	ShowImage(standev_Img->GetSrcImg(), "standev_Img->GetSrcImg()");

	////////////////////////////////////////////--------------------------

	Window<int> avgWin_2 = Window<int>::New(-2, 2, -2, 2);

	F32ImageAccessor1C_Ref avg_Standev_Img = standev_Img->CloneAccAndImage();
	AvgImage(standev_Img->GetMemAccessor(), avg_Standev_Img->GetMemAccessor(), avgWin_2);

	//ShowImage(avg_Img->GetSrcImg(), "avg_Img->GetSrcImg()");

	F32ImageAccessor1C_Ref magSqr_Standev_Img = new F32ImageAccessor1C(standev_Img->GetOffsetCalc());
	CalcMagSqrImage(standev_Img->GetMemAccessor(), magSqr_Standev_Img->GetMemAccessor());

	F32ImageAccessor1C_Ref avg_MagSqr_Standev_Img = new F32ImageAccessor1C(standev_Img->GetOffsetCalc());
	AvgImage(magSqr_Standev_Img->GetMemAccessor(), avg_MagSqr_Standev_Img->GetMemAccessor(), avgWin_2);

	F32ImageAccessor1C_Ref standev_Standev_Img = new F32ImageAccessor1C(standev_Img->GetOffsetCalc());
	CalcStandevImage(avg_Standev_Img->GetMemAccessor(), avg_MagSqr_Standev_Img->GetMemAccessor(),
		standev_Standev_Img->GetMemAccessor());

	ShowImage(standev_Standev_Img->GetSrcImg(), "standev_Standev_Img->GetSrcImg()");

	////////////////////////////////////////////--------------------------

	{
		F32ImageAccessor1C_Ref edge_Img = new F32ImageAccessor1C(standev_Img->GetOffsetCalc());

		const int nSize_1D = standev_Img->GetMemAccessor()->GetIndexSize_X_Org() * standev_Img->GetMemAccessor()->GetIndexSize_Y_Org();

		float * edge_Ptr = edge_Img->GetMemAccessor()->GetDataPtr();
		float * standev_Ptr = standev_Img->GetMemAccessor()->GetDataPtr();
		float * standev_Standev_Ptr = standev_Standev_Img->GetMemAccessor()->GetDataPtr();
		float * avg_Standev_Ptr = avg_Standev_Img->GetMemAccessor()->GetDataPtr();

		for (int i = 0; i < nSize_1D; i++)
		{
			float & rEdge = edge_Ptr[i];
			float & rStandev = standev_Ptr[i];
			float & rStandev_Standev = standev_Standev_Ptr[i];
			float & rAvg_Standev = avg_Standev_Ptr[i];

			//if (rStandev >(rStandev_Standev * 0.666f))
			//if (rStandev >(rAvg_Standev * 0.666f) && rStandev > 20)
			if (rStandev >(rAvg_Standev * 0.44f) && rStandev > 20)
			{
				rEdge = 255;
			}
			else
			{
				rEdge = 0;
			}
		}

		ShowImage(edge_Img->GetSrcImg(), "edge_Img->GetSrcImg()");
	}





}

void ImageProcessor::Try26_3()
{

	F32ImageAccessor1C_Ref mag_Img;
	//F32ImageAccessor3C_Ref mag_Img;
	{
		F32ImageRef src = GlobalStuff::GetLinePathImg();
		F32ImageAccessor3C_Ref org_Img = new F32ImageAccessor3C(src);

		mag_Img = new F32ImageAccessor1C(org_Img->GetOffsetCalc());
		//mag_Img = new F32ImageAccessor3C(org_Img->GetOffsetCalc());

		F32ImageAccessor1C_Ref magImg_0 = new F32ImageAccessor1C(org_Img->GetOffsetCalc());
		CalcMagImage(org_Img->GetMemAccessor(), magImg_0->GetMemAccessor());

		//F32ImageAccessor3C_Ref magImg_0 = new F32ImageAccessor3C(org_Img->GetOffsetCalc());
		//CalcMagImage(org_Img->GetMemAccessor(), magImg_0->GetMemAccessor());

		//AvgImage(magImg_0->GetMemAccessor(), mag_Img->GetMemAccessor(), Window<int>::New(-1, 1, -1, 1));
		//AvgImage(magImg_0->GetMemAccessor(), mag_Img->GetMemAccessor(), Window<int>::New(-1, 0, -1, 0));
		mag_Img = magImg_0;
	}
	GlobalStuff::SetLinePathImg(GenTriChGrayImg(mag_Img->GetSrcImg())); GlobalStuff::ShowLinePathImg();
	ShowImage(mag_Img->GetSrcImg(), "mag_Img->GetSrcImg()");


	F32ImageAccessor1C_Ref standev_Thin_Img;
	{
		F32ImageAccessor1C_Ref avg_Img = new F32ImageAccessor1C(mag_Img->GetOffsetCalc());
		standev_Thin_Img = new F32ImageAccessor1C(mag_Img->GetOffsetCalc());

		Calc_Avg_And_Standev_Image(mag_Img->GetMemAccessor(), avg_Img->GetMemAccessor(), standev_Thin_Img->GetMemAccessor(),
			Window<int>::New(-1, 1, -1, 1));
		//Window<int>::New(-1, 0, -1, 0));
	}
	//GlobalStuff::SetLinePathImg(GenTriChGrayImg(standev_Thin_Img->GetSrcImg())); GlobalStuff::ShowLinePathImg();
	ShowImage(standev_Thin_Img->GetSrcImg(), "standev_Thin_Img->GetSrcImg()");
	//return;


	F32ImageAccessor1C_Ref standev_Wide_Img;
	F32ImageAccessor1C_Ref avg_Wide_Img = new F32ImageAccessor1C(mag_Img->GetOffsetCalc());
	{
		standev_Wide_Img = new F32ImageAccessor1C(mag_Img->GetOffsetCalc());

		Calc_Avg_And_Standev_Image(mag_Img->GetMemAccessor(), avg_Wide_Img->GetMemAccessor(), standev_Wide_Img->GetMemAccessor(),
			Window<int>::New(-10, 10, -10, 10));
	}
	GlobalStuff::SetLinePathImg(GenTriChGrayImg(avg_Wide_Img->GetSrcImg())); GlobalStuff::ShowLinePathImg();
	GlobalStuff::SetLinePathImg(GenTriChGrayImg(standev_Wide_Img->GetSrcImg())); GlobalStuff::ShowLinePathImg();
	ShowImage(standev_Wide_Img->GetSrcImg(), "standev_Wide_Img->GetSrcImg()");



	F32ImageAccessor1C_Ref avg_Wide_Mag_Diff_Img = new F32ImageAccessor1C(mag_Img->GetOffsetCalc());
	{
		const int nSize_1D = mag_Img->GetSize_1D();

		float * mag_Ptr = mag_Img->GetDataPtr();
		float * avg_Wide_Ptr = avg_Wide_Img->GetDataPtr();
		float * avg_Wide_Mag_Diff_Ptr = avg_Wide_Mag_Diff_Img->GetDataPtr();

		for (int i = 0; i < nSize_1D; i++)
		{
			avg_Wide_Mag_Diff_Ptr[i] = fabs(mag_Ptr[i] - avg_Wide_Ptr[i]);
		}
	}
	GlobalStuff::SetLinePathImg(GenTriChGrayImg(avg_Wide_Mag_Diff_Img->GetSrcImg())); GlobalStuff::ShowLinePathImg();
	ShowImage(standev_Thin_Img->GetSrcImg(), "avg_Wide_Mag_Diff_Img->GetSrcImg()");


	return;


	////////////////////////////////////////////--------------------------

	F32ImageAccessor1C_Ref standev_Img;



	Window<int> avgWin_2 = Window<int>::New(-2, 2, -2, 2);

	F32ImageAccessor1C_Ref avg_Standev_Img = standev_Img->CloneAccAndImage();
	AvgImage(standev_Img->GetMemAccessor(), avg_Standev_Img->GetMemAccessor(), avgWin_2);

	//ShowImage(avg_Img->GetSrcImg(), "avg_Img->GetSrcImg()");

	F32ImageAccessor1C_Ref magSqr_Standev_Img = new F32ImageAccessor1C(standev_Img->GetOffsetCalc());
	CalcMagSqrImage(standev_Img->GetMemAccessor(), magSqr_Standev_Img->GetMemAccessor());

	F32ImageAccessor1C_Ref avg_MagSqr_Standev_Img = new F32ImageAccessor1C(standev_Img->GetOffsetCalc());
	AvgImage(magSqr_Standev_Img->GetMemAccessor(), avg_MagSqr_Standev_Img->GetMemAccessor(), avgWin_2);

	F32ImageAccessor1C_Ref standev_Standev_Img = new F32ImageAccessor1C(standev_Img->GetOffsetCalc());
	CalcStandevImage(avg_Standev_Img->GetMemAccessor(), avg_MagSqr_Standev_Img->GetMemAccessor(),
		standev_Standev_Img->GetMemAccessor());

	ShowImage(standev_Standev_Img->GetSrcImg(), "standev_Standev_Img->GetSrcImg()");

	////////////////////////////////////////////--------------------------

	{
		F32ImageAccessor1C_Ref edge_Img = new F32ImageAccessor1C(standev_Img->GetOffsetCalc());

		const int nSize_1D = standev_Img->GetMemAccessor()->GetIndexSize_X_Org() * standev_Img->GetMemAccessor()->GetIndexSize_Y_Org();

		float * edge_Ptr = edge_Img->GetMemAccessor()->GetDataPtr();
		float * standev_Ptr = standev_Img->GetMemAccessor()->GetDataPtr();
		float * standev_Standev_Ptr = standev_Standev_Img->GetMemAccessor()->GetDataPtr();
		float * avg_Standev_Ptr = avg_Standev_Img->GetMemAccessor()->GetDataPtr();

		for (int i = 0; i < nSize_1D; i++)
		{
			float & rEdge = edge_Ptr[i];
			float & rStandev = standev_Ptr[i];
			float & rStandev_Standev = standev_Standev_Ptr[i];
			float & rAvg_Standev = avg_Standev_Ptr[i];

			//if (rStandev >(rStandev_Standev * 0.666f))
			//if (rStandev >(rAvg_Standev * 0.666f) && rStandev > 20)
			if (rStandev >(rAvg_Standev * 0.44f) && rStandev > 20)
			{
				rEdge = 255;
			}
			else
			{
				rEdge = 0;
			}
		}

		ShowImage(edge_Img->GetSrcImg(), "edge_Img->GetSrcImg()");
	}


}

void ImageProcessor::Try26_5()
{
	F32ImageRef src = GlobalStuff::GetLinePathImg();

	//ImgRotationMgr_3_Ref rotMgr88_0_0 = new ImgRotationMgr_3(src, 0);
	//ImgRotationMgr_3_Ref rotMgr88_0_1 = new ImgRotationMgr_3(src, 22.5);
	//ImgRotationMgr_3_Ref rotMgr88_0_2 = new ImgRotationMgr_3(src, 45);
	//ImgRotationMgr_3_Ref rotMgr88_0_3 = new ImgRotationMgr_3(src, 67.5);

	ImgSizeRotationRef rotMgr88_0_2 = new ImgSizeRotation(src->GetSize(), 45);

	ImgSizeRotationRef rotMgr = rotMgr88_0_2;


	F32ImageAccessor3C_Ref org_Img = new F32ImageAccessor3C(src);

	//rot_Img = new F32ImageAccessor3C(org_Img->GetOffsetCalc());
	F32ImageAccessor3C_Ref rot_Img = new F32ImageAccessor3C(new OffsetCalc_2D(1,
		rotMgr->GetResImgSiz().width, rotMgr->GetResImgSiz().height));

	{
		F32ColorVal color1;
		color1.AssignVal(50, 50, 200);

		F32ColorVal color2;
		color2.AssignVal(250, 50, 50);

		//FillImage_Stripes_H<F32ColorVal>(org_Img->GetMemAccessor(), color1, color2, 25);
		FillImage_Stripes_H(org_Img->GetMemAccessor(), color1, color2, 25);
	}

	//rotMgr->RotateImage(org_Img->GetMemAccessor(), rot_Img->GetMemAccessor());
	rotMgr->RotateImage(rot_Img->GetDataPtr(), rot_Img->GetSrcImgSize(),
		(F32ColorVal *)src->GetDataPtr(), src->GetSize());




	//GlobalStuff::SetLinePathImg(rotMgr88_0_1->GetResImg());
	//GlobalStuff::SetLinePathImg(rotMgr88_0_2->GetResImg());
	GlobalStuff::SetLinePathImg(rot_Img->GetSrcImg());
	GlobalStuff::ShowLinePathImg();

	return;


}

void ImageProcessor::Try26_4()
{
	//VectorVal<float, 4> vv1;

	F32ImageRef src = GlobalStuff::GetLinePathImg();
	//F32ImageAccessor3C_Ref org_Img = new F32ImageAccessor3C(src);
	//ImageAccessor_REF(float, VectorVal<float, 3>, 3) org_Img = new F32ImageAccessor3C(src);
	F32VectorValImageAcc_3C_Ref org_Img = new F32VectorValImageAcc_3C(src);
	org_Img->SwitchXY();

	ShowImage(org_Img->GetSrcImg(), "org_Img->GetSrcImg()");

	//F32ImageAccessor1C_Ref mag_Img;
	////F32ImageAccessor3C_Ref mag_Img;
	//{
	//	F32ImageRef src = GlobalStuff::GetLinePathImg();
	//	F32ImageAccessor3C_Ref org_Img = new F32ImageAccessor3C(src);

	//	mag_Img = new F32ImageAccessor1C(org_Img->GetOffsetCalc());
	//	//mag_Img = new F32ImageAccessor3C(org_Img->GetOffsetCalc());

	//	F32ImageAccessor1C_Ref magImg_0 = new F32ImageAccessor1C(org_Img->GetOffsetCalc());
	//	CalcMagImage(org_Img->GetMemAccessor(), magImg_0->GetMemAccessor());

	//	//F32ImageAccessor3C_Ref magImg_0 = new F32ImageAccessor3C(org_Img->GetOffsetCalc());
	//	//CalcMagImage(org_Img->GetMemAccessor(), magImg_0->GetMemAccessor());

	//	//AvgImage(magImg_0->GetMemAccessor(), mag_Img->GetMemAccessor(), Window<int>::New(-1, 1, -1, 1));
	//	//AvgImage(magImg_0->GetMemAccessor(), mag_Img->GetMemAccessor(), Window<int>::New(-1, 0, -1, 0));
	//	mag_Img = magImg_0;
	//}
	//GlobalStuff::SetLinePathImg(GenTriChGrayImg(mag_Img->GetSrcImg())); GlobalStuff::ShowLinePathImg();
	//ShowImage(mag_Img->GetSrcImg(), "mag_Img->GetSrcImg()");

	//GlobalStuff::SetLinePathImg(GenTriChGrayImg(mag_Img->GetSrcImg())); GlobalStuff::ShowLinePathImg();
	//ShowImage(mag_Img->GetSrcImg(), "mag_Img->GetSrcImg()");


	F32ImageAccessor1C_Ref standev_InrWide_Img = new F32ImageAccessor1C(org_Img->GetOffsetCalc());

	//const int nInrRad = 5;
	const int nInrRad = 8;
	//F32ImageAccessor3C_Ref avg_InrWide_Img = new F32ImageAccessor3C(org_Img->GetOffsetCalc());
	F32VectorValImageAcc_3C_Ref avg_InrWide_Img = new F32VectorValImageAcc_3C(org_Img->GetOffsetCalc());
	{
		Calc_Avg_And_Standev_Image(org_Img->GetMemAccessor(), avg_InrWide_Img->GetMemAccessor(), standev_InrWide_Img->GetMemAccessor(),
			Window<int>::New(-nInrRad, nInrRad, -nInrRad, nInrRad));

		MultiplyImageByNum(standev_InrWide_Img->GetMemAccessor(), 2);
		//AssertValues_Image(avg_InrWide_Img->GetMemAccessor());
	}
	GlobalStuff::SetLinePathImg(GenTriChGrayImg(standev_InrWide_Img->GetSrcImg())); GlobalStuff::ShowLinePathImg();
	ShowImage(standev_InrWide_Img->GetSrcImg(), "standev_InrWide_Img->GetSrcImg()");

	F32VectorValImageAcc_4C_Ref avgPStandev_InrWide_Img = new F32VectorValImageAcc_4C(org_Img->GetOffsetCalc());
	{
		const int nSize_1D = avg_InrWide_Img->GetSize_1D();

		F32VectorVal<4> * dest_Ptr = (F32VectorVal<4> *)avgPStandev_InrWide_Img->GetDataPtr();
		F32VectorVal<3> * src_Avg_Ptr = (F32VectorVal<3> *)avg_InrWide_Img->GetDataPtr();
		float * src_Standev_Ptr = standev_InrWide_Img->GetDataPtr();

		for (int i = 0; i < nSize_1D; i++)
		{
			*((F32VectorVal<3> *)&dest_Ptr[i]) = *(&src_Avg_Ptr[i]);
			//Ncpp_ASSERT(src_Standev_Ptr[i] > 0.0 && src_Standev_Ptr[i] < 3000.0f);
			dest_Ptr[i].Vals[3] = src_Standev_Ptr[i];
		}

		//AssertValues_Image(avgPStandev_InrWide_Img->GetMemAccessor());
	}


	//const int nOutRad = 5;
	const int nOutRad = 8;
	{
		F32ImageAccessor1C_Ref standev_OutWide_Img = new F32ImageAccessor1C(org_Img->GetOffsetCalc());
		F32VectorValImageAcc_4C_Ref avg_OutWide_Img = new F32VectorValImageAcc_4C(org_Img->GetOffsetCalc());

		Calc_Avg_And_Standev_Image(avgPStandev_InrWide_Img->GetMemAccessor(), avg_OutWide_Img->GetMemAccessor(), standev_OutWide_Img->GetMemAccessor(),
			Window<int>::New(-nOutRad, nOutRad, -nOutRad, nOutRad));

		////GlobalStuff::SetLinePathImg(GenTriChGrayImg(avg_InrWide_Img->GetSrcImg())); GlobalStuff::ShowLinePathImg();
		//GlobalStuff::SetLinePathImg(GenTriChGrayImg(standev_InrWide_Img->GetSrcImg())); GlobalStuff::ShowLinePathImg();
		//ShowImage(standev_InrWide_Img->GetSrcImg(), "standev_InrWide_Img->GetSrcImg()");

		GlobalStuff::SetLinePathImg(GenTriChGrayImg(standev_OutWide_Img->GetSrcImg())); GlobalStuff::ShowLinePathImg();
		ShowImage(standev_OutWide_Img->GetSrcImg(), "standev_OutWide_Img->GetSrcImg()");
	}


	////------------

	F32ImageAccessor1C_Ref conflictDiff_OutWide_Img = new F32ImageAccessor1C(org_Img->GetOffsetCalc());
	{
		//conflictDiff_OutWide_Img->SwitchXY();

		////Window<int> avgWin = Window<int>::New(-1, 1, -5, 5);
		////Window<int> avgWin = Window<int>::New(-1, 1, -2, 2);
		//Window<int> avgWin = Window<int>::New(-10, 10, -10, 10);
		////Window<int> avgWin = Window<int>::New(0, 0, -2, 2);
		Window<int> avgWin = Window<int>::New(-nOutRad, nOutRad, -nOutRad, nOutRad);

		F32VectorValImageAcc_4C_Ref avg_Img = new F32VectorValImageAcc_4C(org_Img->GetOffsetCalc());
		//avg_Img->SwitchXY();
		AvgImage(avgPStandev_InrWide_Img->GetMemAccessor(), avg_Img->GetMemAccessor(), avgWin);

		F32ImageAccessor1C_Ref magSqr_Img = new F32ImageAccessor1C(org_Img->GetOffsetCalc());
		//magSqr_Img->SwitchXY();
		CalcMagSqrImage(avgPStandev_InrWide_Img->GetMemAccessor(), magSqr_Img->GetMemAccessor());

		F32ImageAccessor1C_Ref avg_MagSqr_Img = new F32ImageAccessor1C(org_Img->GetOffsetCalc());
		//avg_MagSqr_Img->SwitchXY();
		AvgImage(magSqr_Img->GetMemAccessor(), avg_MagSqr_Img->GetMemAccessor(), avgWin);

		Range<int> confRange = Range<int>::New(
			//-10 - avgWin.Get_X2(), 10 - avgWin.Get_X1());
			//-1 - avgWin.Get_X2(), 1 - avgWin.Get_X1());
			-1 - nOutRad - nInrRad, 1 + nOutRad + nInrRad);

		Calc_ConflictDiff_Image_H(avg_Img->GetMemAccessor(), avg_MagSqr_Img->GetMemAccessor(),
			conflictDiff_OutWide_Img->GetMemAccessor(), confRange);

		GlobalStuff::SetLinePathImg(GenTriChGrayImg(conflictDiff_OutWide_Img->GetSrcImg())); GlobalStuff::ShowLinePathImg();
		ShowImage(conflictDiff_OutWide_Img->GetSrcImg(), "conflictDiff_OutWide_Img->GetSrcImg()");
	}



}


//	This is the TRUE Try26()
void ImageProcessor::Try26()
{
	//Try26_5();
	//return;

	//Try26_4();
	//return;

	//Try26_3();
	//return;

	//Try26_2();
	//return;

	Try26_1();
}




void ImageProcessor::MaxMinEdge()
{
	S16ImageRef src = GenS16FromU8Image(img);
	S16ImageRef res = src;

	int nAprSiz = 5;

	S16ImageRef avg_Img = GenFastAvgImg(res, nAprSiz);
	//S16ImageRef avg_Img = res;

	res = avg_Img;

	U8ImageRef resU8 = GenU8FromS16Image(res);

	U8ImageRef resMax = U8Image::Create(resU8->GetSize(),
		resU8->GetNofChannels());

	U8ImageRef resMin = U8Image::Create(resU8->GetSize(),
		resU8->GetNofChannels());

	//int j = ( nAprSiz / 2 ) + 1;
	//int j = ( nAprSiz / 2 );
	int j = 1;

	for (int i = 0; i < 1; i++)
	{
		cvDilate(resU8->GetIplImagePtr(),
			resMax->GetIplImagePtr(), 0, j);

		cvErode(resU8->GetIplImagePtr(),
			resMin->GetIplImagePtr(), 0, j);

	}

	U8ImageRef resDif = U8Image::Create(resU8->GetSize(),
		resU8->GetNofChannels());

	HCV_CALL(
		cvSub(
		resMax->GetIplImagePtr(),
		resMin->GetIplImagePtr(),
		resDif->GetIplImagePtr())
		);

	res = GenS16FromU8Image(resDif);

	S16ImageRef gradImg = GenDifMagImg(res);

	U8ImageRef dsp;

	dsp = GenU8FromS16Image(gradImg);
	ShowImage(dsp->GetIplImagePtr(), "gradImg");

	res = gradImg;

	//res = GenFlattenedImg( avg_Img, gradImg, nAprSiz );
	//res = GenFlattenedImg( avg_Img, gradImg, nAprSiz + 2 );
	//res = GenColorMideanImg( avg_Img );
	res = GenWeightedColorMideanImg(avg_Img, gradImg, 3);

	//AdaptiveConvRef ac = AdaptiveConv::CreateBlur(5);	
	//res = ac->GenResult( avg_Img );	
	//res = ac->GenResult( res );	


	//res = GenThresholdImg(res, 40);


	bool bColorDsp = false;

	dsp = GenU8FromS16Image(avg_Img);
	ShowImage(dsp->GetIplImagePtr(), "avg_Img");

	dsp = GenU8FromS16Image(res);
	ShowImage(dsp->GetIplImagePtr(), "Result");

	HCV_CALL(cvvSaveImage("hcvResult.jpg",
		dsp->GetIplImagePtr()));

}


void ImageProcessor::FastAvg()
{
	S16ImageRef src = GenS16FromU8Image(img);
	S16ImageRef res = src;

	res = GenFastAvgImg(res, 7);

	U8ImageRef dsp;

	bool bColorDsp = false;

	dsp = GenU8FromS16Image(res);

	ShowImage(dsp->GetIplImagePtr(), "Result");

	HCV_CALL(cvvSaveImage("hcvResult.jpg",
		dsp->GetIplImagePtr()));
}


void ImageProcessor::Sobel()
{
	double nMin, nMax;

	//Try1();

	//U8ImageRef src = img;
	//U8ImageRef src = U8Image::Create(
	//	cvGetSize(img->GetIplImagePtr()), 1);

	U8ImageRef src0 = U8Image::Create(
		cvGetSize(img->GetIplImagePtr()), 1);

	HCV_CALL(cvCvtColor(img->GetIplImagePtr(),
		src0->GetIplImagePtr(), CV_RGB2GRAY));

	S16ImageRef src = S16Image::Create(
		cvGetSize(img->GetIplImagePtr()), 1);

	HCV_CALL(cvConvertScale(src0->GetIplImagePtr(),
		src->GetIplImagePtr()));

	{
		S16ChannelRef chnl = src->GetAt(0);

		for (int y = 0; y < chnl->GetHeight(); y++)
		for (int x = 0; x < chnl->GetWidth(); x++)
		{
			chnl->SetAt(x, y,
				//					chnl->GetAt(x, y) * 10);
				chnl->GetAt(x, y));
		}
	}




	cvMinMaxLoc(src->GetIplImagePtr(), &nMin, &nMax);

	//HCV_CALL( cvvSaveImage("C:\\src1.bmp", 
	//	src->GetIplImagePtr()) );

	S16ImageRef outra;
	U8ImageRef sobelImg;

	//cvSetImageCOI (src, 1);

	//CvMat * pMat = (CvMat *) img;

	//CvMat srcstub, *src1 = (CvMat*)img;

	int i;

	//if( !CV_IS_MAT(src) )
	//CV_CALL( src1 = cvGetMat( src1, &srcstub, &i));
	//CV_CALL( src1 = cvGetMat( src1, &srcstub));
	//src1 = cvGetMat( src1, &srcstub, &i);


	// load src
	outra = S16Image::Create(
		cvGetSize(src->GetIplImagePtr()), src->GetNofChannels());
	//cvSobel( src->GetIplImagePtr(), 
	cvSobel(src0->GetIplImagePtr(),
		//outra->GetIplImagePtr(), 1, 0, 7);
		outra->GetIplImagePtr(), 1, 0, 5);
	//outra->GetIplImagePtr(), 1, 0, 3);
	//outra->GetIplImagePtr(), 1, 0, 1);
	sobelImg = U8Image::Create(cvGetSize(
		src->GetIplImagePtr()), src->GetNofChannels());

	cvMinMaxLoc(outra->GetIplImagePtr(), &nMin, &nMax);


	cvConvertScale(outra->GetIplImagePtr(), sobelImg->GetIplImagePtr());

	cvMinMaxLoc(sobelImg->GetIplImagePtr(), &nMin, &nMax);


	int hist[256];
	{
		memset(hist, 0, 256 * sizeof(int));

		U8ChannelRef chnl = sobelImg->GetAt(0);

		for (int y = 0; y < chnl->GetHeight(); y++)
		for (int x = 0; x < chnl->GetWidth(); x++)
		{
			hist[chnl->GetAt(x, y)]++;
		}
	}



	cvNamedWindow("3.Sobel", 1);
	cvShowImage("3.Sobel", sobelImg->GetIplImagePtr());

}


void ImageProcessor::execute() {

	process(img);

}


void ImageProcessor::Create()
{
	int nWidth = 797;
	int nHeight = 600;


	img = U8Image::Create(
		cvSize(nWidth, nHeight), 3);

	cvRectangle(
		img->GetIplImagePtr(),
		cvPoint(0, 0),
		//cvPoint(nWidth-1, nHeight-1), 
		cvPoint(nWidth / 2, nHeight / 2),
		//cvPoint(nWidth+50, nHeight+170), 
		//CV_RGB(64, 128, 255),
		CV_RGB(255, 128, 64),
		//CV_RGB(255, 255, 255),
		-1);

	//cvCircle(
	//	img->GetIplImagePtr(), 

	uchar *uData;

	//cvGetImageRawData( img->GetIplImagePtr(), &uData );
	cvGetRawData(img->GetIplImagePtr(), &uData);


	img = img;


}


void InitLibs(void)
{
	Ncv::InitLib();


}


