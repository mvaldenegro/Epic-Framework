#include <epic.util/logging/Logger.h>

using Epic::Util::Logging::Logger;

int main(int argc, char **argv)
{
    Logger logger = Logger::getLogger("test.log");

    logger.debug("test debug message");
    logger.error("test error message");

    return 0;
}
