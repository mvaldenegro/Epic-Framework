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

#include "Logger.h"
#include "LoggerRepository.h"

namespace Epic {
    namespace Util {
        namespace Logging {

            Logger::Logger()
            : mAppender(nullptr), mLoggerName()
            {
            }

            Logger::Logger(const Epic::Core::ASCIIString& name)
            : mAppender(nullptr), mLoggerName(name)
            {
            }

            Logger::Logger(Logger&& logger)
            : mAppender(logger.mAppender), mLoggerName(logger.mLoggerName)
            {
                logger.mAppender = nullptr;
                logger.mLoggerName = Epic::Core::ASCIIString();
            }

            Logger::~Logger()
            {
            }

            Logger& Logger::getLogger(const Epic::Core::ASCIIString& loggerName)
            {
                return LoggerRepository::instance().getLogger(loggerName);
            }

            void Logger::debug(const Epic::Core::ASCIIString &message)
            {
                appender()->logMessage(Level::Debug, name(), message);
            }

            void Logger::info(const Epic::Core::ASCIIString &message)
            {
                appender()->logMessage(Level::Info, name(), message);
            }

            void Logger::warning(const Epic::Core::ASCIIString &message)
            {
                appender()->logMessage(Level::Warning, name(), message);
            }

            void Logger::error(const Epic::Core::ASCIIString &message)
            {
                appender()->logMessage(Level::Error, name(), message);
            }

            void Logger::fatal(const Epic::Core::ASCIIString &message)
            {
                appender()->logMessage(Level::Fatal, name(), message);
            }

        } /* namespace Logging */
    } /* namespace Util */
} /* namespace Epic */
