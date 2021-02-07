#include "logger.h"
#include "log4cxx/logger.h"
#include "log4cxx/basicconfigurator.h"
#include "log4cxx/propertyconfigurator.h"
#include "log4cxx/helpers/exception.h"


using namespace r::infrastructure;

using namespace log4cxx;
using namespace log4cxx::helpers;


LoggerPtr Log::logger(Logger::getLogger("runpix"));

void Log::init(const char* file){
    if (file != NULL)
    {
        // BasicConfigurator replaced with PropertyConfigurator.
        PropertyConfigurator::configure(file);
    }
    else
    {
        BasicConfigurator::configure();
    }
};	

void Log::info(std::string input){
	LOG4CXX_INFO( Log::logger, input)
};

void Log::error(std::string input){
	LOG4CXX_ERROR( Log::logger, input)
};

