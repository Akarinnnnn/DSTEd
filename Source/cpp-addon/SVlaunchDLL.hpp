//wide strings only,no ANSI string version
//CodePage:936(GBK)
//�ַ���ȫ��wstring/wchar_tע��һ��

#pragma once
#if SVLAUNCHDLL_EXPORTS
#define SVLAUNCHERDLL_API __declspec(dllexport)
#else
#define SVLAUNCHERDLL_API __declspec(dllimport)
#endif

//#define SVLAUNCHERDLL_API __declspec()

#include <vector>
#include <iostream>
#include <memory>
#include <string>
#include <Windows.h>



namespace SVLaunchDLL 
{
	//����
	struct SVPARAM
	{
		std::wstring cluster = L"Cluster_1";
		std::wstring shard = L"Master";
		std::wstring logbackup;
		std::wstring storage_root;
		std::wstring confdir;
		std::wstring tickrate;
		std::wstring maxplayers;
		std::wstring SteamID3;
		std::wstring SteamID64;
		bool offline = true;
		bool fo = false;
	};

	class SV
	{
	public:
		//Advanced
		SVLAUNCHERDLL_API BOOL StartSV(
			const SVPARAM param,
			const wchar_t* SvDir,
			PROCESS_INFORMATION * p_piSv,
			STARTUPINFOW * p_siSv);
		//Advanced
		SVLAUNCHERDLL_API BOOL StartSV(
			const SVPARAM param,
			const wchar_t* SvDir);
		//Common
		SVLAUNCHERDLL_API BOOL StartSV();
		SVLAUNCHERDLL_API void setparam(SVPARAM src) noexcept;
		//WINAPI, startupinfo
		SVLAUNCHERDLL_API void setSI(STARTUPINFOW src) noexcept;
		//sv Diretory
		SVLAUNCHERDLL_API void setDIR(wchar_t* src) noexcept;
		//WINAPI, ProcessInformation
		SVLAUNCHERDLL_API PROCESS_INFORMATION getPI() noexcept;
		SVLAUNCHERDLL_API void setcluster(std::wstring src)
		{
			this->SVParam.cluster = src;
		}
		SVLAUNCHERDLL_API SV();
		SVLAUNCHERDLL_API SV(SVPARAM param);
		SVLAUNCHERDLL_API ~SV();
	private:
		const wchar_t* svDIR;
		SVPARAM SVParam;
		PROCESS_INFORMATION piSV;
		STARTUPINFOW siSv;
	};

	//����
	unsigned short BuildArg(const SVLaunchDLL::SVPARAM &a,wchar_t* target);
};
