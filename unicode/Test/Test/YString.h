//********************************************************************
// File Name	:	YString.h
// Class Name	:	YString
// Description	:	�ַ����ַ����Ȳ�����
//				:	head file
// Author		:	brantyou
// Create time	:	2011-06-01
//********************************************************************

#pragma once

class YString
{
public:
	YString(void);					// ���캯��
	virtual ~YString(void);			// ��������

	// ***	��SOF���ָ��ַ���	***
	static void Split(CString srcStr, CString split, CString *str, int &size);
	static void Split(CString srcStr, CString split, CStringArray &arry, int &size);
	static void Split(CString srcStr, CString split, CStringArray &arry);
	// ***	��EOF���ָ��ַ���	***

	//static int RFind(CString dataStr, CString findStr, int start);		// ��dataStr�ַ����з������findStr���ֵ�λ��
	static int FindLast(CString dataStr, CString findStr);					// ��dataStr�ַ����в���findStr���ֵ�ĩλ��
	static CString Mid(CString source, CString start, CString end);			// ��ȡ���ַ�������ַ���
	static BOOL GetAfter(CString source, CString child, CString& after);	// ��ȡĸ����ĳ���ִ�(��һ�γ���)֮����ַ���
	static BOOL GetLastAfter(CString source, CString child, CString& after);// ��ȡĸ����ĳ���ִ�(������)֮����ַ���

	// ***	��SOF������ת��	***
	static int CStringToInt(CString str);									// CString ת int
	static int CStringToInt2(CString str);									// CString ת int(��ת16����)
	static CString IntToCString(int num);									// int ת CString
	static char * CStringToChar_(CString str);								// CString ת char *
	static CString Char_ToCString(char * ch);								// char * ת CString
	static int Ascii2Hex(char* ascii, char* hex);							// ASCII ת16����
	//static int Hex2Ascii(const char *hex,char * ascii);						// 16����תASCII
	static CString ChineseToUnicode(LPCWSTR lpUnicode);						// ����תUnicode����
	//static char * DecToHex(unsigned int dec);								// ʮ��������ת����ʮ�������ַ���������0x
	//static char DecToHexCh(unsigned int dec);								// ʮ��������(<16)ת����ʮ�������ַ�
	static int ChineseToASCII(CString chinese, char *ascii);				// ����תASCII��
	static CString ChineseToASCIIStr(CString chinese);						// �����ַ���תASCII���ַ���
	static CString AsciiToChinese(char * ascii);							// ASCIIת����
	static char * ChineseToASCII(LPCWSTR chinese, int &aLen);				// ����תASCII��
	static CString AsciiToChinese(CString ascii);							// ASCIIת����
	static char * ChEnToASCII(CString data, int &aLen);						// ��Ӣ��תASCII��
	static BOOL CString2Char(CString str, char* buf, int bufInLen, int& bufOutLen);	// CStringתchar*
	static BOOL Char2CString(char* buf, int bufLen, CString& str);						// char*תCString
	static BOOL Hex2Char(const char hex[2], char *ascii);					// ʮ�������ַ���תASCII�ַ�
	static BOOL Hexs2Chars(char* hex, int hexLen, char *ascii);				// ʮ�������ַ���תASCII�ַ���
	static BOOL CString2Chars(CString str, char *bufout, int* outLen);		// CStringתchar�ַ���	
	static CString AsciiToChinese(char * ascii, int inLen);					// ASCIIת����
	static BOOL Hex2ChEn(CString hex, CString &chEn);						// ��Ӣ�Ķ�Ӧ��ʮ�������ַ���ת����Ӣ��
	static BOOL ChEnToASCII(CString data, char *ascii, int &asciiLen);		// ��Ӣ��תASCII��
	static BOOL ChEn2Hex(CString chEn, CString &hex);						// ��Ӣ��ת����ʮ�������ַ���
	static BOOL Char2HexA(char ch, char* hex);								// �ַ���ʮ������ת�ض�Ӧ��ʮ������
	static BOOL Chars2HexsA(char* string, int strLen, char* hex);			// �ַ���ʮ�������ַ���ת�ض�Ӧ��ʮ�������ַ���
	static BOOL Hexs2Code81(char* hex, int hexLen, char* code);				// ʮ�������ַ���ת��81���ͱ���
	static BOOL Hex2CharA(char hex, char* ch);								// ʮ������תASCII�ַ���(eg:0xc to C)
	static BOOL Hexs2CharsA(char* hex, int hexLen, char* string);			// ʮ����������תASCII�ַ�������(eg:{0xc,0xe,0xc,0xe} to "CECE")
	static BOOL ChangeCode81(CString data, CString& code);					// ͨ����λת��81��������ΪUNICODE����
	static BOOL Decode81(CString hexdata, CString& chEN);					// ��81�������͵�����ת��Ϊ��Ӣ��
	static BOOL Decode82(CString hexdata, CString&chEN);					// ��82�������͵�����ת��Ϊ��Ӣ��
	// ***	��EOF������ת��	***

	static BOOL RevertChar(int len, char *str);								// ����str�е��ַ�
	static char * TwoTwoChange(char * str, int length);						// �ַ�����������
	static void TwoTwoChange2(char * str, int length);						// �ַ�����������
	static BOOL isAllEnglish(CString data);									// ��⴮�Ƿ�ΪȫӢ���ַ�	
};
