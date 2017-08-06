
#pragma once
#include<string>

using namespace std;

class NumBaseConversor
{

public:
	NumBaseConversor();
	NumBaseConversor(uint64_t val);
	NumBaseConversor(string str,int mode);

	~NumBaseConversor();

	void WriteAllProp(uint64_t val);
	void WriteAllProp(void);

	uint64_t InputStr2Data(string str,int mode);

	void WriteData(uint64_t Value);
	void WriteHex(string str);
	void WriteDec(string str);
	void WriteOct(string str);
	void WriteBin(string str);
	void WriteHex();
	void WriteDec();
	void WriteOct();
	void WriteBin();

	uint64_t GetData(void);
	string GetHex(void);
	string GetDec(void);
	string GetOct(void);
	string GetBin(void);
	
	string Data2Hex(uint64_t val);
	string Data2Dec(uint64_t val);
	string Data2Oct(uint64_t val);
	string Data2Bin(uint64_t val);
	string Data2Hex(void);
	string Data2Dec(void);
	string Data2Oct(void);
	string Data2Bin(void);

private:
	uint64_t Data;
	string Hex;
	string Dec;
	string Oct;
	string Bin;
};

