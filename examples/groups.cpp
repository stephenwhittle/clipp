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
#include <string>

#include <clipp.h>

#include "monolithic_examples.h"



#if defined(BUILD_MONOLITHIC)
#define main(cnt, arr)      clipp_groups_main(cnt, arr)
#endif

int main(int argc, const char** argv)
{
    using namespace clipp;
    using std::cout;

    bool x = false, y = false, a = false, b = false;
    bool g = false, h = false, e = false, f = false;

    auto cli = (
        (   option("x").set(x) % "sets X",  //simple group 
            option("y").set(y) % "sets Y"
        ),
        (   option("a").set(a) % "activates A",   
            option("b").set(b) % "activates B" 
        ) % "documented group 1:"           //docstring after group
        ,
        "documented group 2:" % (           //docstring before group
            option("-g").set(g) % "activates G",   
            option("-h").set(h) % "activates H" 
        ),
        "activates E or F" % (              
            option("-e").set(e),        //no docstrings inside group
            option("-f").set(f)
        )
    );

    if(!parse(argc, argv, cli)) {
        cout << make_man_page(cli, argv[0]) << '\n';
    }
    else {
        cout << std::boolalpha 
             << "x = " << x << '\n'
             << "y = " << y << '\n'
             << "a = " << a << '\n'
             << "b = " << b << '\n'
             << "g = " << g << '\n'
             << "h = " << h << '\n'
             << "e = " << e << '\n'
             << "f = " << f << '\n';
    }
	return EXIT_SUCCESS;
}
