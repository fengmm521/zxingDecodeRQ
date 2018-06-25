//********************************************************************
// File Name	:	YString.h
// Class Name	:	YString
// Description	:	字符、字符串等操作类
//				:	head file
// Author		:	brantyou
// Create time	:	2011-06-01
//********************************************************************

#pragma once

class YString
{
public:
	YString(void);					// 构造函数
	virtual ~YString(void);			// 析构函数

	// ***	【SOF】分割字符串	***
	static void Split(CString srcStr, CString split, CString *str, int &size);
	static void Split(CString srcStr, CString split, CStringArray &arry, int &size);
	static void Split(CString srcStr, CString split, CStringArray &arry);
	// ***	【EOF】分割字符串	***

	//static int RFind(CString dataStr, CString findStr, int start);		// 在dataStr字符串中反序查找findStr出现的位置
	static int FindLast(CString dataStr, CString findStr);					// 在dataStr字符串中查找findStr出现的末位置
	static CString Mid(CString source, CString start, CString end);			// 获取两字符串间的字符串
	static BOOL GetAfter(CString source, CString child, CString& after);	// 获取母串中某个字串(第一次出现)之后的字符串
	static BOOL GetLastAfter(CString source, CString child, CString& after);// 获取母串中某个字串(最后出现)之后的字符串

	// ***	【SOF】类型转换	***
	static int CStringToInt(CString str);									// CString 转 int
	static int CStringToInt2(CString str);									// CString 转 int(可转16进制)
	static CString IntToCString(int num);									// int 转 CString
	static char * CStringToChar_(CString str);								// CString 转 char *
	static CString Char_ToCString(char * ch);								// char * 转 CString
	static int Ascii2Hex(char* ascii, char* hex);							// ASCII 转16进制
	//static int Hex2Ascii(const char *hex,char * ascii);						// 16进制转ASCII
	static CString ChineseToUnicode(LPCWSTR lpUnicode);						// 中文转Unicode编码
	//static char * DecToHex(unsigned int dec);								// 十进制整形转换成十六进制字符串，不含0x
	//static char DecToHexCh(unsigned int dec);								// 十进制整形(<16)转换成十六进制字符
	static int ChineseToASCII(CString chinese, char *ascii);				// 中文转ASCII码
	static CString ChineseToASCIIStr(CString chinese);						// 中文字符串转ASCII码字符串
	static CString AsciiToChinese(char * ascii);							// ASCII转中文
	static char * ChineseToASCII(LPCWSTR chinese, int &aLen);				// 中文转ASCII码
	static CString AsciiToChinese(CString ascii);							// ASCII转中文
	static char * ChEnToASCII(CString data, int &aLen);						// 中英文转ASCII码
	static BOOL CString2Char(CString str, char* buf, int bufInLen, int& bufOutLen);	// CString转char*
	static BOOL Char2CString(char* buf, int bufLen, CString& str);						// char*转CString
	static BOOL Hex2Char(const char hex[2], char *ascii);					// 十六进制字符串转ASCII字符
	static BOOL Hexs2Chars(char* hex, int hexLen, char *ascii);				// 十六进制字符串转ASCII字符串
	static BOOL CString2Chars(CString str, char *bufout, int* outLen);		// CString转char字符串	
	static CString AsciiToChinese(char * ascii, int inLen);					// ASCII转中文
	static BOOL Hex2ChEn(CString hex, CString &chEn);						// 中英文对应的十六进制字符串转回中英文
	static BOOL ChEnToASCII(CString data, char *ascii, int &asciiLen);		// 中英文转ASCII码
	static BOOL ChEn2Hex(CString chEn, CString &hex);						// 中英文转换成十六进制字符串
	static BOOL Char2HexA(char ch, char* hex);								// 字符型十六进制转回对应的十六进制
	static BOOL Chars2HexsA(char* string, int strLen, char* hex);			// 字符型十六进制字符串转回对应的十六进制字符串
	static BOOL Hexs2Code81(char* hex, int hexLen, char* code);				// 十六进制字符串转回81类型编码
	static BOOL Hex2CharA(char hex, char* ch);								// 十六进制转ASCII字符型(eg:0xc to C)
	static BOOL Hexs2CharsA(char* hex, int hexLen, char* string);			// 十六进制数组转ASCII字符型数组(eg:{0xc,0xe,0xc,0xe} to "CECE")
	static BOOL ChangeCode81(CString data, CString& code);					// 通过移位转换81编码类型为UNICODE编码
	static BOOL Decode81(CString hexdata, CString& chEN);					// 把81编码类型的数据转换为中英文
	static BOOL Decode82(CString hexdata, CString&chEN);					// 把82编码类型的数据转换为中英文
	// ***	【EOF】类型转换	***

	static BOOL RevertChar(int len, char *str);								// 反序str中的字符
	static char * TwoTwoChange(char * str, int length);						// 字符串两两交换
	static void TwoTwoChange2(char * str, int length);						// 字符串两两交换
	static BOOL isAllEnglish(CString data);									// 检测串是否为全英文字符	
};
