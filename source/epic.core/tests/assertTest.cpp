/*
 * assertTest.cpp
 *
 *  Created on: 08-11-2011
 *      Author: mvaldenegro
 */

#include <epic.core/Core.h>

int main(int argc, char **argv)
{
    EPIC_HARD_ASSERT(1 + 1 == 2);
    EPIC_HARD_ASSERT(1 + 1 == 3);

    return 0;
}
