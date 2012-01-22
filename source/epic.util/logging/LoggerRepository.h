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

#ifndef LOGGERREPOSITORY_H_
#define LOGGERREPOSITORY_H_

#include <epic.core/ASCIIString.h>
#include <epic.core/HashTable.h>
#include <epic.util/logging/Logger.h>

namespace Epic {
    namespace Util {
        namespace Logging {

            class LoggerRepository
            {
                private:
                    Epic::Core::HashTable<Epic::Core::ASCIIString, Logger> mLoggerRepo;
                    static LoggerRepository *mGlobalInstance;

                public:
                    LoggerRepository();
                    virtual ~LoggerRepository();

                    static LoggerRepository& instance();

                    Logger& getLogger(const Epic::Core::ASCIIString& loggerName);
            };

        } /* namespace Logging */
    } /* namespace Util */
} /* namespace Epic */
#endif /* LOGGERREPOSITORY_H_ */
