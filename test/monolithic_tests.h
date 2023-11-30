#pragma once

#if defined(BUILD_MONOLITHIC)

#ifdef __cplusplus
extern "C" {
#endif

int clipp_actions_test_main(void);
int clipp_alternative_groups_test_main(void);
int clipp_alternative_options_test_main(void);
int clipp_alternative_required_test_main(void);
int clipp_blocking_test01_main(void);
int clipp_blocking_test02_main(void);
int clipp_blocking_test03_main(void);
int clipp_blocking_test04_main(void);
int clipp_blocking_test05_main(void);
int clipp_blocking_test06_main(void);
int clipp_blocking_test07_main(void);
int clipp_blocking_test08_main(void);
int clipp_blocking_test09_main(void);
int clipp_blocking_test10_main(void);
int clipp_documentation_test_main(void);
int clipp_empty_args_main(void);
int clipp_flag_param_factories_test_main(int argc, const char** argv);
int clipp_joined_flags_test1_main(void);
int clipp_joined_flags_test2_main(void);
int clipp_joined_flags_test3_main(void);
int clipp_joined_flags_test4_main(void);
int clipp_joined_flags_test5_main(void);
int clipp_joined_flags_test6_main(void);
int clipp_joined_params_test1_main(void);
int clipp_joined_params_test2_main(void);
int clipp_joined_sequence_test_main(void);
int clipp_mixed_params_test_main(void);
int clipp_nesting_test_main(void);
int clipp_options_test_main(void);
int clipp_prefix_free_test_main(void);
int clipp_prefix_test_main(void);
int clipp_repeatability_test_main(void);
int clipp_repeatable_alternatives_test_main(void);
int clipp_required_params_test1_main(void);
int clipp_required_params_test2_main(void);
int clipp_usage_lines_test_main(void);
int clipp_values_conversion_test_main(void);
int clipp_values_filter_test_main(void);
int clipp_values_sequencing_test_main(void);

int clipp_run_all_tests_main(void);

#ifdef __cplusplus
}
#endif

#endif
