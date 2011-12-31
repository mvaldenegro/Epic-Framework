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

#include <epic.core/String.h>

namespace Epic {
    namespace Util {
        namespace Logging {
            class Logger
            {
                private:
                    static Logger *staticRootLogger;

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

