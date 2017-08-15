#ifndef MsgTra_H
#define MsgTra_H

#include "Type.h"

#define MsgTra_DataLen 15
#define MsgTra_2Len    100

class MsgTra
{
    private:
        int MraLen;
        int MraData[MsgTra_DataLen];
        bool MraBool[MsgTra_2Len];
    private:
		int GetSum(void);
		int GetMsgData(int Len,bool *bData);
    public:
        void LoadMra(uchar Mode,int Data);
        void LoadMsgData(MsgTra Data);
        void ShowMraBool();
        void ShowMra();
        void ShowBool(int Num);
//        int  GetDataBool(bool *pBool);
        bool *GetBool(void);
        bool  GetABool(int Num);
    public:
        MsgTra(void);
        ~MsgTra(void);
};

#endif // MsgTra_H

