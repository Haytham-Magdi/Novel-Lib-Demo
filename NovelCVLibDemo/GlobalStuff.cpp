#include "StdAfx.h"
#include "GlobalStuff.h"



Ncv::F32ImageRef GlobalStuff::OrgImg = NULL;

//std::vector < Ncv::F32ImageRef >  GlobalStuff::m_linePathImgVect;
Ncpp::FixedVector  < Ncv::F32ImageRef >  GlobalStuff::m_linePathImgVect( 300 );

std::map<std::string, Ncv::F32ImageRef > GlobalStuff::m_linePathImageMap;


int GlobalStuff::m_linePathImgIndex = -1;
int GlobalStuff::m_nLA_Index = -1;



//int GlobalStuff::AprSize1D = 15;
float GlobalStuff::AprSize1D = 15;
//int GlobalStuff::AprSize1D = 85;

int GlobalStuff::ScanDir = 4;

CString GlobalStuff::m_imgFilePath;

int Ncpp::FixedVectorDebug::AllocCnt = 0;
int Ncpp::FixedVectorDebug::AllocCnt_Old = 0;

int Ncpp::FixedVectorDebug::AllocCnt_2 = 0;
int Ncpp::FixedVectorDebug::AllocCnt_2_Old = 0;

int Ncpp::FixedVectorDebug::FixedVectorID = 0;

long long Ncpp::FixedVectorDebug::AllocSizeTot = 0;
long long Ncpp::FixedVectorDebug::AllocSizeTot_Old = 0;

int Ncpp::FixedVectorDebug::MaxID_Activated = -1;




//int Ncpp::FixedVectorDebug::FixedVectorID_Arr_Size = 10000;
//int Ncpp::FixedVectorDebug::FixedVectorID_Arr_Size = 100000;
int Ncpp::FixedVectorDebug::FixedVectorID_Arr_Size = 1000000;

//int * Ncpp::FixedVectorDebug::FixedVectorID_Arr = new int [ 10000 ];

//int * Ncpp::FixedVectorDebug::FixedVectorID_Arr = new int [ 
//	Ncpp::FixedVectorDebug::FixedVectorID_Arr_Size ];

int * Ncpp::FixedVectorDebug::FixedVectorID_Arr = NULL;


int * Ncpp::FixedVectorDebug::FixedVectorID_Cycle_Arr = NULL;
int Ncpp::FixedVectorDebug::CycleNum = 0;




ImageProcessor * ImageProcessor::s_pProc = NULL;




void (* Ncpp::FixedVectorDebug::pFunc_Update)() = NULL;   



Ncv::F32Point GlobalStuff::m_point0;
Ncv::F32Point GlobalStuff::m_point1;


GlobalStuff::GlobalStuff(void)
{
}

GlobalStuff::~GlobalStuff(void)
{
}
