/**
*	@file Test.h
*	@author Jamison Walrod - 2818737
*	@date 09 April 2018
*	@brief A header file for Test class
*/

#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <vector>
#include <string>
#include "LinkedListOfInts.h"

class Test
{
    public:

    //// Run ////
    Test();

    ~Test();

    private:

    void isSizeCorrect(const std::vector<int> &myVector, int value, LinkedListOfInts testList);

    void seeVector(const std::vector<int> &myVector) const;

    //// Test 1, 2, & 3 ////
    void isListZero();

    //// Test 4 ////
    void isSizeOne_AddBack();

    //// Test 5 ////
    void isSizeOne_AddFront();

    //// Test 6 & 7 ////
    void isAddedBack();

    //// Test 8 & 9 ////
    void isAddedFront();

    //// Test 10, 11, 12, & 13 ////
    void isRemovedBack();

    //// Test 14, 15, 16, & 17 ////
    void isRemovedFront();

    //// Test 18, 19, & 20 ////
    void isSearchCorrect();

    //// Test 21 ////
    void areNodesDeleted();

};

#endif