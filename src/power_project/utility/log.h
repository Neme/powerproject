//---------------------------------------------------------------------------//
// (C)QQW
//---------------------------------------------------------------------------//
#pragma once

#include <fstream>

#define ERROR_LOG( x ) QQW::CLog::get().writeLine(x , __FILE__, __LINE__)
#define LOG_FILE_NAME "log.txt"

namespace QQW // Singleton
{
	class CLog
	{
	public:
		static CLog& get(bool setname = false);
		void writeLine(const std::string& line, const std::string& file, long codeLine);
		void write(const std::string& outText);
		void writeSeparation();
		void close();
		void open();
		bool isOpen(){ return sm_isOpen; };

		~CLog();

		std::string getFilename() const;
		void setFilename(const std::string& val);

	protected:
		CLog();
		std::ofstream m_outputFile;
		std::string m_fileName;
	
	private:
		void writeTimeNow();
		static bool sm_isOpen;
	};
};

