/*
 * File:   Logger.h
 * Author: hunts
 *
 * Created on 8 de enero de 2011, 01:47 PM
 */

#ifndef EPIC_UTIL_LOGGING_LOGGER_H
#define	EPIC_UTIL_LOGGING_LOGGER_H

#include <epic.core/String.h>

namespace Epic {
    namespace Util {
        namespace Logging {
            class Logger
            {
                private:
                    static Logger staticRootLogger;

                public:

                    void debug(Epic::Core::String msg) = 0;
                    void error(Epic::Core::String msg) = 0;
                    void warning(Epic::Core::String msg) = 0;
                    void fatal(Epic::Core::String msg) = 0;
            };
        };
    };
};

#endif	/* EPIC_UTIL_LOGGING_LOGGER_H */

