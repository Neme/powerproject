//---------------------------------------------------------------------------//
// (C)QQW
//---------------------------------------------------------------------------//
#include "stdafx.h"
#include "log.h"
#include "config.h"
//---------------------------------------------------------------------------//
using namespace QQW;
//---------------------------------------------------------------------------//

//---------------------------------------------------------------------------//
bool CConfig::sm_isOpen = false;
//---------------------------------------------------------------------------//
CConfig& CConfig::get(bool setname)
{
	static CConfig config;
	if (!config.isConfigOpen() && !setname)
	{
		config.open();
	}
	return config;
}
//---------------------------------------------------------------------------//
void CConfig::open()
{
	using boost::property_tree::json_parser_error;
	using boost::property_tree::ptree;
	try
	{
		read_json(m_filename, m_pTree);
	}
	catch (json_parser_error& e)
	{
		ERROR_LOG(e.what());
	}
}
//---------------------------------------------------------------------------//
CConfig::CConfig()
:m_filename{CONFIG_FILE_NAME}
{
	
}
//---------------------------------------------------------------------------//
std::string CConfig::getFilename() const
{ 
	return m_filename; 
}
//---------------------------------------------------------------------------//
void CConfig::setFilename(const std::string& val)
{ 
	m_filename = val;

}
//---------------------------------------------------------------------------//
template<typename T>
T CConfig::getValue(const std::string& key)
{
	return m_pTree.get<T>(key);
}
template int CConfig::getValue<int>(const std::string& key);
template std::string CConfig::getValue<std::string>(const std::string& key);
template float CConfig::getValue<float>(const std::string& key);
template bool CConfig::getValue<bool>(const std::string& key);


//---------------------------------------------------------------------------//
