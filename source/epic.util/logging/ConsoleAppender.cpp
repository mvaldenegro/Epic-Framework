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

#include <iostream>
#include "ConsoleAppender.h"

using namespace std;

namespace Epic {
    namespace Util {
        namespace Logging {

            ConsoleAppender::ConsoleAppender()
            : Appender()
            {
            }

            ConsoleAppender::~ConsoleAppender()
            {
            }

            void ConsoleAppender::logMessage(Level level, const Epic::Core::ASCIIString& loggerName,
                                             const Epic::Core::ASCIIString& message)
            {
                if(level == Level::Error) {
                    cerr << levelString(level).data() << " " << loggerName.data() << " - " << message.data() << endl;
                } else {
                    cout << levelString(level).data() << " " << loggerName.data() << " - " << message.data() << endl;
                }
            }

        } /* namespace Logging */
    } /* namespace Util */
} /* namespace Epic */
