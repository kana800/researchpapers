#include <stdio.h>
#include "../../code/BTree/btree.h"
#include <check.h>
#include <stdlib.h>


START_TEST(test_m_createnode) {
    /*summary:
    test cases for:
        allocateNode(bool leaf, int t)
        createBTree(int order)
    */

    node* testnode = allocateNode(true, 2);
    ck_assert_int_eq(testnode->n_key, 0);
    ck_assert_int_eq(testnode->isLeaf, 1);

    // free thy nodes
    int* k = testnode->keys;
    node** t = testnode->childtree;
    free(testnode);
    free(k);
    free(t);
}
END_TEST

Suite* tree_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("RTreeTest");

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
