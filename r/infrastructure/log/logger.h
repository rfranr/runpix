#ifndef R_SPRITE_H
#define R_SPRITE_H

#include "log4cxx/logger.h"

namespace r { namespace infrastructure {

    /**
     * To Work with the log
     */
    class Log {
        static log4cxx::LoggerPtr logger;

    public:
        /**
         * Initialize the log with the configuration if it is NULL, configure by default.
         * @param file Configuration
         */
        static void init(const char* file);
        /**
         * Log info
         * @param message to log
         */
        static void info(std::string message);
        /**
         * Log error
         * @param message to log
         */
        static void error(std::string message);
    };

}}


#endif //R_SPRITE_H

