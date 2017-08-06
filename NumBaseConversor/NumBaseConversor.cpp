
#include "NumBaseConversor.h"
#include <iostream>
#include <string>
#include <strstream>
#include <cmath>

using namespace std;

NumBaseConversor::NumBaseConversor()
{
	Data = 0;
	WriteAllProp();
}

NumBaseConversor::NumBaseConversor(uint64_t val)
{
	WriteAllProp(val);
}

NumBaseConversor::NumBaseConversor(string str,int mode)
{
	uint64_t temp = InputStr2Data(str,mode);
	WriteAllProp(temp);
}


NumBaseConversor::~NumBaseConversor()
{
}

void NumBaseConversor::WriteAllProp(uint64_t val)
{
	WriteData(val);
	WriteBin();
	WriteHex();
	WriteDec();
	WriteOct();
}

void NumBaseConversor::WriteAllProp(void)
{
	WriteAllProp(this->Data);
}

uint64_t NumBaseConversor::InputStr2Data(string str ,int mode)
{
	uint64_t DataReturn=0;
	uint64_t factor = 1;
	uint8_t* DataStr = new uint8_t[str.length()];
	switch (mode)
	{
	case 0:		//Input Type: Hex;
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] >= '0'&&str[i] <= '9')
			{
				DataStr[i] = str[i] - '0';
			}
			else if (str[i] >= 'A'&&str[i] <= 'F')
			{
				DataStr[i] = str[i] - '0' - 7;
			}
			else
			{
				cout << "input erro!";
				return UINT_FAST64_MAX;
			}
		}
		factor = 1;
		for (int i = 0; i < str.length(); i++)
		{
			DataReturn += DataStr[str.length() - i - 1] * factor;
			factor *= 16;
		}
		break;
	}
	case 1:		//input Dec
	{
		DataReturn = atoll(str.c_str());
		break;
	}
	case 2:		//Oct input
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] >= '0'&&str[i] <= '9')
			{
				DataStr[i] = str[i] - '0';
			}
			else
			{
				cout << "input erro";
				return UINT_FAST64_MAX;
			}
		}
		factor = 1;
		for (int i = 0; i < str.length(); i++)
		{
			DataReturn += DataStr[str.length() - i - 1] * factor;
			factor *= 8;
		}
		break;
	}
	case 3:		//Bin input
	{
		factor = 1;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '1')
			{
				DataReturn += factor;
				factor *= 2;
			}
			else if (str[i] != '0')
			{
				cout << "input erro!";
				return UINT_FAST64_MAX;
			}
		}
		break;
	}
	default:
		break;
	}
	return uint64_t(DataReturn);
}


void NumBaseConversor::WriteData(uint64_t Value)
{
	this->Data = Value;
}

void NumBaseConversor::WriteHex(string str)
{
	this->Hex = str;
}

void NumBaseConversor::WriteDec(string str)
{
	this->Dec = str;
}

void NumBaseConversor::WriteOct(string str)
{
	this->Oct = str;
}

void NumBaseConversor::WriteBin(string str)
{
	this->Bin = str;
}

void NumBaseConversor::WriteHex()
{
	this->Hex = Data2Hex();
}

void NumBaseConversor::WriteDec()
{
	this->Dec = Data2Dec();
}

void NumBaseConversor::WriteOct()
{
	this->Oct = Data2Oct();
}

void NumBaseConversor::WriteBin()
{
	this->Bin = Data2Bin();
}

uint64_t NumBaseConversor::GetData(void)
{
	return uint64_t(this->Data);
}

string NumBaseConversor::GetHex(void)
{
	return string(this->Hex);
}

string NumBaseConversor::GetDec(void)
{
	return string(this->Dec);
}

string NumBaseConversor::GetOct(void)
{
	return string(this->Oct);
}

string NumBaseConversor::GetBin(void)
{
	return string(this->Bin);
}

string NumBaseConversor::Data2Hex(uint64_t val)
{
	uint64_t tempval = val;
	uint16_t remainder[16] = { 0 };	
	char ChHex[19] = { '0' };
	for (int i = 0; i < 16; i++)
	{
		remainder[15-i] = tempval&((uint64_t)0x0F);	//remainder[0] is MSB;
		tempval >>= 4;
	}
	for (int i = 0; i < 16; i++)
	{
		if (remainder[i] > 9)		//ChHex should be A above
		{
			ChHex[i] = remainder[i] + '0' + 7;
		}
		else
		{
			ChHex[i] = remainder[i] + '0';
		}

	}
	string TempHex(ChHex);
	TempHex.resize(16);
	TempHex.insert(4, " ");
	TempHex.insert(9, " ");
	TempHex.insert(14, " ");
	return string(TempHex);
}

string NumBaseConversor::Data2Dec(uint64_t val)
{
	char ChDec[20] = { '0' };
	uint16_t remainder[20] = { 0 };
	uint64_t mod=10;
	uint64_t valTemp = val;
	for (int i = 0; i < 20; i++)
	{
			remainder[19-i] = valTemp%mod;		//remainder[0] is MSB
			valTemp /= mod;
	}
	for (int i = 0; i < 20; i++)
	{
		ChDec[i] = remainder[i] + '0';
	}
	string TempDec(ChDec);
	TempDec.resize(20);
	TempDec.insert(17, ",");
	TempDec.insert(14, ",");
	TempDec.insert(11, ",");
	TempDec.insert(8, ",");
	TempDec.insert(5, ",");
	TempDec.insert(2, ",");
	return string(TempDec);
}

string NumBaseConversor::Data2Oct(uint64_t val)
{
	uint64_t tempval = val;
	uint16_t remainder[22] = { 0 };
	char ChOct[22] = { '0' };
	for (int i = 0; i < 22; i++)
	{
		remainder[21 - i] = tempval&((uint64_t)0x07);	//remainder[0] is MSB;
		tempval >>= 3;
	}
	for (int i = 0; i < 22; i++)
	{
			ChOct[i] = remainder[i] + '0';
	}
	string TempOct(ChOct);
	TempOct.resize(22);
	TempOct.insert(19, " ");
	TempOct.insert(16, " ");
	TempOct.insert(13, " ");
	TempOct.insert(10, " ");
	TempOct.insert(7, " ");
	TempOct.insert(4, " ");
	TempOct.insert(1, " ");
	return string(TempOct);
}

string NumBaseConversor::Data2Bin(uint64_t val)
{
	uint64_t tempval = val;
	uint16_t remainder[64] = { 0 };
	char ChBin[64] = { '0' };
	for (int i = 0; i < 64; i++)
	{
		remainder[63 - i] = tempval&((uint64_t)0x01);	//remainder[0] is MSB;
		tempval >>= 1;
	}
	for (int i = 0; i < 64; i++)
	{
		ChBin[i] = remainder[i] + '0';
	}
	string TempBin(ChBin);
	TempBin.resize(64);
	for (int i = 1; i < 16; i++)
	{
		TempBin.insert(64 - i * 4, " ");
	}
	return string(TempBin);
}

string NumBaseConversor::Data2Hex(void)
{
	uint64_t tempData = this->Data;
	uint16_t remainder[16] = { 0 };
	char ChHex[16] = { '0' };
	for (int i = 0; i < 16; i++)
	{
		remainder[15 - i] = tempData&((uint64_t)0x0F);	//remainder[0] is MSB;
		tempData >>= 4;
	}
	for (int i = 0; i < 16; i++)
	{

		if (remainder[i] > 9)		//ChHex should be A above
		{
			ChHex[i] = remainder[i] + '0' + 7;
		}
		else
		{
			ChHex[i] = remainder[i] + '0';
		}
	}
	string TempHex(ChHex);
	TempHex.resize(16);
	TempHex.insert(4," ");
	TempHex.insert(9, " ");
	TempHex.insert(14, " ");
	return string(TempHex);
}

string NumBaseConversor::Data2Dec(void)
{
	char ChDec[20] = { '0' };
	uint16_t remainder[20] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	uint64_t mod = 10;
	uint64_t DataTemp = this->Data;
	for (int i = 0; i < 20; i++)
	{
		remainder[19 - i] = DataTemp%mod;		//remainder[0] is MSB
		DataTemp /= mod;
	}
	for (int i = 0; i < 20; i++)
	{
		ChDec[i] = remainder[i] + '0';
	}
	string TempDec(ChDec);
	TempDec.resize(20);
	TempDec.insert(17, ",");
	TempDec.insert(14, ",");
	TempDec.insert(11, ",");
	TempDec.insert(8, ",");
	TempDec.insert(5, ",");
	TempDec.insert(2, ",");
	return string(TempDec);
}

string NumBaseConversor::Data2Oct(void)
{
	uint64_t tempData = this->Data;
	uint16_t remainder[22] = { 0 };
	char ChOct[22] = { '0' };
	for (int i = 0; i < 22; i++)
	{
		remainder[21 - i] = tempData&((uint64_t)0x07);	//remainder[0] is MSB;
		tempData >>= 3;
	}
	for (int i = 0; i < 22; i++)
	{
		ChOct[i] = remainder[i] + '0';
	}
	string TempOct(ChOct);
	TempOct.resize(22);
	TempOct.insert(19, " ");
	TempOct.insert(16, " ");
	TempOct.insert(13, " ");
	TempOct.insert(10, " ");
	TempOct.insert(7, " ");
	TempOct.insert(4, " ");
	TempOct.insert(1, " ");
	return string(TempOct);
}

string NumBaseConversor::Data2Bin(void)
{
	uint64_t tempData = this->Data;
	uint16_t remainder[64] = { 0 };
	char ChBin[64] = { '0' };
	for (int i = 0; i < 64; i++)
	{
		remainder[63 - i] = tempData&(0x01);	//remainder[0] is MSB;
		tempData >>= 1;
	}
	for (int i = 0; i < 64; i++)
	{
		ChBin[i] = remainder[i] + '0';
	}
	string TempBin(ChBin);
	TempBin.resize(64);
	for (int i = 1; i < 16; i++)
	{
		TempBin.insert(64-i*4, " ");
	}
	return string(TempBin);
}
