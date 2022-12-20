#include <stdio.h>
#include "../../code/MakingDataStructuresPersistent/fatnode.h"
#include <check.h>
#include <stdlib.h>


START_TEST(test_m_createnode) {
    /*summary:
    testing the creation of nodes
        node* createNodeStructure(float val)
    */
    //n = 2.00
    node* test_node_1 = createNodeStructure(2.00);
    ck_assert_float_eq(test_node_1->nodevalue, 2.00);
    ck_assert_int_eq(test_node_1->versionstamp, 1);
    // n = 3.00 fn[0] -> 2.00
    updateNodeStructure(3.00, test_node_1);
    // n = 4.00 fn[0] -> 2.00 fn[1] -> 3.00
    updateNodeStructure(4.00, test_node_1);
    updateNodeStructure(5.00, test_node_1);
    updateNodeStructure(6.00, test_node_1);
    printNode(test_node_1);
}
END_TEST

Suite* node_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("FatNodeTest");

    /* core test cases */
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_m_createnode);
    suite_add_tcase(s, tc_core);
    return s;
}

int main() {
    int number_failed;
	Suite *s;
    SRunner *sr;

	s = node_suite();
	printf("Making Data Structures Persistent\n");
	sr = srunner_create(s);

	srunner_run_all(sr, CK_VERBOSE);
	number_failed = srunner_ntests_failed(sr);
    /*freeing the resources*/
    srunner_free(sr);
	return (number_failed == 0) ? 
        EXIT_SUCCESS : EXIT_FAILURE;
}