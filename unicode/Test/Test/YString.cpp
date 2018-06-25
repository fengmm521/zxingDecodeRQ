//********************************************************************
// File Name	:	YString.cpp
// Class Name	:	YString
// Description	:	�ַ����ַ����Ȳ�����
//				:	cpp file
// Author		:	brantyou
// Create time	:	2011-06-01
//********************************************************************

#include "StdAfx.h"
#include "YString.h"

//********************************************************************
//****************************** ȫ�ֶ��� ****************************
char * ASCII [] = {
"NUL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL", "BS", "HT", "\n", "BT", "FF", "\r", "SO", "SI",
"DLE", "DC1", "DC2", "DC3", " ", "NAK", "SYN", "ETB", "CAN", "EM", "SUB", "ESC", "FS", "GS", "RS", "US",
"SP", "!", "\"", "#", "$", "%", "&", "'", "(", ")", "*", "+", ",", "_", ".", "/",
"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", ":", ";", "<", "=", ">", "?",
"@", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O",
"P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "[", "\\", "]", "", "",
"`", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o",
"p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", "{", "|", "}", "~", "DEL"
};

//CString HEX [] = {
//"00", "01", "02", "03", "04", "05", "06", "07", "08", "09", "0A", "0B", "0C", "0D", "0E", "0F",
//"10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "1A", "1B", "1C", "1D", "1E", "1F",
//"20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "2A", "2B", "2C", "", "", "",
//"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
//"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
//"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
//"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
//"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""
//};
//****************************** ȫ�ֶ��� ****************************
//********************************************************************

YString::YString(void)
{
}

YString::~YString(void)
{
}


//********************************************************************
//****************************** * * * * *****************************
//* * * * * * * * * * ��    Custom Functions    �� * * * * * * * * * *
//****************************** * * * * *****************************
//********************************************************************

//********************************************************************
// Function		:	
// Description	:	
// Input		:	
// Output		:	
// return		:	
//********************************************************************

//********************************************************************
// Function		:	Split
// Description	:	�ָ��ַ���
// Input1		:	CString srcStr	:	Ҫ�ָ���ַ���
// Input2		:	CString split	:	�ָ��ַ����ַ���
// Output1		:	CString *str	:	�ָ����ַ���ָ��
// Output2		:	int &size		:	�ָ�ɶ��ٸ��ַ���, ֵΪ-1��ʾʧ��
// return		:	NONE
//********************************************************************
void YString::Split(CString srcStr, CString split, CString *str, int &size)
{
	int j=0, n=0, m_pos;
	int d_len = split.GetLength();

	while(1)
	{
		m_pos = srcStr.Find(split, j);
		if(m_pos == -1 && j == 0){
			size = -1;
			break;
		}

		if(m_pos == -1 && j != 0){
			str[n] = srcStr.Mid(j, srcStr.GetLength()-j);
			size = n;
			break;
		}

		if( j == 0 ){
			str[n] = srcStr.Mid(0, m_pos);
			j = m_pos + d_len;
		}
		else{
			str[n] = srcStr.Mid(j, m_pos - j);
			j = m_pos + d_len;
		}
		n++;
	} // end while
}

//********************************************************************
// Function		:	Split
// Description	:	�ָ��ַ���
// Input1		:	CString srcStr		:	Ҫ�ָ���ַ���
// Input2		:	CString split		:	�ָ��ַ����ַ���
// Output1		:	CStringArray &arry	:	�ָ����ַ�������
// Output2		:	int &size			:	�ָ�ɶ��ٸ��ַ���
// return		:	NONE
//********************************************************************
void YString::Split(CString srcStr, CString split, CStringArray &arry, int &size)
{
	int j=0, m_pos;
	int d_len = split.GetLength();

	while(1)
	{
		m_pos = srcStr.Find(split, j);
		if(m_pos == -1 && j == 0){
			size = -1;
			break;
		}

		if(m_pos == -1 && j != 0){
			arry.Add( srcStr.Mid(j, srcStr.GetLength()-j) );
			size = arry.GetSize();
			break;
		}

		if( j == 0 ){
			arry.Add( srcStr.Mid(0, m_pos) );
			j = m_pos + d_len;
		}
		else{
			arry.Add( srcStr.Mid(j, m_pos - j) );
			j = m_pos + d_len;
		}
	} // end while
}

//********************************************************************
// Function		:	Split
// Description	:	�ָ��ַ���
// Input1		:	CString srcStr		:	Ҫ�ָ���ַ���
// Input2		:	CString split		:	�ָ��ַ����ַ���
// Output1		:	CStringArray &arry	:	�ָ����ַ�������
// return		:	NONE
//********************************************************************
void YString::Split(CString srcStr, CString split, CStringArray &arry)
{
	int j=0, m_pos;
	int d_len = split.GetLength();

	while(1)
	{
		m_pos = srcStr.Find(split, j);
		if(m_pos == -1 && j == 0){
			arry.Add( srcStr );
			break;
		}

		if(m_pos == -1 && j != 0){
			arry.Add( srcStr.Mid(j, srcStr.GetLength()-j) );
			break;
		}

		if( j == 0 ){
			arry.Add( srcStr.Mid(0, m_pos) );
			j = m_pos + d_len;
		}
		else{
			arry.Add( srcStr.Mid(j, m_pos - j) );
			j = m_pos + d_len;
		}
	} // end while
}

//********************************************************************
// Function		:	RFind
// Description	:	��dataStr�ַ����з������findStr���ֵ�λ��
// Input1		:	CString dataStr		:	�����ҵ�ĸ�ַ���
// Input2		:	CString findStr		:	Ҫ���ҵ����ַ���
// Input3		:	int start			:	��ʼ���ҵ�λ��
// Output1		:	NONE
// return		:	int pos = -1	:	����ʧ��	;	pos >= 0	:	λ��
//********************************************************************
//int YString::RFind(CString dataStr, CString findStr, int start)
//{
//	int pos = -1, pos_tmp = -1;
//	int start_pos = start;
//
//	while(1)
//	{
//		pos = dataStr.Find(findStr, start_pos);
//		if(pos > -1){
//			start_pos = pos;
//			pos_tmp = pos;
//		}
//		else{
//			break;
//		}
//	}// end while
//	if(pos_tmp > -1)
//		pos = pos_tmp;
//
//	return pos;
//}

//********************************************************************
// Function		:	RFind
// Description	:	��dataStr�ַ����з������findStr���ֵ�λ��
// Input1		:	CString dataStr		:	�����ҵ�ĸ�ַ���
// Input2		:	CString findStr		:	Ҫ���ҵ����ַ���
// Output1		:	NONE
// return		:	int pos = -1	:	����ʧ��	;	pos >= 0	:	λ��
//********************************************************************
int YString::FindLast(CString dataStr, CString findStr)
{
	int pos = -1, pos_tmp = -1, start_pos = 0;
	int count = 0;

	while(1)
	{
		pos = dataStr.Find(findStr, start_pos);
		if(pos > -1){
			start_pos = pos;
			pos_tmp = pos;
			if(start_pos == 0 || start_pos == pos)
				start_pos += findStr.GetLength();
			if(start_pos >= dataStr.GetLength())
				break;
		}
		else{
			break;
		}
		// ��ֹ����������ѭ������ѭ���������ڱ�����ԭ�ַ������ȵ�ʱ�������ѭ��
		count++;
		if(count > dataStr.GetLength()){
			break;
		}
	}// end while
	if(pos_tmp > -1)
		pos = pos_tmp;

	return pos;
}

//********************************************************************
// Function		:	Mid
// Description	:	��ȡĸ�ַ������������ַ�������ַ���
// Input1		:	CString source	:	ĸ�ַ���
// Input2		:	CString star	:	��ʼ�����ַ������ַ�
// Input3		:	CString end		:	���������ַ������ַ�
// Output		:	NONE
// return		:	CString	: Ϊ""�����ʾ����ʧ��	�ɹ�����Ӧ���ַ���
//********************************************************************
CString YString::Mid(CString source, CString start, CString end)
{
	CString mid = L"";
	int pos_start = source.Find(start, 0);
	if(pos_start < 0)
		return mid;
	pos_start += start.GetLength();
	int pos_end = source.Find(end, pos_start);
	if(pos_end < 0)
		return mid;
	int len = pos_end - pos_start;
	if(len <= 0)
		return mid;
	mid = source.Mid(pos_start, len);

	return mid;
}

//********************************************************************
// Function		:	GetAfter
// Description	:	��ȡĸ����ĳ���ִ�(��һ�γ���)֮����ַ���
// Input1		:	CString source	:	ĸ�ַ���
// Input2		:	CString child	:	���ַ���
// Output		:	CString &after	:	ĸ�������ַ���(��һ�γ���)֮����ִ�
// return		:	�ɹ�:	TRUE	;	ʧ��:	FALSE
//********************************************************************
BOOL YString::GetAfter(CString source, CString child, CString &after)
{
	BOOL ret = FALSE;
	int pos_start = source.Find(child, 0);
	if(pos_start > -1){
		after = source.Mid(pos_start);
		ret = TRUE;
	}

	return ret;
}

//********************************************************************
// Function		:	GetLastAfter
// Description	:	��ȡĸ����ĳ���ִ�(������)֮����ַ���
// Input1		:	CString source	:	ĸ�ַ���
// Input2		:	CString child	:	���ַ���
// Output		:	CString &after	:	ĸ�������ַ���(������)֮����ִ�
// return		:	�ɹ�:	TRUE	;	ʧ��:	FALSE
//********************************************************************
BOOL YString::GetLastAfter(CString source, CString child, CString &after)
{
	BOOL ret = FALSE;
	int pos_start = FindLast(source, child);	// ��ȡchild��source�г��ֵ�ĩλ��
	if(pos_start > -1){
		after = source.Mid(pos_start);
		ret = TRUE;
	}

	return ret;
}

//********************************************************************
// Function		:	CStringToInt
// Description	:	CString ת int
// Input		:	CString str	:	Ҫת���������ַ���
// Output		:	NONE
// return		:	ת���������
//********************************************************************
int YString::CStringToInt(CString str)
{
	int num;
	char *tmp = new char[str.GetLength()];
	for(int i=0; i<str.GetLength(); i++)
		tmp[i] = str.GetAt(i);
	num = atoi(tmp);
	delete []tmp;

	return num;
}

//********************************************************************
// Function		:	CStringToInt2
// Description	:	CString ת int(��ת16����)
// Input		:	CString str	:	Ҫת���������ַ���
// Output		:	NONE
// return		:	ת���������
//********************************************************************
int YString::CStringToInt2(CString str)
{
	int num;
	char *tmp = new char[str.GetLength()+2];
	memset(tmp, 0, sizeof(tmp));
	for(int i=0; i<str.GetLength(); i++){
		char ch = str.GetAt(i);
		if(ch>='A' && ch<='F'){
			tmp[i++] = '1';
			switch(ch-'A')
			{
			case 0:	tmp[i] = '0';	break;
			case 1:	tmp[i] = '1';	break;
			case 2:	tmp[i] = '2';	break;
			case 3:	tmp[i] = '3';	break;
			case 4:	tmp[i] = '4';	break;
			case 5:	tmp[i] = '5';	break;
			}
		}
		else if(ch>='a' && ch<='f'){
			tmp[i++] = '1';
			switch(ch-'a')
			{
			case 0:	tmp[i] = '0';	break;
			case 1:	tmp[i] = '1';	break;
			case 2:	tmp[i] = '2';	break;
			case 3:	tmp[i] = '3';	break;
			case 4:	tmp[i] = '4';	break;
			case 5:	tmp[i] = '5';	break;
			}
		}
		else
			tmp[i] = ch;
	}
	num = atoi(tmp);
	delete []tmp;

	return num;
}

//********************************************************************
// Function		:	IntToCString
// Description	:	int ת CString
// Input		:	int num		:	Ҫת��������
// Output		:	NONE
// return		:	ת����������ַ���
//********************************************************************
CString YString::IntToCString(int num)
{
	CString str;
	str.Format(_T("%d"), num);

	return str;
}

//********************************************************************
// Function		:	CStringToChar_
// Description	:	CString ת char *
// Input		:	CString str	:	Ҫת���������ַ���
// Output		:	NONE
// return		:	char *
//********************************************************************
char * YString::CStringToChar_(CString str)
{
	int len = str.GetLength();
	char * ch = new char[len];
	int i=0;
	for(i=0; i<len; i++)
		ch[i] = str.GetAt(i);
	ch[i] = '\0';

	return ch;
}

//********************************************************************
// Function		:	Char_ToCString
// Description	:	char * ת CString
// Input		:	char *ch	:	Ҫת�����ַ�ָ��
// Output		:	NONE
// return		:	CString
//********************************************************************
CString YString::Char_ToCString(char *ch)
{
	CString str;
	for(int i=0; ch[i]!='\0'; i++){
		str += ch[i];
	}

	return str;
}

//********************************************************************
// Function		:	Ascii2Hex
// Description	:	ASCII ת16����
// Input		:	char *ascii	:	ASCII�ַ���
// Output		:	char *hex	:	ʮ�������ַ���
// return		:	int len		:	ʮ�������ַ�������
//********************************************************************
int YString::Ascii2Hex(char *ascii, char *hex)
{
	int i, len = strlen(ascii);
	char chHex[] = "0123456789ABCDEF";
	    
	for (i = 0; i<len; i++){
		hex[i*3] = chHex[((BYTE)ascii[i]) >> 4];
		hex[i*3 +1] = chHex[((BYTE)ascii[i]) & 0xf];
		hex[i*3 +2] = ' ';
	}
	hex[len * 3] = '\0';

	return len * 3;
}

//********************************************************************
// Function		:	Hex2Ascii
// Description	:	16����תASCII
// Input		:	char *hex	:	ʮ�������ַ���
// Output		:	char *ascii	:	ASCII�ַ���
// return		:	int tlen	:	ASCII�ַ�������
//********************************************************************
//int YString::Hex2Ascii(const char *hex, char *ascii)
//{
//	len = 0, i;
//	char * hexStr = DecToHex(0);
//	for(i=1; i<128; i++){
//		hexStr = DecToHex(i);
//		if(strcmp(hex, hexStr) == 0)
//			break;
//	}
//	if(i < 128){
//		ascii = ASCII[i];
//		int len = strlen(ascii);
//		//ascii[len] = '\0';
//		tlen = len;// + 1;
//	}
//
//	return tlen;
//}

//********************************************************************
// Function		:	ChineseToUnicode
// Description	:	����תUnicode����
// Input		:	LPCWSTR lpUnicode	:	�����ַ���
// Output		:	NONE
// return		:	CString strResult	:	Unicode�ַ���
//********************************************************************
CString YString::ChineseToUnicode(LPCWSTR lpUnicode)
{
	unsigned char *pCh = (unsigned char *) lpUnicode;
    int nCount = wcslen( lpUnicode );
    CString strResult;

    for ( int i = 0; i < nCount * sizeof(WCHAR); i += 2 ){
        CString strTemp;
        strTemp.Format( _T("%02X%02X"), pCh[i+1], pCh[i] );
        strResult += strTemp;
    }

    return strResult;
}

//********************************************************************
// Function		:	DecToHex
// Description	:	ʮ��������ת����ʮ�������ַ���������0x
// Input		:	int dec	:	ʮ��������
// Output		:	NONE
// return		:	CString	ʮ�������ַ���
//********************************************************************
//char * YString::DecToHex(unsigned int dec)
//{
//	char * hex;
//	CString tmp;
//	tmp.Format(_T("%x"), dec);
//	tmp.MakeUpper();
//	if(tmp.GetLength() < 2){
//		char ch = '0';
//		hex[0] = ch;
//		hex[1] = tmp.GetAt(0);
//		hex[2] = '\0';
//	}
//	else{
//		hex[0] = tmp.GetAt(0);
//		hex[1] = tmp.GetAt(1);
//		hex[2] = '\0';
//	}
//
//	return hex;
//}

//********************************************************************
// Function		:	DecToHexCh
// Description	:	ʮ��������(<16)ת����ʮ�������ַ�
// Input		:	int dec	:	ʮ��������
// Output		:	NONE
// return		:	char	ʮ�������ַ�
//********************************************************************
//char YString::DecToHexCh(unsigned int dec)
//{
//	char hex;
//
//	if(dec < 10){
//		hex = (char)dec;
//	}
//	else if(dec == 10){
//		hex = 'A';
//	}
//	else if(dec == 11){
//		hex = 'B';
//	}
//	else if(dec == 12){
//		hex = 'C';
//	}
//	else if(dec == 13){
//		hex = 'D';
//	}
//	else if(dec == 14){
//		hex = 'E';
//	}
//
//	return hex;
//}

//********************************************************************
// Function		:	ChineseToASCII
// Description	:	����תASCII�룬һ�����ֻ��ת�������ģ�ʹ��֮ǰascii�����ȷ���ռ�
// Input		:	CString chinese	:	Ҫת���������ַ���
// Output		:	char *ascii		:	ת�����ASCII�ַ���ָ�룬ΪNULLʱ���Ի�ȡת�����ASCII�ַ�������
// return		:	ת�����ASCII�ַ�������
//********************************************************************
int YString::ChineseToASCII(CString chinese, char *ascii)
{
	CString unicode = YString::ChineseToUnicode(chinese);
	int size = unicode.GetLength();
	int len = size/2;
	if(ascii == NULL){
		return len;
	}
	// CString to char *
	char * buf = new char[size];
	if(!buf)
		delete []buf;
	for(int i=0; i<size; i++)
		buf[i] = unicode.GetAt(i);
	// unicode string to ascii string
	// ת�����ַ����෴�ģ���Ҫ��ת�ַ���
	sscanf(buf, "%x", ascii);
	BOOL ret = RevertChar(len, ascii);
	delete []buf;

	return len;
}

//********************************************************************
// Function		:	RevertChar
// Description	:	����str�е��ַ�
// Input1		:	int len		:	����ĳ���
// Input2		:	char *str	:	������ַ���ָ��
// Output		:	char *str	:	��ת����ַ���ָ��
// return		:	�ɹ�	:	TRUE	;	ʧ��	:	FALSE
//********************************************************************
BOOL YString::RevertChar(int len, char *str)
{
	if(len <= 0)
		return FALSE;
	char *buf = new char[len];
	buf = strcpy(buf, str);
	if(!buf){
		delete []buf;
		return FALSE;
	}
	for(int i=0; i<len; i++)
		str[i] = buf[len-i-1];

	delete []buf;

	return TRUE;
}

//********************************************************************
// Function		:	ChineseToASCIIStr
// Description	:	�����ַ���תASCII���ַ���
// Input		:	CString chinese	:	Ҫת���������ַ���
// Output		:	NONE
// return		:	CString ascii	:	ת�����ASCII�ַ���
//********************************************************************
CString YString::ChineseToASCIIStr(CString chinese)
{
	CString ascii;

	int len;
	char * buf = YString::ChineseToASCII(chinese, len);
	buf[len] = '\0';
	for(int i=0; i<len; i++){
		ascii.AppendChar(buf[i]);
	}
	free(buf);
	//for(int i=0; i<chinese.GetLength(); i++){
	//	CString tmp = chinese.Mid(i, 1);
	//	// ��ȡת�����ASCII�������ڷ���ռ�
	//	int len = ChineseToASCII(tmp, NULL);
	//	buf = new char[len];
	//	if(!buf){
	//		delete []buf;
	//	}
	//	// ����תASCII
	//	len = ChineseToASCII(tmp, buf);
	//	for(int j=0; j<len; j++){
	//		ascii.AppendChar(buf[j]);
	//	}
	//}
	//delete []buf;

	return ascii;
}

//********************************************************************
// Function		:	AsciiToChinese
// Description	:	ASCIIת����
// Input		:	char * ascii	:	ascii�ַ������磺"`O}Y6e0R",���Ӧ��������:����յ�
// Output		:	NONE
// return		:	CString chinese	:	�����ַ���
//********************************************************************
CString YString::AsciiToChinese(char * ascii)
{
	CString chinese;
	// ��ASCII�ַ���ǿ��ת��WCHAR���ͼ��ɰѶ�Ӧ��ASCII�ַ�ת������
	WCHAR *wch = (WCHAR *)ascii;
	int len = wcslen(wch);
	for(int i=0; i<len; i++){
		chinese.AppendChar(wch[i]);
	}

	return chinese;
}

//********************************************************************
// Function		:	TwoTwoChange
// Description	:	�ַ�����������
// Input1		:	char *str	:	Ҫ�������ַ���
// Input2		:	int length	:	�ַ�������
// Output		:	NONE
// return		:	char *str	:	��������ַ���
//********************************************************************
char * YString::TwoTwoChange(char *str, int length)
{
	int len = ( (length%2 == 0) ? length : length - 1 );
	char * buf = new char[length+1];
	for(int i=0; i<len; i+=2){
		buf[i] = str[i+1];
		buf[i+1] = str[i];
	}
	buf[length] = '\0';

	return buf;
}

//********************************************************************
// Function		:	TwoTwoChange2
// Description	:	�ַ�����������
// Input1		:	char *str	:	Ҫ�������ַ���,��������ַ���
// Input2		:	int length	:	�ַ�������
// Output		:	NONE
// return		:	NONE
//********************************************************************
void YString::TwoTwoChange2(char *str, int length)
{
	int len = ( (length%2 == 0) ? length : length - 1 );
	for(int i=0; i<len; i+=2){
		char ch1 = str[i+1];
		char ch2 = str[i];
		str[i] = ch1;
		str[i+1] = ch2;
	}
}

//********************************************************************
// Function		:	ChineseToASCII
// Description	:	����תASCII��
// Input		:	LPCWSTR chinese	:	Ҫת���������ַ���
// Output		:	int &aLen		:	ת�����ASCII�ַ�������
// return		:	char *ascii		:	ת�����ASCII�ַ���ָ��
//********************************************************************
char * YString::ChineseToASCII(LPCWSTR chinese, int &aLen)
{
	char * buf = (char *)chinese;
	aLen = strlen(buf);

	return buf;
}

//********************************************************************
// Function		:	AsciiToChinese
// Description	:	ASCIIת����
// Input		:	CString ascii	:	ascii�ַ������磺"`O}Y6e0R",���Ӧ��������:����յ�
// Output		:	NONE
// return		:	CString chinese	:	�����ַ���
//********************************************************************
CString YString::AsciiToChinese(CString ascii)
{
	/*char *buf = YString::CStringToChar_(ascii);
	int ll = ascii.GetLength();
	buf[ll] = '\0';
	char *tmp = YString::TwoTwoChange(buf, ll );
	tmp[ll] = '\0';*/
	int ll = ascii.GetLength();
	if(ll <= 0)	return ascii;
	char *buf = new char[ll+1];
	for(int i=0; i<ll; i++){
		buf[i] = ascii.GetAt(i);
	}
	buf[ll] = '\0';
	char *tmp = YString::TwoTwoChange(buf, ll );
	// ��ASCII�ַ���ǿ��ת��WCHAR���ͼ��ɰѶ�Ӧ��ASCII�ַ�ת������
	WCHAR *wch = (WCHAR *)tmp;
	int len = wcslen(wch);
	if(len*2 != ll)
		len = ll/2;
	CString chinese;
	for(int i=0; i<len; i++){
		chinese.AppendChar(wch[i]);
	}
	/*chinese.AppendChar('\0');
	CString aa;
	aa.Format(_T("wch len = %d\nascii len = %d"), len, ll);
	AfxMessageBox(aa);*/

	free(buf);
	free(tmp);
	//free(wch);
	buf = NULL;
	tmp = NULL;
	wch = NULL;

	return chinese;
}


//********************************************************************
// Function		:	ChEnToASCII
// Description	:	����תASCII��
// Input		:	CString data	:	Ҫת���������ַ���
// Output		:	int &aLen		:	ת�����ASCII�ַ�������
// return		:	char *ascii		:	ת�����ASCII�ַ���ָ��
//********************************************************************
char * YString::ChEnToASCII(CString data, int &aLen)
{
	int len = data.GetLength(); 
	char *buf = new char[len*2];
	int t_len = 0;
	for(int i=0; i<len; i++){
		WCHAR str = data.GetAt(i);
		LPCWSTR tmp = &str;
		if(str > 0x80){
			char * chTmp = (char *)(tmp);
			buf[t_len++] = chTmp[1];
			buf[t_len++] = chTmp[0];
		}
		else{
			char * chTmp = (char *)(tmp); 
			buf[t_len++] = (char)0x00;
			buf[t_len++] = chTmp[0];
		}
	}
	buf[t_len] = '\0';
	aLen = t_len;

	return buf;
}

//********************************************************************
// Function		:	isAllEnglish
// Description	:	��⴮�Ƿ�ΪȫӢ���ַ�
// Input		:	CString data	:	Ҫ�����ַ���
// Output		:	NONE
// return		:	TRUE: ȫӢ���ַ���	FALSE: �������ĵ��ַ���
//********************************************************************
BOOL YString::isAllEnglish(CString data)
{
	BOOL ret = FALSE;
	int len = data.GetLength();
	int count = 0;
	for(int i=0; i<len; i++){
		WCHAR str = data.GetAt(i);
		if(str > 0x80){
			break;
		}
		else{
			count++;
		}
	}
	if(count == len)
		ret = TRUE;

	return ret;
}

//********************************************************************
// Function		:	CString2Char
// Description	:	CStringתchar*
// Input		:	str	: CString�����ַ������ɺ���Ӣ��
// Input		:	bufInLen	: buf��size��С
// Output		:	buf	: char�����ַ���
// Output		:	bufOutLen	: ʵ�ʶ�ȡ�ַ����ĳ���
// return		:	TRUE/FALSE
//********************************************************************
BOOL YString::CString2Char(CString str, char *buf, int bufInLen, int& bufOutLen)
{
	if(str.IsEmpty() || buf == NULL || bufInLen<=0)	return FALSE;
	// CString to WCHAR
	WCHAR *wch = (WCHAR*)str.GetBuffer(str.GetLength());
	memset(buf, 0, bufInLen);
	// WCHRA to char
	WideCharToMultiByte( CP_ACP, 0, wch, -1, buf, bufInLen, NULL, NULL );
	// get str length, this will cout the string length which can include chinese and english
	bufOutLen = 0;
	for(int i=0; i<str.GetLength(); i++){
		WCHAR data = str.GetAt(i);
		if(data > 0x80){
			bufOutLen += 2;
		}
		else{
			bufOutLen++;
		}
	}

	return TRUE;
}

//********************************************************************
// Function		:	Char2CString
// Description	:	char*תCString
// Input		:	buf	: char�����ַ���
// Input		:	bufLen	: buf�ĳ���
// Output		:	str	: CString�����ַ���
// return		:	TRUE/FALSE
//********************************************************************
BOOL YString::Char2CString(char *buf, int bufLen, CString &str)
{
	if(buf == NULL || bufLen<=0)	return FALSE;

	int m = MultiByteToWideChar( CP_ACP, 0, buf, bufLen, NULL, 0 );
	WCHAR wch[2048];
	memset(wch, 0, sizeof(wch));
	if(m > 0){
		MultiByteToWideChar( CP_ACP, 0, buf, bufLen, wch, m );
		str.Format(_T("%s"), wch);
	}
	else{
		for(int i=0; i<strlen(buf); i++)
			str.AppendChar(buf[i]);		
	}

	return TRUE;
}

//********************************************************************
// Function		:	Hex2Char
// Description	:	ʮ�������ַ���תASCII�ַ�
// Input		:	hex	:	ʮ�������ַ�������󳤶�3
// Output		:	ascii:	ת�����ASCII�ַ�
// return		:	TRUE/FALSE
//********************************************************************
BOOL YString::Hex2Char(const char hex[], char *ascii)
{
	if(hex == NULL || ascii == NULL)	return FALSE;
	char cRtn = '\0';

	// д����λ
	if( (hex[0]>='0') && (hex[0]<='9') ){
		cRtn = (hex[0] & 0x0F)<<4;
	}
	else if( (hex[0]>='A') && (hex[0]<='F') ){
		cRtn = (hex[0]-'A'+10)<<4;
	}
	else if( (hex[0]>='a') && (hex[0]<='f') ){
		cRtn = (hex[0]-'a'+10)<<4;
	}
	
	// д����λ
	if( (hex[1]>='0') && (hex[1]<='9') ){
		cRtn += (hex[1] & 0x0F);
	}
	else if( (hex[1]>='A') && (hex[1]<='F') ){
		cRtn += (hex[1]-'A'+10);
	}
	else if( (hex[1]>='a') && (hex[1]<='f') ){
		cRtn += (hex[1]-'a'+10);
	}
	*ascii = cRtn;

	return TRUE;
}

//********************************************************************
// Function		:	Hexs2Chars
// Description	:	ʮ�������ַ���תASCII�ַ�
// Input		:	hex	:	ʮ�������ַ���
// Input		:	hexLen	: hex�ַ�������
// Output		:	ascii:	ת�����ASCII�ַ���
// return		:	TRUE/FALSE
//********************************************************************
BOOL YString::Hexs2Chars(char *hex, int hexLen, char *ascii)
{
	if(hex == NULL || ascii == NULL)	return FALSE;
	if(hexLen == 0 || hexLen%2 != 0)	return FALSE;

	BOOL ok = FALSE;
	char *p = ascii;
	char *h = hex;
	for(int i=0; i<hexLen; i+=2){
		char tmpHex[3] = {0};
		tmpHex[0] = *h++;
		tmpHex[1] = *h++;
		ok = YString::Hex2Char(tmpHex, p++);
		if(!ok)	break;
	}
	*p = '\0';

	return ok;
}

//********************************************************************
// Function		:	CString2Chars
// Description	:	CStringתchar�ַ���
// Input		:	str	: Ҫת����CString�ַ���
// Output		:	bufout : ת�����char�ַ���,����ΪNULLʱ������ת�����char�ַ�������
// Output		:	outLen : ת�����ASCII�ַ�
// return		:	TRUE/FALSE
//********************************************************************
BOOL YString::CString2Chars(CString str, char *bufout, int* outLen)
{
	if(str.IsEmpty())	return FALSE;
	*outLen = str.GetLength();
	if(bufout == NULL){
		return TRUE;
	}

	char *p = bufout;
	for(int i=0; i<*outLen; i++){
		*p++ = str.GetAt(i);
	}
	*p = '\0';

	return TRUE;
}

//********************************************************************
// Function		:	AsciiToChinese
// Description	:	ASCIIת����
// Input		:	ascii	: ascii�ַ������磺"`O}Y6e0R",���Ӧ��������:����յ�
// Input		:	inLen	: ascii�ַ����ĳ���
// Output		:	NONE
// return		:	CString chinese	:	�����ַ���
//********************************************************************
CString YString::AsciiToChinese(char * ascii, int inLen)
{
	if(ascii == NULL || inLen < 1)	return L"";
	CString chinese;
	// ��ASCII�ַ���ǿ��ת��WCHAR���ͼ��ɰѶ�Ӧ��ASCII�ַ�ת������
	WCHAR *wch = (WCHAR *)ascii;
	int len = inLen/2;
	if(inLen%2 != 0)	len++;
	for(int i=0; i<len; i++){
		if(wch[i] == 0x0)	continue;
		chinese.AppendChar(wch[i]);
	}

	return chinese;
}

//********************************************************************
// Function		:	Hex2ChEn
// Description	:	��Ӣ�Ķ�Ӧ��ʮ�������ַ���ת����Ӣ��
// Input		:	hex	: ��Ӣ�Ķ�Ӧ��ʮ�������ַ���
// Output		:	chEn : ��Ӣ��
// return		:	TRUE/FALSE
//********************************************************************
BOOL YString::Hex2ChEn(CString hex, CString &chEn)
{
	if(hex.IsEmpty())	return FALSE;
	// CString to char*
	int hexLen = hex.GetLength();
	char* chHex = new char[hexLen+1];
	memset(chHex, 0, hexLen+1);
	int outHexlen = 0;
	BOOL ok = YString::CString2Chars(hex, chHex, &outHexlen);
	if(!ok){
		delete[] chHex;
		chHex = NULL;
		return FALSE;
	}
	// hex to ascii
	int asciiLen = outHexlen/2 +1;
	char* ascii = new char[asciiLen];
	ok = YString::Hexs2Chars(chHex, outHexlen, ascii);
	if(!ok){
		delete[] ascii;
		ascii = NULL;
		return FALSE;
	}
	// ascii two two change
	YString::TwoTwoChange2(ascii, asciiLen);
	// ascii to chinese and/or english
	chEn = YString::AsciiToChinese(ascii, asciiLen-1);

	delete[] ascii;
	ascii = NULL;
		
	delete[] chHex;
	chHex = NULL;

	return TRUE;
}

//********************************************************************
// Function		:	ChEnToASCII
// Description	:	����תASCII��
// Input		:	CString data	:	Ҫת���������ַ���
// Input		:	ascii			:	ת�����ASCII�ַ���
// Output		:	asciiLen		:	ת�����ASCII�ַ�������
// return		:	TRUE/FALSE
//********************************************************************
BOOL YString::ChEnToASCII(CString data, char *ascii, int &asciiLen)
{
	if(data.IsEmpty() || ascii == NULL)	return FALSE;

	int len = data.GetLength(); 
	//char *buf = new char[len*2];
	char *buf = ascii;
	int t_len = 0;
	for(int i=0; i<len; i++){
		WCHAR str = data.GetAt(i);
		LPCWSTR tmp = &str;
		if(str > 0x80){
			char * chTmp = (char *)(tmp);
			*buf++ = chTmp[1];
			//buf[t_len++] = chTmp[1];
			*buf++ = chTmp[0];
			//buf[t_len++] = chTmp[0];
			t_len += 2;
		}
		else{
			char * chTmp = (char *)(tmp); 
			//buf[t_len++] = (char)0x00;
			*buf++ = (char)0x00;
			//buf[t_len++] = chTmp[0];
			*buf++ = chTmp[0];
			t_len += 2;
		}
	}
	*buf = '\0';
	asciiLen = t_len;

	return TRUE;
}

//********************************************************************
// Function		:	ChEn2Hex
// Description	:	��Ӣ��ת����ʮ�������ַ���
// Input		:	chEn : ��Ӣ��
// Output		:	hex	: ��Ӣ�Ķ�Ӧ��ʮ�������ַ���
// return		:	TRUE/FALSE
//********************************************************************
BOOL YString::ChEn2Hex(CString chEn, CString &hex)
{
	if(chEn.IsEmpty())	return FALSE;

	// chinese and/or english to ascii
	int chenLen = chEn.GetLength()*2 + 1;
	int asciiLen = 0;
	char* ascii = new char[chenLen];
	memset (ascii, 0, chenLen);
	BOOL ok = YString::ChEnToASCII(chEn, ascii, asciiLen);
	if(!ok){
		delete[] ascii;
		ascii = NULL;
		return FALSE;
	}
	// ascii to hex
	CString tmp;
	char *p = ascii;
	for(int i=0; i<asciiLen; i++){
		/*if(*p == 0x0){
			tmp.Format(_T("0%x"), *p++);
			hex += tmp;
		}
		else{
			tmp.Format(_T("%x"), *p++ & 0xFF);
			hex += tmp;
		}*/
		tmp.Format(_T("%x"), *p++ & 0xFF);
		if(tmp.GetLength() == 1)	tmp.Insert(0, L"0");
		hex += tmp;
	}

	// hex to upper
	hex.MakeUpper();

	delete[] ascii;
	ascii = NULL;

	return TRUE;
}

//********************************************************************
// Function		:	Char2HexA
// Description	:	�ַ���ʮ������ת�ض�Ӧ��ʮ������
// Input		:	ch	: �ַ���ʮ������,eg: 'C'
// Output		:	hex : ASCIIʮ������
// return		:	TRUE/FALSE
//********************************************************************
BOOL YString::Char2HexA(char ch, char *hex)
{
	if(hex == NULL)	return FALSE;
	if(ch >= '0' && ch <= '9'){
		*hex = 0xFF & (ch - '0');
	}
	else if(ch >= 'A' && ch <= 'F'){
		*hex = 0xFF & (ch - 'A' + 10);
	}
	else if(ch >= 'a' && ch <= 'f'){
		*hex = 0xFF & (ch - 'a' + 10);
	}
	else{
		return	FALSE;
	}

	return TRUE;
}

//********************************************************************
// Function		:	Chars2HexsA
// Description	:	�ַ���ʮ�������ַ���ת�ض�Ӧ��ʮ�������ַ�����
// Input		:	string	: �ַ���ʮ�������ַ���,eg: "A498"
// Input		:	strLen	: string�ĳ��ȣ�������������
// Output		:	hex : ASCIIʮ�������ַ���
// return		:	TRUE/FALSE
//********************************************************************
BOOL YString::Chars2HexsA(char* string, int strLen, char* hex)
{
	if(string == NULL || hex == NULL || strLen <= 0)	return FALSE;
	char *p = hex;
	char *ps = string;
	for(int i=0; i<strLen; i++){
		BOOL ok = YString::Char2HexA(*ps++, p++);
		if(!ok)	return FALSE;
	}

	return TRUE;
}

//********************************************************************
// Function		:	Hexs2Code81
// Description	:	ʮ�������ַ���ת��81���ͱ���
// Input		:	hex	: ʮ�������ַ���,eg: {0xc,0xe,0xc,0xe}
// Input		:	hexLen	: hex�ĳ���
// Output		:	code : ת�����81���ͱ���
// return		:	TRUE/FALSE
//********************************************************************
BOOL YString::Hexs2Code81(char *hex, int hexLen, char *code)
{
	if(hex == NULL || code == NULL || hexLen <=0 )	return FALSE;
	char *phex = hex;
	char *pcode = code;

	if(hexLen%4 != 0)	return FALSE;
	int n = hexLen / 4;
	int m = 0x0;

	for(int i=0; i<n; i++){
		m = 0x0;
		m = 4 << (*phex & 0x01);
		*pcode++ = (*phex++) >> 1;

		*pcode = m & 0x08;
		m = 0x0;
		m = 4 << (*phex & 0x01);
		*pcode++ |= (*phex++) >> 1;

		*pcode++ = (*phex++ & (m | 0x07));

		*pcode++ = *phex++;
	}

	return TRUE;
}

//********************************************************************
// Function		:	Hex2CharA
// Description	:	ʮ������תASCII�ַ���(eg:0xc to C)
// Input		:	hex	:	ʮ������
// Output		:	ch:	ASCII�ַ���(eg:C)
// return		:	TRUE/FALSE
//********************************************************************
BOOL YString::Hex2CharA(char hex, char *ch)
{
	if(ch == NULL)	return FALSE;
	if(hex < 0x00 || hex > 0x0f)	return FALSE;
	if(hex >= 0x0 && hex <= 0x9){
		*ch = '0' + hex;
	}
	else if(hex <= 0x0f){
		*ch = 'A' + (hex - 10);
	}
	else{
		return	FALSE;
	}

	return TRUE;
}

//********************************************************************
// Function		:	Hexs2CharsA
// Description	:	ʮ����������תASCII�ַ�������(eg:{0xc,0xe,0xc,0xe} to "CECE")
// Input		:	hex	:	ʮ����������
// Input		:	hexLen : hex�ĳ���
// Output		:	string:	ASCII�ַ�������
// return		:	TRUE/FALSE
//********************************************************************
BOOL YString::Hexs2CharsA(char *hex, int hexLen, char *string)
{
	if(hex == NULL || string == NULL || hexLen <= 0)	return FALSE;
	char *phex = hex;
	char *pstring = string;

	for(int i=0; i<hexLen; i++){
		BOOL ok = YString::Hex2CharA(*phex++, pstring++);
		if(!ok)	return FALSE;
	}

	return TRUE;
}

//********************************************************************
// Function		:	ChangeCode81
// Description	:	ͨ����λת��81��������ΪUNICODE����
// Input		:	data	:	Ҫת��81���������ַ���
// Output		:	code	:	ת�����UNICODE����
// return		:	TRUE/FALSE
//********************************************************************
BOOL YString::ChangeCode81(CString data, CString &code)
{
	if(data.IsEmpty())	return FALSE;

	// CString to char*
	int len = data.GetLength();
	char* chs = new char[len+1];
	memset(chs, 0 , len+1);
	int chsLen = 0;
	BOOL ok = YString::CString2Chars(data, chs, &chsLen);
	if(!ok)	goto EXIT_CHANGECODE;

	// char to hex
	char* hex = new char[len+1];
	memset(hex, 0 , len+1);
	ok = YString::Chars2HexsA(chs, len, hex);
	if(!ok)	goto EXIT_CHANGECODE;

	// hex code81 to unicode
	memset(chs, 0 , len+1);
	ok = YString::Hexs2Code81(hex, len, chs);
	if(!ok)	goto EXIT_CHANGECODE;

	// hex to char
	memset(hex, 0 , len+1);
	ok = YString::Hexs2CharsA(chs, len, hex);
	if(!ok)	goto EXIT_CHANGECODE;

	// char* to CString
	char *p = hex;
	for(int i=0; i<len; i++){
		code.AppendChar(*p++);
	}

EXIT_CHANGECODE:
	if(hex != NULL){
		delete[] hex;
		hex = NULL;
	}

	if(chs != NULL){
		delete[] chs;
		chs = NULL;
	}

	return ok;
}

//********************************************************************
// Function		:	Decode81
// Description	:	��81�������͵�����ת��Ϊ��Ӣ��
// Input		:	hexdata	:	ʮ������(eg: 03A731CB32����������Ӧ����1��2)
// Output		:	chEN :	��Ӣ��
// return		:	TRUE/FALSE
//********************************************************************
BOOL YString::Decode81(CString hexdata, CString &chEN)
{
	if(hexdata.IsEmpty() || hexdata.GetLength()<6)	return FALSE;

	BOOL ok = FALSE;
	CString strLen = hexdata.Left(2);
	int n = YString::CStringToInt2(strLen);// ���ж��ٸ��֣�������Ӣ�ģ����Ŀ϶�ֻ��һ��(�п����Ǽ����ص���)
	int count = 4 + (n-1)*2;
	CString chTmp = hexdata.Mid(2, 2);
	//CString chinese;
	CString left, right, data;
	BOOL leftSign = TRUE;
	for(int i=0; i<n; i++){
		CString strTmp = hexdata.Mid(4+i*2, 2);
		if(strTmp.Compare(L"80") > 0){
			CString tt, ttt;
			ok = YString::ChangeCode81(chTmp + strTmp, tt);
			if(!ok)	return FALSE;
			ok = YString::Hex2ChEn(tt, ttt);
			if(!ok)	return FALSE;
			data.Append(ttt);
			leftSign = FALSE;
			continue;
		}
		CString tmp;
		tmp.Format(_T("00%s"), strTmp);
		if(leftSign){
			left.Append(tmp);
		}
		else{
			CString t_right;
			ok = YString::Hex2ChEn(tmp, t_right);
			if(!ok)	return FALSE;
			data.Append(t_right);
		}
	}
	if(!left.IsEmpty()){
		CString t_left;
		ok = YString::Hex2ChEn(left, t_left);
		if(!ok)	return FALSE;
		data.Insert(0, t_left);
	}

	chEN = data;

	return ok;
}

//********************************************************************
// Function		:	Decode82
// Description	:	��82�������͵�����ת��Ϊ��Ӣ��
// Input		:	hexdata	:	ʮ������(eg: 03A731CB32����������Ӧ����1��2)
// Output		:	chEN :	��Ӣ��
// return		:	TRUE/FALSE
//********************************************************************
BOOL YString::Decode82(CString hexdata, CString&chEN)
{
	if(hexdata.IsEmpty() || hexdata.GetLength()<6)	return FALSE;
	
	CString strLen = hexdata.Left(2);
	int n = YString::CStringToInt2(strLen);// ���ж��ٸ��֣�������Ӣ�ģ����Ŀ϶�ֻ��һ��
	int count = 4 + (n-1)*2;

	BOOL leftSign = TRUE;
	CString chTmp = hexdata.Mid(2, 4);
	CString left, right, data;
	for(int i=0; i<n; i++){
		CString strTmp = hexdata.Mid(6+i*2, 2);
		if(strTmp == L"80"){
			data.Append(chTmp);
			leftSign = FALSE;
			continue;
		}
		CString tmp;
		tmp.Format(_T("00%s"), strTmp);
		if(leftSign){// ������ǰ����ַ�
			left.Append(tmp);
		}
		else{// �������ұߵ��ַ�
			data.Append(tmp);
		}
	}
	if(!left.IsEmpty()){
		data.Insert(0, left);
	}

	BOOL ok = YString::Hex2ChEn(data, chEN);

	return ok;
}
