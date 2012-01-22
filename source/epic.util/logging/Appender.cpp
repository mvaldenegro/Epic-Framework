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

#include "Appender.h"

namespace Epic {
    namespace Util {
        namespace Logging {

            Appender::Appender()
            {
            }

            Appender::~Appender()
            {
            }

            Epic::Core::ASCIIString Appender::levelString(Level level) const
            {
                switch(level) {
                    case Level::Debug: {
                        return Epic::Core::ASCIIString("DEBUG");
                    }

                    case Level::Error: {
                        return Epic::Core::ASCIIString("ERROR");
                    }

                    case Level::Fatal: {
                        return Epic::Core::ASCIIString("FATAL");
                    }

                    case Level::Info: {
                        return Epic::Core::ASCIIString("INFO");
                    }

                    case Level::Warning: {
                        return Epic::Core::ASCIIString("WARNING");
                    }

                    default: {
                        return Epic::Core::ASCIIString("UNKNOWN");
                    }
                }
            }

        } /* namespace Logging */
    } /* namespace Util */
} /* namespace Epic */
