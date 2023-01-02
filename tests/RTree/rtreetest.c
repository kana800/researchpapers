#include <stdio.h>
#include "../../code/RTree/rtree.h"
#include <check.h>
#include <stdlib.h>

START_TEST(test_m_createnode) {
    /*summary: 
    testing the node creation of objects;
        - tuple
        - node
    testing functions:
        tuple* createBoundingBoxes(
            double x0, double y0, 
            double x1, double y1)
        createNode(char repr, tuple* tuple)

    */

    rect* t1 = createBoundingBoxes(1, 2, 3, 4);
    ck_assert_double_eq(t1->x0, 1);
    ck_assert_double_eq(t1->y0, 2);
    ck_assert_double_eq(t1->x1, 3);
    ck_assert_double_eq(t1->y1, 4);
    // area = 4 - 2 * 3 - 1 = 4
    ck_assert_double_eq(t1->area, (double)4);
    node* n1 = createNode('a', 1,2,3,4,true);
    ck_assert_double_eq(n1->rect_1->y0, 2);
    // free the node
    freeNode(n1);
    ck_assert_double_eq(t1->x0, 1);

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
