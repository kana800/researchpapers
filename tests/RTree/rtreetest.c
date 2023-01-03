#include <stdio.h>
#include "../../code/RTree/rtree.h"
#include <check.h>
#include <stdlib.h>

START_TEST(test_m_createnode) {
    /*summary: 
    testing the node creation of objects;
        - node
        - childpointer
        - rect
    testing functions:
        tuple* createBoundingBoxes(
            double x0, double y0, 
            double x1, double y1)
        createNode
    */


    rect* r1 = createBoundingBoxes(1, 2, 3, 4);
    rect* r2 = createBoundingBoxes(2, 3, 4, 5);

    node* n1 = createNode('L', true, r1);
    node* n3 = createNode('L2', true, r2);

    ck_assert_ptr_null(n1->arr);
    ck_assert_int_eq(n1->leaf, true);
    ck_assert_double_eq(n1->rect->x0, 1);
    ck_assert_double_eq(n1->rect->x1, 3);
    ck_assert_double_eq(n1->rect->y0, 2);
    ck_assert_double_eq(n1->rect->y1, 4);


    node* n2 = createNode('B', false, n1);
    ck_assert_ptr_null(n1->arr);
    ck_assert_int_eq(n1->leaf, true);
    ck_assert_ptr_eq(n2->rect, n1->rect);

    addChildPointer(n2->arr, n3);
    childpointer* tempcp = n2->arr;

    ck_assert_ptr_eq(tempcp->ptr[0], n1);
    ck_assert_ptr_eq(tempcp->ptr[1], n3);

    //freeNode(n1);
    //freeNode(n2);
    //freeNode(n3);
}
END_TEST

START_TEST(test_m_getBiggestChildNode) {
    /*summary:
    test for function:
        getBiggestChildNode(node* n);
    */
}

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
