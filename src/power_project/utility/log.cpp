//---------------------------------------------------------------------------//
// (C)QQW
//---------------------------------------------------------------------------//

#include "stdafx.h"
#include "log.h"
#include <chrono>
#include <ctime>

using namespace QQW;

typedef std::chrono::system_clock Clock;

//---------------------------------------------------------------------------//
bool CLog::sm_isOpen = false;
//---------------------------------------------------------------------------//
CLog::CLog()
:m_fileName{ LOG_FILE_NAME }
{
}
//---------------------------------------------------------------------------//
CLog::~CLog()
{
	if (m_outputFile.is_open())
	{
		m_outputFile.close();
	}
}
//---------------------------------------------------------------------------//
CLog& CLog::get(bool setname)
{
	static CLog log;
	if (!log.isOpen() && !setname)
	{
		log.open();
	}
	return log;
}
//---------------------------------------------------------------------------//
void CLog::write(const std::string& outText)
{
	writeSeparation();
	writeTimeNow();
	m_outputFile << outText;
	writeSeparation();
}
//---------------------------------------------------------------------------//
void CLog::writeLine(const std::string& line, const std::string& file, long codeLine)
{
	writeTimeNow();
	m_outputFile << file << " >> " << codeLine << "||" << line << std::endl;
}
//---------------------------------------------------------------------------//
//---------------------------------------------------------------------------//
void CLog::writeSeparation()
{
	m_outputFile << "____________________________________________________________________" << std::endl;
}
//---------------------------------------------------------------------------//
void CLog::open()
{
	m_outputFile.open(m_fileName, std::wofstream::out | std::wofstream::trunc);
	writeTimeNow();
	m_outputFile << "LOG START " << std::endl;
	sm_isOpen = true;
}
//---------------------------------------------------------------------------//
void CLog::close()
{
	writeTimeNow();
	m_outputFile << "LOG CLOSE" << std::endl;
	m_outputFile.close();
	sm_isOpen = false;
}
//---------------------------------------------------------------------------//
void CLog::writeTimeNow()
{
	auto timeNow = Clock::now();
	std::time_t timeNow_c = Clock::to_time_t(timeNow);
	struct tm parts;
	localtime_s(&parts, &timeNow_c);
	
	m_outputFile << parts.tm_year + 1900 << "/" << parts.tm_mon + 1 << \
		"/" << parts.tm_mday << " " << parts.tm_hour << \
		":" << parts.tm_min << ":" << parts.tm_sec << "||";
}
//---------------------------------------------------------------------------//
std::string CLog::getFilename() const 
{
	return m_fileName; 
}
//---------------------------------------------------------------------------//

void CLog::setFilename(const std::string& val)
{
	m_fileName = val; 
	sm_isOpen = false;
}
//---------------------------------------------------------------------------//
