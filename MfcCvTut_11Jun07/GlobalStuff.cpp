#include "StdAfx.h"
#include "GlobalStuff.h"



Ncv::F32ImageRef GlobalStuff::OrgImg = NULL;

//std::vector < Ncv::F32ImageRef >  GlobalStuff::m_linePathImgVect;
Hcpl::FixedVector  < Ncv::F32ImageRef >  GlobalStuff::m_linePathImgVect( 300 );


int GlobalStuff::m_linePathImgIndex = -1;
int GlobalStuff::m_nLA_Index = -1;



//int GlobalStuff::AprSize1D = 15;
float GlobalStuff::AprSize1D = 15;
//int GlobalStuff::AprSize1D = 85;

int GlobalStuff::ScanDir = 4;

CString GlobalStuff::m_imgFilePath;

int Hcpl::FixedVectorDebug::AllocCnt = 0;
int Hcpl::FixedVectorDebug::AllocCnt_Old = 0;

int Hcpl::FixedVectorDebug::AllocCnt_2 = 0;
int Hcpl::FixedVectorDebug::AllocCnt_2_Old = 0;

int Hcpl::FixedVectorDebug::FixedVectorID = 0;

long long Hcpl::FixedVectorDebug::AllocSizeTot = 0;
long long Hcpl::FixedVectorDebug::AllocSizeTot_Old = 0;

int Hcpl::FixedVectorDebug::MaxID_Activated = -1;




//int Hcpl::FixedVectorDebug::FixedVectorID_Arr_Size = 10000;
//int Hcpl::FixedVectorDebug::FixedVectorID_Arr_Size = 100000;
int Hcpl::FixedVectorDebug::FixedVectorID_Arr_Size = 1000000;

//int * Hcpl::FixedVectorDebug::FixedVectorID_Arr = new int [ 10000 ];

//int * Hcpl::FixedVectorDebug::FixedVectorID_Arr = new int [ 
//	Hcpl::FixedVectorDebug::FixedVectorID_Arr_Size ];

int * Hcpl::FixedVectorDebug::FixedVectorID_Arr = NULL;


int * Hcpl::FixedVectorDebug::FixedVectorID_Cycle_Arr = NULL;
int Hcpl::FixedVectorDebug::CycleNum = 0;




ImageProcessor * ImageProcessor::s_pProc = NULL;




void (* Hcpl::FixedVectorDebug::pFunc_Update)() = NULL;   


Ncv::IRegionSegmentor20Ref GlobalStuff::m_RgnSgm;

Ncv::F32Point GlobalStuff::m_point0;
Ncv::F32Point GlobalStuff::m_point1;


GlobalStuff::GlobalStuff(void)
{
}

GlobalStuff::~GlobalStuff(void)
{
}
