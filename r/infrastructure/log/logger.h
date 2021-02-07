#ifndef R_SPRITE_H
#define R_SPRITE_H

#include "log4cxx/logger.h"
 
namespace r {
	namespace infrastructure {
		class Logger {
			static log4cxx::LoggerPtr logger;
 
			public:
				void doIt();
		};
	}
}

#endif //R_SPRITE_H