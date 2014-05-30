//---------------------------------------------------------------------------//
// (C)QQW
//---------------------------------------------------------------------------//
#pragma once

#include <boost\property_tree\json_parser.hpp>

#define CONFIG_FILE_NAME "data/config.json"

namespace QQW
{
	class CConfig //Singleton
	{

	public:
		static CConfig& get(bool setname = false);

		template<typename T>
		T getValue(const std::string& key);

		std::string getFilename() const;
		void setFilename(const std::string& val);

		bool isConfigOpen(){ return sm_isOpen; };
		void open();

	protected:
		CConfig();

	private:
		static bool sm_isOpen;
		boost::property_tree::ptree m_pTree;

		std::string m_filename;


	};
};