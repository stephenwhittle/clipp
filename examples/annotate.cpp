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
#define main(cnt, arr)      clipp_annotate_main(cnt, arr)
#endif

int main(int argc, const char** argv)
{
    using namespace clipp;
    using std::cout;

    auto is_char = [](const std::string& arg) {
        return arg.size() == 1 && std::isalpha(arg[0]);
    };

    char lbl = ' ';
    auto cli = (
        command("auto").set(lbl, '_') |
        ( command("label"), value(is_char, "character", lbl) )
    );

    if(parse(argc, argv, cli)) {
        cout << "Label: " << lbl << '\n';
    }
    else {
        cout << "Usage:\n" << usage_lines(cli,argv[0]) << '\n';
    }
	return EXIT_SUCCESS;
}
