#include "MsgTra.h"
#include <iostream>

using namespace std;

void MsgTra::LoadMra(uchar Mode,int Data)
{
	int i=0;

    if(Mode==0){MraLen = 0;return;}
	if (MraLen>MsgTra_DataLen)MraLen = MsgTra_DataLen;
	for(i=MsgTra_2Len-Mode;i>0;i--){
        MraBool[i+Mode-1] = MraBool[i-1];
    }
    for(i=0;i<Mode;i++){
        MraBool[i] = (bool)((Data>>i)& 0x01);
    }
    MraData[MraLen] = Mode;
	MraLen ++;
}

int MsgTra::GetSum(void)
{
    int Sum=0,i=0;

    for(i=0;i<MraLen;i++){
        Sum += MraData[i];
    }
	if (Sum>MsgTra_2Len)
		Sum = MsgTra_2Len;
	return Sum;
}

int MsgTra::GetMsgData(int Len,bool *bData)
{
    int j=0,Data=0;

    for(j=0;j<Len;j++){
		Data += bData[j]<<j;
    }
	return Data;
}

void MsgTra::ShowMraBool()
{
    int Sum=0,i=0;

	Sum = GetSum();
    for(i=0;i<Sum;i++){
        cout <<MraBool[i];
    }
}

void MsgTra::ShowBool(int Num)
{
    int Sum=0;

	if (Num<1)Num=1;
	Sum = GetSum();
	if (Num>Sum)Num=Sum;
    cout <<MraBool[Num-1];
}

bool MsgTra::GetABool(int Num)
{
    int Sum=0;

	if (Num<1)Num=1;
	Sum = GetSum();
	if (Num>Sum)Num=Sum;
    return MraBool[Num-1];
}

void MsgTra::ShowMra()
{
    int i=0,Sum=0;

	Sum = GetSum();
    for(i=MraLen;i>0;i--){
        Sum = Sum - MraData[i-1];
		cout << GetMsgData(MraData[i - 1], &MraBool[Sum]);
        if(i>1)cout<<",";
    }
}

//int MsgTra::GetDataBool(bool *pBool)
//{
//    int i,Sum=0;
//
//    if(pBool == NULL)return 0;
//    if(MraLen == 0)return 0;
//	Sum = GetSum();
//    for(i=0;i<Sum;i++){
//        pBool[i] = MraBool[i];
//    }
//    return Sum;
//}

bool *MsgTra::GetBool(void)
{
	return MraBool;
}

void MsgTra::LoadMsgData(MsgTra Data)
{
    int i=0,Sum=0;

	MraLen = Data.MraLen;
	if(MraLen == 0)return;
	for (i=0;i < MraLen;i++){
		MraData[i] = Data.MraData[i];
	}
	Sum = GetSum();
	for (i = 0; i < Sum; i++){
		MraBool[i] = Data.MraBool[i];
	}
}

MsgTra::MsgTra(void)
{
    MraLen = 0;
}

MsgTra::~MsgTra(void)
{
}
