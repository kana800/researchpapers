#include <stdio.h>
#include "../../code/BTree/btree.h"
#include <check.h>
#include <stdlib.h>

Suite* tree_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("RTreeTest");

    /* core test cases */
    tc_core = tcase_create("Core");
    //tcase_add_test(tc_core, test_m_createnode);
    suite_add_tcase(s, tc_core);
    return s;
}

int main() {
    int number_failed;
	Suite *s;
    SRunner *sr;

	s = tree_suite();
	printf("Implementation of a R-Tree\n");
	sr = srunner_create(s);
	srunner_run_all(sr, CK_VERBOSE);
	number_failed = srunner_ntests_failed(sr);
    /*freeing the resources*/
    srunner_free(sr);
	return (number_failed == 0) ? 
        EXIT_SUCCESS : EXIT_FAILURE;
}
