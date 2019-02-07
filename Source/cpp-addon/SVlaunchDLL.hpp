//wide strings only,no ANSI string version
//CodePage:936(GBK)
//�ַ���ȫ��wstring/wchar_tע��һ��


//#define __declspec()
#pragma once

#include <vector>
#include <iostream>
#include <memory>
#include <string>
#include <Windows.h>



namespace SVLaunch_CPP 
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
		BOOL StartSV(
			const SVPARAM param,
			const wchar_t* SvDir,
			PROCESS_INFORMATION * p_piSv,
			STARTUPINFOW * p_siSv);
		//Advanced
		BOOL StartSV(
			const SVPARAM param,
			const wchar_t* SvDir);
		//Common
		BOOL StartSV();
		void setparam(SVPARAM src) noexcept;
		//WINAPI, startupinfo
		void setSI(STARTUPINFOW src) noexcept;
		//sv Diretory
		void setDIR(wchar_t* src) noexcept;
		//WINAPI, ProcessInformation
		PROCESS_INFORMATION getPI() noexcept;
		void setcluster(std::wstring src)
		{
			this->SVParam.cluster = src;
		}
		SV();
		SV(SVPARAM param);
		~SV();
	private:
		const wchar_t* svDIR;
		SVPARAM SVParam;
		PROCESS_INFORMATION piSV;
		STARTUPINFOW siSv;
	};

	//����
	unsigned short BuildArg(const SVLaunch_CPP::SVPARAM &a,wchar_t* target);
};
