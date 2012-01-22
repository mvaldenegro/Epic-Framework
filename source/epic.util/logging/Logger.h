/*
 * Copyright (C) 2011 Matias Valdenegro <matias.valdenegro@gmail.com>
 * This file is part of Epic Framework.
 *
 * Epic Framework is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 *
 * Epic Framework is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Epic Framework.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef EPIC_UTIL_LOGGING_LOGGER_H
#define	EPIC_UTIL_LOGGING_LOGGER_H

#include <epic.core/ASCIIString.h>

#include <epic.util/logging/Appender.h>

namespace Epic {
    namespace Util {
        namespace Logging {

            class Logger
            {
                private:
                    Appender *mAppender;
                    Epic::Core::ASCIIString mLoggerName;

                public:
                    Logger();
                    Logger(const Epic::Core::ASCIIString& name);
                    Logger(const Logger& logger);
                    Logger(Logger&& logger);
                    ~Logger();

                    static Logger& getLogger(const Epic::Core::ASCIIString& loggerName);

                    inline Appender *appender() const
                    {
                        return mAppender;
                    }

                    inline void setAppender(Appender *appender)
                    {
                        mAppender = appender;
                    }

                    inline Epic::Core::ASCIIString name() const
                    {
                        return mLoggerName;
                    }

                    void debug(const Epic::Core::ASCIIString &message);
                    void info(const Epic::Core::ASCIIString &message);
                    void warning(const Epic::Core::ASCIIString &message);
                    void error(const Epic::Core::ASCIIString &message);
                    void fatal(const Epic::Core::ASCIIString &message);
            };
        }
    }
}

#endif	/* EPIC_UTIL_LOGGING_LOGGER_H */

