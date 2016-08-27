#include "showParameters.h"

std::string showParameters(std::map<std::string, std::string> info)
{
	std::string execute="";
	std::cout<<"Parameters:"<<std::endl;
	std::map<std::string, std::string>::iterator it= info.begin();
	for (it = info.begin(); it!= info.end(); it++)
	{
		std::cout<< it->first << "....." << it->second <<std::endl;
	}
	std::cout<<"Continue?...(Y/N)"<<std::endl;
	std::cin>>execute;
	return execute;
}
