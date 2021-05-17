/*****************************************************************************
 *
 * demo program - part of CLIPP (command line interfaces for modern C++)
 *
 * released under MIT license
 *
 * (c) 2017-2018 André Müller; foss@andremueller-online.de
 *
 *****************************************************************************/

#include <iostream>
#include <vector>

#include <clipp.h>

#include "monolithic_examples.h"



#if defined(BUILD_MONOLITHIC)
#define main(cnt, arr)      clipp_counter_main(cnt, arr)
#endif

int main(int argc, const char** argv)
{
    using namespace clipp;
    using std::cout;

    int as = 0;
    int bs = 0;

    auto cli = joinable(
        repeatable(
            option("a")([&]{++as;}) |
            option("b")([&]{++bs;})
        )
    );

    if(parse(argc, argv, cli)) {
        cout << "as: " << as << '\n';
        cout << "bs: " << bs << '\n';
    } else {
        cout << "Usage:\n" << usage_lines(cli, argv[0]) << '\n';
    }

	return EXIT_SUCCESS;
}
