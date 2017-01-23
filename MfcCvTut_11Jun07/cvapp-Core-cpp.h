//#include <vector.h>

#include "cvapp.h"
#include <Lib\Hcv\SignalOneDim.h>
#include "GlobalStuff.h"

#include <Lib\Hcv\TempImageAccessor.h>
#include <Lib\Hcv\VectorVal.h>
#include <Lib\Hcv\ImgSizeRotationColl.h>

//#include <Lib\Hcv\CircleContourOfPix.h>

using namespace Hcpl;
using namespace Hcv;
using namespace Hcv::Image_Operations;
using namespace Hcv::ImageAccessorOperations;
//using namespace Hcv::Ns;

//using namespace Hcpl::MfcEx;


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

	int nDId = HCV_DEPTH_ID(Uint8);

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

	//Hcpl::KillObj(pInt);
	//Hcpl::KillObj(pFloat);

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


void ImageProcessor::MorphG1S2LinePathImg(int a_nAprSiz)
{
	GlobalStuff::SetLinePathImg(GenMorphG1S2Img(
		GlobalStuff::GetLinePathImg(), a_nAprSiz));

	ShowImage(GlobalStuff::GetLinePathImg(), "LinePathImg");
}


void ImageProcessor::MorphGradLinePathImg(int a_nAprSiz)
{
	//GlobalStuff::SetLinePathImg( GenMorphGradImg( 
	GlobalStuff::SetLinePathImg(CircDiff::GenResult(
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


void ImageProcessor::CircPntOfLinePathImg3(int a_x, int a_y)
{
	//#define ARR_SIZ 35
#define ARR_SIZ 3

	//if( false )
	{
		F32ImageRef img1 = GlobalStuff::GetLinePathImg();

		//IImgDataMgr_2_FactorySetRef imgFactoryMgr = 
		//	new ImgDataMgr_2_FactorySet_CovMat();

		IImgDataMgr_2_FactorySetRef imgFactoryMgr =
			new ImgDataMgr_2_FactorySet_LocHist();

		IImgCoreSrcRef ids1 = new ImgDataSrc_LocHist(img1);

		//IImgDataMgr_2_FactorySetRef imgFactoryMgr = 
		//	new ImgDataMgr_2_FactorySet_GridPal();

		//IImgCoreSrcRef ids1 = new ImgDataSrc_GridPal(img1);

		RgnSegmDiameter rsDiam;
		rsDiam.SetDiamFull(GlobalStuff::AprSize1D);

		//int nAprSiz_Far = rsDiam.GetDiamInr_1();
		int nAprSiz_Far = rsDiam.GetDiamFull();

		//int nAprSiz_Loc = rsDiam.GetDiamInr_1();
		int nAprSiz_Loc = rsDiam.GetDiamFull();

		ImageRotationMgr_ExParamsRef rotParams =
			new ImageRotationMgr_ExParams(
			//img1, NULL, 0, nAprSiz_Far, nAprSiz_Loc, imgFactoryMgr );
			img1, ids1, 0, nAprSiz_Far, nAprSiz_Loc, imgFactoryMgr);


		ImgScanMgrRef ism = new ImgScanMgr(rotParams, 4,
			cvPoint(a_x, a_y));

		return;
	}

	{
	//ScanTryMgr stm(a_x, a_y);
	//ScanTryMgr2 stm(a_x, a_y);
	//ScanTryMgr_3 stm(a_x, a_y);
	//ScanTryMgr_4 stm(a_x, a_y);
	//ScanTryMgr_5 stm(a_x, a_y);
	//ScanTryMgr_6 stm(a_x, a_y);
	//ScanTryMgr_7 stm(a_x, a_y);
	//ScanTryMgr_8 stm(a_x, a_y);
	ScanTryMgr_9 stm(a_x, a_y);
	//ScanTryMgr2 stm( GlobalStuff::GetLinePathImg() );

	return;
}



	//goto LastOrg;


	{
		//a_x = 282;
		//a_y = 170;

		//a_x = 430;
		//a_y = 87;

		const int nRadius = GlobalStuff::AprSize1D / 2;
		const int nDiameter = nRadius * 2 + 1;
		//const int nRadius = 3;


		F32Point pntArr1[4000];
		F32Point * pMedPnt = &pntArr1[2000];
		pMedPnt[0] = F32Point(a_x, a_y);

		F32ImageRef src = GlobalStuff::GetLinePathImg();

		//CircDiff2Ref cd1 = new CircDiff2( src, nRadius );
		//ImgGradMgr igm1( src, 7, 8 );
		ImgGradMgr igm1(src, nDiameter, 8);
		//ImgGradMgr igm1( src, 7, 4 );




		//LineStepper ls1;
		{
			ImgGradMgr::FwdBkdPoints fBPnts = igm1.GetFwdBkdMatrix().GetAt(a_x, a_y);

			CvSize srcSiz = src->GetSize();

			IndexCalc2D idx2D(srcSiz.width, srcSiz.height);

			const int nPI = idx2D.Calc(a_x, a_y);

			S32ImageRef dirImg = igm1.GetGradDirImg();
			Hcpl::Int32 * dirBuf = dirImg->GetPixAt(0, 0);

			const int nDir = dirBuf[nPI];

			/*
						{
						Signal1DRef sig1 = igm1.GenLineSignal( F32Point( a_x, a_y ), nDir );

						Signal1DViewer sv1;

						sv1.AddSignal( sig1 );

						ShowImage( sv1.GenDisplayImage(), "G D L S" );
						}
						*/




			F32ImageRef difMagImg = igm1.GetGradMagImg();


			//ls1.SetPoints( fBPnts.FwdPnt, fBPnts.BkdPnt );


			ScanDirMgrCollRef sdmColl = igm1.GetScanDirMgrColl();


			ScanDirMgr & rScanMgr = sdmColl->GetMgrAt(nDir);

			FixedVector< ScanDirMgr::PixLineInfo > & pliArr =
				rScanMgr.GetPixLineInfoArr();

			ScanDirMgr::PixLineInfo & rPli = pliArr[nPI];

			const int nBPI = rScanMgr.GetBgnIndexArr()[rPli.nLineNum];

			FixedVector< int > & rShiftArr = rScanMgr.GetShiftIndexArr();




			//for( int i=1; i < 50; i++ )				
			for (int i = 0; i < 50; i++)
			{
				{
					int nSV = rShiftArr[rPli.nIOL + i];

					const int nCPI = nBPI + nSV;

					pMedPnt[i] = F32Point::CreateFromIndex(nCPI, srcSiz);
				}

				{
				int nSV = rShiftArr[rPli.nIOL - i];

				const int nCPI = nBPI + nSV;

				pMedPnt[-i] = F32Point::CreateFromIndex(nCPI, srcSiz);
			}

				//pMedPnt[ i ] = ls1.GetCurrentFwd();
				//pMedPnt[ -i ] = ls1.GetCurrentBkd();				

				//ls1.FwdMoveNext();
				//ls1.BkdMoveNext();
			}

			F32Point fwdPnt = pMedPnt[nRadius];
			F32Point bkdPnt = pMedPnt[-nRadius];

			float difMagArr[ARR_SIZ];
			float dif_2_Arr[ARR_SIZ];
			float dif_2_Arr_0[ARR_SIZ];

			int nLastFwdI = 0;
			int nLastBkdI = 0;

			{
				int nMaxDif_2_Idx = 2;

				for (int i = 0; i < ARR_SIZ; i++)
				{
					const int j = i;
					nLastFwdI = i;

					F32Point & rPnt1 = pMedPnt[i + nRadius];
					F32Point & rPnt2 = pMedPnt[i - nRadius];

					F32ColorVal * pColor1 = (F32ColorVal *)src->GetPixAt(
						rPnt1.x, rPnt1.y);

					F32ColorVal * pColor2 = (F32ColorVal *)src->GetPixAt(
						rPnt2.x, rPnt2.y);

					difMagArr[j] = F32ColorVal::Sub(
						*pColor1, *pColor2).CalcMag();

					if (j >= 2)
					{
						dif_2_Arr_0[j] = difMagArr[j - 2] - difMagArr[j];
						dif_2_Arr[j] = fabs(
							dif_2_Arr_0[j]);

						if (dif_2_Arr[j] > dif_2_Arr[nMaxDif_2_Idx])
							nMaxDif_2_Idx = j;

						//if( dif_2_Arr[ j ] < dif_2_Arr[ nMaxDif_2_Idx ] * 0.25 )
						if (dif_2_Arr[j] < dif_2_Arr[nMaxDif_2_Idx] * 0.5)
						{
							nLastFwdI -= 2;
							//i = i;

							//break;
						}

					}

					/*
										//if( difMagArr[ j ] > difMagArr[ j - 2 ] )
										if( j >= 2 &&
										difMagArr[ j ] > difMagArr[ j - 2 ] * 1.2 )
										{
										nLastFwdI -= 2;
										//i = i;
										break;
										}
										*/

					//difMagArr[ i ] = F32Point::Sub(
					//rPnt1, rPnt2 ).CalcMag();
				}


			}

			fwdPnt = fwdPnt;

			{
				int nMaxDif_2_Idx = 2;

				for (int i = 0; i > -ARR_SIZ; i--)
				{
					const int j = -i;

					nLastBkdI = i;

					F32Point & rPnt1 = pMedPnt[i + nRadius];
					F32Point & rPnt2 = pMedPnt[i - nRadius];

					F32ColorVal * pColor1 = (F32ColorVal *)src->GetPixAt(
						rPnt1.x, rPnt1.y);

					F32ColorVal * pColor2 = (F32ColorVal *)src->GetPixAt(
						rPnt2.x, rPnt2.y);

					difMagArr[j] = F32ColorVal::Sub(
						*pColor1, *pColor2).CalcMag();

					if (j >= 2)
					{
						dif_2_Arr_0[j] = difMagArr[j - 2] - difMagArr[j];
						dif_2_Arr[j] = fabs(
							dif_2_Arr_0[j]);

						if (dif_2_Arr[j] > dif_2_Arr[nMaxDif_2_Idx])
							nMaxDif_2_Idx = j;

						//if( dif_2_Arr[ j ] < dif_2_Arr[ nMaxDif_2_Idx ] * 0.25 )
						if (dif_2_Arr[j] < dif_2_Arr[nMaxDif_2_Idx] * 0.5)
						{
							nLastBkdI += 2;
							//i = i;

							//break;
						}

					}

					/*
										//if( difMagArr[ j ] > difMagArr[ j - 2 ] )
										if( j >= 2 &&
										difMagArr[ j ] > difMagArr[ j - 2 ] * 1.2 )
										{
										nLastBkdI -= 2;
										//i = i;
										break;
										}
										*/

					//difMagArr[ i ] = F32Point::Sub(
					//rPnt1, rPnt2 ).CalcMag();
				}


			}

			bkdPnt = bkdPnt;

			{
				F32Point & newFwdPnt = pMedPnt[nLastFwdI];
				F32Point & newBkdPnt = pMedPnt[nLastBkdI];

				F32ImageRef dspImg = src->Clone();

				U8ColorVal colorFwd(0, 180, 0);
				U8ColorVal colorBkd(0, 180, 255);

				//DrawCircle( dspImg, newFwdPnt, colorFwd, 3 );
				//DrawCircle( dspImg, newBkdPnt, colorBkd, 3 );

				{
					Signal1DBuilder sb1;
					Signal1DBuilder sb2;

					//Ns_ImgGradMgr::ScanLineItrRef sli = igm1.GenScanLineItr( nPI, nDir );
					Ns_ImgGradMgr::ScanLineItrRef sli = igm1.GenScanLineItr(nPI, nDir);

					sli->GotoFirst();

					F32ColorVal * dspImgBuf = (F32ColorVal *)dspImg->GetPixAt(0, 0);

					//const F32ColorVal colorN = { 0, 255, 0 };
					//const F32ColorVal colorF = { 255, 0, 0 };

					F32ColorVal colorN = { 255, 0, 0 };
					F32ColorVal colorF = { 0, 180, 0 };

					FixedVector< float > & gradDataArr = igm1.GetGradDataArr();

					const int nofDirs = sdmColl->GetNofMgrs();

					do
					{
						const int nCPI = sli->GetCurPI();

						F32ColorVal color1;

						const int nCurDir = dirBuf[nCPI];

						float val1 = 0;
						{
							const int nValIdx = nDir + nCPI * nofDirs;
							float val = gradDataArr[nValIdx];

							if (val >= val1)
							{
								val1 = val;
								color1 = colorF;
							}

							//if( nCurDir != nDir )
							//val = 0;

							sb1.AddValue(val);
						}

						{
							const int nValIdx = nCurDir + nCPI * nofDirs;
							float val = gradDataArr[nValIdx];

							if (val < val1)
							{
								val1 = val;
								color1 = colorN;
							}

							sb2.AddValue(val);
						}

						float angDif = sdmColl->GetDirAngDif(nDir, nCurDir);

						//if( angDif < 30 )
						//if( angDif < 25 )
						if (angDif < 15)
							color1 = colorN;
						else
							color1 = colorF;

						//dspImgBuf[ nCPI ] = color1;

						F32Point pnt1 = F32Point::CreateFromIndex(nCPI, srcSiz);
						DrawCircle(dspImg, pnt1, color1.ToU8(), 2);
					} while (sli->MoveNext());

					DrawCircle(dspImg, F32Point(a_x, a_y),
						u8ColorVal(0, 0, 255), 2);

					Signal1DViewer sv1;

					sv1.AddSignal(sb2.GetResult(), colorF.ToU8());
					sv1.AddSignal(sb1.GetResult(), colorN.ToU8());

					{
						Signal1DRef sig1 = sb1.GetResult();

						const int nSize = sig1->m_data.size();

						Filt1D2SysProtoRef filtSys1 = new Filt1D2SysProto(nSize);

						filtSys1->GetInpMgr()->AssignData(&sig1->m_data[0], nSize);

						filtSys1->Proceed();

						{
							Signal1DBuilder sb3(1000, sig1->m_nBgn);

							ISingFilt1D2DataReaderRef avgRdr = filtSys1->GetAvgFilt(
								)->GetOutputReader();

							sb3.AddData(avgRdr->GetData(), avgRdr->GetSize());

							//sv1.AddSignal( sb3.GetResult(), u8ColorVal( 255, 255, 255 ) );
						}
					}

					const int nSI = rScanMgr.GetShiftStartArr()[rPli.nLineNum];

					sv1.AddSignal(DeltaSignal::CreateAt(rPli.nIOL - nSI),
						u8ColorVal(0, 0, 255));

					ShowImage(sv1.GenDisplayImage(), "G D L S");
				}

				GlobalStuff::ShowLinePathImg(dspImg);
				ShowImage(igm1.GenIsPeakImg(), "IsPeakImg");
			}

		}


	}



	return;






LastOrg:

	{

		const int nRadius = GlobalStuff::AprSize1D / 2;
		const int nDiameter = nRadius * 2 + 1;
		//const int nRadius = 3;


		F32Point pntArr1[4000];
		F32Point * pMedPnt = &pntArr1[2000];
		pMedPnt[0] = F32Point(a_x, a_y);

		F32ImageRef src = GlobalStuff::GetLinePathImg();

		CircDiff2Ref cd1 = new CircDiff2(src, nRadius);



		LineStepper ls1;
		{
			CircDiff2::FwdBkdPoints fBPnts = cd1->GetFwdBkdMatrix().GetAt(a_x, a_y);

			F32ImageRef difMagImg = cd1->GetDifMagImg();

			//F32Point fwdPnt =  fBPnts.FwdPnt;
			//F32Point bkdPnt = fBPnts.BkdPnt;

			//ls1.SetPoints( fwdPnt, bkdPnt );
			ls1.SetPoints(fBPnts.FwdPnt, fBPnts.BkdPnt);



			//for( int i=0; i < 3; i++ )
			for (int i = 1; i < 50; i++)
			{
				pMedPnt[i] = ls1.GetCurrentFwd();
				pMedPnt[-i] = ls1.GetCurrentBkd();

				ls1.FwdMoveNext();
				ls1.BkdMoveNext();
			}

			F32Point fwdPnt = pMedPnt[nRadius];
			F32Point bkdPnt = pMedPnt[-nRadius];

			float difMagArr[ARR_SIZ];
			float dif_2_Arr[ARR_SIZ];
			float dif_2_Arr_0[ARR_SIZ];

			int nLastFwdI = 0;
			int nLastBkdI = 0;

			{
				int nMaxDif_2_Idx = 2;

				for (int i = 0; i < ARR_SIZ; i++)
				{
					const int j = i;
					nLastFwdI = i;

					F32Point & rPnt1 = pMedPnt[i + nRadius];
					F32Point & rPnt2 = pMedPnt[i - nRadius];

					F32ColorVal * pColor1 = (F32ColorVal *)src->GetPixAt(
						rPnt1.x, rPnt1.y);

					F32ColorVal * pColor2 = (F32ColorVal *)src->GetPixAt(
						rPnt2.x, rPnt2.y);

					difMagArr[j] = F32ColorVal::Sub(
						*pColor1, *pColor2).CalcMag();

					if (j >= 2)
					{
						dif_2_Arr_0[j] = difMagArr[j - 2] - difMagArr[j];
						dif_2_Arr[j] = fabs(
							dif_2_Arr_0[j]);

						if (dif_2_Arr[j] > dif_2_Arr[nMaxDif_2_Idx])
							nMaxDif_2_Idx = j;

						//if( dif_2_Arr[ j ] < dif_2_Arr[ nMaxDif_2_Idx ] * 0.25 )
						if (dif_2_Arr[j] < dif_2_Arr[nMaxDif_2_Idx] * 0.5)
						{
							nLastFwdI -= 2;
							//i = i;
							break;
						}

					}

					/*
										//if( difMagArr[ j ] > difMagArr[ j - 2 ] )
										if( j >= 2 &&
										difMagArr[ j ] > difMagArr[ j - 2 ] * 1.2 )
										{
										nLastFwdI -= 2;
										//i = i;
										break;
										}
										*/

					//difMagArr[ i ] = F32Point::Sub(
					//rPnt1, rPnt2 ).CalcMag();
				}


			}

			fwdPnt = fwdPnt;

			{
				int nMaxDif_2_Idx = 2;

				for (int i = 0; i > -ARR_SIZ; i--)
				{
					const int j = -i;

					nLastBkdI = i;

					F32Point & rPnt1 = pMedPnt[i + nRadius];
					F32Point & rPnt2 = pMedPnt[i - nRadius];

					F32ColorVal * pColor1 = (F32ColorVal *)src->GetPixAt(
						rPnt1.x, rPnt1.y);

					F32ColorVal * pColor2 = (F32ColorVal *)src->GetPixAt(
						rPnt2.x, rPnt2.y);

					difMagArr[j] = F32ColorVal::Sub(
						*pColor1, *pColor2).CalcMag();

					if (j >= 2)
					{
						dif_2_Arr_0[j] = difMagArr[j - 2] - difMagArr[j];
						dif_2_Arr[j] = fabs(
							dif_2_Arr_0[j]);

						if (dif_2_Arr[j] > dif_2_Arr[nMaxDif_2_Idx])
							nMaxDif_2_Idx = j;

						//if( dif_2_Arr[ j ] < dif_2_Arr[ nMaxDif_2_Idx ] * 0.25 )
						if (dif_2_Arr[j] < dif_2_Arr[nMaxDif_2_Idx] * 0.5)
						{
							nLastBkdI += 2;
							//i = i;
							break;
						}

					}

					/*
										//if( difMagArr[ j ] > difMagArr[ j - 2 ] )
										if( j >= 2 &&
										difMagArr[ j ] > difMagArr[ j - 2 ] * 1.2 )
										{
										nLastBkdI -= 2;
										//i = i;
										break;
										}
										*/

					//difMagArr[ i ] = F32Point::Sub(
					//rPnt1, rPnt2 ).CalcMag();
				}


			}

			bkdPnt = bkdPnt;

			{
				F32Point & newFwdPnt = pMedPnt[nLastFwdI];
				F32Point & newBkdPnt = pMedPnt[nLastBkdI];

				F32ImageRef dspImg = src->Clone();

				U8ColorVal colorFwd(0, 180, 0);
				U8ColorVal colorBkd(0, 180, 255);

				DrawCircle(dspImg, newFwdPnt, colorFwd, 3);
				DrawCircle(dspImg, newBkdPnt, colorBkd, 3);

				GlobalStuff::ShowLinePathImg(dspImg);
			}

		}

	}



	return;











	{

		const int nRadius = GlobalStuff::AprSize1D;
		const int nDiameter = nRadius * 2 + 1;
		//const int nRadius = 3;


		F32ImageRef src = GlobalStuff::GetLinePathImg();

		CircDiff2Ref cd1 = new CircDiff2(src, nRadius);



		LineStepper ls1;
		{
			CircDiff2::FwdBkdPoints fBPnts = cd1->GetFwdBkdMatrix().GetAt(a_x, a_y);

			F32ImageRef difMagImg = cd1->GetDifMagImg();

			//F32Point fwdPnt =  fBPnts.FwdPnt;
			//F32Point bkdPnt = fBPnts.BkdPnt;

			//ls1.SetPoints( fwdPnt, bkdPnt );
			ls1.SetPoints(fBPnts.FwdPnt, fBPnts.BkdPnt);

			//for( int i=0; i < 3; i++ )
			for (int i = 0; i < nRadius / 2; i++)
			{
				ls1.FwdMoveNext();
				ls1.BkdMoveNext();
			}

			F32Point fwdPnt = ls1.GetCurrentFwd();
			F32Point bkdPnt = ls1.GetCurrentBkd();

			F32ColorVal * pBkdColorOrg = (F32ColorVal *)src->GetPixAt(
				bkdPnt.x, bkdPnt.y);

			F32ColorVal * pFwdColorOrg = (F32ColorVal *)src->GetPixAt(
				fwdPnt.x, fwdPnt.y);


			F32ColorVal StepColorDist;
			{
				StepColorDist = F32ColorVal::Sub(
					*pFwdColorOrg, *pBkdColorOrg);

				StepColorDist.DividSelfBy(nDiameter);
			}





			F32Point lastFwdPnt = ls1.GetCurrentFwd();



			float ucdDifArr[ARR_SIZ];
			float difMagArr[ARR_SIZ];
			F32Point pntArr[ARR_SIZ];
			int nLastI = -1;

			{
				//F32ColorVal * pBkdColorOrg = (F32ColorVal *)src->GetPixAt(
				//bkdPnt.x, bkdPnt.y );

				F32ColorVal * pLastFwdColor = (F32ColorVal *)src->GetPixAt(
					fwdPnt.x, fwdPnt.y);

				F32ColorVal * pLastFwdColor2 = pLastFwdColor;
				F32ColorVal * pLastFwdColor3 = pLastFwdColor;
				F32ColorVal * pLastFwdColor4 = pLastFwdColor;
				F32ColorVal * pLastFwdColor5 = pLastFwdColor;

				for (int i = 0; i < ARR_SIZ; i++)
				{
					nLastI = i;

					ls1.FwdMoveNext();

					fwdPnt = ls1.GetCurrentFwd();

					F32ColorVal * pFwdColor = (F32ColorVal *)src->GetPixAt(
						fwdPnt.x, fwdPnt.y);

					const float colorMag = pFwdColor->CalcMag();

					F32ColorVal AssumedColor = F32ColorVal::Add(
						*pLastFwdColor, StepColorDist);
					AssumedColor.ZeroSelfUnder(0);

					const float asmColorMag = AssumedColor.CalcMag();

					const float maxColorMag =
						(colorMag > asmColorMag) ? colorMag : asmColorMag;

					const float TrueAsmDifMag = F32ColorVal::Sub(
						*pFwdColor, AssumedColor).CalcMag();

					//difMagArr[ i ] = TrueAsmDifMag / maxColorMag;
					//difMagArr[ i ] = TrueAsmDifMag;
					difMagArr[i] = F32ColorVal::Sub(
						*pFwdColor, *pLastFwdColor).CalcMag();
					//*pFwdColor, *pLastFwdColor3 ).CalcMag();

					//if( TrueAsmDifMag > colorMag * 0.2 )
					if (TrueAsmDifMag > maxColorMag * 0.05)
						//						break;
						i = i;

					pLastFwdColor5 = pLastFwdColor4;
					pLastFwdColor4 = pLastFwdColor3;
					pLastFwdColor3 = pLastFwdColor2;
					pLastFwdColor2 = pLastFwdColor;

					pLastFwdColor = pFwdColor;

					lastFwdPnt = fwdPnt;
				}

			}


			F32Point lastBkdPnt = ls1.GetCurrentBkd();

			{
				//F32ColorVal * pBkdColorOrg = (F32ColorVal *)src->GetPixAt(
				//bkdPnt.x, bkdPnt.y );

				F32ColorVal * pLastBkdColor = (F32ColorVal *)src->GetPixAt(
					bkdPnt.x, bkdPnt.y);

				for (int i = 0; i < ARR_SIZ; i++)
				{
					nLastI = i;

					ls1.BkdMoveNext();

					bkdPnt = ls1.GetCurrentBkd();

					F32ColorVal * pBkdColor = (F32ColorVal *)src->GetPixAt(
						bkdPnt.x, bkdPnt.y);

					const float colorMag = pBkdColor->CalcMag();

					//F32ColorVal AssumedColor = F32ColorVal::Add(
					F32ColorVal AssumedColor = F32ColorVal::Sub(
						*pLastBkdColor, StepColorDist);
					AssumedColor.ZeroSelfUnder(0);


					const float asmColorMag = AssumedColor.CalcMag();

					const float maxColorMag =
						(colorMag > asmColorMag) ? colorMag : asmColorMag;

					const float TrueAsmDifMag = F32ColorVal::Sub(
						*pBkdColor, AssumedColor).CalcMag();

					//if( TrueAsmDifMag > colorMag * 0.2 )
					if (TrueAsmDifMag > maxColorMag * 0.05)
						break;

					pLastBkdColor = pBkdColor;

					lastBkdPnt = bkdPnt;
				}

			}

			F32Point newFwdPnt = lastFwdPnt;
			F32Point newBkdPnt = lastBkdPnt;

			F32ImageRef dspImg = src->Clone();

			U8ColorVal colorFwd(0, 180, 0);
			U8ColorVal colorBkd(0, 180, 255);

			DrawCircle(dspImg, newFwdPnt, colorFwd, 3);
			DrawCircle(dspImg, newBkdPnt, colorBkd, 3);

			GlobalStuff::ShowLinePathImg(dspImg);
		}



		//ccp1.ShowResult();

	}

	return;













	{

		const int nRadius = GlobalStuff::AprSize1D;
		//const int nRadius = 3;


		F32ImageRef src = GlobalStuff::GetLinePathImg();

		CircDiff2Ref cd1 = new CircDiff2(src, nRadius);



		LineStepper ls1;
		{
			CircDiff2::FwdBkdPoints fBPnts = cd1->GetFwdBkdMatrix().GetAt(a_x, a_y);

			F32ImageRef difMagImg = cd1->GetDifMagImg();

			//F32Point fwdPnt =  fBPnts.FwdPnt;
			//F32Point bkdPnt = fBPnts.BkdPnt;

			//ls1.SetPoints( fwdPnt, bkdPnt );
			ls1.SetPoints(fBPnts.FwdPnt, fBPnts.BkdPnt);

			//for( int i=0; i < 3; i++ )
			for (int i = 0; i < nRadius / 2; i++)
			{
				ls1.FwdMoveNext();
				ls1.BkdMoveNext();
			}

			F32Point fwdPnt = ls1.GetCurrentFwd();
			F32Point bkdPnt = ls1.GetCurrentBkd();

			F32ColorVal * pBkdColorOrg = (F32ColorVal *)src->GetPixAt(
				bkdPnt.x, bkdPnt.y);

			F32ColorVal * pFwdColorOrg = (F32ColorVal *)src->GetPixAt(
				fwdPnt.x, fwdPnt.y);

			F32ColorVal bfUcdOrg;
			float fbDifMagOrg;
			{
				bfUcdOrg = F32ColorVal::Sub(
					*pFwdColorOrg, *pBkdColorOrg);

				fbDifMagOrg = bfUcdOrg.CalcMag();

				bfUcdOrg.DividSelfBy(fbDifMagOrg);
			}

			//const float difThr = 0.765;
			//const float difThr = 0.1;
			//const float difThr = 0.05;
			const float difThr = 0.2;

			F32Point lastFwdPnt = ls1.GetCurrentFwd();



			float ucdDifArr[ARR_SIZ];
			float difMagArr[ARR_SIZ];
			F32Point pntArr[ARR_SIZ];
			int nLastI = -1;

			{
				//F32ColorVal * pBkdColorOrg = (F32ColorVal *)src->GetPixAt(
				//bkdPnt.x, bkdPnt.y );

				for (int i = 0; i < ARR_SIZ; i++)
				{
					ls1.FwdMoveNext();

					fwdPnt = ls1.GetCurrentFwd();

					F32ColorVal * pFwdColor = (F32ColorVal *)src->GetPixAt(
						fwdPnt.x, fwdPnt.y);

					F32ColorVal bfUcd = F32ColorVal::Sub(
						*pFwdColor, *pBkdColorOrg);

					float fbDifMag = bfUcd.CalcMag();

					bfUcd.DividSelfBy(fbDifMag);

					float ucdDif = F32ColorVal::Sub(
						bfUcdOrg, bfUcd).CalcMag();

					ucdDifArr[i] = ucdDif;

					difMagArr[i] = *difMagImg->GetPixAt(fwdPnt.x, fwdPnt.y);

					nLastI = i;

					pntArr[i] = fwdPnt;

					if (ucdDif > difThr)
						break;

					if (i >= 2 &&
						difMagArr[i] > 1.2 * difMagArr[i - 2])
						break;

					lastFwdPnt = fwdPnt;
				}

			}

			F32Point lastBkdPnt = ls1.GetCurrentBkd();

			{
				//F32ColorVal * pFwdColorOrg = (F32ColorVal *)src->GetPixAt(
				//fwdPnt.x, fwdPnt.y );

				F32ColorVal bfUcdInvOrg = bfUcdOrg.MultBy(-1);

				for (int i = 0; i < ARR_SIZ; i++)
				{
					ls1.BkdMoveNext();

					bkdPnt = ls1.GetCurrentBkd();

					F32ColorVal * pBkdColor = (F32ColorVal *)src->GetPixAt(
						bkdPnt.x, bkdPnt.y);


					F32ColorVal bfUcd = F32ColorVal::Sub(
						*pBkdColor, *pFwdColorOrg);

					float fbDifMag = bfUcd.CalcMag();

					bfUcd.DividSelfBy(fbDifMag);

					float ucdDif = F32ColorVal::Sub(
						bfUcdInvOrg, bfUcd).CalcMag();

					ucdDifArr[i] = ucdDif;

					difMagArr[i] = *difMagImg->GetPixAt(bkdPnt.x, bkdPnt.y);

					nLastI = i;

					pntArr[i] = bkdPnt;

					if (ucdDif > difThr)
						break;

					if (i >= 2 &&
						difMagArr[i] > 1.2 * difMagArr[i - 2])
						break;

					lastBkdPnt = bkdPnt;
				}

			}


			//F32ImageRef angImg = cd1->GetDifAngleImg();

			//F32Point newFwdPnt = ls1.GetCurrentFwd();
			//F32Point newBkdPnt = ls1.GetCurrentBkd();

			F32Point newFwdPnt = lastFwdPnt;
			F32Point newBkdPnt = lastBkdPnt;

			F32ImageRef dspImg = src->Clone();

			//U8ColorVal color1( 0, 180, 0 );

			U8ColorVal colorFwd(0, 180, 0);
			U8ColorVal colorBkd(0, 180, 255);

			DrawCircle(dspImg, newFwdPnt, colorFwd, 3);
			DrawCircle(dspImg, newBkdPnt, colorBkd, 3);

			GlobalStuff::ShowLinePathImg(dspImg);
		}



		//ccp1.ShowResult();

	}

	return;
















	const int nRadius = GlobalStuff::AprSize1D;
	//const int nRadius = 3;


	F32ImageRef src = GlobalStuff::GetLinePathImg();

	CircDiff2Ref cd1 = new CircDiff2(src, nRadius);


	//ShowImage( cd1->GetDifAngleImg(), "Diff Angle" );

	//ShowImage( cd1->GenColorShowImg(), "Color Show Img" );

	//F32ImageRef difMagImg = cd1->GetDifMagImg();
	//ShowImage( difMagImg, "Diff Mag" );

	//GlobalStuff::SetLinePathImg( difMagImg );
	//GlobalStuff::ShowLinePathImg();






	////////////////////////

	/*
		CircleContourOfPix5 ccp1( GlobalStuff::GetLinePathImg(),
		GlobalStuff::AprSize1D );

		ccp1.PreparePix( a_x, a_y );

		float angDig = ccp1.GetAngleByDigree();

		float angRad = ccp1.GetAngleByRad();
		*/


	LineStepper ls1;
	{
		CircDiff2::FwdBkdPoints fBPnts = cd1->GetFwdBkdMatrix().GetAt(a_x, a_y);

		F32Point fwdPnt = fBPnts.FwdPnt;
		F32Point bkdPnt = fBPnts.BkdPnt;


		//F32ImageRef angImg = cd1->GetDifAngleImg();



		ls1.SetPoints(fwdPnt, bkdPnt);

		//for( int i=0; i < 20; i++ )
		for (int i = 0; i < ARR_SIZ; i++)
		{
			ls1.FwdMoveNext();
			ls1.BkdMoveNext();
		}

		F32Point newFwdPnt = ls1.GetCurrentFwd();
		F32Point newBkdPnt = ls1.GetCurrentBkd();

		F32ImageRef dspImg = src->Clone();

		U8ColorVal color1(0, 180, 0);

		DrawCircle(dspImg, newFwdPnt, color1, 3);
		DrawCircle(dspImg, newBkdPnt, color1, 3);

		GlobalStuff::ShowLinePathImg(dspImg);
	}





	//ccp1.ShowResult();



}


void ImageProcessor::CircPntOfLinePathImg2(int a_x, int a_y)
{
	//	a_x = 440;
	//	a_y = 200;

	//	a_x = 182;
	//	a_y = 82;

	//	a_x = 112;
	//	a_y = 366;

	//CircleContourOfPix ccp1( GlobalStuff::GetLinePathImg(),
	//CircleContourOfPix2 ccp1( GlobalStuff::GetLinePathImg(), NULL,
	//CircleContourOfPix3 ccp1( GlobalStuff::GetLinePathImg(), NULL,
	//CircleContourOfPix4 ccp1( GlobalStuff::GetLinePathImg(), NULL,
	CircleContourOfPix5 ccp1(GlobalStuff::GetLinePathImg(),
		GlobalStuff::AprSize1D);

	ccp1.PreparePix(a_x, a_y);

	float angDig = ccp1.GetAngleByDigree();

	float angRad = ccp1.GetAngleByRad();

	ccp1.ShowResult();

	return;

	F32ImageRef src = GlobalStuff::GetLinePathImg();

	CvSize srcSiz = src->GetSize();

	{

		//int nRadius = siz1.width / 4;
		//int nRadius = 3;
		int nRadius = GlobalStuff::AprSize1D;

		if (nRadius > 10)
			nRadius = 10;

		if (a_x - nRadius < 0 ||
			a_x + nRadius > srcSiz.width - 1 ||
			a_y - nRadius < 0 ||
			a_y + nRadius > srcSiz.height - 1)
		{
			return;
		}


		CircleContPathRef cp1 = new CircleContPath(0, 180, nRadius);
		//CircleContPathRef cp1 = new CircleContPath( 0, 270, nRadius );
		//CircleContPathRef cp1 = new CircleContPath( 0, 360, nRadius );

		/*
				cvRectangle(
				img1->GetIplImagePtr(),
				cvPoint( orgPnt.x - nRadius, orgPnt.y - nRadius),
				//cvPoint(nWidth-1, nHeight-1),
				cvPoint( orgPnt.x + nRadius, orgPnt.y + nRadius),
				//cvPoint(nWidth+50, nHeight+170),
				//CV_RGB(64, 128, 255),
				//CV_RGB(255, 128, 64),
				cvScalar( 128, 128, 128, 128 ),
				//CV_RGB(255, 255, 255),
				-1);
				*/


		//CvSize siz1 = cvSize( 400, 400 );
		//CvSize siz1 = cvSize( 40, 40 );
		CvSize siz1 = cvSize(nRadius * 4, nRadius * 4);

		F32ImageRef img1 = F32Image::Create(siz1, 1);

		img1->SetAll(0);

		F32Point orgPnt(siz1.width / 2, siz1.height / 2);


		float midVal = *src->GetPixAt(a_x, a_y);

		//*img1->GetPixAt( orgPnt.x, orgPnt.y ) = 255;
		*img1->GetPixAt(orgPnt.x, orgPnt.y) = midVal;


		FixedVector< F32Point > pntArr(300);




		do
		{
			F32Point pnt1 = cp1->GetCurrent();

			pntArr.PushBack(pnt1);

		} while (cp1->MoveNext());

		F32Point pntSrcMid(a_x, a_y);


		FixedVector< float > valArr;
		valArr.SetSize(pntArr.GetSize() * 2);

		for (int i = 0; i < pntArr.GetSize(); i++)
		{
			F32Point & pntI = pntArr[i];

			float valI;
			{
				F32Point pntSrcI = pntSrcMid;
				pntSrcI.IncBy(pntI);

				valI = *src->GetPixAt(pntSrcI.x, pntSrcI.y);
			}

			F32Point pntJ = pntI;
			pntJ.MultSelfBy(-1);

			float valJ;
			{
				F32Point pntSrcJ = pntSrcMid;
				pntSrcJ.IncBy(pntJ);

				valJ = *src->GetPixAt(pntSrcJ.x, pntSrcJ.y);
			}

			valArr[i] = valI;
			valArr[i + pntArr.GetSize()] = valJ;

			if (midVal < valI || midVal < valJ)
			{
				//valI = 0;
				//valJ = 0;					
			}

			{
				F32Point & pnt1 = pntI;

				F32Point pnt2 = pnt1;
				pnt2.IncBy(orgPnt);

				float * pPix = img1->GetPixAt(pnt2.x, pnt2.y);

				*pPix = valI;
			}

			{
				F32Point & pnt1 = pntJ;

				F32Point pnt2 = pnt1;
				pnt2.IncBy(orgPnt);

				float * pPix = img1->GetPixAt(pnt2.x, pnt2.y);

				*pPix = valJ;
			}



		}

		{
			const int nScaleW = 800 / valArr.GetSize() + 1;

			Signal1DViewer sv1;
			int i;

			{
				Signal1DBuilder sb1(1000);

				for (int j = 0; j < valArr.GetSize(); j++)
				{
					for (int k = 0; k < nScaleW; k++)
						sb1.AddValue(midVal);
				}

				sv1.AddSignal(sb1.GetResult(), u8ColorVal(0, 170, 0));
			}

			bool bDone;

			for (int i = 0, m = 0; m < 4; m++)
			{

				{
					Signal1DBuilder sb1(1000, i * nScaleW);

					int nLim = i + valArr.GetSize() / 8;
					if (nLim > valArr.GetSize())
						nLim = valArr.GetSize();

					bDone = false;

					for (; i < nLim; i++)
					{
						for (int k = 0; k < nScaleW; k++)
						{
							sb1.AddValue(valArr[i]);
							bDone = true;
						}
					}

					if (!bDone)
						bDone = bDone;

					if (m < 2)
						sv1.AddSignal(sb1.GetResult(), u8ColorVal(0, 0, 255));
					else
						sv1.AddSignal(sb1.GetResult(), u8ColorVal(200, 0, 200));
				}

				{
				Signal1DBuilder sb1(1000, i * nScaleW);

				int nLim = i + valArr.GetSize() / 8;
				if (nLim > valArr.GetSize())
					nLim = valArr.GetSize();

				bDone = false;

				for (; i < nLim; i++)
				{
					for (int k = 0; k < nScaleW; k++)
					{
						sb1.AddValue(valArr[i]);
						bDone = true;
					}
				}

				if (!bDone)
					bDone = bDone;

				if (m < 2)
					//sv1.AddSignal( sb1.GetResult(), u8ColorVal( 200, 0, 200 ) );
					sv1.AddSignal(sb1.GetResult(), u8ColorVal(200, 0, 0));
				else
					sv1.AddSignal(sb1.GetResult(), u8ColorVal(255, 255, 255));
			}

			}

			ShowImage(sv1.GenDisplayImage(), "CircSig");


			//sv1

		}

		F32ImageRef img2 = GenUpSampledImage(img1, 10);

		ShowImage(img2, "CircleContPath");


		return;
	}


}

void ImageProcessor::CircPntOfLinePathImg(int a_x, int a_y)
{


	{
		F32ImageRef src = GlobalStuff::GetLinePathImg();

		CvSize srcSiz = src->GetSize();

		FixedVector< F32Point > pntArr;
		pntArr.SetSize(srcSiz.width * srcSiz.height);

		FillSlidePointArr(src, GlobalStuff::AprSize1D, &pntArr);

		F32ImageRef dsp = GlobalStuff::GetLinePathImg()->Clone();
		int nofChns = dsp->GetNofChannels();
		dsp = GenTriChGrayImg(dsp);


		Accessor2D< F32Point > acSlide(&pntArr[0], srcSiz.width, srcSiz.height);

		FixedVector< float > avgValArr(200);
		FixedVector< float > valArr(200);

		FixedVector< U8ColorVal > avgValColorArr(200);
		FixedVector< U8ColorVal > valColorArr(200);

		MultiColorSignal1DViewerRef mcv1 = new MultiColorSignal1DViewer();

		F32ImageRef avg_Img = GenFastAvgImg(src, GlobalStuff::AprSize1D);
		//IndexCalc2D indexCalc( srcSiz.width, srcSiz.height );

		F32Point srcPnt(a_x, a_y);

		GlobalStuff::SetPoint0(srcPnt);

		bool bFlg = true;

		while (bFlg)
		{
			float srcVal = *src->GetPixAt(srcPnt.x, srcPnt.y);

			float avgVal = *avg_Img->GetPixAt(srcPnt.x, srcPnt.y);

			F32Point & rPnt = acSlide.GetAt(srcPnt.x, srcPnt.y);


			F32Point pnt1 = rPnt.Round();

			float dstVal = *src->GetPixAt(pnt1.x, pnt1.y);

			float dstAvgVal = *avg_Img->GetPixAt(pnt1.x, pnt1.y);

			GlobalStuff::SetPoint1(pnt1);





			/*
						F32ColorVal * pix = (F32ColorVal *) dsp->GetPixAt( pnt1.x, pnt1.y );

						pix->val0 = 0;
						pix->val1 = 180;
						pix->val2 = 0;
						*/
			{
				//int nRadius = 2;
				//int nRadius = 3;
				int nRadius = 0;
				//int nRadius = 4;

				U8ColorVal color1;
				{

					if (F32Point::Compare(pnt1, srcPnt))
					{
						color1 = u8ColorVal(0, 0, 255);
						bFlg = false;
					}
					//else if( dstVal >= avgVal || dstVal >= srcVal )
					else if (dstVal > srcVal ||
						dstAvgVal > avgVal)
					{
						//color1 = u8ColorVal( 100, 180, 180 );
						color1 = u8ColorVal(255, 255, 255);
						bFlg = false;
					}
					else if (dstVal > avgVal)
					{
						color1 = u8ColorVal(0, 150, 255);
						//bFlg = false;
					}
					//else if( dstVal < avgVal )
					else if (dstVal <= avgVal)
					{
						color1 = u8ColorVal(0, 180, 0);
					}

					DrawCircle(dsp, pnt1, color1, nRadius);
				}

				U8ColorVal color0;
				{

					if (F32Point::Compare(pnt1, srcPnt))
					{
						if (srcVal > avgVal)
							color0 = u8ColorVal(0, 0, 100);
						else
							color0 = u8ColorVal(0, 0, 255);
					}
					//else if( srcVal < avgVal * 0.6666 )
					else if (srcVal < avgVal * 0.8)
						color0 = u8ColorVal(255, 0, 0);
					else
						color0 = u8ColorVal(255, 0, 150);

					DrawCircle(dsp, srcPnt, color0, nRadius);
				}



				{
					FixedVector< float > & rValArr = avgValArr;

					//rValArr.PushBack( avgVal );
					rValArr.PushBack(dstAvgVal);

					FixedVector< U8ColorVal > & rColorArr = avgValColorArr;

					//rColorArr.PushBack( u8ColorVal( avgVal, avgVal, avgVal ) );
					rColorArr.PushBack(u8ColorVal(dstAvgVal, dstAvgVal, dstAvgVal));

				}

				{
					FixedVector< float > & rValArr = valArr;

					//rValArr.PushBack( srcVal );
					rValArr.PushBack(dstVal);

					FixedVector< U8ColorVal > & rColorArr = valColorArr;

					//rColorArr.PushBack( color0 );
					rColorArr.PushBack(color1);
				}

			}

			srcPnt = pnt1;
		}

		mcv1->DrawValueSignals(avgValArr, avgValColorArr);

		mcv1->DrawValueSignals(valArr, valColorArr);

		ShowImage(mcv1->GenDisplayImage(), "ValSig");

		GlobalStuff::ShowLinePathImg(dsp);


		return;

	}






















	{
		//a_x = 187;
		//a_y = 189;

		//F32ImageRef src = GenImageFromChannel(			
		//	GlobalStuff::GetLinePathImg(), 0 );

		F32ImageRef src = GlobalStuff::GetLinePathImg();

		CvSize srcSiz = src->GetSize();

		FixedVector< F32Point > pntArr;
		pntArr.SetSize(srcSiz.width * srcSiz.height);

		//FillCenterOfMassArr( src, GlobalStuff::AprSize1D, &pntArr );
		FillSlidePointArr(src, GlobalStuff::AprSize1D, &pntArr);
		//FillClimbPointArr( src, GlobalStuff::AprSize1D, &pntArr );

		//GlobalStuff::SetLinePathImg(
		//GenFastAvgImg( GlobalStuff::GetLinePathImg(), GlobalStuff::AprSize1D ) );

		F32ImageRef dsp = GlobalStuff::GetLinePathImg()->Clone();
		int nofChns = dsp->GetNofChannels();
		dsp = GenTriChGrayImg(dsp);


		Accessor2D< F32Point > acSlide(&pntArr[0], srcSiz.width, srcSiz.height);

		FixedVector< float > avgValArr(200);
		FixedVector< float > valArr(200);

		{
			F32ImageRef avg_Img = GenFastAvgImg(src, GlobalStuff::AprSize1D);

			IndexCalc2D indexCalc(srcSiz.width, srcSiz.height);

			F32Point srcPnt(a_x, a_y);

			float srcVal = *src->GetPixAt(srcPnt.x, srcPnt.y);

			float avgVal = *avg_Img->GetPixAt(srcPnt.x, srcPnt.y);

			//F32Point & rPnt = pntArr[ indexCalc.Calc( a_x, a_y ) ];
			F32Point & rPnt = acSlide.GetAt(a_x, a_y);


			F32Point pnt1 = rPnt.Round();

			float dstVal = *src->GetPixAt(pnt1.x, pnt1.y);

			float dstAvgVal = *avg_Img->GetPixAt(pnt1.x, pnt1.y);

			GlobalStuff::SetPoint1(pnt1);





			/*
						F32ColorVal * pix = (F32ColorVal *) dsp->GetPixAt( pnt1.x, pnt1.y );

						pix->val0 = 0;
						pix->val1 = 180;
						pix->val2 = 0;
						*/
			{
				//int nRadius = 2;
				int nRadius = 3;
				//int nRadius = 4;

				U8ColorVal color1;
				{

					if (F32Point::Compare(pnt1, srcPnt))
						color1 = u8ColorVal(0, 0, 255);
					//else if( dstVal >= avgVal || dstVal >= srcVal )
					else if (dstVal > srcVal)
						//color1 = u8ColorVal( 100, 180, 180 );
						color1 = u8ColorVal(255, 255, 255);
					else if (dstVal > avgVal)
						color1 = u8ColorVal(0, 150, 255);
					//else if( dstVal < avgVal )
					else if (dstVal <= avgVal)
						color1 = u8ColorVal(0, 180, 0);

					DrawCircle(dsp, pnt1, color1, nRadius);
				}

				U8ColorVal color0;
				{

					if (F32Point::Compare(pnt1, srcPnt))
					{
						if (srcVal > avgVal)
							color0 = u8ColorVal(0, 0, 100);
						else
							color0 = u8ColorVal(0, 0, 255);
					}
					//else if( srcVal < avgVal * 0.6666 )
					else if (srcVal < avgVal * 0.8)
						color0 = u8ColorVal(255, 0, 0);
					else
						color0 = u8ColorVal(255, 0, 150);

					DrawCircle(dsp, srcPnt, color0, nRadius);
				}

				/*
								{
								CvSize siz1 = cvSize( 600, 400 );

								F32ImageRef recImg = F32Image::Create( siz1, 3 );

								cvRectangle(
								recImg->GetIplImagePtr(),
								cvPoint(0, 0),
								cvPoint( siz1.width / 3, siz1.height - 1 ),
								CV_RGB(srcVal, srcVal, srcVal),
								-1);

								cvRectangle(
								recImg->GetIplImagePtr(),
								cvPoint(siz1.width / 3, 0),
								cvPoint( siz1.width * 2 / 3, siz1.height - 1 ),
								CV_RGB(avgVal, avgVal, avgVal),
								-1);

								cvRectangle(
								recImg->GetIplImagePtr(),
								cvPoint(siz1.width * 2 / 3, 0),
								cvPoint( siz1.width - 1, siz1.height - 1 ),
								CV_RGB(dstVal, dstVal, dstVal),
								-1);

								ShowImage(recImg, "recImg");
								}
								*/


				/*
								{
								FixedVector< float > valArr(200);


								//valArr.PushBack( abvVal );
								valArr.PushBack( srcVal );
								valArr.PushBack( avgVal );
								valArr.PushBack( dstVal );
								valArr.PushBack( dstAvgVal );

								FixedVector< U8ColorVal > colorArr(200);

								//colorArr.PushBack( u8ColorVal( abvVal, abvVal, abvVal ) );
								colorArr.PushBack( color0 );
								colorArr.PushBack( u8ColorVal( avgVal, avgVal, avgVal ) );
								colorArr.PushBack( color1 );
								colorArr.PushBack( u8ColorVal( dstAvgVal, dstAvgVal, dstAvgVal ) );


								//DrawValueSignals( valArr, colorArr );

								MultiColorSignal1DViewerRef mcv1 = new MultiColorSignal1DViewer();

								mcv1->DrawValueSignals( valArr, colorArr );

								//ShowImage( sv1.GenDisplayImage(), "ValSig" );
								ShowImage( mcv1->GenDisplayImage(), "ValSig" );

								}
								*/

				//FixedVector< float > avgValArr(200);
				//FixedVector< float > valArr(200);

				MultiColorSignal1DViewerRef mcv1 = new MultiColorSignal1DViewer();
				{
					FixedVector< float > & rValArr = avgValArr;

					rValArr.PushBack(avgVal);
					rValArr.PushBack(dstAvgVal);

					FixedVector< U8ColorVal > colorArr(200);

					colorArr.PushBack(u8ColorVal(avgVal, avgVal, avgVal));
					colorArr.PushBack(u8ColorVal(dstAvgVal, dstAvgVal, dstAvgVal));

					mcv1->DrawValueSignals(rValArr, colorArr);
				}

				{
					FixedVector< float > & rValArr = valArr;

					rValArr.PushBack(srcVal);
					rValArr.PushBack(dstVal);

					FixedVector< U8ColorVal > colorArr(200);

					colorArr.PushBack(color0);
					colorArr.PushBack(color1);

					mcv1->DrawValueSignals(rValArr, colorArr);
				}
				ShowImage(mcv1->GenDisplayImage(), "ValSig");



			}
		}

		GlobalStuff::ShowLinePathImg(dsp);


		return;

	}
















	CircleContourOfPix ccp1(GlobalStuff::GetLinePathImg(),
		//CircleContourOfPix2 ccp1( GlobalStuff::GetLinePathImg(), NULL,
		GlobalStuff::AprSize1D);

	ccp1.PreparePix(a_x, a_y);

	ccp1.ShowResult();

	return;

	F32ImageRef src = GlobalStuff::GetLinePathImg();

	CvSize srcSiz = src->GetSize();

	{

		//int nRadius = siz1.width / 4;
		//int nRadius = 3;
		int nRadius = GlobalStuff::AprSize1D;

		if (nRadius > 10)
			nRadius = 10;

		if (a_x - nRadius < 0 ||
			a_x + nRadius > srcSiz.width - 1 ||
			a_y - nRadius < 0 ||
			a_y + nRadius > srcSiz.height - 1)
		{
			return;
		}


		CircleContPathRef cp1 = new CircleContPath(0, 180, nRadius);
		//CircleContPathRef cp1 = new CircleContPath( 0, 270, nRadius );
		//CircleContPathRef cp1 = new CircleContPath( 0, 360, nRadius );

		/*
				cvRectangle(
				img1->GetIplImagePtr(),
				cvPoint( orgPnt.x - nRadius, orgPnt.y - nRadius),
				//cvPoint(nWidth-1, nHeight-1),
				cvPoint( orgPnt.x + nRadius, orgPnt.y + nRadius),
				//cvPoint(nWidth+50, nHeight+170),
				//CV_RGB(64, 128, 255),
				//CV_RGB(255, 128, 64),
				cvScalar( 128, 128, 128, 128 ),
				//CV_RGB(255, 255, 255),
				-1);
				*/


		//CvSize siz1 = cvSize( 400, 400 );
		//CvSize siz1 = cvSize( 40, 40 );
		CvSize siz1 = cvSize(nRadius * 4, nRadius * 4);

		F32ImageRef img1 = F32Image::Create(siz1, 1);

		img1->SetAll(0);

		F32Point orgPnt(siz1.width / 2, siz1.height / 2);


		float midVal = *src->GetPixAt(a_x, a_y);

		//*img1->GetPixAt( orgPnt.x, orgPnt.y ) = 255;
		*img1->GetPixAt(orgPnt.x, orgPnt.y) = midVal;


		FixedVector< F32Point > pntArr(300);




		do
		{
			F32Point pnt1 = cp1->GetCurrent();

			pntArr.PushBack(pnt1);

		} while (cp1->MoveNext());

		F32Point pntSrcMid(a_x, a_y);


		FixedVector< float > valArr;
		valArr.SetSize(pntArr.GetSize() * 2);

		for (int i = 0; i < pntArr.GetSize(); i++)
		{
			F32Point & pntI = pntArr[i];

			float valI;
			{
				F32Point pntSrcI = pntSrcMid;
				pntSrcI.IncBy(pntI);

				valI = *src->GetPixAt(pntSrcI.x, pntSrcI.y);
			}

			F32Point pntJ = pntI;
			pntJ.MultSelfBy(-1);

			float valJ;
			{
				F32Point pntSrcJ = pntSrcMid;
				pntSrcJ.IncBy(pntJ);

				valJ = *src->GetPixAt(pntSrcJ.x, pntSrcJ.y);
			}

			valArr[i] = valI;
			valArr[i + pntArr.GetSize()] = valJ;

			if (midVal < valI || midVal < valJ)
			{
				//valI = 0;
				//valJ = 0;					
			}

			{
				F32Point & pnt1 = pntI;

				F32Point pnt2 = pnt1;
				pnt2.IncBy(orgPnt);

				float * pPix = img1->GetPixAt(pnt2.x, pnt2.y);

				*pPix = valI;
			}

			{
				F32Point & pnt1 = pntJ;

				F32Point pnt2 = pnt1;
				pnt2.IncBy(orgPnt);

				float * pPix = img1->GetPixAt(pnt2.x, pnt2.y);

				*pPix = valJ;
			}



		}

		{
			const int nScaleW = 800 / valArr.GetSize() + 1;

			Signal1DViewer sv1;
			int i;

			{
				Signal1DBuilder sb1(1000);

				for (int j = 0; j < valArr.GetSize(); j++)
				{
					for (int k = 0; k < nScaleW; k++)
						sb1.AddValue(midVal);
				}

				sv1.AddSignal(sb1.GetResult(), u8ColorVal(0, 170, 0));
			}

			bool bDone;

			for (int i = 0, m = 0; m < 4; m++)
			{

				{
					Signal1DBuilder sb1(1000, i * nScaleW);

					int nLim = i + valArr.GetSize() / 8;
					if (nLim > valArr.GetSize())
						nLim = valArr.GetSize();

					bDone = false;

					for (; i < nLim; i++)
					{
						for (int k = 0; k < nScaleW; k++)
						{
							sb1.AddValue(valArr[i]);
							bDone = true;
						}
					}

					if (!bDone)
						bDone = bDone;

					if (m < 2)
						sv1.AddSignal(sb1.GetResult(), u8ColorVal(0, 0, 255));
					else
						sv1.AddSignal(sb1.GetResult(), u8ColorVal(200, 0, 200));
				}

				{
				Signal1DBuilder sb1(1000, i * nScaleW);

				int nLim = i + valArr.GetSize() / 8;
				if (nLim > valArr.GetSize())
					nLim = valArr.GetSize();

				bDone = false;

				for (; i < nLim; i++)
				{
					for (int k = 0; k < nScaleW; k++)
					{
						sb1.AddValue(valArr[i]);
						bDone = true;
					}
				}

				if (!bDone)
					bDone = bDone;

				if (m < 2)
					//sv1.AddSignal( sb1.GetResult(), u8ColorVal( 200, 0, 200 ) );
					sv1.AddSignal(sb1.GetResult(), u8ColorVal(200, 0, 0));
				else
					sv1.AddSignal(sb1.GetResult(), u8ColorVal(255, 255, 255));
			}

			}

			ShowImage(sv1.GenDisplayImage(), "CircSig");


			//sv1

		}

		F32ImageRef img2 = GenUpSampledImage(img1, 10);

		ShowImage(img2, "CircleContPath");


		return;
	}



	//ShowImage( src, "CircleContPath" );
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

	//ImageLineViewerRef ilv1 = new ImageLineViewer( img1, lp ); 
	ImageLineViewer2Ref ilv1 = new ImageLineViewer2(img1, lp);
	//ImageLineViewer3Ref ilv1 = new ImageLineViewer3( img1, lp ); 

	//ConflictScannerRef ilv1 = new ConflictScanner( img1 ); 
	//ilv1->ProcessLine( lp ); 

	/*
	{
	F32ColorVal color1 = { 0, 180, 0 };


	{
	F32ColorVal * pix1 =
	(F32ColorVal *)img1Dsp->GetPixAt( x1, y1 );

	*pix1 = color1;
	}

	{
	F32ColorVal * pix88 =
	(F32ColorVal *)img1Dsp->GetPixAt( x2, y2 );

	*pix88 = color1;
	}


	Filter1DPosAccum fpa1;


	IIterator_REF( F32Point ) iter1 = lp;

	LinearColorFilter1DRef cf1 = new LinearColorFilter1D(
	LinearAvgFilter1D::Create( GlobalStuff::AprSize1D ) );

	//const int nShiftCf1 = cf1->GetShift();
	//const int nShiftCf1 = 0;

	fpa1.Add( cf1->GetLength() - 1, cf1->GetShift() );

	//		Signal1DBuilderRef sigBuilder0 = new Signal1DBuilder( 300, nShiftCf1 );
	//		Signal1DBuilderRef sigBuilder1 = new Signal1DBuilder( 300, nShiftCf1 );
	//		Signal1DBuilderRef sigBuilder2 = new Signal1DBuilder( 300, nShiftCf1 );

	Signal1DBuilderRef sigBuilder0 = new Signal1DBuilder( 300, fpa1.GetAnchPos() );
	Signal1DBuilderRef sigBuilder1 = new Signal1DBuilder( 300, fpa1.GetAnchPos() );
	Signal1DBuilderRef sigBuilder2 = new Signal1DBuilder( 300, fpa1.GetAnchPos() );



	LinearColorFilter1DRef cf2 = new LinearColorFilter1D(
	LinearDiffFilter1D::Create( cf1->GetLength() ) );

	//const int nShiftCf2 = nShiftCf1 + cf2->GetShift();
	fpa1.Add( cf2->GetLength() - 1, cf2->GetShift() );


	IFilter1DRef flt1 = LinearAvgFilter1D::Create( 15 );

	Signal1DBuilderRef sbDif1_2 = new Signal1DBuilder( 300, fpa1.GetAnchPos() + flt1->GetShift() );



	//Signal1DBuilderRef sbDif = new Signal1DBuilder(300, nShiftCf2 );
	Signal1DBuilderRef sbDif = new Signal1DBuilder( 300, fpa1.GetAnchPos() );





	LinearColorFilter1DRef cf3 = new LinearColorFilter1D(
	LinearDiffFilter1D::Create( cf2->GetLength() ) );

	//const int nShiftCf3 = nShiftCf2 + cf3->GetShift();
	fpa1.Add( cf3->GetLength() - 1, cf3->GetShift() );



	//Signal1DBuilderRef sbDif2 = new Signal1DBuilder(300, nShiftCf3 );

	Signal1DBuilderRef sbDif2 = new Signal1DBuilder( 300, fpa1.GetAnchPos() );


	//int cnt = 0;

	F32ColorVal * pix2 = NULL;

	F32ColorVal drv1;

	F32ColorVal pix21;
	F32ColorVal pix22;

	float maxVal = 0;

	do
	{
	//F32Point cp = lp->GetCurrent();
	F32Point cp = iter1->GetCurrent();


	pix2 = (F32ColorVal *)img1->GetPixAt( (int)cp.x, (int)cp.y );

	pix21 = *pix2;


	{
	F32ColorVal * pix88 =
	(F32ColorVal *)img1Dsp->GetPixAt( (int)cp.x, (int)cp.y );


	*pix88 = color1;
	}


	cf1->InputVal( pix21 );

	if( cf1->HasOutput() )
	{
	//pix21 = cf1->CalcOutput();
	cf1->CalcOutput();
	pix21 = cf1->GetLastOutput();

	cf2->InputVal( pix21 );

	sigBuilder0->AddValue( pix21.val0 );
	sigBuilder1->AddValue( pix21.val1 );
	sigBuilder2->AddValue( pix21.val2 );

	if( cf2->HasOutput() )
	{
	cf2->CalcOutput();
	pix22 = cf2->GetLastOutput();

	{
	const float drv1Val = pix22.CalcMag();

	if( drv1Val > maxVal )
	maxVal = drv1Val;

	sbDif->AddValue( 0.5 * drv1Val );
	//sbDif->AddValue( drv1Val );

	flt1->InputVal( drv1Val );

	if( flt1->HasOutput() )
	{
	flt1->CalcOutput();

	sbDif1_2->AddValue( 0.5 * flt1->GetLastOutput() );
	//sbDif1_2->AddValue( flt1->GetLastOutput() );
	}

	}

	cf3->InputVal( pix22 );

	if( cf3->HasOutput() )
	{
	cf3->CalcOutput();
	F32ColorVal pix23 = cf3->GetLastOutput();

	const float drv2Val = pix23.CalcMag();

	sbDif2->AddValue( 0.5 * drv2Val );
	//sbDif2->AddValue( drv2Val );
	}

	}
	}


	//}while(lp->MoveNext());
	}while(iter1->MoveNext());

	Signal1DViewerRef sv1 = new Signal1DViewer();

	sv1->AddSignal( sigBuilder0->GetResult(), u8ColorVal(200, 0, 0) );
	sv1->AddSignal( sigBuilder1->GetResult(), u8ColorVal(0, 180, 0) );
	sv1->AddSignal( sigBuilder2->GetResult(), u8ColorVal(0, 0, 255) );

	//sv1->AddSignal( sigBuilder0->GetResult(), u8ColorVal(255, 255, 255) );
	//sv1->AddSignal( sigBuilder1->GetResult(), u8ColorVal(255, 255, 255) );
	//sv1->AddSignal( sigBuilder2->GetResult(), u8ColorVal(255, 255, 255) );

	sv1->AddSignal( sbDif->GetResult(), u8ColorVal(255, 255, 255) );
	sv1->AddSignal( sbDif2->GetResult(), u8ColorVal(160, 0, 160) );

	sv1->AddSignal( sbDif1_2->GetResult(), u8ColorVal(0, 128, 255) );


	ShowImage( sv1->GenDisplayImage(), "Signals" );


	}
	*/

	ShowImage(ilv1->GetSignalDspImg(), "Signals");





	//ShowImage(img1Dsp, "LinePathImg");

	ShowImage(ilv1->GetResultImg(), "LinePathImg");
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


void ImageProcessor::AvgColorsOfLinePathImg()
{
	F32Point p1, p2;

	p1.x = IOMgr::ReadInt("x1");
	p1.y = IOMgr::ReadInt("y1");
	p2.x = IOMgr::ReadInt("x2");
	p2.y = IOMgr::ReadInt("y2");

	F32ImageRef avgColorImg = GenAvgColorsImg(
		GlobalStuff::GetLinePathImg(), p1, p2);

	//GlobalStuff::SetLinePathImg(  );


	ShowImage(avgColorImg, "avgColorImg");
}



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



void ImageProcessor::TryRS20()
{
	//F32ImageRef src = GenF32FromS16Image(
	//	GenS16FromU8Image(img));
	//F32ImageRef res = src;

	F32ImageRef res = GlobalStuff::GetLinePathImg();

	//GlobalStuff::OrgImg = res;

	//SaveImage(res, "OrgImg.jpg");

	const int nPyrIterCnt = 0;



	//res = GenPyrDownImg(res, nPyrIterCnt);
	//res = GenDownSampledImage( res , 1 );


	U8ImageRef dsp;

	//res = GenTriChGrayImg( res );


	//SaveImage(avg_Img, "avg_Img.jpg");

	//int nAprSiz = 81;
	//int nAprSiz = 41;
	//int nAprSiz = 5;
	//int nAprSiz = 3;

	F32ImageRef avg_Img = GenCvSmoothedImg(res,
		//F32ImageRef avg_Img = GenFastAvgImg( res, 
		//(nAprSiz - 1) * 2 + 1  );
		//nAprSiz);
		//		5);
		7);
	//9);
	//25);
	//45);
	//GlobalStuff::AprSize1D );

	avg_Img = res;

	{
		GlobalStuff::SetLinePathImg(avg_Img);

		ShowImage(GlobalStuff::GetLinePathImg(), "LinePathImg");
	}


	//F32ImageRef avg_Img = res;

	GlobalStuff::SetLinePathImg(avg_Img);

	//ShowImage(avg_Img, "avg_Img");

	{
		F32ColorVal colorFact;

		/*		colorFact.val0 = 0.51 * 0.5;
				colorFact.val1 = 1.44 * 0.5;
				colorFact.val2 = 1.048 * 0.5;*/

		colorFact.val0 = 0.51;
		colorFact.val1 = 1.44;
		colorFact.val2 = 1.048;

		//avg_Img = GenMultByColorImg( avg_Img, colorFact);

		//BalanceImageWithIntensityFactors(avg_Img);
	}


	res = avg_Img;

	//ShowImage(avg_Img, "avg_Img");





	S16ImageRef res2_1 = GenS16FromF32Image(avg_Img);

	//res2_1 = GenUpSampledImage( res2_1, 8 );

	//SaveImage(res2_1, "avg_Img.jpg");







	//SaveImage(avg_Img, "avg_Img.jpg");

	//int nAprSizG1 = nAprSiz;
	int nAprSizG1 = 1;
	//F32ImageRef gradImg = GenMorphGradImg( res, nAprSizG1 );
	F32ImageRef gradImg = res;

	//GlobalStuff::SetLinePathImg( gradImg );


	//ShowImage(gradImg, "gradImg");

	//F32ImageRef grad1Dil = GenCvDilateImg( gradImg, 3 );
	//ShowImage(grad1Dil, "grad1Dil");


	//S16ImageRef weightImgS16 = GenWeightImg5( gradImg, nAprSizG1 * 2 );
	//S16ImageRef weightImgS16 = gradImg;
	S16ImageRef weightImgS16 = NULL;




	//weightImgS16 = GenPyrUpImg( weightImgS16, nPyrIterCnt);
	//avg_Img = GenPyrUpImg( avg_Img, nPyrIterCnt);

	{
		//dsp = GenU8FromS16Image(
		//	GenBinImposedImg( 
		//	GenS16FromF32Image(avg_Img), 
		//	weightImgS16 ) );
		//	//weightImgS16 );

		//HCV_CALL( cvvSaveImage("WtBinImposedImg.jpg", 
		//dsp->GetIplImagePtr()) );

		//ShowImage(dsp->GetIplImagePtr(), "weightImgS16");
		//ShowImage(NULL, "weightImgS16");
	}

	F32ImageRef avgImg0 = avg_Img;
	F32ImageRef avgImg2 = avgImg0;
	//S16ImageRef avgImg2 = GenCvMedGausImg( avg_Img, 51);

	//dsp = GenU8FromS16Image(avgImg2);
	//ShowImage(dsp->GetIplImagePtr(), "avgImg2");

	//return;

	{
		//int nThrVal = 7;
		//int nThrVal = 15;
		//int nThrVal = 20; 
		int nThrVal = 25;
		//int nThrVal = 30;
		//int nThrVal = 35;
		//int nThrVal = 45;
		//int nThrVal = 10;


		GlobalStuff::SetRegionSegmentor(NULL);

		//Hcpl::FixedVectorDebug::CycleNum++;
		Hcpl::FixedVectorDebug::IncCycleNum();


		//IRegionSegmentor20Ref rs2 = new RegionSegmentor20(avgImg2, weightImgS16, nThrVal, avgImg0);	
		//IRegionSegmentor20Ref rs2 = new RegionSegmentor21(avgImg2, weightImgS16, nThrVal, avgImg0);	
		//IRegionSegmentor20Ref rs2 = new RegionSegmentor22(avgImg2, weightImgS16, nThrVal, avgImg0);	
		//IRegionSegmentor20Ref rs2 = new RegionSegmentor23(avgImg2, weightImgS16, nThrVal, avgImg0);	
		//IRegionSegmentor20Ref rs2 = new RegionSegmentor24(avgImg2, weightImgS16, nThrVal, avgImg0);	
		//IRegionSegmentor20Ref rs2 = new RegionSegmentor25(avgImg2, weightImgS16, nThrVal, avgImg0);	
		//IRegionSegmentor20Ref rs2 = new RegionSegmentor26(avgImg2, weightImgS16, nThrVal, avgImg0);	
		//IRegionSegmentor20Ref rs2 = new RegionSegmentor27(avgImg2, weightImgS16, nThrVal, avgImg0);	
		//IRegionSegmentor20Ref rs2 = new RegionSegmentor28(avgImg2, weightImgS16, nThrVal, avgImg0);	
		//IRegionSegmentor20Ref rs2 = new RegionSegmentor29(avgImg2, weightImgS16, nThrVal, avgImg0);	
		//IRegionSegmentor20Ref rs2 = new RegionSegmentor30(avgImg2, weightImgS16, nThrVal, avgImg0);	
		//IRegionSegmentor20Ref rs2 = new RegionSegmentor31(avgImg2, weightImgS16, nThrVal, avgImg0);	
		//IRegionSegmentor20Ref rs2 = new RegionSegmentor32(avgImg2, weightImgS16, nThrVal, avgImg0);	
		//IRegionSegmentor20Ref rs2 = new RegionSegmentor33(avgImg2, weightImgS16, nThrVal, avgImg0);	
		//IRegionSegmentor20Ref rs2 = new RegionSegmentor34(avgImg2, weightImgS16, nThrVal, avgImg0);	
		//IRegionSegmentor20Ref rs2 = new RegionSegmentor35(avgImg2, weightImgS16, nThrVal, avgImg0);	
		//IRegionSegmentor20Ref rs2 = new RegionSegmentor36(avgImg2, weightImgS16, nThrVal, avgImg0);	
		//IRegionSegmentor20Ref rs2 = new RegionSegmentor37(avgImg2, weightImgS16, nThrVal, avgImg0);	
		//IRegionSegmentor20Ref rs2 = new RegionSegmentor38(avgImg2, weightImgS16, nThrVal, avgImg0);	
		//IRegionSegmentor20Ref rs2 = new RegionSegmentor39(avgImg2, weightImgS16, nThrVal, avgImg0);	
		//IRegionSegmentor20Ref rs2 = new RegionSegmentor40(avgImg2, weightImgS16, nThrVal, avgImg0);	
		//IRegionSegmentor20Ref rs2 = new RegionSegmentor41(avgImg2, weightImgS16, nThrVal, avgImg0);	
		//IRegionSegmentor20Ref rs2 = new RegionSegmentor42(avgImg2, weightImgS16, nThrVal, avgImg0);	
		//IRegionSegmentor20Ref rs2 = new RegionSegmentor43(avgImg2, weightImgS16, nThrVal, avgImg0);	
		//IRegionSegmentor20Ref rs2 = new RegionSegmentor44(avgImg2, weightImgS16, nThrVal, avgImg0);	
		//IRegionSegmentor20Ref rs2 = new RegionSegmentor45(avgImg2, weightImgS16, nThrVal, avgImg0);	
		//IRegionSegmentor20Ref rs2 = new RegionSegmentor46(avgImg2, weightImgS16, nThrVal, avgImg0);	
		//IRegionSegmentor20Ref rs2 = new RegionSegmentor47(avgImg2, weightImgS16, nThrVal, avgImg0);	
		//IRegionSegmentor20Ref rs2 = new RegionSegmentor48(avgImg2, weightImgS16, nThrVal, avgImg0);	
		//IRegionSegmentor20Ref rs2 = new RegionSegmentor49(avgImg2, weightImgS16, nThrVal, avgImg0);	
		//IRegionSegmentor20Ref rs2 = new RegionSegmentor50(avgImg2, weightImgS16, nThrVal, avgImg0);
		IRegionSegmentor20Ref rs2 = new RegionSegmentor51(avgImg2, weightImgS16, nThrVal, avgImg0);
		//RegionSegmentor20Ref rs2 = new RegionSegmentor20(avgImg2, weightImgS16, nThrVal, src);	
		//	From 15, F32 Work.

		//IRegionSegmentor20Ref rs2 = NULL;	
		//rs2 = new RegionSegmentor21(avgImg2, weightImgS16, nThrVal, avgImg0);	

		GlobalStuff::SetRegionSegmentor(rs2);

		rs2->Segment();
		//S16ImageRef res2 = rs2->GenSegmentedImage(false);
		S16ImageRef res2 = rs2->GenSegmentedImage(true);
		//S16ImageRef res2 = rs2->GenSegmentedImage();

		//GlobalStuff::SetLinePathImg(
		//GenF32FromS16Image( res2 ) );

		//ShowImage(GlobalStuff::GetLinePathImg(), "LinePathImg");



		//ShowImage(res2, "RegionSegmentor");
		ShowImage(res2, "RgnSgmImg");

		SaveImage(res2, "RgnSgmImg.jpg");

		/*
				res2 = GenUpSampledImage( res2, 8 );



				SaveImage(res2, "RegionSegmentor.jpg");
				*/
	}

}


void ImageProcessor::Try26_0()
{
	const int nRadius = GlobalStuff::AprSize1D;
	//const int nRadius = 3;


	F32ImageRef src = GlobalStuff::GetLinePathImg();

	CircDiff2Ref cd1 = new CircDiff2(src, nRadius);


	ShowImage(cd1->GetDifAngleImg(), "Diff Angle");

	ShowImage(cd1->GenColorShowImg(), "Color Show Img");

	F32ImageRef difMagImg = cd1->GetDifMagImg();
	ShowImage(difMagImg, "Diff Mag");

	GlobalStuff::SetLinePathImg(difMagImg);
	GlobalStuff::ShowLinePathImg();
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
			//Hcpl_ASSERT(src_Standev_Ptr[i] > 0.0 && src_Standev_Ptr[i] < 3000.0f);
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
	return;

	const int nRadius = GlobalStuff::AprSize1D;
	//const int nRadius = 3;

	F32ImageRef src = GlobalStuff::GetLinePathImg();


	//ImgRotationMgrRef rotMgr88_0_0 = new ImgRotationMgr(src, 0);
	//ImgRotationMgrRef rotMgr88_0_1 = new ImgRotationMgr(src, 22.5);
	//ImgRotationMgrRef rotMgr88_0_2 = new ImgRotationMgr(src, 45);
	//ImgRotationMgrRef rotMgr88_0_3 = new ImgRotationMgr(src, 67.5);

	////GlobalStuff::SetLinePathImg(rotMgr88_0_1->GetResImg());
	//GlobalStuff::SetLinePathImg(rotMgr88_0_2->GetResImg());
	//GlobalStuff::ShowLinePathImg();

	//return;

	//ImgRotationMgrRef rotMgr88 = new ImgRotationMgr(src, 45);
	//ImgRotationMgrRef rotMgr88 = new ImgRotationMgr(src, 55);
	ImgRotationMgrRef rotMgr88 = new ImgRotationMgr(src, 0);
	//ImgRotationMgrRef rotMgr88 = new ImgRotationMgr(src, 70);
	//ImgRotationMgrRef rotMgr88 = new ImgRotationMgr(src, 89);
	//ImgRotationMgrRef rotMgr88 = new ImgRotationMgr(src, 20);
	//F32ImageRef res1 = rotMgr1->GetResImg();

	src = rotMgr88->GetResImg();

	//GlobalStuff::SetLinePathImg(rotMgr88->GetResImg());
	//GlobalStuff::ShowLinePathImg();


	//src = GlobalStuff::GetLinePathImg();


	F32ImageAccessor3C_Ref org_Img = new F32ImageAccessor3C(src);
	org_Img->SwitchXY();

	ShowImage(org_Img->GetSrcImg(), "org_Img->GetSrcImg()");

	//MemAccessor_2D_REF(F32ColorVal) acc1 = org_Img->GetMemAccessor()->Clone();
	////acc1->SetRange_Relative_Y(100, 200);
	////acc1->SwitchXY();
	//acc1->SetRange_Relative_X(50, 150);
	////acc1->SetRange_Relative_X(50, 53);

	//F32ColorVal color1;
	//color1.AssignVal(50, 50, 200);

	//F32ColorVal color2;
	//color2.AssignVal(250, 50, 50);

	////F32ImageAccessor3C_Ref imgAcc0 = new F32ImageAccessor3C(src->CloneNew());
	//F32ImageAccessor3C_Ref imgAcc0 = org_Img->CloneAccAndImage();
	//CopyImage(imgAcc0->GetMemAccessor(), org_Img->GetMemAccessor());

	////F32ImageAccessor3C_Ref imgAcc2 = GenFillImage_Stripes_H(org_Img, color1, color2, 25);
	////ShowImage(imgAcc2->GetSrcImg(), "imgAcc2->GetSrcImg()");

	////F32ImageAccessor3C_Ref imgAcc3 = org_Img->CloneAccAndImage();

	////F32ImageAccessor3C_Ref imgAcc3 = org_Img->CloneAccessorOnly();
	////DivideImageByNum(imgAcc3->GetMemAccessor(), 2);

	////F32ImageAccessor1C_Ref imgMag = new F32ImageAccessor1C(org_Img->GetOffsetCalc());
	////CalcMagImage(imgAcc3->GetMemAccessor(), imgMag->GetMemAccessor());
	////ShowImage(imgMag->GetSrcImg(), "imgMag->GetSrcImg()");

	/////-----------------------------------------------------------------------------------


	F32ImageAccessor1C_Ref magSqr_Img = new F32ImageAccessor1C(org_Img->GetOffsetCalc());
	CalcMagSqrImage(org_Img->GetMemAccessor(), magSqr_Img->GetMemAccessor());

	F32ImageAccessor1C_Ref avgStandev_H_Img = new F32ImageAccessor1C(org_Img->GetOffsetCalc());
	Cala_AvgStandevImage_H(org_Img->GetMemAccessor(), magSqr_Img->GetMemAccessor(),
		avgStandev_H_Img->GetMemAccessor(), Range<int>::New(-2, 2), Range<int>::New(-2, 2));
	//avgStandev_H_Img->GetMemAccessor(), Range<int>::New(-2, 2), Range<int>::New(-1, 1));

	//ShowImage(avgStandev_H_Img->GetSrcImg(), "avgStandev_H_Img->GetSrcImg()");
	//return;



	//Window<int> avgWin = Window<int>::New(-3, 3, -7, 7);
	Window<int> avgWin = Window<int>::New(-1, 1, -5, 5);
	//Window<int> avgWin = Window<int>::New(-1, 1, -3, 3);
	//Window<int> avgWin = Window<int>::New(0, 0, -2, 2);
	//Window<int> avgWin = Window<int>::New(0, 0, -1, 1);
	//Window<int> avgWin = Window<int>::New(-1, 1, -2, 2);
	//Window<int> avgWin = Window<int>::New(-1, 0, -1, 0);

	//----

	F32ImageAccessor3C_Ref avg_Img = org_Img->CloneAccAndImage();
	AvgImage(org_Img->GetMemAccessor(), avg_Img->GetMemAccessor(), avgWin);
	//ShowImage(avg_Img->GetSrcImg(), "avg_Img->GetSrcImg()");

	//F32ImageAccessor1C_Ref magSqr_Avg_Img = new F32ImageAccessor1C(org_Img->GetOffsetCalc());
	//CalcMagSqrImage(avg_Img->GetMemAccessor(), magSqr_Avg_Img->GetMemAccessor());

	//----

	F32ImageAccessor1C_Ref avg_MagSqr_Img = new F32ImageAccessor1C(org_Img->GetOffsetCalc());
	AvgImage(magSqr_Img->GetMemAccessor(), avg_MagSqr_Img->GetMemAccessor(), avgWin);



	//ShowImage(avg_MagSqr_Img->GetSrcImg(), "avg_MagSqr_Img->GetSrcImg()");

	//return;
	//----

	F32ImageAccessor1C_Ref standev_Img = new F32ImageAccessor1C(org_Img->GetOffsetCalc());
	CalcStandevImage(avg_Img->GetMemAccessor(), avg_MagSqr_Img->GetMemAccessor(),
		standev_Img->GetMemAccessor());

	//ShowImage(standev_Img->GetSrcImg(), "standev_Img->GetSrcImg()");
	//return;

	//Range<int> confRange = Range<int>::New(-2, 2);
	Range<int> confRange = Range<int>::New(
		-1 - avgWin.Get_X2(), 1 - avgWin.Get_X1());

	TempImageAccessor_REF(ConflictInfo) conflict_Img = new TempImageAccessor<ConflictInfo>(
		org_Img->GetMemAccessor()->GetOffsetCalc());

	CalcConflictImage_H(avg_Img->GetMemAccessor(), avg_MagSqr_Img->GetMemAccessor(),
		conflict_Img->GetMemAccessor(), confRange);

	//SaveImage(conflict_Img->GetSrcImg(), "E:\\result_V.jpg");
	//SaveImage(conflict_Img->GetSrcImg(), "result_V.jpg");
	//SaveImage(conflict_Img->GetSrcImg(), "result_H.jpg");

	{
		MemAccessor_2D_REF(ConflictInfo) confAcc = conflict_Img->GetMemAccessor();
		F32ImageRef confDsp_Img = F32Image::Create(cvSize(confAcc->GetIndexSize_X_Org(), confAcc->GetIndexSize_Y_Org()), 3);

		confDsp_Img->SetAll(0);

		const int nSize_1D = confAcc->GetIndexSize_X() * confAcc->GetIndexSize_Y();

		F32ColorVal * destPtr = (F32ColorVal *)confDsp_Img->GetDataPtr();
		ConflictInfo * srcPtr = confAcc->GetDataPtr();

		float angle_Old = -1;
		for (int i = 0; i < nSize_1D; i++)
		{
			ConflictInfo & rSrc = srcPtr[i];
			F32ColorVal & rDest = destPtr[i];

			//Hcpl_ASSERT(-1 != rSrc.Dir);

			if (rSrc.Exists)
			{
				F32ColorVal & rDest_Side_1 = destPtr[rSrc.Offset_Side_1];
				F32ColorVal & rDest_Side_2 = destPtr[rSrc.Offset_Side_2];

				rDest.val0 = 0;
				rDest.val1 = 0;
				rDest.val2 = 255;

				rDest_Side_1.val0 = 0;
				rDest_Side_1.val1 = 255;
				rDest_Side_1.val2 = 0;

				rDest_Side_2.val0 = 0;
				rDest_Side_2.val1 = 255;
				rDest_Side_2.val2 = 0;
			}
			//else
			//{
			//	rDest.val0 = 0;
			//	rDest.val1 = 0;
			//	rDest.val2 = 0;
			//}
		}

		ShowImage(confDsp_Img, "confDsp_Img->GetSrcImg()");
	}

	return;

	/////-----------------------------------------------------------------------------------

	////ShowImage(imgAcc3->GetSrcImg(), "imgAcc3->GetSrcImg()");

	////GlobalStuff::ShowLinePathImg();


	////	new F32ImageAccessor3C(src->CloneNew());
	////CopyImage(imgAcc0->GetMemAccessor(), org_Img->GetMemAccessor());

	////FillImage<F32ColorVal>(acc1, color1);
	//FillImage_Stripes_H<F32ColorVal>(acc1, color1, color2, 25);
	////FillImage_Stripes_H<F32ColorVal>(org_Img->GetMemAccessor(), color1, color2, 25);

	//ShowImage(imgAcc0->GetSrcImg(), "imgAcc0->GetSrcImg()");
	ShowImage(org_Img->GetSrcImg(), "org_Img->GetSrcImg()");


	return;

}





void ImageProcessor::Try25()
{
	const int nAprSize = GlobalStuff::AprSize1D;

	F32ImageRef src = GlobalStuff::GetLinePathImg();
	F32ImageRef srcGrad = NULL;

	{
		srcGrad = src;
		srcGrad = GenCvSmoothedImg(srcGrad, nAprSize);
		srcGrad = CircDiff::GenResult(srcGrad, nAprSize);
		srcGrad = GenCvSmoothedImg(srcGrad, nAprSize);
	}
	CvSize srcSiz = src->GetSize();

	const int nSrcSiz1D = srcSiz.width * srcSiz.height;


	SlideMgrRef sm1 = new SlideMgr(srcGrad, nAprSize, NULL,
		NULL);

	FixedVector< bool > & isRootArr = sm1->GetIsRootArr();
	FixedVector< SlideMgr::SlideChainElm > & slideChainArr = sm1->GetSlideChainArr();
	FixedVector< SlideMgr::SlideChainElm * > & chainHeadPtrArr = sm1->GetChainHeadPtrArr();


	F32ImageRef res = F32Image::Create(srcSiz, 3);
	res->SetAll(0);

	F32ImageRef res2 = F32Image::Create(srcSiz, 3);
	res2->SetAll(0);

	for (int i = 0; i < chainHeadPtrArr.GetSize(); i++)
	{
		const int nDrawRad = 3;

		SlideMgr::SlideChainElm * pHeadCE = chainHeadPtrArr[i];

		//if( 0 != rand() % 100 )
		//	continue;


		{
			SlideMgr::SlideChainElm * pCE = pHeadCE;
			SlideMgr::SlideChainElm * pTailCE = pHeadCE->pTail;

			F32ColorVal color1;

			//U8ColorVal color1;

			//color1.val0 = rand() % 256;
			//color1.val1 = rand() % 256;
			//color1.val2 = rand() % 256;

			F32Point pntTail = sm1->GetPosOfElm(*pTailCE);
			F32ColorVal * pixTail = (F32ColorVal *)src->GetPixAt(pntTail.x, pntTail.y);

			do
			{
				//float val = fabs( pCE->val - pTailCE->val );

				F32Point pnt1 = sm1->GetPosOfElm(*pCE);
				F32ColorVal * pixCE = (F32ColorVal *)src->GetPixAt(pnt1.x, pnt1.y);
				//*resPix = color1;

				float val = F32ColorVal::Sub(*pixCE, *pixTail).CalcMag();

				F32ColorVal * resPix = (F32ColorVal *)res2->GetPixAt(pnt1.x, pnt1.y);
				resPix->AssignVal(val, val, val);

				//DrawCircle( res, pnt1, color1, nDrawRad );

				if (pCE->bHasNext)
					pCE = pCE->pNext;
				else
					break;
			}
			//while( pCE->bHasNext );
			while (true);
		}



		/*
				{
				SlideMgr::SlideChainElm * pCE = pHeadCE;

				//F32ColorVal color1;
				U8ColorVal color1;

				color1.val0 = rand() % 256;
				color1.val1 = rand() % 256;
				color1.val2 = rand() % 256;

				do
				{

				F32Point pnt1 = sm1->GetPosOfElm( *pCE );

				//F32ColorVal * resPix = (F32ColorVal *) res->GetPixAt( pnt1.x, pnt1.y );
				//*resPix = color1;

				DrawCircle( res, pnt1, color1, nDrawRad );

				if( pCE->bHasNext )
				pCE = pCE->pNext;
				else
				break;
				}
				//while( pCE->bHasNext );
				while( true );

				}
				*/


		{
			F32Point pntRt = sm1->GetPosOfElm(*pHeadCE);

			F32ColorVal * resPix = (F32ColorVal *)res->GetPixAt(pntRt.x, pntRt.y);

			F32ColorVal color1;
			color1.AssignVal(0, 0, 255);

			*resPix = color1;
		}



		{
			SlideMgr::SlideChainElm * pTailCE = pHeadCE->pTail;

			F32Point pntRt = sm1->GetPosOfElm(*pTailCE);

			F32ColorVal * resPix = (F32ColorVal *)res->GetPixAt(pntRt.x, pntRt.y);

			//F32ColorVal color1;
			//color1.AssignVal( 255, 70, 70 );

			//*resPix = color1;

			U8ColorVal dspColor = u8ColorVal(255, 70, 70);

			DrawCircle(res, pntRt, dspColor, nDrawRad);
		}


	}




	//float * srcPixPtr = src->GetPixAt( 0, 0 );


	Accessor2D< SlideMgr::SlideChainElm > acSlideCE(&slideChainArr[0], srcSiz.width, srcSiz.height);




	const F32Point testPnt(393, 97);



	ShowImage(res, "Result");

	GlobalStuff::SetLinePathImg(res2);
	GlobalStuff::ShowLinePathImg();
}








void ImageProcessor::Try24()
{

	F32ImageRef src = GlobalStuff::GetLinePathImg();

	CvSize srcSiz = src->GetSize();

	const int nSrcSiz1D = srcSiz.width * srcSiz.height;

	const int nAprSize = GlobalStuff::AprSize1D;

	SlideMgrRef sm1 = new SlideMgr(src, nAprSize, NULL,
		NULL);

	FixedVector< bool > & isRootArr = sm1->GetIsRootArr();
	FixedVector< SlideMgr::SlideChainElm > & slideChainArr = sm1->GetSlideChainArr();
	FixedVector< SlideMgr::SlideChainElm * > & chainHeadPtrArr = sm1->GetChainHeadPtrArr();


	F32ImageRef res = F32Image::Create(srcSiz, 3);
	res->SetAll(0);

	F32ImageRef res2 = F32Image::Create(srcSiz, 3);
	res2->SetAll(0);

	for (int i = 0; i < chainHeadPtrArr.GetSize(); i++)
	{
		const int nDrawRad = 3;

		SlideMgr::SlideChainElm * pHeadCE = chainHeadPtrArr[i];

		//if( 0 != rand() % 100 )
		//	continue;

		/*
				{
				SlideMgr::SlideChainElm * pCE = pHeadCE;
				SlideMgr::SlideChainElm * pTailCE = pHeadCE->pTail;

				F32ColorVal color1;

				//U8ColorVal color1;

				//color1.val0 = rand() % 256;
				//color1.val1 = rand() % 256;
				//color1.val2 = rand() % 256;

				do
				{
				float val = fabs( pCE->val - pTailCE->val );

				F32Point pnt1 = sm1->GetPosOfElm( *pCE );

				F32ColorVal * resPix = (F32ColorVal *) res2->GetPixAt( pnt1.x, pnt1.y );
				//*resPix = color1;

				resPix->AssignVal( val, val, val );


				//DrawCircle( res, pnt1, color1, nDrawRad );

				if( pCE->bHasNext )
				pCE = pCE->pNext;
				else
				break;
				}
				//while( pCE->bHasNext );
				while( true );
				}
				*/


		/*
				{
				SlideMgr::SlideChainElm * pCE = pHeadCE;

				//F32ColorVal color1;
				U8ColorVal color1;

				color1.val0 = rand() % 256;
				color1.val1 = rand() % 256;
				color1.val2 = rand() % 256;

				do
				{

				F32Point pnt1 = sm1->GetPosOfElm( *pCE );

				//F32ColorVal * resPix = (F32ColorVal *) res->GetPixAt( pnt1.x, pnt1.y );
				//*resPix = color1;

				DrawCircle( res, pnt1, color1, nDrawRad );

				if( pCE->bHasNext )
				pCE = pCE->pNext;
				else
				break;
				}
				//while( pCE->bHasNext );
				while( true );

				}
				*/


		{
			F32Point pntRt = sm1->GetPosOfElm(*pHeadCE);

			F32ColorVal * resPix = (F32ColorVal *)res->GetPixAt(pntRt.x, pntRt.y);

			F32ColorVal color1;
			color1.AssignVal(0, 0, 255);

			*resPix = color1;
		}



		{
			SlideMgr::SlideChainElm * pTailCE = pHeadCE->pTail;

			F32Point pntRt = sm1->GetPosOfElm(*pTailCE);

			F32ColorVal * resPix = (F32ColorVal *)res->GetPixAt(pntRt.x, pntRt.y);

			//F32ColorVal color1;
			//color1.AssignVal( 255, 70, 70 );

			//*resPix = color1;

			U8ColorVal dspColor = u8ColorVal(255, 70, 70);

			DrawCircle(res, pntRt, dspColor, nDrawRad);
		}


	}




	//float * srcPixPtr = src->GetPixAt( 0, 0 );


	Accessor2D< SlideMgr::SlideChainElm > acSlideCE(&slideChainArr[0], srcSiz.width, srcSiz.height);




	const F32Point testPnt(393, 97);



	ShowImage(res, "Result");

	//GlobalStuff::SetLinePathImg( res2 );
	//GlobalStuff::ShowLinePathImg();
}







void ImageProcessor::Try23()
{
	class IndexLQM : public MultiListQueMember< IndexLQM >
	{
	public:
		int Index;
	};

	class PixInfo
	{
	public:
		int index;
		F32Point pos;
		float val;
		float avgVal;

		PixInfo * pSlidePix;
		PixInfo * pAbovePix;

		PixInfo * pSlideSrc;

		bool bIsEdge;
		bool bIsValley;
	};




	//a_x = 187;
	//a_y = 189;

	//F32ImageRef src = GenImageFromChannel(			
	//	GlobalStuff::GetLinePathImg(), 0 );

	F32ImageRef src = GlobalStuff::GetLinePathImg();

	CvSize srcSiz = src->GetSize();

	const int nSrcSiz1D = srcSiz.width * srcSiz.height;


	FixedVector< bool > isRootArr;
	isRootArr.SetSize(nSrcSiz1D);

	FillIsEdgeRootArr(src, &isRootArr);
	//FillIsEdgePeakArr( src, &isRootArr );




	FixedVector< PixInfo > pixInfoArr;
	pixInfoArr.SetSize(nSrcSiz1D);


	FixedVector< IndexLQM > indexLQMArr;

	indexLQMArr.SetSize(nSrcSiz1D);

	float * srcPixPtr = src->GetPixAt(0, 0);

	const int nValScale = 10;


	MultiListQueMgr< IndexLQM > mlqMgr;
	mlqMgr.InitSize(500 * nValScale);

	for (int i = 0; i < nSrcSiz1D; i++)
	{
		IndexLQM & indexLQM = indexLQMArr[i];

		indexLQM.Index = i;

		float val = srcPixPtr[i];

		mlqMgr.PushPtr(val * nValScale, &indexLQM);
	}








	FixedVector< F32Point > pntArr;
	pntArr.SetSize(nSrcSiz1D);

	//FillCenterOfMassArr( src, GlobalStuff::AprSize1D, &pntArr );
	FillSlidePointArr(src, GlobalStuff::AprSize1D, &pntArr);
	//FillClimbPointArr( src, GlobalStuff::AprSize1D, &pntArr );


	Accessor2D< F32Point > acSlide(&pntArr[0], srcSiz.width, srcSiz.height);
	Accessor2D< PixInfo > acPixInfo(&pixInfoArr[0], srcSiz.width, srcSiz.height);

	F32ImageRef avg_Img = GenFastAvgImg(src, GlobalStuff::AprSize1D);


	for (int y = 0; y < srcSiz.height; y++)
	{
		for (int x = 0; x < srcSiz.width; x++)
		{
			int i = acPixInfo.GetIndex1D(x, y);

			PixInfo & rPixInfo = pixInfoArr[i];

			rPixInfo.index = i;
			rPixInfo.pos = F32Point(x, y);

			F32Point & rPnt = acSlide.GetAt(x, y);
			F32Point pnt1 = rPnt.Round();

			//rPixInfo.pSlidePix = &pixInfoArr[ acSlide.GetIndex1D( pnt1.x, pnt1.y ) ];
			rPixInfo.pSlidePix = acPixInfo.GetPtrAt(pnt1.x, pnt1.y);

			{
				//int nAbvX = x - ( pnt1.x - x );

				int nAbvX = 2 * x - pnt1.x;
				int nAbvY = 2 * y - pnt1.y;

				rPixInfo.pAbovePix = acPixInfo.GetPtrAt(nAbvX, nAbvY);
			}

			rPixInfo.pSlideSrc = NULL;

			rPixInfo.bIsEdge = false;
			rPixInfo.bIsValley = false;

			rPixInfo.val = *src->GetPixAt(x, y);
			rPixInfo.avgVal = *avg_Img->GetPixAt(x, y);
		}
	}





	while (true)
	{
		IndexLQM * pIlqm = mlqMgr.PopPtrMax();

		if (NULL == pIlqm)
			break;

		PixInfo * pPI = &pixInfoArr[pIlqm->Index];
		PixInfo * pDstPI = pPI->pSlidePix;


	}



	//F32ImageRef dsp = GenTriChGrayImg( GlobalStuff::GetLinePathImg() );
	F32ImageRef res = F32Image::Create(srcSiz, 3);

	const F32Point testPnt(393, 97);


	for (int y = 0; y < srcSiz.height; y++)
	{
		for (int x = 0; x < srcSiz.width; x++)
		{
			if (testPnt.x == x && testPnt.y == y)
				x = x;

			PixInfo * pSrcPI = acPixInfo.GetPtrAt(x, y);
			PixInfo * pDstPI = pSrcPI->pSlidePix;

			//const float srcVal = *src->GetPixAt( x, y );
			const float srcVal = pSrcPI->val;

			const float avgSrcVal = *avg_Img->GetPixAt(x, y);
			//F32Point & rPnt = acSlide.GetAt( x, y );
			//F32Point pnt1 = rPnt.Round();


			//const float dstVal = *src->GetPixAt( pnt1.x, pnt1.y );
			const float dstVal = pDstPI->val;

			//const float avgDstVal = *avg_Img->GetPixAt( pnt1.x, pnt1.y );
			//const float avgDstVal = *avg_Img->GetPixAt( pDstPI->pos.x, pDstPI->pos.y );
			const float avgDstVal = pDstPI->avgVal;

			const float abvVal = pSrcPI->pAbovePix->val;



			//F32ColorVal * resPix = (F32ColorVal *) res->GetPixAt( pnt1.x, pnt1.y );
			//F32ColorVal * resPix = (F32ColorVal *) res->GetPixAt( pDstPI->pos.x, pDstPI->pos.y );
			F32ColorVal * resPix = (F32ColorVal *)res->GetPixAt(pSrcPI->pos.x, pSrcPI->pos.y);


			//U8ColorVal color1;
			F32ColorVal color1;

			/*
						//if( dstVal < avgDstVal * 0.8 )
						if( dstVal <= abvVal
						)
						{
						if( dstVal < abvVal )
						color1.AssignVal( 255, 70, 70 );
						else if( dstVal == abvVal )
						color1.AssignVal( 0, 0, 255 );
						else
						color1.AssignVal( 0, 0, 0 );
						}
						else
						//color1 = u8ColorVal( 0, 0, 0 );
						color1.AssignVal( 0, 0, 0 );
						*/


			/*
						//if( dstVal < avgDstVal * 0.8 )
						if( dstVal < avgDstVal * 0.8 &&
						dstVal < avgSrcVal
						)
						{
						if( dstVal < srcVal )
						color1.AssignVal( 255, 70, 70 );
						else if( dstVal == srcVal )
						color1.AssignVal( 0, 0, 255 );
						else
						color1.AssignVal( 0, 0, 0 );
						}
						else
						//color1 = u8ColorVal( 0, 0, 0 );
						color1.AssignVal( 0, 0, 0 );
						*/

			//if( isRootArr[ pDstPI->index ] )
			if (isRootArr[pSrcPI->index])
				color1.AssignVal(255, 70, 70);
			else
				color1.AssignVal(0, 0, 0);


			*resPix = color1;

			/*
						U8ColorVal color1;
						{

						if( F32Point::Compare( pnt1, srcPnt ) )
						color1 = u8ColorVal( 0, 0, 255 );
						//else if( dstVal >= avgVal || dstVal >= srcVal )
						else if( dstVal > srcVal )
						color1 = u8ColorVal( 0, 180, 180 );
						else if( dstVal > avgVal )
						color1 = u8ColorVal( 0, 150, 255 );
						//else if( dstVal < avgVal )
						else if( dstVal <= avgVal )
						color1 = u8ColorVal( 0, 180, 0 );

						DrawCircle( dsp, pnt1, color1, nRadius );
						}

						U8ColorVal color0;
						{

						if( F32Point::Compare( pnt1, srcPnt ) )
						{
						if( srcVal > avgVal )
						color0 = u8ColorVal( 0, 0, 100 );
						else
						color0 = u8ColorVal( 0, 0, 255 );
						}
						//else if( srcVal < avgVal * 0.6666 )
						else if( srcVal < avgVal * 0.8 )
						color0 = u8ColorVal( 255, 0, 0 );
						else
						color0 = u8ColorVal( 255, 0, 150 );

						DrawCircle( dsp, srcPnt, color0, nRadius );
						}
						*/




		}
	}


	ShowImage(res, "Result");
}








void ImageProcessor::Try22()
{
	//a_x = 187;
	//a_y = 189;

	//F32ImageRef src = GenImageFromChannel(			
	//	GlobalStuff::GetLinePathImg(), 0 );

	F32ImageRef src = GlobalStuff::GetLinePathImg();

	CvSize srcSiz = src->GetSize();

	FixedVector< F32Point > pntArr;
	pntArr.SetSize(srcSiz.width * srcSiz.height);

	//FillCenterOfMassArr( src, GlobalStuff::AprSize1D, &pntArr );
	FillSlidePointArr(src, GlobalStuff::AprSize1D, &pntArr);

	Accessor2D< F32Point > acSlide(&pntArr[0], srcSiz.width, srcSiz.height);

	F32ImageRef avg_Img = GenFastAvgImg(src, GlobalStuff::AprSize1D);


	//F32ImageRef dsp = GenTriChGrayImg( GlobalStuff::GetLinePathImg() );
	F32ImageRef res = F32Image::Create(srcSiz, 3);

	const F32Point testPnt(393, 97);


	for (int y = 0; y < srcSiz.height; y++)
	{
		for (int x = 0; x < srcSiz.width; x++)
		{
			if (testPnt.x == x && testPnt.y == y)
				x = x;

			const float srcVal = *src->GetPixAt(x, y);

			const float avgSrcVal = *avg_Img->GetPixAt(x, y);
			F32Point & rPnt = acSlide.GetAt(x, y);
			F32Point pnt1 = rPnt.Round();


			const float dstVal = *src->GetPixAt(pnt1.x, pnt1.y);

			const float avgDstVal = *avg_Img->GetPixAt(pnt1.x, pnt1.y);

			F32ColorVal * resPix = (F32ColorVal *)res->GetPixAt(pnt1.x, pnt1.y);

			//U8ColorVal color1;
			F32ColorVal color1;

			//if( dstVal < avgDstVal * 0.8 )
			if (dstVal < avgDstVal * 0.8 &&
				dstVal < avgSrcVal
				)
			{
				if (dstVal < srcVal)
					color1.AssignVal(255, 70, 70);
				else if (dstVal == srcVal)
					color1.AssignVal(0, 0, 255);
				else
					color1.AssignVal(0, 0, 0);
			}
			else
				//color1 = u8ColorVal( 0, 0, 0 );
				color1.AssignVal(0, 0, 0);


			*resPix = color1;

			/*
						U8ColorVal color1;
						{

						if( F32Point::Compare( pnt1, srcPnt ) )
						color1 = u8ColorVal( 0, 0, 255 );
						//else if( dstVal >= avgVal || dstVal >= srcVal )
						else if( dstVal > srcVal )
						color1 = u8ColorVal( 0, 180, 180 );
						else if( dstVal > avgVal )
						color1 = u8ColorVal( 0, 150, 255 );
						//else if( dstVal < avgVal )
						else if( dstVal <= avgVal )
						color1 = u8ColorVal( 0, 180, 0 );

						DrawCircle( dsp, pnt1, color1, nRadius );
						}

						U8ColorVal color0;
						{

						if( F32Point::Compare( pnt1, srcPnt ) )
						{
						if( srcVal > avgVal )
						color0 = u8ColorVal( 0, 0, 100 );
						else
						color0 = u8ColorVal( 0, 0, 255 );
						}
						//else if( srcVal < avgVal * 0.6666 )
						else if( srcVal < avgVal * 0.8 )
						color0 = u8ColorVal( 255, 0, 0 );
						else
						color0 = u8ColorVal( 255, 0, 150 );

						DrawCircle( dsp, srcPnt, color0, nRadius );
						}
						*/




		}
	}


	ShowImage(res, "Result");
}


void ImageProcessor::Try20()
{

	//if( false )
	{
		F32ImageRef img1 = GlobalStuff::GetLinePathImg();

		F32ImageRef img_2 = F32Image::Create(img1->GetSize(), 1);
		img_2->SetAll(0);

		float * img_2_Buf = img_2->GetPixAt(0, 0);

		IImgDataMgr_2_FactorySetRef imgFactoryMgr =
			new ImgDataMgr_2_FactorySet_Simple();

		//IImgCoreSrcRef ids1 = new ImgDataSrc_GridPal(img1);

		int nAprSiz_Far = 7;
		int nAprSiz_Loc = 7;

		FixedVector< float > angArr(10);

		angArr.PushBack(0);
		angArr.PushBack(22.5);
		angArr.PushBack(45);
		angArr.PushBack(67.5);

		for (int i = 0; i < angArr.GetSize(); i++)
		{
			ImageRotationMgr_ExParamsRef rotParams =
				new ImageRotationMgr_ExParams(
				//img1, ids1, 0, 23, 15, imgFactoryMgr );
				img1, NULL, 0, nAprSiz_Far, nAprSiz_Loc, imgFactoryMgr);

			//ImgRotationMgrRef rm1 = new ImgRotationMgr( img1, 0 );
			ImgRotationMgrRef rm1 = new ImgRotationMgr(img1, 45);

			IImgDataMgr_2Ref idm1 = imgFactoryMgr->GetDataMgr_Factory(
				)->CreateImgDataMgr(
				//img1, rotParams->nAprSiz_Far, ids1, rm1 );
				//img1, rotParams->nAprSiz_Far, NULL, rm1 );
				rm1->GetResImg(), rotParams->nAprSiz_Far, NULL, rm1);

			F32ImageRef resImg = rm1->GetResImg();

			CvSize resSiz = resImg->GetSize();

			IImgDataGradMgrRef igm1 =
				imgFactoryMgr->GetGradMgr_Factory()->CreateImgDataGradMgr(
				idm1,
				new ImageNbrMgr(rm1->GetImageItrMgr(), nAprSiz_Loc));

			Int32 * resToSrcMap = rm1->Get_ResToSrcMapImage()->GetPixAt(0, 0);

			FixedVector< F32ImageRef > confImgArr(10);
			confImgArr.PushBack(igm1->GetConflictImg_H());
			confImgArr.PushBack(igm1->GetConflictImg_V());

			for (int j = 0; j < confImgArr.GetSize(); j++)
			{
				F32ImageRef confImg = confImgArr[j];

				float * confImg_Buf = confImg->GetPixAt(0, 0);

				int nConfSiz1D = confImg->GetSize1D();

				int nImg_2_Siz1D = img_2->GetSize1D();

				for (int k = 0; k < nConfSiz1D; k++)
				{
					int nIdx_Dst = resToSrcMap[k];

					if (nIdx_Dst < 0)
						continue;

					float val = confImg_Buf[k];

					Hcpl_ASSERT(nIdx_Dst < nImg_2_Siz1D);

					float & rDst = img_2_Buf[nIdx_Dst];

					if (rDst < val)
						rDst = val;
				}

			}

			//ShowImage( igm1->GetGradImg_H(), "Grad_H" );
			//ShowImage( rm1->GetResImg(), "GetResImg" );
			//ShowImage( igm1->GetConflictImg_H(), "ConflictImg_H" );
			//ShowImage( igm1->GetConflictImg_V(), "ConflictImg_V" );

		}

		ShowImage(img_2, "img_2");


		//ImgScanMgrRef ism = new ImgScanMgr( rotParams, 4,
		//	cvPoint( 40, 40 ) );

		return;
	}


	if (false)
	{
		//GridColorPalette::Share share1;

		GridColorPalette::ColorRep rep1;

		F32ColorVal c1;
		//c1.AssignVal( 21, 50, 70 );
		c1.AssignVal(21, 55, 70);

		GridColorPalette::GetCore()->PrepareColorRep(c1, &rep1);

		int a;
		a = 0;

		return;
	}


	if (false)
	{
		F32ImageRef img1 = GlobalStuff::GetLinePathImg();

		IImgDataMgr_2_FactorySetRef imgFactoryMgr =
			new ImgDataMgr_2_FactorySet_GridPal();

		IImgCoreSrcRef ids1 = new ImgDataSrc_GridPal(img1);

		ImageRotationMgr_ExParamsRef rotParams =
			new ImageRotationMgr_ExParams(
			img1, ids1, 0, 23, 15, imgFactoryMgr);

		//ImgRotationMgrRef rm1 = new ImgRotationMgr( img1, 45 );

		//IImgDataMgr_2Ref idm1 = imgFactoryMgr->GetDataMgr_Factory(
		//	)->CreateImgDataMgr(
		//	img1, rotParams->nAprSiz_Far, ids1, rm1 );

		//imgFactoryMgr->GetGradMgr_Factory()->CreateImgDataGradMgr(
		//	idm1, 


		ImgScanMgrRef ism = new ImgScanMgr(rotParams, 4,
			cvPoint(40, 40));

		return;
	}

	if (false)
	{
		F32ImageRef img1 = GlobalStuff::GetLinePathImg();

		IImgDataMgr_2_FactorySetRef imgFactoryMgr =
			new ImgDataMgr_2_FactorySet_LocHist();

		IImgCoreSrcRef ids1 = new ImgDataSrc_LocHist(img1);

		ImageRotationMgr_ExParamsRef rotParams =
			new ImageRotationMgr_ExParams(
			img1, ids1, 0, 23, 15, imgFactoryMgr);

		//ImgRotationMgrRef rm1 = new ImgRotationMgr( img1, 45 );

		//IImgDataMgr_2Ref idm1 = imgFactoryMgr->GetDataMgr_Factory(
		//	)->CreateImgDataMgr(
		//	img1, rotParams->nAprSiz_Far, ids1, rm1 );

		//imgFactoryMgr->GetGradMgr_Factory()->CreateImgDataGradMgr(
		//	idm1, 


		ImgScanMgrRef ism = new ImgScanMgr(rotParams, 4,
			cvPoint(40, 40));

		return;
	}

	{
		F32ImageRef img1 = GlobalStuff::GetLinePathImg();

		IImgDataMgr_2_FactorySetRef imgFactoryMgr =
			new ImgDataMgr_2_FactorySet_LocHist();

		IImgCoreSrcRef ids1 = new ImgDataSrc_LocHist(img1);

		ImageRotationMgr_ExParamsRef rotParams =
			new ImageRotationMgr_ExParams(
			img1, ids1, 0, 23, 15, imgFactoryMgr);

		ImgScanMgrRef ism = new ImgScanMgr(rotParams, 4,
			cvPoint(40, 40));

		//ImgRotationMgrRef idrm1 = new ImgRotationMgr(
		//ImageRotationMgr_ExRef idrm1 = new ImageRotationMgr_Ex(
		//img1, GlobalStuff::AprSize1D, 23, 15, imgFactoryMgr );
		//rotParams );

		return;
	}

	{
		F32ImageRef img1 = GlobalStuff::GetLinePathImg();

		ImgDataSrc_LocHist ids1(img1);

		//ImgClusteringTryRef ict = new ImgClusteringTry(img1);


		return;
	}

	{
		F32ImageRef img1 = GlobalStuff::GetLinePathImg();

		ImgClusteringTryRef ict = new ImgClusteringTry(img1);


		return;
	}

	{
		F32ImageRef img1 = GlobalStuff::GetLinePathImg();

		IImgDataMgr_2_FactorySetRef imgFactoryMgr =
			new ImgDataMgr_2_FactorySet_CovMat();

		ImageRotationMgr_ExParamsRef rotParams =
			new ImageRotationMgr_ExParams(
			img1, NULL, 0, 23, 15, imgFactoryMgr);

		ImgScanMgrRef ism = new ImgScanMgr(rotParams, 4,
			cvPoint(40, 40));

		//ImgRotationMgrRef idrm1 = new ImgRotationMgr(
		//ImageRotationMgr_ExRef idrm1 = new ImageRotationMgr_Ex(
		//img1, GlobalStuff::AprSize1D, 23, 15, imgFactoryMgr );
		//rotParams );

		return;
	}


	{
		F32ImageRef img1 = GlobalStuff::GetLinePathImg();

		RgnSegmDiameter rsDiam;

		rsDiam.SetDiamFull(GlobalStuff::AprSize1D);

		//ImgDataMgr_CovMatRef idm1 = new ImgDataMgr_CovMat(
		IImgDataMgrRef idm1 = new ImgDataMgr_CovMat(
			img1, rsDiam.GetDiamInr_1());

		ImgGradMgr_2Ref igm1 = new ImgGradMgr_2(
			idm1, rsDiam.GetDiamFull(), 8);

		igm1->ShowLineImages();

		return;
	}


	{
		ColorTryMgrRef ctm1 = new ColorTryMgr();

		ctm1->Proceed();

		return;
	}



	if (false)
	{
		ImgSeg_GrandMethod_EvalMgrRef gme = new ImgSeg_GrandMethod_EvalMgr();

		gme->Proceed();

		return;
	}





	if (false)
	{
		int a = sizeof(ImgDataElm_Simple);

		F32ImageRef img1 = GlobalStuff::GetLinePathImg();

		//IImgDataMgrRef idm1 = new ImgDataMgr_Simple_2(
		ImgDataMgr_Simple_2Ref idm1 = new ImgDataMgr_Simple_2(
			img1, GlobalStuff::AprSize1D);


		F32ImageRef covMatImg = Gen_CovMatPure_Img(
			img1, GlobalStuff::AprSize1D
			//, NULL,
			//(F32ColorVal *) ( & (idm1->GetDataArr_Mean())[ 0 ] ) );
			);


		F32ImageRef mag_Img = Gen_CovMatMag_Img(covMatImg);

		GlobalStuff::SetLinePathImg(mag_Img);

		GlobalStuff::ShowLinePathImg();



		return;
	}


	{
		F32ImageRef img1 = GlobalStuff::GetLinePathImg();

		IImgDataMgrRef idm1 = new ImgDataMgr_Simple_2(
			img1, GlobalStuff::AprSize1D);


		F32ImageRef stDevImg = idm1->GetStandDiv_Mag_Image();

		GlobalStuff::SetLinePathImg(stDevImg);

		GlobalStuff::ShowLinePathImg();

		return;
	}


	{
		FixedVector< int > coreArr(500);

		//coreArr.

		int nSize;

		for (int i = 0; i < 20; i++)
		{
			if (0 == i % 2)
				continue;

			nSize = i * 3 + 2;
		}

		return;
	}




	{
		ImgSegDataMgrRef imd = new ImgSegDataMgr(
			//"E:\\HthmWork\\Master\\Image-Segmentation-Source-Code\\Special\\Efficient-Graph-Based-Image-Segmentation\\Result-Images\\101085-Res.seg2");
			//"E:\\HthmWork\\Master\\Image-Segmentation-Source-Code\\Special\\Efficient-Graph-Based-Image-Segmentation\\Result-Images\\101087-Res.seg2");
			//"E:\\HthmWork\\Master\\Image-Segmentation-Source-Code\\Special\\Efficient-Graph-Based-Image-Segmentation\\Result-Images\\102061-Res.seg2");

			//"E:\\HthmWork\\Master\\Image-Segmentation-Source-Code\\Special\\Mean-Shift\\MS-Csl\\MS-Csl\\segmimage.seg2");
			"E:\\HthmWork\\Master\\Image-Segmentation-Source-Code\\Special\\Mean-Shift\\Result-Images\\101085-res.seg2");



		//for( int i=0; i < 3; i++ )
		{
			//imd->ShowSegmImg();

			imd->ShowSegmImg("img1");
			//::Sleep( 1000 );

			//imd->ShowSegmImg("img2");
			//::Sleep( 1000 );

			//imd->ShowSegmImg("img3");
			//::Sleep( 1000 );

			//cvDestroyWindow("img1");
			//cvDestroyWindow(imd->GetFileName());


		}

	}


	if (false)
	{
		ImgSeg_EvalMgr::Calc_ExpectedIndex_2();
		//ImgSeg_EvalMgr::Save_ExpectedIndex_Text();

		return;
	}

	//if( false )
	{
		CString sMethodPath =
			"E:\\HthmWork\\Lib\\BSDS_300_2\\CBIS";

		ImgSeg_Method_EvalMgrRef smm = new ImgSeg_Method_EvalMgr();

		smm->Set_MethodDirPath(sMethodPath.GetBuffer());

		smm->Proceed();


		return;
	}


	{
		ImgSeg_EvalMgrRef evalMgr = new ImgSeg_EvalMgr();

		CString sAppSegPath(
			"E:\\HthmWork\\Lib\\BSDS_300_2\\Img_Human_1\\2092\\2092_1103.seg2");

		evalMgr->Set_AppSegMgr(new ImgSegDataMgr(
			sAppSegPath.GetBuffer()));

		CString sDirPath(
			"E:\\HthmWork\\Lib\\BSDS_300_2\\Img_Human_1\\2092");

		evalMgr->Set_HumanSegMgr_Coll(sDirPath);

		evalMgr->Proceed();


		return;
	}


	{
		F32ColorVal c1;
		//c1.AssignVal( 0, 128, 255 );
		c1.AssignVal(128, 128, 128);
		//c1.AssignVal( 255, 255, 255 );

		//c1.DividSelfBy( 2 );

		F32ColorVal uc1;
		uc1 = c1;
		uc1.DividSelfBy(c1.CalcMag());



		F32ColorVal c2;
		c2.AssignVal(0, 0, 255);

		F32ColorVal uc2;
		uc2 = c2;
		uc2.DividSelfBy(c2.CalcMag());



		F32ColorVal c3;
		//c3 = F32ColorVal::Add( c1, c2 );
		c3 = F32ColorVal::Add(uc1, uc2);
		c3.DividSelfBy(2);

		F32ColorVal uc3;
		uc3 = c3;
		uc3.DividSelfBy(c3.CalcMag());




		float u_Dif = F32ColorVal::Sub(uc1, uc2).CalcMag();

		float u_Dif_3 = F32ColorVal::Sub(uc1, uc3).CalcMag();

		return;
	}



	{
		FixedVector<bool> someArr;

		//someArr.SetSize( 10000000 );
		//someArr.SetSize( 50000000 );
		//someArr.SetSize( 100000000 );
		//someArr.SetSize( 200000000 );
		//someArr.SetSize( 400000000 );
		//someArr.SetSize( 800000000 );
		someArr.SetSize(1200000000);
		//someArr.SetSize( 1600000000 );

		for (int i = 0; i < someArr.GetSize(); i++)
			someArr[i] = true;

		return;
	}


	{
		CvSize siz = cvSize(400, 300);

		int nofChns = 7;

		F32ImageRef img1 = F32Image::Create(siz, nofChns);

		img1->SetAll(10);

		for (int i = 0; i < nofChns; i++)
			FillBorder(img1->GetAt(i), (float)0, 5);

		F32ImageRef img2 = GenCvSmoothedImg(img1, 11);

		float * img2_Buf = img2->GetPixAt(0, 0);



		return;
	}


	{
		int a;

		//F32ColorVal c1 = { 10, 0, 0 };
		F32ColorVal c1 = { 40, 0, 0 };

		//F32ColorVal c2 = { 60, 60, 60 };
		F32ColorVal c2 = { 0, 0, 60 };

		F32ColorVal c40 = c1.IncLessToNum(40);

		F32ColorVal uc1 = c1.IncLessToNum(40).GetUnitVect();
		F32ColorVal uc2 = c2.IncLessToNum(40).GetUnitVect();

		//float unitDif = F32ColorVal::Sub( uc1, uc2 ).CalcMag();

		float unitDif = CalcColorUnitDif(c1, c2);

		a = 0;

		return;
	}

	{
		F32ImageRef srcImg = GlobalStuff::GetLinePathImg();

		CvSize srcSiz = srcImg->GetSize();

		const int nofDirs = 8;
		//const int nofDirs = 4;
		//const int nofDirs = 16;

		const int nAprSiz = 7;



		//const int nofDirs = 1;
		//const int nofDirs = 2;

		int nDir1 = GlobalStuff::AprSize1D;

		//if( nDir1 < 0 || nDir1 >= nofDirs )
		//return;

		ImgGradMgr igm1(srcImg, nAprSiz, nofDirs);


		const int nSrcSiz1D = srcSiz.width * srcSiz.height;

		//FixedVector< float > resArr( nofDirs * nSrcSiz1D );

		FixedVector< float > & resArr = igm1.GetGradDataArr();


		//F32ImageRef gradImg = igm1.GetGradImgOfDir( nDir1 );
		F32ImageRef gradImg = igm1.GetGradMagImg();


		GlobalStuff::SetLinePathImg(gradImg);
		GlobalStuff::ShowLinePathImg();


		//ShowImage( gradImg, "gradImg" );

		int a = 0;

		return;
	}





	{
		F32ImageRef srcImg = GlobalStuff::GetLinePathImg();

		CvSize srcSiz = srcImg->GetSize();

		const int nofDirs = 8;
		//const int nofDirs = 1;
		//const int nofDirs = 2;

		int nDir1 = GlobalStuff::AprSize1D;

		if (nDir1 < 0 || nDir1 >= nofDirs)
			return;

		//ScanDirMgrColl sdmColl( 4, cvSize( 800, 600 ) );
		ScanDirMgrColl sdmColl(nofDirs, srcSiz);

		const int nSrcSiz1D = srcSiz.width * srcSiz.height;

		//FixedVector< float > resArr( nofDirs * nSrcSiz1D );

		FixedVector< float > resArr;
		resArr.SetSize(nofDirs * nSrcSiz1D);

		//F32ImageRef gradImg = F32Image::Create( srcSiz, 1 );
		F32ImageRef gradImg = F32Image::Create(srcSiz, 3);
		//float * resArr = gradImg->GetPixAt( 0, 0 );
		F32ColorVal * gradImgBuf = (F32ColorVal *)gradImg->GetPixAt(0, 0);

		const int nAprSiz = 7;

		/*
		{
		const int nMarg = nAprSiz / 2;

		const float maxDif = sqrt( (float) 3 * Sqr( 255 ) );

		for( int i=0; i < resArr.GetSize(); i++ )
		resArr[ i ] = maxDif;

		FillBorder( gradImg->GetAt(0), (float) maxDif, nMarg + 1 );
		}
		*/

		//float tmp = resArr[ nSrcSiz1D / 2 ];
		float tmp = resArr[0];

		for (int i = 0; i < sdmColl.GetNofMgrs(); i++)
		{
			ScanDirMgr & rScanMgr = sdmColl.GetMgrAt(i);
			//ScanDirMgrRef scanMgr = &sdmColl.GetMgrAt( i );

			//SubGradMgr::Process( scanMgr, srcImg, 		 
			SubGradMgr::Process(rScanMgr, srcImg,
				nAprSiz, &resArr[i], nofDirs);



		}

		//tmp = resArr[ nSrcSiz1D / 2 ];
		tmp = resArr[0];

		/*
				for( int i=0; i < nSrcSiz1D; i++ )
				{
				if( maxDif != gradImgBuf[ i ] )
				gradImgBuf[ i ] = resArr[ i ];
				//gradImgBuf[ i ] = 0;
				}
				*/


		//for( int i=0; i < nSrcSiz1D; i += nofDirs; )
		for (int i = 0; i < nSrcSiz1D; i++)
		{
			float * gradValColl = &resArr[i * nofDirs];

			float val1 = gradValColl[nDir1];

			//if( maxDif != gradImgBuf[ i ] )
			//gradImgBuf[ i ] = gradValColl[ 1 ];
			gradImgBuf[i].AssignVal(val1, val1, val1);
		}

		/*
				FixedVector< F32Point > & rBgnPntArr = sdmColl.GetMgrAt( nDir1 ).GetBgnPntArr();
				//FixedVector< int > & rBgnIndexArr = sdmColl.GetMgrAt( nDir1 ).GetBgnIndexArr();

				//for( int i=0; i < rBgnIndexArr.GetSize(); i++ )
				for( int i=0; i < rBgnPntArr.GetSize(); i++ )
				{
				//int j = rBgnIndexArr[ i ];
				F32Point & rBgnPnt = rBgnPntArr[ i ];


				//gradImgBuf[ j ] = 0;

				//F32ColorVal & rPix = gradImgBuf[ j ];
				F32ColorVal * pPix = (F32ColorVal *)gradImg->GetPixAt( rBgnPnt.x, rBgnPnt.y );
				pPix->AssignVal( 0, 180, 0 );

				//DrawCircle( gradImg, rBgnPnt, u8ColorVal( 0, 0, 0 ), 3 );
				}
				*/

		//GlobalStuff::SetLinePathImg( gradImg );
		//GlobalStuff::ShowLinePathImg();

		ShowImage(gradImg, "gradImg");

		int a = 0;

		return;
	}










	{
		//ScanDirMgrColl sdmColl( 4, cvSize( 800, 600 ) );
		ScanDirMgrColl sdmColl(8, cvSize(800, 600));

		int a = 0;

		return;
	}






	{
#define ARR_SIZ 30

		//LineStepperByAngle ls1( 0, 0, 90 );
		LineStepperByAngle ls1(0, 0, 22.5);

		F32Point pntArr[ARR_SIZ];

		for (int i = 0; i < ARR_SIZ; i++)
		{
			pntArr[i] = ls1.GetCurrentFwd();

			ls1.FwdMoveNext();
		}

		int a = 0;

		return;
	}

	{
		F32Point pnt1 = GlobalStuff::GetPoint1();

		this->CircPntOfLinePathImg(pnt1.x, pnt1.y);
		return;
	}







	{
		F32ImageRef src = GenImageFromChannel(
			GlobalStuff::GetLinePathImg(), 0);

		//src->SetAll( 1 );

		CvSize srcSiz = src->GetSize();

		FixedVector< F32Point > pntArr;
		pntArr.SetSize(srcSiz.width * srcSiz.height);

		//FillCenterOfMassArr( src, GlobalStuff::AprSize1D, &pntArr );
		FillSlidePointArr(src, GlobalStuff::AprSize1D, &pntArr);
		//FillClimbPointArr( src, GlobalStuff::AprSize1D, &pntArr );


		//		GlobalStuff::SetLinePathImg(
		//GenFastAvgHImg( GlobalStuff::GetLinePathImg(), GlobalStuff::AprSize1D ) );
		//			GenFastAvgImg( GlobalStuff::GetLinePathImg(), GlobalStuff::AprSize1D ) );

		GlobalStuff::ShowLinePathImg();

		return;

	}

	{
		float f1 = 10000;

		f1 *= 1000.3453;

		f1 *= 100;
		f1 /= 100;

		f1 /= 1000.3453;

		S32ImageRef minDepthImg = GenMinPosDepthImg(
			GlobalStuff::GetLinePathImg()->GetSize());


		GlobalStuff::SetLinePathImg(
			GenFastAvgImg(GlobalStuff::GetLinePathImg(), GlobalStuff::AprSize1D));

		GlobalStuff::ShowLinePathImg();

		return;
	}


	{

		//int nRadius = siz1.width / 4;
		//int nRadius = 3;
		int nRadius = GlobalStuff::AprSize1D;

		if (nRadius > 10)
			nRadius = 10;

		//CvSize siz1 = cvSize( 400, 400 );
		//CvSize siz1 = cvSize( 40, 40 );
		CvSize siz1 = cvSize(nRadius * 4, nRadius * 4);


		//CircleContPathRef cp1 = new CircleContPath( 0, 180, 100 );
		CircleContPathRef cp1 = new CircleContPath(0, 180, nRadius);
		//CircleContPathRef cp1 = new CircleContPath( 0, 270, nRadius );

		F32ImageRef img1 = F32Image::Create(siz1, 1);

		img1->SetAll(0);

		F32Point orgPnt(siz1.width / 2, siz1.height / 2);

		cvRectangle(
			img1->GetIplImagePtr(),
			cvPoint(orgPnt.x - nRadius, orgPnt.y - nRadius),
			//cvPoint(nWidth-1, nHeight-1), 
			cvPoint(orgPnt.x + nRadius, orgPnt.y + nRadius),
			//cvPoint(nWidth+50, nHeight+170), 
			//CV_RGB(64, 128, 255),
			//CV_RGB(255, 128, 64),
			cvScalar(128, 128, 128, 128),
			//CV_RGB(255, 255, 255),
			-1);

		*img1->GetPixAt(orgPnt.x, orgPnt.y) = 255;


		F32Point pnt1;

		do
		{
			pnt1 = cp1->GetCurrent();


			F32Point pnt2 = pnt1;

			pnt2.IncBy(orgPnt);

			float * pPix = img1->GetPixAt(pnt2.x, pnt2.y);
			*pPix = 255;

		} while (cp1->MoveNext());

		F32ImageRef img2 = GenUpSampledImage(img1, 10);

		ShowImage(img2, "CircleContPath");

		return;
	}

	{
		FixedDeque<int> fd1(1000);

		for (int i = 0; i < 10; i++)
			fd1.PushBack(i);

		int a = fd1[5];

		a = fd1.GetFront();

		a = fd1.GetBack();

		//return;
	}



	{
		FixedVector<int> fv1(1000);

		for (int i = 0; i < 10; i++)
			fv1.PushBack(i);

		int * ptr = &fv1[5];

		fv1[5] = 7;

		int a = fv1[5];

		//return;
	}


	{
		F32ImageRef img1 = GlobalStuff::GetLinePathImg();

		Try17May10(img1);

		return;
	}





	/*
		{
		std::queue< int > que1;

		const int nSize = 30;


		for( int i=0; i < 10000; i++ )
		{

		for( int j=0; j < nSize; j++ )
		{
		que1.push(70);
		}


		//while( false == que1.empty() )
		//que1.pop();

		std::deque< float > * pCont = (std::deque< float > *)( &que1._Get_container() );


		pCont->clear();


		}






		return;
		}
		*/

	{
		std::vector< int > vec1;
		//std::vector< int, allocator, > vec1;


		const int nSize = 1000000;

		vec1.resize(nSize);
		vec1.resize(0);

		vec1.push_back(80);

		for (int i = 0; i < 10000; i++)
		{
			vec1.resize(nSize);
			vec1.resize(0);

			//vec1.clear();






		}





		return;
	}

	F32ImageRef res = GlobalStuff::GetLinePathImg();

	//res = GenThresholdImg( res, 130 );


	//ConvKernelRef ck1 = new ConvKernel( 10 );
	//ConvKernelRef ck1 = ConvKernel::CreateBlur( 21 );

	//ConvKernelRef ck1 = ConvKernel::CreateFilter1( 51 );

	//res = ck1->GenResult( res );



	//SobelBuilder sb1;








	GlobalStuff::SetLinePathImg(res);

	ShowImage(GlobalStuff::GetLinePathImg(), "LinePathImg");

}


void ImageProcessor::Try19()
{
	//F32ImageRef src = GenF32FromS16Image(
	//	GenS16FromU8Image(img));
	//F32ImageRef res = src;

	F32ImageRef res = GlobalStuff::GetLinePathImg();

	//GlobalStuff::OrgImg = res;

	SaveImage(res, "OrgImg.jpg");

	const int nPyrIterCnt = 0;



	//res = GenPyrDownImg(res, nPyrIterCnt);
	//res = GenDownSampledImage( res , 1 );


	U8ImageRef dsp;

	//res = GenTriChGrayImg( res );


	//SaveImage(avg_Img, "avg_Img.jpg");

	//int nAprSiz = 81;
	//int nAprSiz = 41;
	//int nAprSiz = 5;
	//int nAprSiz = 3;
	//int nAprSiz = 19;

	//	F32ImageRef avg_Img = GenCvSmoothedImg( res, 
	//(nAprSiz - 1) * 2 + 1  );
	//nAprSiz);
	//		5);
	//9);
	//25);
	//45);

	F32ImageRef avg_Img = res;

	//ShowImage(avg_Img, "avg_Img");

	{
		F32ColorVal colorFact;

		/*		colorFact.val0 = 0.51 * 0.5;
				colorFact.val1 = 1.44 * 0.5;
				colorFact.val2 = 1.048 * 0.5;*/

		colorFact.val0 = 0.51;
		colorFact.val1 = 1.44;
		colorFact.val2 = 1.048;

		//avg_Img = GenMultByColorImg( avg_Img, colorFact);

		//BalanceImageWithIntensityFactors(avg_Img);
	}


	res = avg_Img;

	//ShowImage(avg_Img, "avg_Img");





	S16ImageRef res2_1 = GenS16FromF32Image(avg_Img);

	res2_1 = GenUpSampledImage(res2_1, 8);

	SaveImage(res2_1, "avg_Img.jpg");







	//SaveImage(avg_Img, "avg_Img.jpg");

	//int nAprSizG1 = nAprSiz;
	int nAprSizG1 = 1;
	//S16ImageRef gradImg = GenMorphGradImg( res, 1 );
	F32ImageRef gradImg = GenMorphGradImg(res, nAprSizG1);

	GlobalStuff::SetLinePathImg(gradImg);


	//ShowImage(gradImg, "gradImg");

	//F32ImageRef grad1Dil = GenCvDilateImg( gradImg, 3 );
	//ShowImage(grad1Dil, "grad1Dil");


	//S16ImageRef weightImgS16 = GenWeightImg5( gradImg, nAprSizG1 * 3 );
	S16ImageRef weightImgS16 = GenWeightImg5(gradImg, nAprSizG1 * 2);




	//weightImgS16 = GenPyrUpImg( weightImgS16, nPyrIterCnt);
	//avg_Img = GenPyrUpImg( avg_Img, nPyrIterCnt);

	{
		dsp = GenU8FromS16Image(
			GenBinImposedImg(
			GenS16FromF32Image(avg_Img),
			weightImgS16));
		//weightImgS16 );

		//HCV_CALL( cvvSaveImage("WtBinImposedImg.jpg", 
		//dsp->GetIplImagePtr()) );

		//ShowImage(dsp->GetIplImagePtr(), "weightImgS16");
		//ShowImage(NULL, "weightImgS16");
	}

	F32ImageRef avgImg0 = avg_Img;
	F32ImageRef avgImg2 = avgImg0;
	//S16ImageRef avgImg2 = GenCvMedGausImg( avg_Img, 51);

	//dsp = GenU8FromS16Image(avgImg2);
	//ShowImage(dsp->GetIplImagePtr(), "avgImg2");

	//return;

	{
		//int nThrVal = 7;
		//int nThrVal = 15;
		//int nThrVal = 20; 
		int nThrVal = 25;
		//int nThrVal = 30;
		//int nThrVal = 35;
		//int nThrVal = 45;
		//int nThrVal = 10;

		//RegionSegmentor10Ref rs2 = new RegionSegmentor10(avg_Img, weightImgS16, nThrVal);	
		//	From 9, Conflicts are guided by Edge Roots.

		//RegionSegmentor11Ref rs2 = new RegionSegmentor11(avg_Img, weightImgS16, nThrVal);	
		//	From 10, Conflicts are guided by Edge Roots.

		//RegionSegmentor12Ref rs2 = new RegionSegmentor12(avg_Img, weightImgS16, nThrVal);	
		//	From 10, Conflicts are guided by Edge Roots.

		//RegionSegmentor13Ref rs2 = new RegionSegmentor13(avgImg2, weightImgS16, nThrVal, avg_Img);	
		//RegionSegmentor13Ref rs2 = new RegionSegmentor13(avgImg2, weightImgS16, nThrVal, src);	
		//RegionSegmentor13Ref rs2 = new RegionSegmentor13(avgImg2, weightImgS16, nThrVal);	
		//	From 10, Conflicts are guided by Edge Roots.

		//RegionSegmentor14Ref rs2 = new RegionSegmentor14(avgImg2, weightImgS16, nThrVal, avg_Img);	
		//RegionSegmentor14Ref rs2 = new RegionSegmentor14(avgImg2, weightImgS16, nThrVal, src);	
		//	From 13, Conflicts are guided by Edge Roots.

		//RegionSegmentor15Ref rs2 = new RegionSegmentor15(avgImg2, weightImgS16, nThrVal, avg_Img);	
		//RegionSegmentor15Ref rs2 = new RegionSegmentor15(avgImg2, weightImgS16, nThrVal, src);	
		//	From 13, Conflicts are guided by Edge Roots.

		//RegionSegmentor16Ref rs2 = new RegionSegmentor16(avgImg2, weightImgS16, nThrVal, avgImg0);	
		//RegionSegmentor16Ref rs2 = new RegionSegmentor16(avgImg2, weightImgS16, nThrVal, src);	
		//	From 15, F32 Work.

		//RegionSegmentor17Ref rs2 = new RegionSegmentor17(avgImg2, weightImgS16, nThrVal, avgImg0);	
		//RegionSegmentor17Ref rs2 = new RegionSegmentor17(avgImg2, weightImgS16, nThrVal, src);	
		//	From 15, F32 Work.

		//RegionSegmentor18Ref rs2 = new RegionSegmentor18(avgImg2, weightImgS16, nThrVal, avgImg0);	
		//RegionSegmentor18Ref rs2 = new RegionSegmentor18(avgImg2, weightImgS16, nThrVal, src);	
		//	From 15, F32 Work.

		RegionSegmentor19Ref rs2 = new RegionSegmentor19(avgImg2, weightImgS16, nThrVal, avgImg0);
		//RegionSegmentor19Ref rs2 = new RegionSegmentor19(avgImg2, weightImgS16, nThrVal, src);	
		//	From 15, F32 Work.

		rs2->Segment();
		S16ImageRef res2 = rs2->GenSegmentedImage(false);
		//S16ImageRef res2 = rs2->GenSegmentedImage();

		GlobalStuff::SetLinePathImg(
			GenF32FromS16Image(res2));

		ShowImage(GlobalStuff::GetLinePathImg(), "LinePathImg");



		//ShowImage(res2, "RegionSegmentor");
		ShowImage(res2, "RgnSgmImg");

		res2 = GenUpSampledImage(res2, 8);



		SaveImage(res2, "RegionSegmentor.jpg");
	}

}










void ImageProcessor::Try18()
{
	F32ImageRef src = GenF32FromS16Image(
		GenS16FromU8Image(img));
	F32ImageRef res = src;

	const int nPyrIterCnt = 0;



	//res = GenPyrDownImg(res, nPyrIterCnt);
	//res = GenDownSampledImage( res , 1 );


	U8ImageRef dsp;

	//res = GenTriChGrayImg( res );

	ShowImage(res, "Org Img");

	//int nAprSiz = 81;
	//int nAprSiz = 41;
	//int nAprSiz = 5;
	//int nAprSiz = 3;
	//int nAprSiz = 19;

	F32ImageRef avg_Img = GenCvSmoothedImg(res,
		//(nAprSiz - 1) * 2 + 1  );
		//nAprSiz);
		5);
	//45);


	{
		F32ColorVal colorFact;

		/*		colorFact.val0 = 0.51 * 0.5;
				colorFact.val1 = 1.44 * 0.5;
				colorFact.val2 = 1.048 * 0.5;*/

		colorFact.val0 = 0.51;
		colorFact.val1 = 1.44;
		colorFact.val2 = 1.048;

		//avg_Img = GenMultByColorImg( avg_Img, colorFact);

		BalanceImageWithIntensityFactors(avg_Img);
	}


	res = avg_Img;

	ShowImage(avg_Img, "avg_Img");

	//SaveImage(avg_Img, "avg_Img.jpg");

	//int nAprSizG1 = nAprSiz;
	int nAprSizG1 = 1;
	//S16ImageRef gradImg = GenMorphGradImg( res, 1 );
	F32ImageRef gradImg = GenMorphGradImg(res, nAprSizG1);

	ShowImage(gradImg, "gradImg");

	//F32ImageRef grad1Dil = GenCvDilateImg( gradImg, 3 );
	//ShowImage(grad1Dil, "grad1Dil");


	//S16ImageRef weightImgS16 = GenWeightImg5( gradImg, nAprSizG1 * 3 );
	S16ImageRef weightImgS16 = GenWeightImg5(gradImg, nAprSizG1 * 2);




	//weightImgS16 = GenPyrUpImg( weightImgS16, nPyrIterCnt);
	//avg_Img = GenPyrUpImg( avg_Img, nPyrIterCnt);

	{
		dsp = GenU8FromS16Image(
			GenBinImposedImg(
			GenS16FromF32Image(avg_Img),
			weightImgS16));
		//weightImgS16 );

		HCV_CALL(cvvSaveImage("WtBinImposedImg.jpg",
			dsp->GetIplImagePtr()));

		ShowImage(dsp->GetIplImagePtr(), "weightImgS16");
	}

	F32ImageRef avgImg0 = avg_Img;
	F32ImageRef avgImg2 = avgImg0;
	//S16ImageRef avgImg2 = GenCvMedGausImg( avg_Img, 51);

	//dsp = GenU8FromS16Image(avgImg2);
	//ShowImage(dsp->GetIplImagePtr(), "avgImg2");

	//return;

	{
		//int nThrVal = 15;
		//int nThrVal = 20; 
		int nThrVal = 25;
		//int nThrVal = 30;
		//int nThrVal = 35;
		//int nThrVal = 45;
		//int nThrVal = 10;

		//RegionSegmentor10Ref rs2 = new RegionSegmentor10(avg_Img, weightImgS16, nThrVal);	
		//	From 9, Conflicts are guided by Edge Roots.

		//RegionSegmentor11Ref rs2 = new RegionSegmentor11(avg_Img, weightImgS16, nThrVal);	
		//	From 10, Conflicts are guided by Edge Roots.

		//RegionSegmentor12Ref rs2 = new RegionSegmentor12(avg_Img, weightImgS16, nThrVal);	
		//	From 10, Conflicts are guided by Edge Roots.

		//RegionSegmentor13Ref rs2 = new RegionSegmentor13(avgImg2, weightImgS16, nThrVal, avg_Img);	
		//RegionSegmentor13Ref rs2 = new RegionSegmentor13(avgImg2, weightImgS16, nThrVal, src);	
		//RegionSegmentor13Ref rs2 = new RegionSegmentor13(avgImg2, weightImgS16, nThrVal);	
		//	From 10, Conflicts are guided by Edge Roots.

		//RegionSegmentor14Ref rs2 = new RegionSegmentor14(avgImg2, weightImgS16, nThrVal, avg_Img);	
		//RegionSegmentor14Ref rs2 = new RegionSegmentor14(avgImg2, weightImgS16, nThrVal, src);	
		//	From 13, Conflicts are guided by Edge Roots.

		//RegionSegmentor15Ref rs2 = new RegionSegmentor15(avgImg2, weightImgS16, nThrVal, avg_Img);	
		//RegionSegmentor15Ref rs2 = new RegionSegmentor15(avgImg2, weightImgS16, nThrVal, src);	
		//	From 13, Conflicts are guided by Edge Roots.

		//RegionSegmentor16Ref rs2 = new RegionSegmentor16(avgImg2, weightImgS16, nThrVal, avgImg0);	
		//RegionSegmentor16Ref rs2 = new RegionSegmentor16(avgImg2, weightImgS16, nThrVal, src);	
		//	From 15, F32 Work.

		//RegionSegmentor17Ref rs2 = new RegionSegmentor17(avgImg2, weightImgS16, nThrVal, avgImg0);	
		//RegionSegmentor17Ref rs2 = new RegionSegmentor17(avgImg2, weightImgS16, nThrVal, src);	
		//	From 15, F32 Work.

		RegionSegmentor18Ref rs2 = new RegionSegmentor18(avgImg2, weightImgS16, nThrVal, avgImg0);
		//RegionSegmentor18Ref rs2 = new RegionSegmentor18(avgImg2, weightImgS16, nThrVal, src);	
		//	From 15, F32 Work.

		rs2->Segment();
		S16ImageRef res2 = rs2->GenSegmentedImage();

		ShowImage(res2, "RegionSegmentor");

		SaveImage(res2, "RegionSegmentor.jpg");
	}

}








void ImageProcessor::Try17()
{
	F32ImageRef src = GenF32FromS16Image(
		GenS16FromU8Image(img));
	F32ImageRef res = src;

	const int nPyrIterCnt = 0;



	//res = GenPyrDownImg(res, nPyrIterCnt);
	//res = GenDownSampledImage( res , 1 );


	U8ImageRef dsp;

	//res = GenTriChGrayImg( res );

	ShowImage(res, "Org Img");

	//int nAprSiz = 81;
	//int nAprSiz = 41;
	//int nAprSiz = 5;
	//int nAprSiz = 3;
	//int nAprSiz = 19;

	F32ImageRef avg_Img = GenCvSmoothedImg(res,
		//(nAprSiz - 1) * 2 + 1  );
		//nAprSiz);
		5);


	{
		F32ColorVal colorFact;

		/*		colorFact.val0 = 0.51 * 0.5;
				colorFact.val1 = 1.44 * 0.5;
				colorFact.val2 = 1.048 * 0.5;*/

		colorFact.val0 = 0.51;
		colorFact.val1 = 1.44;
		colorFact.val2 = 1.048;

		//avg_Img = GenMultByColorImg( avg_Img, colorFact);

		BalanceImageWithIntensityFactors(avg_Img);
	}


	res = avg_Img;

	ShowImage(avg_Img, "avg_Img");

	//SaveImage(avg_Img, "avg_Img.jpg");

	//int nAprSizG1 = nAprSiz;
	int nAprSizG1 = 1;
	//S16ImageRef gradImg = GenMorphGradImg( res, 1 );
	F32ImageRef gradImg = GenMorphGradImg(res, nAprSizG1);

	ShowImage(gradImg, "gradImg");

	//F32ImageRef grad1Dil = GenCvDilateImg( gradImg, 3 );
	//ShowImage(grad1Dil, "grad1Dil");


	//S16ImageRef weightImgS16 = GenWeightImg5( gradImg, nAprSizG1 * 3 );
	S16ImageRef weightImgS16 = GenWeightImg5(gradImg, nAprSizG1 * 2);




	//weightImgS16 = GenPyrUpImg( weightImgS16, nPyrIterCnt);
	//avg_Img = GenPyrUpImg( avg_Img, nPyrIterCnt);

	{
		dsp = GenU8FromS16Image(
			GenBinImposedImg(
			GenS16FromF32Image(avg_Img),
			weightImgS16));
		//weightImgS16 );

		HCV_CALL(cvvSaveImage("WtBinImposedImg.jpg",
			dsp->GetIplImagePtr()));

		ShowImage(dsp->GetIplImagePtr(), "weightImgS16");
	}

	F32ImageRef avgImg0 = avg_Img;
	F32ImageRef avgImg2 = avgImg0;
	//S16ImageRef avgImg2 = GenCvMedGausImg( avg_Img, 51);

	//dsp = GenU8FromS16Image(avgImg2);
	//ShowImage(dsp->GetIplImagePtr(), "avgImg2");

	//return;

	{
		//int nThrVal = 15;
		//int nThrVal = 20; 
		int nThrVal = 25;
		//int nThrVal = 30;
		//int nThrVal = 35;
		//int nThrVal = 45;
		//int nThrVal = 10;

		//RegionSegmentor10Ref rs2 = new RegionSegmentor10(avg_Img, weightImgS16, nThrVal);	
		//	From 9, Conflicts are guided by Edge Roots.

		//RegionSegmentor11Ref rs2 = new RegionSegmentor11(avg_Img, weightImgS16, nThrVal);	
		//	From 10, Conflicts are guided by Edge Roots.

		//RegionSegmentor12Ref rs2 = new RegionSegmentor12(avg_Img, weightImgS16, nThrVal);	
		//	From 10, Conflicts are guided by Edge Roots.

		//RegionSegmentor13Ref rs2 = new RegionSegmentor13(avgImg2, weightImgS16, nThrVal, avg_Img);	
		//RegionSegmentor13Ref rs2 = new RegionSegmentor13(avgImg2, weightImgS16, nThrVal, src);	
		//RegionSegmentor13Ref rs2 = new RegionSegmentor13(avgImg2, weightImgS16, nThrVal);	
		//	From 10, Conflicts are guided by Edge Roots.

		//RegionSegmentor14Ref rs2 = new RegionSegmentor14(avgImg2, weightImgS16, nThrVal, avg_Img);	
		//RegionSegmentor14Ref rs2 = new RegionSegmentor14(avgImg2, weightImgS16, nThrVal, src);	
		//	From 13, Conflicts are guided by Edge Roots.

		//RegionSegmentor15Ref rs2 = new RegionSegmentor15(avgImg2, weightImgS16, nThrVal, avg_Img);	
		//RegionSegmentor15Ref rs2 = new RegionSegmentor15(avgImg2, weightImgS16, nThrVal, src);	
		//	From 13, Conflicts are guided by Edge Roots.

		//RegionSegmentor16Ref rs2 = new RegionSegmentor16(avgImg2, weightImgS16, nThrVal, avgImg0);	
		//RegionSegmentor16Ref rs2 = new RegionSegmentor16(avgImg2, weightImgS16, nThrVal, src);	
		//	From 15, F32 Work.

		RegionSegmentor17Ref rs2 = new RegionSegmentor17(avgImg2, weightImgS16, nThrVal, avgImg0);
		//RegionSegmentor17Ref rs2 = new RegionSegmentor17(avgImg2, weightImgS16, nThrVal, src);	
		//	From 15, F32 Work.

		rs2->Segment();
		S16ImageRef res2 = rs2->GenSegmentedImage();

		ShowImage(res2, "RegionSegmentor");

		SaveImage(res2, "RegionSegmentor.jpg");
	}

}






void ImageProcessor::Try16()
{
	F32ImageRef src = GenF32FromS16Image(
		GenS16FromU8Image(img));
	F32ImageRef res = src;

	const int nPyrIterCnt = 0;



	//res = GenPyrDownImg(res, nPyrIterCnt);
	//res = GenDownSampledImage( res , 1 );


	U8ImageRef dsp;

	//res = GenTriChGrayImg( res );

	ShowImage(res, "Org Img");

	//int nAprSiz = 81;
	//int nAprSiz = 41;
	//int nAprSiz = 5;
	//int nAprSiz = 3;
	//int nAprSiz = 19;

	F32ImageRef avg_Img = GenCvSmoothedImg(res,
		//(nAprSiz - 1) * 2 + 1  );
		//nAprSiz);
		5);

	res = avg_Img;

	ShowImage(avg_Img, "avg_Img");

	//SaveImage(avg_Img, "avg_Img.jpg");

	//int nAprSizG1 = nAprSiz;
	int nAprSizG1 = 1;
	//S16ImageRef gradImg = GenMorphGradImg( res, 1 );
	F32ImageRef gradImg = GenMorphGradImg(res, nAprSizG1);

	ShowImage(gradImg, "gradImg");

	//F32ImageRef grad1Dil = GenCvDilateImg( gradImg, 3 );
	//ShowImage(grad1Dil, "grad1Dil");


	//S16ImageRef weightImgS16 = GenWeightImg5( gradImg, nAprSizG1 * 3 );
	S16ImageRef weightImgS16 = GenWeightImg5(gradImg, nAprSizG1 * 2);




	//weightImgS16 = GenPyrUpImg( weightImgS16, nPyrIterCnt);
	//avg_Img = GenPyrUpImg( avg_Img, nPyrIterCnt);

	{
		dsp = GenU8FromS16Image(
			GenBinImposedImg(
			GenS16FromF32Image(avg_Img),
			weightImgS16));
		//weightImgS16 );

		HCV_CALL(cvvSaveImage("WtBinImposedImg.jpg",
			dsp->GetIplImagePtr()));

		ShowImage(dsp->GetIplImagePtr(), "weightImgS16");
	}

	F32ImageRef avgImg0 = avg_Img;
	F32ImageRef avgImg2 = avgImg0;
	//S16ImageRef avgImg2 = GenCvMedGausImg( avg_Img, 51);

	//dsp = GenU8FromS16Image(avgImg2);
	//ShowImage(dsp->GetIplImagePtr(), "avgImg2");

	//return;

	{
		//int nThrVal = 15;
		//int nThrVal = 20; 
		int nThrVal = 25;
		//int nThrVal = 30;
		//int nThrVal = 35;
		//int nThrVal = 45;
		//int nThrVal = 10;

		//RegionSegmentor10Ref rs2 = new RegionSegmentor10(avg_Img, weightImgS16, nThrVal);	
		//	From 9, Conflicts are guided by Edge Roots.

		//RegionSegmentor11Ref rs2 = new RegionSegmentor11(avg_Img, weightImgS16, nThrVal);	
		//	From 10, Conflicts are guided by Edge Roots.

		//RegionSegmentor12Ref rs2 = new RegionSegmentor12(avg_Img, weightImgS16, nThrVal);	
		//	From 10, Conflicts are guided by Edge Roots.

		//RegionSegmentor13Ref rs2 = new RegionSegmentor13(avgImg2, weightImgS16, nThrVal, avg_Img);	
		//RegionSegmentor13Ref rs2 = new RegionSegmentor13(avgImg2, weightImgS16, nThrVal, src);	
		//RegionSegmentor13Ref rs2 = new RegionSegmentor13(avgImg2, weightImgS16, nThrVal);	
		//	From 10, Conflicts are guided by Edge Roots.

		//RegionSegmentor14Ref rs2 = new RegionSegmentor14(avgImg2, weightImgS16, nThrVal, avg_Img);	
		//RegionSegmentor14Ref rs2 = new RegionSegmentor14(avgImg2, weightImgS16, nThrVal, src);	
		//	From 13, Conflicts are guided by Edge Roots.

		//RegionSegmentor15Ref rs2 = new RegionSegmentor15(avgImg2, weightImgS16, nThrVal, avg_Img);	
		//RegionSegmentor15Ref rs2 = new RegionSegmentor15(avgImg2, weightImgS16, nThrVal, src);	
		//	From 13, Conflicts are guided by Edge Roots.

		//RegionSegmentor16Ref rs2 = new RegionSegmentor16(avgImg2, weightImgS16, nThrVal, avgImg0);	
		//RegionSegmentor16Ref rs2 = new RegionSegmentor16(avgImg2, weightImgS16, nThrVal, src);	
		//	From 15, F32 Work.

		RegionSegmentor17Ref rs2 = new RegionSegmentor17(avgImg2, weightImgS16, nThrVal, avgImg0);
		//RegionSegmentor17Ref rs2 = new RegionSegmentor17(avgImg2, weightImgS16, nThrVal, src);	
		//	From 15, F32 Work.

		rs2->Segment();
		S16ImageRef res2 = rs2->GenSegmentedImage();

		ShowImage(res2, "RegionSegmentor");

		SaveImage(res2, "RegionSegmentor.jpg");
	}

}




void ImageProcessor::EdgeDir2()
{
	F32ImageRef src = GenF32FromU8Image(img);
	F32ImageRef res = src;

	//res = res->Clone();

	U8ImageRef dsp;



	F32ImageRef ed2 = F32Image::Create(
		src->GetSize(), 4);

	//ed2 = GenCvSmoothedImg( ed2, 5);





	ShowImage(src, "src");

	F32ImageRef avg_Img = GenCvSmoothedImg(res, 5);
	//S16ImageRef avg_Img = res;

	ShowImage(avg_Img, "avg_Img");

	//F32ImageRef avgImgF32 = GenF32FromS16Image( avg_Img );
	//avg_Img = GenS16FromF32Image( avgImgF32 );

	res = avg_Img;

	F32ImageRef gradImg = GenMorphGradImg(res, 1);

	//S16ImageRef weightImgS16 = GenWeightImg5( gradImg, nAprSizG1 * 3 );
	S16ImageRef weightImgS16 = GenWeightImg5(gradImg, 2);

	//S16ImageRef weightImgS16 = GenWeightImg4( gradImg, 3 );


	SobelBuilderRef sobelBuilder = new SobelBuilder(res, 3);

	float scale = 1000;
	int avgSiz = 7;

	F32ImageRef gradImgF32X =
		GenMagImgF32(sobelBuilder->GenImageX(1));
	{
		//gradImgF32X =  GenMultByNumImg( gradImgF32X, scale);
		//gradImgF32X = GenCvSmoothedImg( gradImgF32X, avgSiz);
	}

	F32ImageRef gradImgF32Y =
		GenMagImgF32(sobelBuilder->GenImageY(1));
	{
		//gradImgF32Y =  GenMultByNumImg( gradImgF32Y, scale);
		//gradImgF32Y = GenCvSmoothedImg( gradImgF32Y, avgSiz);
	}

	NormalizeEdgeDirImages(gradImgF32X, gradImgF32Y);
	//NormalizeEdgeDirImages( gradImgF32X, gradImgF32Y, 500 );

	S16ImageRef gradImgX = GenS16FromF32Image(gradImgF32X);

	ShowImage(gradImgX, "gradImgX");

	S16ImageRef gradImgY = GenS16FromF32Image(gradImgF32Y);

	ShowImage(gradImgY, "gradImgY");

	//NormalizeEdgeDirImages( gradImgX, gradImgY );

	S16ImageRef res16 = GenColorEdgeDirImg(
		gradImgX, gradImgY, weightImgS16);
	//gradImgX, gradImgY, NULL);

	//res = GenCvSmoothedImg( res, 27);

	ShowImage(res16, "ColorEdgeDirImg");
}






void ImageProcessor::EdgeDir()
{
	F32ImageRef src = GenF32FromU8Image(img);
	F32ImageRef res = src;

	U8ImageRef dsp;


	ShowImage(src, "src");

	F32ImageRef avg_Img = GenCvSmoothedImg(res, 5);
	//S16ImageRef avg_Img = res;

	ShowImage(avg_Img, "avg_Img");

	//F32ImageRef avgImgF32 = GenF32FromS16Image( avg_Img );
	//avg_Img = GenS16FromF32Image( avgImgF32 );

	res = avg_Img;

	F32ImageRef gradImg = GenMorphGradImg(res, 1);

	//S16ImageRef weightImgS16 = GenWeightImg5( gradImg, nAprSizG1 * 3 );
	S16ImageRef weightImgS16 = GenWeightImg5(gradImg, 2);

	//S16ImageRef weightImgS16 = GenWeightImg4( gradImg, 3 );


	SobelBuilderRef sobelBuilder = new SobelBuilder(res, 3);

	float scale = 1000;
	int avgSiz = 7;

	F32ImageRef gradImgF32X =
		GenMagImgF32(sobelBuilder->GenImageX(1));
	{
		gradImgF32X = GenMultByNumImg(gradImgF32X, scale);
		gradImgF32X = GenCvSmoothedImg(gradImgF32X, avgSiz);
	}

	F32ImageRef gradImgF32Y =
		GenMagImgF32(sobelBuilder->GenImageY(1));
	{
		gradImgF32Y = GenMultByNumImg(gradImgF32Y, scale);
		gradImgF32Y = GenCvSmoothedImg(gradImgF32Y, avgSiz);
	}

	NormalizeEdgeDirImages(gradImgF32X, gradImgF32Y);
	//NormalizeEdgeDirImages( gradImgF32X, gradImgF32Y, 500 );

	S16ImageRef gradImgX = GenS16FromF32Image(gradImgF32X);

	ShowImage(gradImgX, "gradImgX");

	S16ImageRef gradImgY = GenS16FromF32Image(gradImgF32Y);

	ShowImage(gradImgY, "gradImgY");

	//NormalizeEdgeDirImages( gradImgX, gradImgY );

	S16ImageRef res16 = GenColorEdgeDirImg(
		gradImgX, gradImgY, weightImgS16);
	//gradImgX, gradImgY, NULL);

	//res = GenCvSmoothedImg( res, 27);

	ShowImage(res16, "ColorEdgeDirImg");
}


void ImageProcessor::Try15()
{
	S16ImageRef src = GenS16FromU8Image(img);
	S16ImageRef res = src;

	const int nPyrIterCnt = 0;



	res = GenPyrDownImg(res, nPyrIterCnt);
	//res = GenDownSampledImage( res , 1 );

	int y = res->GetHeight() / 2;

	//int y = res->GetHeight() / 2 - 50;

	//int y = 110;

	SignalOneDimViewerRef viewer = new SignalOneDimViewer();

	SignalOneDimRef sig;

	U8ImageRef dsp;

	//res = GenTriChGrayImg( res );

	sig = GenHorzLineFromImage(res, y);
	viewer->AddSignal(sig);


	//res = GenImageFromHorzSignal(sig, res->GetHeight());


	int nShift = 0;



	dsp = GenU8FromS16Image(res);

	HCV_CALL(
		cvLine(
		dsp->GetIplImagePtr(),
		cvPoint(0, y - nShift),
		cvPoint(res->GetWidth() - 1, y - nShift),
		CV_RGB(0, 255, 0), 1)
		);


	ShowImage(dsp->GetIplImagePtr(), "Org Gray");

	//int nAprSiz = 81;
	//int nAprSiz = 41;
	int nAprSiz = 5;
	//int nAprSiz = 3;
	//int nAprSiz = 19;
	//S16ImageRef avg_Img = GenFastAvgImg( res, nAprSiz * 10 );
	//S16ImageRef avg_Img = GenFastAvgImg( res, nAprSiz);
	S16ImageRef avg_Img = GenCvSmoothedImg(res, nAprSiz);
	//S16ImageRef avg_Img = res;


	//F32ImageRef avgImgF32 = GenF32FromS16Image( avg_Img );
	//avg_Img = GenS16FromF32Image( avgImgF32 );

	res = avg_Img;

	//y = res->GetHeight() / 2;

	SobelBuilderRef sobelBuilder = new SobelBuilder(
		GenF32FromS16Image(avg_Img), 3);


	//nShift += nAprSiz / 2;


	dsp = GenU8FromS16Image(res);

	HCV_CALL(
		cvLine(
		dsp->GetIplImagePtr(),
		cvPoint(0, y - nShift),
		cvPoint(res->GetWidth() - 1, y - nShift),
		CV_RGB(0, 255, 0), 1)
		);


	ShowImage(dsp->GetIplImagePtr(), "avg_Img");
	//ShowImage(avg_Img, "avg_Img");
	HCV_CALL(cvvSaveImage("avg_Img.jpg",
		dsp->GetIplImagePtr()));



	sig = GenHorzLineFromImage(res, y - nShift);
	sig->m_nBgn = nShift;
	viewer->AddSignal(sig, u8ColorVal(0, 0, 255));

	//int nAprSizG1 = nAprSiz;
	//int nAprSizG1 = 1;
	int nAprSizG1 = 1;
	float gradScale = 5;
	//S16ImageRef gradImg = GenMorphGradImg( res, 1 );
	S16ImageRef gradImg = GenMorphGradImg(res, nAprSizG1);

	//S16ImageRef gradImg = GenS16FromF32Image(
	//GenMagImgF32( sobelBuilder->GenImageX( 1 ) ) );

	//gradImg = GenFastAvgImg( gradImg, 21);
	//nShift += 10;

	res = gradImg;

	dsp = GenU8FromS16Image(res);

	HCV_CALL(
		cvLine(
		dsp->GetIplImagePtr(),
		cvPoint(0, y - nShift),
		cvPoint(res->GetWidth() - 1, y - nShift),
		CV_RGB(0, 255, 0), 1)
		);


	//ShowImage(dsp->GetIplImagePtr(), "gradImg");
	ShowImage(gradImg, "gradImg");

	sig = GenHorzLineFromImage(gradImg, y - nShift);
	sig->m_nBgn = nShift;
	viewer->AddSignal(sig, u8ColorVal(0, 180, 0), gradScale);


	//res = GenFlattenedImg( avg_Img, gradImg, nAprSiz + 0 );
	//nShift += (nAprSiz + 0) / 2;
	//res = GenFastAvgImg( avg_Img, nAprSiz);
	//nShift += nAprSiz / 2;
	//res = GenWeightedColorMideanImg( avg_Img, gradImg, 3 );
	//nShift += 1;

	int nAprSizG2 = nAprSizG1;
	//int nAprSizG2 = 1;
	//int nAprSizG2 = nAprSizG1 * 2;
	S16ImageRef gradImg2 = GenMorphGradImg(gradImg, nAprSizG2);

	//S16ImageRef gradImg2 = GenS16FromF32Image(
	//GenMagImgF32( sobelBuilder->GenImageX( 2 ) ) );



	//gradImg2 = GenFastAvgImg( gradImg2, 3);
	//nShift += 1;

	//nShift += nAprSizG2 / 2;


	sig = GenHorzLineFromImage(gradImg2, y - nShift);
	sig->m_nBgn = nShift;
	viewer->AddSignal(sig, u8ColorVal(255, 255, 0), gradScale);

	/*{
		int nAprSizG3 = nAprSizG2;
		//int nAprSizG2 = 1;
		//int nAprSizG3 = nAprSizG2 * 2;
		S16ImageRef gradImg3 = GenMorphGradImg( gradImg2, nAprSizG3 );

		//S16ImageRef gradImg2 = GenS16FromF32Image(
		//GenMagImgF32( sobelBuilder->GenImageX( 2 ) ) );



		//gradImg2 = GenFastAvgImg( gradImg2, 3);
		//nShift += 1;

		//nShift += nAprSizG2 / 2;


		sig = GenHorzLineFromImage( gradImg3, y - nShift );
		sig->m_nBgn = nShift;
		viewer->AddSignal( sig, u8ColorVal(0, 255, 255), gradScale );

		//gradImg2 = gradImg3;
		}*/




	S16ImageRef gradImg2_F = gradImg2;
	//S16ImageRef gradImg2_F = GenCvMedianImg( gradImg2, 1 );
	//S16ImageRef gradImg2_F = GenCvErodeImg( gradImg2, 1 );


	sig = GenHorzLineFromImage(gradImg2_F, y - nShift);
	sig->m_nBgn = nShift;
	//viewer->AddSignal( sig, u8ColorVal(0, 0, 255), gradScale );


	//F32ImageRef weightImg = GenWeightImg2( gradImg, nAprSizG1 * 3 );
	//F32ImageRef weightImg = GenWeightImg4( gradImg, 3 );


	//F32ImageRef weightImg = GenWeightImg3( 
	//	avg_Img, gradImg, gradImg2, nAprSiz / 5 );



	S16ImageRef weightImgS16 = GenWeightImg4(gradImg, 3);


	weightImgS16 = GenPyrUpImg(weightImgS16, nPyrIterCnt);
	avg_Img = GenPyrUpImg(avg_Img, nPyrIterCnt);

	{
		dsp = GenU8FromS16Image(
			//GenBinImposedImg( avg_Img, weightImgS16 ) );
			weightImgS16);


		HCV_CALL(cvvSaveImage("WtBinImposedImg.jpg",
			dsp->GetIplImagePtr()));


		HCV_CALL(
			cvLine(
			dsp->GetIplImagePtr(),
			cvPoint(0, y - nShift),
			cvPoint(dsp->GetWidth() - 1, y - nShift),
			CV_RGB(255, 255, 255), 1)
			);

		ShowImage(dsp->GetIplImagePtr(), "weightImgS16");
	}


	/*

			S16ImageRef avgImg2 = avg_Img;
			//S16ImageRef avgImg2 = GenCvMedGausImg( avg_Img, 51);

			//dsp = GenU8FromS16Image(avgImg2);
			//ShowImage(dsp->GetIplImagePtr(), "avgImg2");

			{
			int nThrVal = 15;
			//int nThrVal = 20;
			//int nThrVal = 25;
			//int nThrVal = 45;
			//int nThrVal = 10;

			//RegionSegmentor10Ref rs2 = new RegionSegmentor10(avg_Img, weightImgS16, nThrVal);
			//	From 9, Conflicts are guided by Edge Roots.

			//RegionSegmentor11Ref rs2 = new RegionSegmentor11(avg_Img, weightImgS16, nThrVal);
			//	From 10, Conflicts are guided by Edge Roots.

			//RegionSegmentor12Ref rs2 = new RegionSegmentor12(avg_Img, weightImgS16, nThrVal);
			//	From 10, Conflicts are guided by Edge Roots.

			//RegionSegmentor13Ref rs2 = new RegionSegmentor13(avgImg2, weightImgS16, nThrVal, avg_Img);
			//RegionSegmentor13Ref rs2 = new RegionSegmentor13(avgImg2, weightImgS16, nThrVal, src);
			//RegionSegmentor13Ref rs2 = new RegionSegmentor13(avgImg2, weightImgS16, nThrVal);
			//	From 10, Conflicts are guided by Edge Roots.

			//RegionSegmentor14Ref rs2 = new RegionSegmentor14(avgImg2, weightImgS16, nThrVal, avg_Img);
			//RegionSegmentor14Ref rs2 = new RegionSegmentor14(avgImg2, weightImgS16, nThrVal, src);
			//	From 13, Conflicts are guided by Edge Roots.

			RegionSegmentor15Ref rs2 = new RegionSegmentor15(avgImg2, weightImgS16, nThrVal, avg_Img);
			//RegionSegmentor15Ref rs2 = new RegionSegmentor15(avgImg2, weightImgS16, nThrVal, src);
			//	From 13, Conflicts are guided by Edge Roots.

			rs2->Segment();
			S16ImageRef res2 = rs2->GenSegmentedImage();

			dsp = GenU8FromS16Image( res2 );

			ShowImage(dsp->GetIplImagePtr(), "RegionSegmentor");

			HCV_CALL( cvvSaveImage("RegionSegmentor.jpg",
			dsp->GetIplImagePtr()) );
			}
			*/



	sig = GenHorzLineFromImage(weightImgS16, y - nShift);
	sig->m_nBgn = nShift;
	viewer->AddSignal(sig, u8ColorVal(255, 0, 255), gradScale);

	//int nAprSizF = nAprSiz - 1;
	int nAprSizF = nAprSiz * 0.5;
	//res = GenFlattenedImg( avg_Img, gradImg2, nAprSizF );
	//res = GenFlattenedImg( avg_Img, weightImg, nAprSizF );	
	nShift += nAprSizF / 2;

	dsp = GenU8FromS16Image(res);

	HCV_CALL(
		cvLine(
		dsp->GetIplImagePtr(),
		cvPoint(0, y - nShift),
		cvPoint(res->GetWidth() - 1, y - nShift),
		CV_RGB(0, 255, 0), 1)
		);

	//ShowImage(dsp->GetIplImagePtr(), "FlattenedImg");
	//ShowImage(res, "FlattenedImg");



	sig = GenHorzLineFromImage(res, y - nShift);
	sig->m_nBgn = nShift;
	//viewer->AddSignal( sig, u8ColorVal(255, 255, 255) );



	//res = GenThresholdImg(res, 40);

	//	AdaptiveConv2Ref ac = AdaptiveConv2::CreateBlur(7);	
	//	res = ac->GenResult( avg_Img , gradImg );	





	dsp = viewer->GenDisplayImage();

	ShowImage(dsp, "Lines");

	HCV_CALL(cvvSaveImage("hcvResult.jpg",
		dsp->GetIplImagePtr()));
}













void ImageProcessor::SobelMax()
{
	S16ImageRef src = GenS16FromU8Image(img);
	S16ImageRef res = src;

	double dMin, dMax;

	//HCV_CALL( cvMinMaxLoc( res->GetIplImagePtr(), &dMin, &dMax) );

	//res = GenThresholdImg(res, 128);


	SobelBuilderRef sobelBuilder = new SobelBuilder(
		GenF32FromS16Image(res), 3);


	//S16ImageRef gradImg = GenS16FromF32Image(
	F32ImageRef gradImg = (
		GenMagImgF32(sobelBuilder->GenImageX(1)));



	HCV_CALL(cvMinMaxLoc(gradImg->GetIplImagePtr(), &dMin, &dMax));


}

void ImageProcessor::Try14()
{
	S16ImageRef src = GenS16FromU8Image(img);
	S16ImageRef res = src;

	const int nPyrIterCnt = 0;



	res = GenPyrDownImg(res, nPyrIterCnt);
	//res = GenDownSampledImage( res , 1 );

	int y = res->GetHeight() / 2;

	//int y = res->GetHeight() / 2 - 50;

	//int y = 110;

	SignalOneDimViewerRef viewer = new SignalOneDimViewer();

	SignalOneDimRef sig;

	U8ImageRef dsp;

	//res = GenTriChGrayImg( res );

	sig = GenHorzLineFromImage(res, y);
	viewer->AddSignal(sig);


	//res = GenImageFromHorzSignal(sig, res->GetHeight());


	int nShift = 0;



	dsp = GenU8FromS16Image(res);

	HCV_CALL(
		cvLine(
		dsp->GetIplImagePtr(),
		cvPoint(0, y - nShift),
		cvPoint(res->GetWidth() - 1, y - nShift),
		CV_RGB(0, 255, 0), 1)
		);


	ShowImage(dsp->GetIplImagePtr(), "Org Gray");

	//int nAprSiz = 81;
	//int nAprSiz = 41;
	int nAprSiz = 5;
	//int nAprSiz = 3;
	//int nAprSiz = 19;
	//S16ImageRef avg_Img = GenFastAvgImg( res, nAprSiz * 10 );
	//S16ImageRef avg_Img = GenFastAvgImg( res, nAprSiz);
	S16ImageRef avg_Img = GenCvSmoothedImg(res,
		(nAprSiz - 1) * 2 + 1);
	//S16ImageRef avg_Img = GenCvSmoothedImg( res, 80);
	//S16ImageRef avg_Img = res;


	//F32ImageRef avgImgF32 = GenF32FromS16Image( avg_Img );
	//avg_Img = GenS16FromF32Image( avgImgF32 );

	res = avg_Img;

	//y = res->GetHeight() / 2;

	SobelBuilderRef sobelBuilder = new SobelBuilder(
		GenF32FromS16Image(avg_Img), 3);


	//nShift += nAprSiz / 2;


	dsp = GenU8FromS16Image(res);

	HCV_CALL(
		cvLine(
		dsp->GetIplImagePtr(),
		cvPoint(0, y - nShift),
		cvPoint(res->GetWidth() - 1, y - nShift),
		CV_RGB(0, 255, 0), 1)
		);


	ShowImage(dsp->GetIplImagePtr(), "avg_Img");
	//ShowImage(avg_Img, "avg_Img");
	HCV_CALL(cvvSaveImage("avg_Img.jpg",
		dsp->GetIplImagePtr()));



	sig = GenHorzLineFromImage(res, y - nShift);
	sig->m_nBgn = nShift;
	viewer->AddSignal(sig, u8ColorVal(0, 0, 255));

	//int nAprSizG1 = nAprSiz;
	int nAprSizG1 = 1;
	float gradScale = 5;
	//S16ImageRef gradImg = GenMorphGradImg( res, 1 );
	S16ImageRef gradImg = GenMorphGradImg(res, nAprSizG1);

	//S16ImageRef gradImg = GenS16FromF32Image(
	//GenMagImgF32( sobelBuilder->GenImageX( 1 ) ) );

	//gradImg = GenFastAvgImg( gradImg, 21);
	//nShift += 10;

	res = gradImg;

	dsp = GenU8FromS16Image(res);

	HCV_CALL(
		cvLine(
		dsp->GetIplImagePtr(),
		cvPoint(0, y - nShift),
		cvPoint(res->GetWidth() - 1, y - nShift),
		CV_RGB(0, 255, 0), 1)
		);


	//ShowImage(dsp->GetIplImagePtr(), "gradImg");
	ShowImage(gradImg, "gradImg");

	sig = GenHorzLineFromImage(gradImg, y - nShift);
	sig->m_nBgn = nShift;
	viewer->AddSignal(sig, u8ColorVal(0, 180, 0), gradScale);


	//res = GenFlattenedImg( avg_Img, gradImg, nAprSiz + 0 );
	//nShift += (nAprSiz + 0) / 2;
	//res = GenFastAvgImg( avg_Img, nAprSiz);
	//nShift += nAprSiz / 2;
	//res = GenWeightedColorMideanImg( avg_Img, gradImg, 3 );
	//nShift += 1;

	int nAprSizG2 = nAprSizG1;
	//int nAprSizG2 = 1;
	//int nAprSizG2 = nAprSizG1 * 2;
	S16ImageRef gradImg2 = GenMorphGradImg(gradImg, nAprSizG2);

	//S16ImageRef gradImg2 = GenS16FromF32Image(
	//GenMagImgF32( sobelBuilder->GenImageX( 2 ) ) );



	//gradImg2 = GenFastAvgImg( gradImg2, 3);
	//nShift += 1;

	//nShift += nAprSizG2 / 2;


	sig = GenHorzLineFromImage(gradImg2, y - nShift);
	sig->m_nBgn = nShift;
	viewer->AddSignal(sig, u8ColorVal(255, 255, 0), gradScale);

	/*{
		int nAprSizG3 = nAprSizG2;
		//int nAprSizG2 = 1;
		//int nAprSizG3 = nAprSizG2 * 2;
		S16ImageRef gradImg3 = GenMorphGradImg( gradImg2, nAprSizG3 );

		//S16ImageRef gradImg2 = GenS16FromF32Image(
		//GenMagImgF32( sobelBuilder->GenImageX( 2 ) ) );



		//gradImg2 = GenFastAvgImg( gradImg2, 3);
		//nShift += 1;

		//nShift += nAprSizG2 / 2;


		sig = GenHorzLineFromImage( gradImg3, y - nShift );
		sig->m_nBgn = nShift;
		viewer->AddSignal( sig, u8ColorVal(0, 255, 255), gradScale );

		//gradImg2 = gradImg3;
		}*/




	S16ImageRef gradImg2_F = gradImg2;
	//S16ImageRef gradImg2_F = GenCvMedianImg( gradImg2, 1 );
	//S16ImageRef gradImg2_F = GenCvErodeImg( gradImg2, 1 );


	sig = GenHorzLineFromImage(gradImg2_F, y - nShift);
	sig->m_nBgn = nShift;
	//viewer->AddSignal( sig, u8ColorVal(0, 0, 255), gradScale );


	//F32ImageRef weightImg = GenWeightImg( gradImg, gradImg2 );
	//F32ImageRef weightImg = GenWeightImg2( gradImg, 8 );
	F32ImageRef weightImg = GenWeightImg2(gradImg, nAprSizG1 * 3);
	//F32ImageRef weightImg = GenWeightImg2( gradImg, nAprSizG1 * 5 );


	//F32ImageRef weightImg = GenWeightImg3( 
	//	avg_Img, gradImg, gradImg2, nAprSiz / 5 );



	S16ImageRef weightImgS16 = GenS16FromF32Image(weightImg);


	weightImgS16 = GenPyrUpImg(weightImgS16, nPyrIterCnt);
	avg_Img = GenPyrUpImg(avg_Img, nPyrIterCnt);

	{
		dsp = GenU8FromS16Image(
			GenBinImposedImg(avg_Img, weightImgS16));
		//weightImgS16 );


		HCV_CALL(cvvSaveImage("WtBinImposedImg.jpg",
			dsp->GetIplImagePtr()));


		HCV_CALL(
			cvLine(
			dsp->GetIplImagePtr(),
			cvPoint(0, y - nShift),
			cvPoint(dsp->GetWidth() - 1, y - nShift),
			CV_RGB(255, 255, 255), 1)
			);

		ShowImage(dsp->GetIplImagePtr(), "weightImgS16");
	}




	S16ImageRef avgImg2 = avg_Img;
	//S16ImageRef avgImg2 = GenCvMedGausImg( avg_Img, 51);

	//dsp = GenU8FromS16Image(avgImg2);
	//ShowImage(dsp->GetIplImagePtr(), "avgImg2");

	{
		//int nThrVal = 15;
		//int nThrVal = 20; 
		int nThrVal = 25;
		//int nThrVal = 30;
		//int nThrVal = 45;
		//int nThrVal = 10;

		//RegionSegmentor10Ref rs2 = new RegionSegmentor10(avg_Img, weightImgS16, nThrVal);	
		//	From 9, Conflicts are guided by Edge Roots.

		//RegionSegmentor11Ref rs2 = new RegionSegmentor11(avg_Img, weightImgS16, nThrVal);	
		//	From 10, Conflicts are guided by Edge Roots.

		//RegionSegmentor12Ref rs2 = new RegionSegmentor12(avg_Img, weightImgS16, nThrVal);	
		//	From 10, Conflicts are guided by Edge Roots.

		//RegionSegmentor13Ref rs2 = new RegionSegmentor13(avgImg2, weightImgS16, nThrVal, avg_Img);	
		//RegionSegmentor13Ref rs2 = new RegionSegmentor13(avgImg2, weightImgS16, nThrVal, src);	
		//RegionSegmentor13Ref rs2 = new RegionSegmentor13(avgImg2, weightImgS16, nThrVal);	
		//	From 10, Conflicts are guided by Edge Roots.

		//RegionSegmentor14Ref rs2 = new RegionSegmentor14(avgImg2, weightImgS16, nThrVal, avg_Img);	
		//RegionSegmentor14Ref rs2 = new RegionSegmentor14(avgImg2, weightImgS16, nThrVal, src);	
		//	From 13, Conflicts are guided by Edge Roots.

		RegionSegmentor15Ref rs2 = new RegionSegmentor15(avgImg2, weightImgS16, nThrVal, avg_Img);
		//RegionSegmentor15Ref rs2 = new RegionSegmentor15(avgImg2, weightImgS16, nThrVal, src);	
		//	From 13, Conflicts are guided by Edge Roots.

		rs2->Segment();
		S16ImageRef res2 = rs2->GenSegmentedImage();

		dsp = GenU8FromS16Image(res2);

		ShowImage(dsp->GetIplImagePtr(), "RegionSegmentor");

		HCV_CALL(cvvSaveImage("RegionSegmentor.jpg",
			dsp->GetIplImagePtr()));
	}




	sig = GenHorzLineFromImage(weightImgS16, y - nShift);
	sig->m_nBgn = nShift;
	viewer->AddSignal(sig, u8ColorVal(255, 0, 255), gradScale);

	//int nAprSizF = nAprSiz - 1;
	int nAprSizF = nAprSiz * 0.5;
	//res = GenFlattenedImg( avg_Img, gradImg2, nAprSizF );
	//res = GenFlattenedImg( avg_Img, weightImg, nAprSizF );	
	nShift += nAprSizF / 2;

	dsp = GenU8FromS16Image(res);

	HCV_CALL(
		cvLine(
		dsp->GetIplImagePtr(),
		cvPoint(0, y - nShift),
		cvPoint(res->GetWidth() - 1, y - nShift),
		CV_RGB(0, 255, 0), 1)
		);

	//ShowImage(dsp->GetIplImagePtr(), "FlattenedImg");
	//ShowImage(res, "FlattenedImg");



	sig = GenHorzLineFromImage(res, y - nShift);
	sig->m_nBgn = nShift;
	//viewer->AddSignal( sig, u8ColorVal(255, 255, 255) );



	//res = GenThresholdImg(res, 40);

	//	AdaptiveConv2Ref ac = AdaptiveConv2::CreateBlur(7);	
	//	res = ac->GenResult( avg_Img , gradImg );	





	dsp = viewer->GenDisplayImage();

	ShowImage(dsp, "Lines");

	HCV_CALL(cvvSaveImage("hcvResult.jpg",
		dsp->GetIplImagePtr()));
}










void ImageProcessor::Try13()
{
	S16ImageRef src = GenS16FromU8Image(img);
	S16ImageRef res = src;

	int y = res->GetHeight() / 2;

	//int y = 110;

	SignalOneDimViewerRef viewer = new SignalOneDimViewer();

	SignalOneDimRef sig;

	U8ImageRef dsp;

	//res = GenTriChGrayImg( res );

	sig = GenHorzLineFromImage(res, y);
	viewer->AddSignal(sig);


	//res = GenImageFromHorzSignal(sig, res->GetHeight());


	int nShift = 0;



	dsp = GenU8FromS16Image(res);

	HCV_CALL(
		cvLine(
		dsp->GetIplImagePtr(),
		cvPoint(0, y - nShift),
		cvPoint(res->GetWidth() - 1, y - nShift),
		CV_RGB(0, 255, 0), 1)
		);


	ShowImage(dsp->GetIplImagePtr(), "Org Gray");

	int nAprSiz = 81;
	//int nAprSiz = 5;
	//S16ImageRef avg_Img = GenFastAvgImg( res, nAprSiz * 10 );
	//S16ImageRef avg_Img = GenFastAvgImg( res, nAprSiz);
	S16ImageRef avg_Img = GenCvSmoothedImg(res, nAprSiz);
	res = avg_Img;

	//nShift += nAprSiz / 2;


	dsp = GenU8FromS16Image(res);

	HCV_CALL(
		cvLine(
		dsp->GetIplImagePtr(),
		cvPoint(0, y - nShift),
		cvPoint(res->GetWidth() - 1, y - nShift),
		CV_RGB(0, 255, 0), 1)
		);


	ShowImage(dsp->GetIplImagePtr(), "avg_Img");
	//ShowImage(avg_Img, "avg_Img");




	sig = GenHorzLineFromImage(res, y - nShift);
	sig->m_nBgn = nShift;
	viewer->AddSignal(sig, u8ColorVal(0, 0, 255));

	//int nAprSizG1 = nAprSiz;
	int nAprSizG1 = 1;
	float gradScale = 1;
	//S16ImageRef gradImg = GenMorphGradImg( res, 1 );
	S16ImageRef gradImg = GenMorphGradImg(res, nAprSizG1);

	//gradImg = GenFastAvgImg( gradImg, 21);
	//nShift += 10;

	res = gradImg;

	dsp = GenU8FromS16Image(res);

	HCV_CALL(
		cvLine(
		dsp->GetIplImagePtr(),
		cvPoint(0, y - nShift),
		cvPoint(res->GetWidth() - 1, y - nShift),
		CV_RGB(0, 255, 0), 1)
		);


	ShowImage(dsp->GetIplImagePtr(), "gradImg");
	//ShowImage(gradImg, "gradImg");

	sig = GenHorzLineFromImage(gradImg, y - nShift);
	sig->m_nBgn = nShift;
	viewer->AddSignal(sig, u8ColorVal(0, 180, 0), gradScale);


	//res = GenFlattenedImg( avg_Img, gradImg, nAprSiz + 0 );
	//nShift += (nAprSiz + 0) / 2;
	//res = GenFastAvgImg( avg_Img, nAprSiz);
	//nShift += nAprSiz / 2;
	//res = GenWeightedColorMideanImg( avg_Img, gradImg, 3 );
	//nShift += 1;

	//int nAprSizG2 = nAprSizG1;
	//int nAprSizG2 = 1;
	int nAprSizG2 = 3;
	//int nAprSizG2 = nAprSizG1 * 2;
	//S16ImageRef gradImg2 = GenMorphGradImg( gradImg, nAprSizG2 );
	//S16ImageRef gradImg2 = GenCvLaplaceImg( avg_Img, 7 );
	S16ImageRef gradImg2 = GenCvSobelImg(avg_Img, 0, 1, 7);

	//gradImg2 = GenFastAvgImg( gradImg2, 3);
	//nShift += 1;

	//nShift += nAprSizG2 / 2;

	{
		gradImg2 = GenImageFromChannel(gradImg2, 0);

		double dMin, dMax;

		HCV_CALL(cvMinMaxLoc(gradImg2->GetIplImagePtr(), &dMin, &dMax));

		if (dMin < 0 || dMax > 255)
		{
			double scale = (250 / (dMax - dMin));
			double shift = -dMin * scale;

			HCV_CALL(cvConvertScale(gradImg2->GetIplImagePtr(),
				gradImg2->GetIplImagePtr(), scale, shift));
		}

		HCV_CALL(cvMinMaxLoc(gradImg2->GetIplImagePtr(), &dMin, &dMax));

		dMin = dMin;

	}


	sig = GenHorzLineFromImage(gradImg2, y - nShift);
	sig->m_nBgn = nShift;
	viewer->AddSignal(sig, u8ColorVal(255, 255, 0), gradScale);


	/*
		//int nAprSizF = nAprSiz - 1;
		int nAprSizF = nAprSiz;
		res = GenFlattenedImg( avg_Img, gradImg2, nAprSizF );
		nShift += (nAprSiz + 0) / 2;

		dsp = GenU8FromS16Image(res);

		HCV_CALL(
		cvLine (
		dsp->GetIplImagePtr(),
		cvPoint( 0, y - nShift ),
		cvPoint( res->GetWidth() - 1, y - nShift ),
		CV_RGB( 0, 255, 0 ), 1 )
		);

		ShowImage(dsp->GetIplImagePtr(), "FlattenedImg");
		//ShowImage(res, "FlattenedImg");



		sig = GenHorzLineFromImage( res, y - nShift );
		sig->m_nBgn = nShift;
		viewer->AddSignal( sig, u8ColorVal(255, 255, 255) );
		*/


	//res = GenThresholdImg(res, 40);

	//	AdaptiveConv2Ref ac = AdaptiveConv2::CreateBlur(7);	
	//	res = ac->GenResult( avg_Img , gradImg );	





	dsp = viewer->GenDisplayImage();

	ShowImage(dsp, "Lines");

	HCV_CALL(cvvSaveImage("hcvResult.jpg",
		dsp->GetIplImagePtr()));
}






void ImageProcessor::Try12()
{
	S16ImageRef src = GenS16FromU8Image(img);
	S16ImageRef res = src;

	int y = res->GetHeight() / 2;

	//int y = 110;

	SignalOneDimViewerRef viewer = new SignalOneDimViewer();

	SignalOneDimRef sig;

	U8ImageRef dsp;

	//res = GenTriChGrayImg( res );

	sig = GenHorzLineFromImage(res, y);
	viewer->AddSignal(sig);


	//res = GenImageFromHorzSignal(sig, res->GetHeight());


	int nShift = 0;



	dsp = GenU8FromS16Image(res);

	HCV_CALL(
		cvLine(
		dsp->GetIplImagePtr(),
		cvPoint(0, y - nShift),
		cvPoint(res->GetWidth() - 1, y - nShift),
		CV_RGB(0, 255, 0), 1)
		);


	ShowImage(dsp->GetIplImagePtr(), "Org Gray");

	int nAprSiz = 81;
	//int nAprSiz = 21;
	//S16ImageRef avg_Img = GenFastAvgImg( res, nAprSiz * 10 );
	//S16ImageRef avg_Img = GenFastAvgImg( res, nAprSiz);
	S16ImageRef avg_Img = GenCvSmoothedImg(res, nAprSiz);
	res = avg_Img;

	//nShift += nAprSiz / 2;


	dsp = GenU8FromS16Image(res);

	HCV_CALL(
		cvLine(
		dsp->GetIplImagePtr(),
		cvPoint(0, y - nShift),
		cvPoint(res->GetWidth() - 1, y - nShift),
		CV_RGB(0, 255, 0), 1)
		);


	ShowImage(dsp->GetIplImagePtr(), "avg_Img");
	//ShowImage(avg_Img, "avg_Img");




	sig = GenHorzLineFromImage(res, y - nShift);
	sig->m_nBgn = nShift;
	viewer->AddSignal(sig, u8ColorVal(0, 0, 255));

	//int nAprSizG1 = nAprSiz;
	int nAprSizG1 = 1;
	float gradScale = 15;
	//S16ImageRef gradImg = GenMorphGradImg( res, 1 );
	S16ImageRef gradImg = GenMorphGradImg(res, nAprSizG1);

	//gradImg = GenFastAvgImg( gradImg, 21);
	//nShift += 10;

	res = gradImg;

	dsp = GenU8FromS16Image(res);

	HCV_CALL(
		cvLine(
		dsp->GetIplImagePtr(),
		cvPoint(0, y - nShift),
		cvPoint(res->GetWidth() - 1, y - nShift),
		CV_RGB(0, 255, 0), 1)
		);


	ShowImage(dsp->GetIplImagePtr(), "gradImg");
	//ShowImage(gradImg, "gradImg");

	sig = GenHorzLineFromImage(gradImg, y - nShift);
	sig->m_nBgn = nShift;
	viewer->AddSignal(sig, u8ColorVal(0, 180, 0), gradScale);


	//res = GenFlattenedImg( avg_Img, gradImg, nAprSiz + 0 );
	//nShift += (nAprSiz + 0) / 2;
	//res = GenFastAvgImg( avg_Img, nAprSiz);
	//nShift += nAprSiz / 2;
	//res = GenWeightedColorMideanImg( avg_Img, gradImg, 3 );
	//nShift += 1;

	int nAprSizG2 = nAprSizG1;
	//int nAprSizG2 = 1;
	//int nAprSizG2 = nAprSizG1 * 2;
	S16ImageRef gradImg2 = GenMorphGradImg(gradImg, nAprSizG2);

	//gradImg2 = GenFastAvgImg( gradImg2, 3);
	//nShift += 1;

	//nShift += nAprSizG2 / 2;


	sig = GenHorzLineFromImage(gradImg2, y - nShift);
	sig->m_nBgn = nShift;
	viewer->AddSignal(sig, u8ColorVal(255, 255, 0), gradScale);

	S16ImageRef gradImg2_F = gradImg2;
	//S16ImageRef gradImg2_F = GenCvMedianImg( gradImg2, 1 );
	//S16ImageRef gradImg2_F = GenCvErodeImg( gradImg2, 1 );


	sig = GenHorzLineFromImage(gradImg2_F, y - nShift);
	sig->m_nBgn = nShift;
	//viewer->AddSignal( sig, u8ColorVal(0, 0, 255), gradScale );


	F32ImageRef weightImg = GenWeightImg(gradImg, gradImg2);

	S16ImageRef weightImgS16 = GenS16FromF32Image(weightImg);

	sig = GenHorzLineFromImage(weightImgS16, y - nShift);
	sig->m_nBgn = nShift;
	viewer->AddSignal(sig, u8ColorVal(255, 0, 255), gradScale);

	//int nAprSizF = nAprSiz - 1;
	int nAprSizF = nAprSiz * 0.5;
	//res = GenFlattenedImg( avg_Img, gradImg2, nAprSizF );
	res = GenFlattenedImg(avg_Img, weightImg, nAprSizF);
	nShift += nAprSizF / 2;

	dsp = GenU8FromS16Image(res);

	HCV_CALL(
		cvLine(
		dsp->GetIplImagePtr(),
		cvPoint(0, y - nShift),
		cvPoint(res->GetWidth() - 1, y - nShift),
		CV_RGB(0, 255, 0), 1)
		);

	ShowImage(dsp->GetIplImagePtr(), "FlattenedImg");
	//ShowImage(res, "FlattenedImg");



	sig = GenHorzLineFromImage(res, y - nShift);
	sig->m_nBgn = nShift;
	viewer->AddSignal(sig, u8ColorVal(255, 255, 255));



	//res = GenThresholdImg(res, 40);

	//	AdaptiveConv2Ref ac = AdaptiveConv2::CreateBlur(7);	
	//	res = ac->GenResult( avg_Img , gradImg );	





	dsp = viewer->GenDisplayImage();

	ShowImage(dsp, "Lines");

	HCV_CALL(cvvSaveImage("hcvResult.jpg",
		dsp->GetIplImagePtr()));
}






void ImageProcessor::Try11()
{
	S16ImageRef src = GenS16FromU8Image(img);
	S16ImageRef res = src;

	int y = res->GetHeight() / 2;


	SignalOneDimViewerRef viewer = new SignalOneDimViewer();

	SignalOneDimRef sig;

	U8ImageRef dsp;

	res = GenTriChGrayImg(res);

	sig = GenHorzLineFromImage(res, y);
	viewer->AddSignal(sig);


	res = GenImageFromHorzSignal(sig, res->GetHeight());


	int nShift = 0;

	dsp = GenU8FromS16Image(res);

	ShowImage(dsp->GetIplImagePtr(), "Org Gray");

	int nAprSiz = 80;
	//S16ImageRef avg_Img = GenFastAvgImg( res, nAprSiz * 10 );
	S16ImageRef avg_Img = GenFastAvgImg(res, nAprSiz);
	res = avg_Img;

	nShift += nAprSiz / 2;

	ShowImage(avg_Img, "avg_Img");




	sig = GenHorzLineFromImage(res, y - nShift);
	sig->m_nBgn = nShift;
	viewer->AddSignal(sig, u8ColorVal(0, 0, 255));

	//int nAprSizG1 = nAprSiz;
	int nAprSizG1 = 1;
	//S16ImageRef gradImg = GenMorphGradImg( res, 1 );
	S16ImageRef gradImg = GenMorphGradImg(res, nAprSizG1);
	res = gradImg;

	//nShift += nAprSizG1 / 2;

	ShowImage(gradImg, "gradImg");

	sig = GenHorzLineFromImage(gradImg, y - nShift);
	sig->m_nBgn = nShift;
	viewer->AddSignal(sig, u8ColorVal(0, 180, 0));


	//res = GenFlattenedImg( avg_Img, gradImg, nAprSiz + 0 );
	//nShift += (nAprSiz + 0) / 2;
	//res = GenFastAvgImg( avg_Img, nAprSiz);
	//nShift += nAprSiz / 2;
	//res = GenWeightedColorMideanImg( avg_Img, gradImg, 3 );
	//nShift += 1;

	int nAprSizG2 = nAprSizG1;
	S16ImageRef gradImg2 = GenMorphGradImg(gradImg, nAprSizG2);

	//nShift += nAprSizG2 / 2;


	sig = GenHorzLineFromImage(gradImg2, y - nShift);
	sig->m_nBgn = nShift;
	viewer->AddSignal(sig, u8ColorVal(255, 255, 0));

	F32ImageRef weightImg = GenWeightImg(gradImg, gradImg2);

	//int nAprSizF = nAprSiz - 1;
	int nAprSizF = nAprSiz;
	res = GenFlattenedImg(avg_Img, weightImg, nAprSizF);
	nShift += (nAprSiz + 0) / 2;
	ShowImage(res, "FlattenedImg");

	sig = GenHorzLineFromImage(res, y - nShift);
	sig->m_nBgn = nShift;
	viewer->AddSignal(sig, u8ColorVal(255, 255, 255));


	//res = GenThresholdImg(res, 40);

	//	AdaptiveConv2Ref ac = AdaptiveConv2::CreateBlur(7);	
	//	res = ac->GenResult( avg_Img , gradImg );	





	dsp = viewer->GenDisplayImage();

	ShowImage(dsp, "Lines");

	HCV_CALL(cvvSaveImage("hcvResult.jpg",
		dsp->GetIplImagePtr()));
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

void ImageProcessor::Try10()
{
	int j = 1;

	//cvErode( img->GetIplImagePtr(), 
	//	img->GetIplImagePtr(), 0, j );

	//cvDilate( img->GetIplImagePtr(), 
	//	img->GetIplImagePtr(), 0, j );

	S16ImageRef src = GenS16FromU8Image(img);
	S16ImageRef res = src;



	U8ImageRef dsp;

	bool bColorDsp = false;

	//res = GenPyrDownImg(res);
	//res = GenPyrDownImg(res);
	//res = GenDownSampledImage( res, 4 );

	//res = GenColorMideanImg( res );

	dsp = GenU8FromS16Image(res);

	HCV_CALL(cvvSaveImage("hcvResult3.jpg",
		dsp->GetIplImagePtr()));

	AdaptiveConvRef ac = AdaptiveConv::CreateBlur(5);
	//ConvKernelRef ac = ConvKernel::CreateBlur(7);

	//res = ac->GenResult(res);	
	res = GenFastAvgImg(res, 5);
	dsp = GenU8FromS16Image(res);
	ShowImage(dsp->GetIplImagePtr(), "Smoothed Image");

	//int nThrVal = 25;
	int nThrVal = 40;
	//int nThrVal = 15;
	//int nThrVal = 10;

	//nThrVal = nThrVal * 441 / 255;

	//RegionSegmentor2Ref rs2 = new RegionSegmentor2(res, nThrVal);	
	//	Conflicts

	//RegionSegmentor3Ref rs2 = new RegionSegmentor3(res, nThrVal);	
	//	CalcRgnMeanDif

	//RegionSegmentor4Ref rs2 = new RegionSegmentor4(res, nThrVal);
	//	CalcColorDif( pActRgn1->colorMean,

	//RegionSegmentor5Ref rs2 = new RegionSegmentor5(res, nThrVal);
	//	GetLocalMeanColor

	//RegionSegmentor6Ref rs2 = new RegionSegmentor6(res, nThrVal);
	//	PrepareFarConflicts

	//RegionSegmentor7Ref rs2 = new RegionSegmentor7(res, nThrVal);

	//RegionSegmentor8Ref rs2 = new RegionSegmentor8(res, nThrVal);
	//	PreMerge

	RegionSegmentor9Ref rs2 = new RegionSegmentor9(res, nThrVal);
	//	From 2, Link Conflicted first.

	//RegionSegmentor10Ref rs2 = new RegionSegmentor10(res, NULL, nThrVal);	
	//RegionSegmentor10Ref rs2 = new RegionSegmentor10(res, nThrVal);	
	//	From 9, Conflicts are guided by Edge Roots.

	rs2->Segment();

	//res = rs2->GenDifImg(1, 0, 0, 0, nThrVal); bColorDsp = true;
	//res = rs2->GenDifImg(1, 1, 1, 1); //bColorDsp = true;
	res = rs2->GenSegmentedImage();

	dsp = GenU8FromS16Image(res);

	//if(bColorDsp) 
	//	dsp = GenColorDsp(dsp);

	ShowImage(dsp->GetIplImagePtr(), "Result");

	HCV_CALL(cvvSaveImage("hcvResult.jpg",
		dsp->GetIplImagePtr()));

	res = rs2->GenDifImg(1, 1, 1, 1); //bColorDsp = true;

	dsp = GenU8FromS16Image(res);

	ShowImage(dsp->GetIplImagePtr(), "Result Edges");

	HCV_CALL(cvvSaveImage("hcvResult2.jpg",
		dsp->GetIplImagePtr()));

	res = rs2->GenConflictImg(1, 1, 1, 1); //bColorDsp = true;

	dsp = GenU8FromS16Image(res);

	//	ShowImage(dsp->GetIplImagePtr(), "Conflicts");

	//dsp = hist->GenDspImage();
	//ShowImage(dsp->GetIplImagePtr(), "Histogram");
}

void ImageProcessor::Try9()
{
	S16ImageRef src = GenS16FromU8Image(img);
	S16ImageRef res = src;

	AdaptiveConvRef ac = AdaptiveConv::CreateBlur(3);
	res = ac->GenResult(res);

	ImageClusteringMgr icm;

	icm.Process(res);

	//res = icm.GenResultImage();
	res = icm.GenRgnImage();
	//res = icm.GenMaxRgnImage();

	U8ImageRef dsp = GenU8FromS16Image(res);

	ShowImage(dsp->GetIplImagePtr(), "Result");

	HCV_CALL(cvvSaveImage("hcvResult.jpg",
		dsp->GetIplImagePtr()));
}

void ImageProcessor::Try8()
{
	S16ImageRef src = GenS16FromU8Image(img);
	S16ImageRef res = src;

	bool bColorDsp = false;

	//res = GenPyrDownImg(res);
	//res = GenPyrDownImg(res);

	//AdaptiveConvRef ac = AdaptiveConv::CreateBlur(5, 1);
	//ConvKernelRef ac = ConvKernel::CreateBlur(5, 3);
	AdaptiveConvRef ac = AdaptiveConv::CreateBlur(3);


	//res = ac->GenResult(res);
	res = GenFastAvgImg(res, 5);

	RegionSegmentorRef rs = new RegionSegmentor(res, 0.0);

	int nThrVal = 40;

	//res = rs->GenDifImg(1, 1, 1, 1, nThrVal); //bColorDsp = true;
	//res = rs->GenDifImg(1, 1, 1, 1, 0, 0); //bColorDsp = true;
	res = rs->GenDifImg(1, 1, 1, 1, 0, 1); //bColorDsp = true;
	//res = rs->GenDifImg(1, 1, 1, 1, 0, 30); //bColorDsp = true;
	//res = rs->GenDifImg(1, 1, 1, 1, 0); //bColorDsp = true;
	//res = rs->GenDifImg(1, 1, 1, 1, 2); //bColorDsp = true;

	//HCV_CALL( cvThreshold (res->GetIplImagePtr(),
	//	res->GetIplImagePtr(), 20, 255, CV_THRESH_BINARY) );

	////res = GenThresholdImg(res, 1);
	//res = GenHDensityImg(res);

	U8ImageRef dsp = GenU8FromS16Image(res);

	//dsp = GenScaledImage(dsp);

	//if(bColorDsp) 
	//	dsp = GenColorDsp(dsp);

	ShowImage(dsp->GetIplImagePtr(), "Result");

	HCV_CALL(cvvSaveImage("hcvResult.jpg",
		dsp->GetIplImagePtr()));

	//dsp = hist->GenDspImage();
	//ShowImage(dsp->GetIplImagePtr(), "Histogram");
}




void ImageProcessor::Clusters()
{
	S16ImageRef src = GenS16FromU8Image(img);
	S16ImageRef res = src;

	const int nDataVal = 0;
	const int nBkgVal = 255;

	res = GenThresholdImg(res, 130);

	std::vector<CvPoint> dataPts = GenDataPoints(res, nDataVal);
	//std::vector<CvPoint> resDataPts(dataPts.size());
	std::vector<CvPoint> resDataPts = dataPts;

	int nSiz = dataPts.size();

	//std::vector<int> dataPtCnts(dataPts.size());

	S16ImageRef res2 = S16Image::Create(src->GetSize(), src->GetNofChannels());
	res2->SetAll(255);

	//	for(int i=0; i<1; i++)
	//	{

	DoClusteringStep16(&dataPts, &resDataPts, res, res2,
		(std::vector< Pattern< int, 2 > > *) &dataPts);

	dataPts = resDataPts;
	//	}

	//DrawPoints(resDataPts, res2,  CV_RGB(50, 100, 200));

	U8ImageRef dsp;

	dsp = GenU8FromS16Image(res);
	ShowImage(dsp->GetIplImagePtr(), "Original Image");
	//ShowImage(dsp->GetIplImagePtr(), "Result");

	HCV_CALL(cvvSaveImage("hcvResult.jpg",
		dsp->GetIplImagePtr()));

	dsp = GenU8FromS16Image(res2);
	ShowImage(dsp->GetIplImagePtr(), "Result");

	HCV_CALL(cvvSaveImage("hcvResult2.jpg",
		dsp->GetIplImagePtr()));
}

void ImageProcessor::Try7()
{
	S16ImageRef src = GenS16FromU8Image(img);
	S16ImageRef res = src;

	bool bColorDsp = false;

	//res = GenPyrDownImg(res);
	//res = GenPyrDownImg(res);

	AdaptiveConvRef ac = AdaptiveConv::CreateBlur(5, 0);
	//ConvKernelRef ac = ConvKernel::CreateBlur(5, 3);


	res = ac->GenResult(res);

	RegionSegmentorRef rs = new RegionSegmentor(res, 0.0);

	//res = rs->GenDifImg(1, 0, 0, 0, 20); bColorDsp = true;
	res = rs->GenDifImg(1, 1, 1, 1, 15); bColorDsp = true;

	//rs->Segment(3);

	//res = rs->GenSegmentedImage();

	U8ImageRef dsp = GenU8FromS16Image(res);

	if (bColorDsp)
		dsp = GenColorDsp(dsp);

	ShowImage(dsp->GetIplImagePtr(), "Result");

	HCV_CALL(cvvSaveImage("hcvResult.jpg",
		dsp->GetIplImagePtr()));

	//dsp = hist->GenDspImage();
	//ShowImage(dsp->GetIplImagePtr(), "Histogram");
}

void ImageProcessor::Try6()
{
	S16ImageRef src = GenS16FromU8Image(img);

	HCV_CALL(cvvSaveImage("result6.jpg",
		img->GetIplImagePtr()));

	//src = ConvKernel::CreateBlur(3)->GenResult(src);

	S16ImageRef res = src;

	RegionSegmentorRef rs = new RegionSegmentor(src, 0.0);


	//double dMin, dMax;
	//HCV_CALL( cvMinMaxLoc( res->GetIplImagePtr(), &dMin, &dMax) );

	//rs->Segment(15);

	bool bColorDsp = false;

	//res = rs->GenDifImg(1, 0, 0, 0);
	res = rs->GenDifImg(1, 1, 1, 1, 0); bColorDsp = true;
	//res = rs->GenSegmentedImage();

	//HCV_CALL( cvMinMaxLoc( res->GetIplImagePtr(), &dMin, &dMax) );

	U8ImageRef dsp = GenU8FromS16Image(res);

	//HCV_CALL( cvvSaveImage("result6.jpg", 
	//	dsp->GetIplImagePtr()) );

	//	HistoGramRef hist = new HistoGram();
	//	CalcHisto(dsp->GetAt(0), (Uint8)0, hist);

	HistoGramRef hist = rs->GenDifHisto(1, 1, 1, 1);

	//dsp = GenScaledImage(dsp);
	//dsp = GenNegativeImage(dsp);

	if (bColorDsp)
		dsp = GenColorDsp(dsp);

	ShowImage(dsp->GetIplImagePtr(), "Result");

	//	HCV_CALL( cvvSaveImage("c:\\resDsp.jpg", 
	//		dsp->GetIplImagePtr()) );

	dsp = hist->GenDspImage();
	ShowImage(dsp->GetIplImagePtr(), "Histogram");
}



void ImageProcessor::Try5()
{
	S16ImageRef src = GenS16FromU8Image(img);

	S16ImageRef res;

	//res = GenDownSampledImage(src, 2);
	res = src;

	res = GenColorSobelGradImage(res, 3);

	res = GenMinimaImage(res);
	//res = GenMaximaImage(res);

	U8ImageRef dsp = GenU8FromS16Image(res);

	dsp = GenScaledImage(dsp);
	dsp = GenNegativeImage(dsp);
	dsp = GenColorDsp(dsp);

	ShowImage(dsp->GetIplImagePtr(), "Result");

	HCV_CALL(cvvSaveImage("c:\\resDsp.jpg",
		dsp->GetIplImagePtr()));

	HistoGramRef hist = new HistoGram();
	CalcHisto(res->GetAt(0), (Int16)0, hist);

	dsp = hist->GenDspImage();
	ShowImage(dsp->GetIplImagePtr(), "Histogram");
}

void ImageProcessor::Try4()
{
	S16ImageRef src = GenS16FromU8Image(img);

	//src = GenDownSampledImage(src, 2);

	//S16ImageRef src0 = S16Image::Create(
	//	cvGetSize(src->GetIplImagePtr()), src->GetNofChannels());

	//GetColorMidean(src, src0);
	//src = src0;

	int nAprSiz = 3;

	// X

	ConvKernelRef sblKer = ConvKernel::CreateSobel(1, 0, nAprSiz);

	S16ImageRef resX = S16Image::Create(
		src->GetSize(), src->GetNofChannels());

	sblKer->Process(src, resX);

	// Y

	sblKer = ConvKernel::CreateSobel(0, 1, nAprSiz);

	S16ImageRef resY = S16Image::Create(
		src->GetSize(), src->GetNofChannels());

	sblKer->Process(src, resY);

	//	XY

	S16ImageRef res = S16Image::Create(
		src->GetSize(), 1);

	CalcColorSblXY(resX, resY, res);

	U8ImageRef dsp = U8Image::Create(
		res->GetSize(), res->GetNofChannels());

	HCV_CALL(cvConvertScale(res->GetIplImagePtr(),
		//dsp->GetIplImagePtr(), 0.45, 128) );
		dsp->GetIplImagePtr()));

	cvNamedWindow("3.Sobel", 1);
	cvShowImage("3.Sobel",
		GenColorDsp(GenScaledImage(dsp))->GetIplImagePtr());
	//GenColorDsp( (dsp) )->GetIplImagePtr() );
	//( GenScaledImage(dsp) )->GetIplImagePtr() );

	HistoGramRef hist = new HistoGram();
	CalcHisto(res->GetAt(0), (Int16)0, hist);
	//CalcHisto(GenScaledImage(dsp)->GetAt(0), (Uint8)0, hist);
	//CalcHisto(dsp->GetAt(0), (Uint8)0, hist);

	dsp = hist->GenDspImage();

	ShowImage(dsp->GetIplImagePtr(), "Histogram");

	S16ImageRef nbrImg = GenScaledS16FromS32Image(
		GenNeighbourhoodImage(res));

	nbrImg = GenUpSampledImage(nbrImg, 20);

	dsp = GenU8FromS16Image(nbrImg);

	//dsp = GenScaledImage(dsp);
	//dsp = GenNegativeImage(dsp);
	dsp = GenColorDsp(dsp);

	ShowImage(dsp->GetIplImagePtr(), "Neighbourhood");
}

void ImageProcessor::Try3()
{
	S16ImageRef src = S16Image::Create(
		cvGetSize(img->GetIplImagePtr()), img->GetNofChannels());

	HCV_CALL(cvConvertScale(img->GetIplImagePtr(),
		src->GetIplImagePtr()));


	int nAprSiz = 3;

	// X

	ConvKernelRef sblKer = ConvKernel::CreateSobel(1, 0, nAprSiz);

	ConvKernelRef sblKerP = sblKer->CreatePositiveInst();
	ConvKernelRef sblKerAN = sblKer->CreateAbsNegativeInst();

	CvSize resSiz = cvGetSize(img->GetIplImagePtr());
	//resSiz.width -= nAprSiz - 1;
	//resSiz.height -= nAprSiz - 1;

	S16ImageRef resP = S16Image::Create(
		resSiz, src->GetNofChannels());

	sblKerP->Process(src, resP);

	S16ImageRef resAN = S16Image::Create(
		resSiz, src->GetNofChannels());

	sblKerAN->Process(src, resAN);

	S16ImageRef resX = S16Image::Create(
		resSiz, src->GetNofChannels());

	Hsv::CalcHsvDiff(resP, resAN, resX);

	// Y

	sblKer = ConvKernel::CreateSobel(0, 1, nAprSiz);

	sblKerP = sblKer->CreatePositiveInst();
	sblKerAN = sblKer->CreateAbsNegativeInst();

	resP = S16Image::Create(
		resSiz, src->GetNofChannels());

	sblKerP->Process(src, resP);

	resAN = S16Image::Create(
		resSiz, src->GetNofChannels());

	sblKerAN->Process(src, resAN);

	S16ImageRef resY = S16Image::Create(
		resSiz, src->GetNofChannels());

	Hsv::CalcHsvDiff(resP, resAN, resY);

	// XY

	S16ImageRef res = S16Image::Create(
		resSiz, src->GetNofChannels());

	HCV_CALL(GetMaxImg(resX, resY, res));

	/*	HCV_CALL( cvSub (
			resP->GetIplImagePtr(), resAN->GetIplImagePtr(),
			res->GetIplImagePtr()) );*/

	/*	S16ImageRef resT = S16Image::Create(
			resSiz, src->GetNofChannels());

			sblKer->Process(src, resT);

			HCV_CALL( cvSub (
			resT->GetIplImagePtr(), res->GetIplImagePtr(),
			res->GetIplImagePtr()) );*/


	U8ImageRef dsp = U8Image::Create(
		cvGetSize(res->GetIplImagePtr()), res->GetNofChannels());

	double nMin, nMax;

	//HCV_CALL( cvMinMaxLoc( res->GetIplImagePtr(), &nMin, &nMax) );


	HCV_CALL(cvConvertScale(res->GetIplImagePtr(),
		//dsp->GetIplImagePtr(), 0.45, 128) );
		dsp->GetIplImagePtr()));

	cvNamedWindow("3.Sobel", 1);
	cvShowImage("3.Sobel", dsp->GetIplImagePtr());
}

void ImageProcessor::Try2()
{
	int i;
	int x, y;

	U8ImageRef imgHSV = U8Image::Create(img->GetSize(), img->GetNofChannels());

	/*	S16ImageRef src = S16Image::Create(
			cvGetSize(img->GetIplImagePtr()), img->GetNofChannels());

			HCV_CALL( cvConvertScale( img->GetIplImagePtr(),
			src->GetIplImagePtr()) );*/

	HCV_CALL(CvtRgbToHsl(img, imgHSV));

	//HCV_CALL(  cvCvtColor( img->GetIplImagePtr(), 
	//	imgHSV->GetIplImagePtr(), CV_BGR2HSV ) );

	/*	{
			U8ChannelRef valCh = imgHSV->GetAt(2);

			for(y=0; y<valCh->GetHeight(); y++)
			for(x=0; x<valCh->GetWidth(); x++)
			{
			if(valCh->GetAt(x, y) > 180)
			valCh->SetAt(x, y, 255);
			}

			}*/

	HCV_CALL(cvCvtColor(imgHSV->GetIplImagePtr(),
		img->GetIplImagePtr(), CV_HSV2BGR));

	cvNamedWindow("Max Sat", 1);
	cvShowImage("Max Sat", img->GetIplImagePtr());

	/*	U8ImageRef imgH = U8Image::Create(img->GetSize(), 1);
		U8ImageRef imgS = U8Image::Create(img->GetSize(), 1);
		U8ImageRef imgV = U8Image::Create(img->GetSize(), 1);

		HCV_CALL(  cvCvtPixToPlane(imgHSV->GetIplImagePtr() ,
		imgH->GetIplImagePtr(), imgS->GetIplImagePtr(),
		imgV->GetIplImagePtr(), NULL) );

		cvNamedWindow( "H imgH", 1 );
		cvShowImage( "H imgH", imgH->GetIplImagePtr() );

		HCV_CALL( cvvSaveImage("c:\\imgH.jpg",
		imgH->GetIplImagePtr()) );
		HCV_CALL( cvvSaveImage("c:\\imgS.jpg",
		imgS->GetIplImagePtr()) );
		HCV_CALL( cvvSaveImage("c:\\imgV.jpg",
		imgV->GetIplImagePtr()) );

		cvNamedWindow( "S imgS", 1 );
		cvShowImage( "S imgS", imgS->GetIplImagePtr() );

		cvNamedWindow( "V imgV", 1 );
		cvShowImage( "V imgV", imgV->GetIplImagePtr() );

		S16ImageRef edg1 = S16Image::Create(img->GetSize(), img->GetNofChannels());
		*/
	/*	for(i=0; i<img->GetNofChannels(); i++)
		{
		HCV_CALL( FillBorder(img->GetAt(i), (Uint8)0, 30));
		}*/
}

void ImageProcessor::Try1()
{
	ChannelRefColl<Uint8> coll1;

	coll1.push_back(img->GetAt(0));
	coll1.push_back(img->GetAt(1));
	coll1.push_back(img->GetAt(2));

	/*	ObjRef<Channel<Uint8>> im0 = new Channel<Uint8>(img, 0);
		ObjRef<Channel<Uint8>> im1 = new Channel<Uint8>(img, 1);
		ObjRef<Channel<Uint8>> im2 = new Channel<Uint8>(img, 2);	*/

	ObjRef<Channel<Uint8>> im0 = coll1[0];
	ObjRef<Channel<Uint8>> im1 = coll1[1];
	ObjRef<Channel<Uint8>> im2 = coll1[2];

	for (int y = 0; y < im0->GetHeight(); y++)
	for (int x = 0; x < im0->GetWidth(); x++)
	{
		Uint8 nTmp = im0->GetAt(x, y);

		im0->SetAt(x, y,
			//im0->GetAt(x, y) * 0.5);
			im1->GetAt(x, y));
		im1->SetAt(x, y,
			//im1->GetAt(x, y) * 0.5);
			im2->GetAt(x, y));
		im2->SetAt(x, y,
			//im2->GetAt(x, y) * 0.5);
			nTmp);
	}

	im0 = im0;
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
	Hcv::InitLib();


}


