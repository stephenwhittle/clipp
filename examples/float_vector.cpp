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
#include <cmath>

#include <clipp.h>

#include "monolithic_examples.h"



#if defined(BUILD_MONOLITHIC)
#define main(cnt, arr)      clipp_float_vector_main(cnt, arr)
#endif

int main(int argc, const char** argv)
{
    using namespace clipp;
    using std::cout;

    std::vector<float> nums;

    auto cli = required("--data") & numbers("number", nums);

    if(parse(argc, argv, cli)) {
        cout << "numbers:\n";
        for(auto n : nums) cout << n << '\n';
    } else {
        cout << "Usage:\n" << usage_lines(cli, argv[0]) << '\n';
    }
	return EXIT_SUCCESS;
}
