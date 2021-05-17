#ifndef CLIPP_TESTING_H_
#define CLIPP_TESTING_H_

//don't include anything else before the test subject
#include "../include/clipp.h"

#include <initializer_list>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <vector>
#include <iostream>
#include <functional>
#include <type_traits>
#include <limits>


/*************************************************************************//**
 *
 * @brief stores the location of a test definition
 *
 *****************************************************************************/
struct test_location
{
    test_location(std::string file_, int line_):
        file{std::move(file_)}, line{line_}
    {}

    std::string file;
    int line;
};



/*************************************************************************//**
 *
 * @brief returns wrapped/nested variants of the input command line interface
 *
 *****************************************************************************/
template<class CLI>
std::vector<CLI>
wrapped_variants(const CLI& cli)
{
    using namespace clipp;
    return {
        /* 1*/ cli
        ,
        /* 2*/ group{cli}
        ,
        /* 3*/ group{group{cli}}
        ,
        /* 4*/ group{option("?a?"), cli}
        ,
        /* 5*/ group{cli, option("?a?")}
        ,
        /* 6*/ group{option("?b?"), cli, option("?a?")}
        ,
        /* 7*/ group{group{option("?a?")}, cli}
        ,
        /* 8*/ group{cli, group{option("?a?")}}
        ,
        /* 9*/ group{option("?a?"), group{cli}}
        ,
        /*10*/ group{group{cli}, option("?a?")}
        ,
        /*11*/ group{option("?b?"), group{cli}, option("?a?")}
    };
}



/*************************************************************************//**
 *
 * @brief runs CLI validity tests based on differently wrapped variants of
 *        the original input CLI
 *
 *****************************************************************************/
template<class CLI>
void run_wrapped_variants(
    const test_location& info,
    const std::initializer_list<const char*>& args,
    const CLI& cli,
    std::function<void()> initialize,
    std::function<bool()> valid)
{
    using std::cout;
    using std::to_string;

    int variant = 0;
    for(const auto& wrappedCli : wrapped_variants(cli)) {
        ++variant;

        initialize();

        parse(args, wrappedCli);

//        cout << "==============================================\n"
//             << " in file " << info.file << " in line " << info.line
//             << " with variant " << variant << '\n'
//             << "==============================================\n";
//        clipp::debug::print(cout, wrappedCli);
//        cout << "args = { ";
//        for(const auto& a : args) cout << '"' << a << "\" ";
//        cout << "}\n";
//        auto res = clipp::parse(args, wrappedCli);
//        cout << "----------------------------------------------\n";
//        clipp::debug::print(cout, res);

        if(!valid()) {
            throw std::runtime_error{"failed test " + info.file +
                                     " in line " + to_string(info.line) +
                                     " with variant " + to_string(variant) };
        }
    }
}



/*************************************************************************//**
 *
 * @brief runs CLI validity test
 *
 *****************************************************************************/
template<class CLI>
void run_test(
    const test_location& info,
    const std::initializer_list<const char*>& args,
    const CLI& cli,
    std::function<bool()> valid)
{
    using std::cout;
    using std::to_string;

    parse(args, cli);

//    cout << "==============================================\n"
//         << " in file " << info.file << " in line " << info.line << '\n'
//         << "==============================================\n";
//    clipp::debug::print(cout, cli);
//    cout << "args = { ";
//    for(const auto& a : args) cout << '"' << a << "\" ";
//    cout << "}\n";
//    auto res = clipp::parse(args, cli);
//    cout << "----------------------------------------------\n";
//    clipp::debug::print(cout, res);

    if(!valid()) {
        throw std::runtime_error{"failed test " + info.file +
                                 " in line " + to_string(info.line) };
    }
}




//#if defined(BUILD_MONOLITHIC)

int clipp_actions_test_main();
int clipp_alternative_groups_test_main();
int clipp_alternative_options_test_main();
int clipp_alternative_required_test_main();
int clipp_blocking_test01_main();
int clipp_blocking_test02_main();
int clipp_blocking_test03_main();
int clipp_blocking_test04_main();
int clipp_blocking_test05_main();
int clipp_blocking_test06_main();
int clipp_blocking_test07_main();
int clipp_blocking_test08_main();
int clipp_blocking_test09_main();
int clipp_blocking_test10_main();
int clipp_documentation_test_main();
int clipp_empty_args_main();
int clipp_flag_param_factories_test_main(int argc, const char **argv);
int clipp_joined_flags_test1_main();
int clipp_joined_flags_test2_main();
int clipp_joined_flags_test3_main();
int clipp_joined_flags_test4_main();
int clipp_joined_flags_test5_main();
int clipp_joined_flags_test6_main();
int clipp_joined_params_test1_main();
int clipp_joined_params_test2_main();
int clipp_joined_sequence_test_main();
int clipp_mixed_params_test_main();
int clipp_nesting_test_main();
int clipp_options_test_main();
int clipp_prefix_free_test_main();
int clipp_prefix_test_main();
int clipp_repeatability_test_main();
int clipp_repeatable_alternatives_test_main();
int clipp_required_params_test1_main();
int clipp_required_params_test2_main();
int clipp_usage_lines_test_main();
int clipp_values_conversion_test_main();
int clipp_values_filter_test_main();
int clipp_values_sequencing_test_main();

//#endif

#endif

