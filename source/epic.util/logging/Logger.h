/* 
 * File:   Logger.h
 * Author: hunts
 *
 * Created on 8 de enero de 2011, 01:47 PM
 */

#ifndef EPIC_UTIL_LOGGING_LOGGER_H
#define	EPIC_UTIL_LOGGING_LOGGER_H

namespace Epic {
    namespace Util {
        namespace Logging {
            class Logger
            {
                public:
                    virtual void debug(String msg) = 0;
                    virtual void error(String msg) = 0;
                    virtual void warning(String msg) = 0;
                    virtual void fatal(String msg) = 0;
            };
        };
    };
};

#endif	/* EPIC_UTIL_LOGGING_LOGGER_H */

