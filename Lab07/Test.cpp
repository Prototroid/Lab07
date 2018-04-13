/**
*	@file Test.cpp
*	@author Jamison Walrod - 2818737
*	@date 09 April 2018
*	@brief A header file for Test class
*/


// #include <iostream>
// #include <vector>
// #include <string>
#include "Test.h"

//// Run ////
Test::Test()
{
    //// 1, 2, & 3 ////
    isListZero();

    //// 4 ////
    isSizeOne_AddBack();

    //// 5 ////
    isSizeOne_AddFront();

    //// 6 & 7 ////
    isAddedBack();

    //// 8 & 9 ////
    isAddedFront();

    //// 10, 11, 12, & 13 ////
    isRemovedBack();

    //// 14, 15, 16, & 17 ////
    isRemovedFront();

    //// 18, 19, & 20 ////
    isSearchCorrect();

    //// 21 ////
    areNodesDeleted();
}

Test::~Test()
{
}

//// Checks the size of the vector with expected value and the list with the vector ////
void Test::isSizeCorrect(const std::vector<int> &myVector, int value, LinkedListOfInts testList)
{
    if((myVector.size() == value) && (testList.size() == myVector.size())) 
    {
        std::cout << "PASSED\n";
    }
    else
    {
        std::cout << "FAILED\n";
    }
}

//// Used to check the contents of the vector; only used when I was validating my tests ////
void Test::seeVector(const std::vector<int> &myVector) const
{
    std::cout << "List Vector: [";
	for(int i = 0; i < myVector.size(); i++)
	{
		std::cout << myVector[i];

		if(i != myVector.size() - 1)
		{
			std::cout << ",";
		}
	}
	std::cout << "]\n";
}

//// Test 1, 2, & 3 ////
void Test::isListZero()
{
    LinkedListOfInts testList;
    bool test1 = testList.isEmpty();
    const std::vector<int> &myVector = testList.toVector();

    //// Test 1 ////
    std::cout << "Test 1: isEmpty returns true if the list is empty: ";

    if(test1)
    {
        std::cout << "PASSED\n";
    }
    else
    {
        std::cout << "FAILED\n";
    }

    //// Test 2 ////
    std::cout << "Test 2: size of empty list is zero: ";

    isSizeCorrect(myVector, 0, testList);

    testList.addFront(5);
    bool test3 = testList.isEmpty();
    
    //// Test 3 ////
    std::cout << "Test 3: isEmpty returns false if the list is not empty: ";

    if(!(test3))
    {
        std::cout << "PASSED\n";
    }
    else
    {
        std::cout << "FAILED\n";
    }
}

//// Test 4 ////
void Test::isSizeOne_AddBack()
{
    LinkedListOfInts testList;
    testList.addBack(5);
    const std::vector<int> &myVector = testList.toVector();

    std::cout << "Test 4: size returns correct value after 1 addBack: ";

    isSizeCorrect(myVector, 1, testList);
}

//// Test 5 ////
void Test::isSizeOne_AddFront()
{
    LinkedListOfInts testList;
    testList.addFront(5);
    const std::vector<int> &myVector = testList.toVector();

    std::cout << "Test 5: size returns correct value after 1 addFront: ";

    isSizeCorrect(myVector, 1, testList);
}

//// Test 6 & 7 ////
void Test::isAddedBack()
{
    int value = 5;
    LinkedListOfInts testList;
    testList.addBack(15);
    testList.addBack(10);
    testList.addBack(value);
    const std::vector<int> &myVector = testList.toVector();
    std::vector<int>::const_iterator myBegin =  myVector.begin();
    std::vector<int>::const_iterator myEnd =  myVector.end();

    for(;myBegin < myEnd-1; myBegin++)
    {
    }

    //// Test 6 ////
    std::cout << "Test 6: size returns correct value after multiple addBack: ";

    isSizeCorrect(myVector, 3, testList);

    //// Test 7 ////
    std::cout << "Test 7: value was added to end of list after using addBack: ";

    if(value == *myBegin)
    {
        std::cout << "PASSED\n";
    }
    else
    {
        std::cout << "FAILED\n";
    }
}

//// Test 8 & 9 ////
void Test::isAddedFront()
{
    int value = 5;
    LinkedListOfInts testList;
    testList.addFront(15);
    testList.addFront(10);
    testList.addFront(value);
    const std::vector<int> &myVector = testList.toVector();

    //// Test 8 ////
    std::cout << "Test 8: size returns correct value after multiple addFront: ";

    isSizeCorrect(myVector, 3, testList);

    //// Test 9 ////
    std::cout << "Test 9: value was added to beginning of list after using addFront: ";

    if(value == *myVector.begin() )
    {
        std::cout << "PASSED\n";
    }
    else
    {
        std::cout << "FAILED\n";
    }
}

//// Test 10, 11, 12, & 13 ////
void Test::isRemovedBack()
{
    int value;
    LinkedListOfInts testList;
    testList.addBack(15);
    testList.addBack(10);
    testList.addBack(5);
    const std::vector<int> &myVector1 = testList.toVector();
    std::vector<int>::const_iterator myBegin1 =  myVector1.begin();
    std::vector<int>::const_iterator myEnd1 =  myVector1.end();

    for(;myBegin1 < myEnd1; myBegin1++)
    {
        value = *myBegin1;
    }

    bool test12 = testList.removeBack();
    const std::vector<int> &myVector2 = testList.toVector();
    std::vector<int>::const_iterator myBegin2 =  myVector2.begin();
    std::vector<int>::const_iterator myEnd2 =  myVector2.end();

    for(;myBegin2 < myEnd2-1; myBegin2++)
    {
    }

    LinkedListOfInts testList2;
    bool test13 = testList2.removeBack();
    const std::vector<int> &myVector3 = testList2.toVector();

    //// Test 10 ////
    std::cout << "Test 10: size returns correct value after adds and removeBack: ";
    
    isSizeCorrect(myVector2, 2, testList);

    //// Test 11 ////
    std::cout << "Test 11: value was removed from end of list: ";
    
    if(value != *myBegin2)
    {
        std::cout << "PASSED\n";
    }
    else
    {
        std::cout << "FAILED\n";
    }

    //// Test 12 ////
    std::cout << "Test 12: removeBack returns true if the back element was removed: ";

    if(test12)
    {
        std::cout << "PASSED\n";
    }
    else
    {
        std::cout << "FAILED\n";
    }

    //// Test 13 ////
    std::cout << "Test 13: removeBack returns false on empty list: ";

    if(!(test13))
    {
        std::cout << "PASSED\n";
    }
    else
    {
        std::cout << "FAILED\n";
    }
}

//// Test 14, 15, 16, & 17 ////
void Test::isRemovedFront()
{
    int value;
    LinkedListOfInts testList;
    testList.addFront(15);
    testList.addFront(10);
    testList.addFront(5);
    const std::vector<int> &myVector1 = testList.toVector();

    value = *myVector1.begin();
    
    bool test16 = testList.removeFront();
    const std::vector<int> &myVector2 = testList.toVector();

    LinkedListOfInts testList2;
    bool test17 = testList2.removeFront();
    const std::vector<int> &myVector3 = testList2.toVector();

    //// Test 14 ////
    std::cout << "Test 14: size returns correct value after adds and removeFront: ";
    isSizeCorrect(myVector2, 2, testList);

    //// Test 15 ////
    std::cout << "Test 15: value was removed from end of list: ";

    if(value != *myVector2.begin())
    {
        std::cout << "PASSED\n";
    }
    else
    {
        std::cout << "FAILED\n";
    }

    //// Test 16 ////
    std::cout << "Test 16: removeFront returns true if the front element was removed: ";

    if(test16)
    {
        std::cout << "PASSED\n";
    }
    else
    {
        std::cout << "FAILED\n";
    }

    //// Test 17 ////
    std::cout << "Test 17: removeFront returns false on empty list: ";

    if(!(test17))
    {
        std::cout << "PASSED\n";
    }
    else
    {
        std::cout << "FAILED\n";
    }
}

//// Test 18, 19, & 20 ////
void Test::isSearchCorrect()
{
    int value;
    LinkedListOfInts testList;
    bool test18 = testList.search(15);

    testList.addFront(15);
    testList.addFront(10);
    bool test19 = testList.search(15);
    bool test20 = testList.search(5);

    //// Test 18 ////
    std::cout << "Test 18: search returns false on empty list: ";

    if(!(test18))
    {
        std::cout << "PASSED\n";
    }
    else
    {
        std::cout << "FAILED\n";
    }

    //// Test 19 ////
    std::cout << "Test 19: search returns true on nonempty list with value: ";

    if(test19)
    {
        std::cout << "PASSED\n";
    }
    else
    {
        std::cout << "FAILED\n";
    }

    //// Test 20 ////
    std::cout << "Test 20: search returns false on nonempty list without value: ";

    if(!(test20))
    {
        std::cout << "PASSED\n";
    }
    else
    {
        std::cout << "FAILED\n";
    }
    
}

//// Test 21 ////
void Test::areNodesDeleted()
{
    LinkedListOfInts testList;
    testList.addFront(15);
    testList.addFront(10);
    testList.addFront(5);

    const std::vector<int> &myVector = testList.toVector();
    //seeVector(myVector);

    testList.~LinkedListOfInts();

    const std::vector<int> &myVector2 = testList.toVector();
    //seeVector(myVector2);

    std::cout << "Test 21: deconstructor deletes all nodes in the list: ";

    isSizeCorrect(myVector2, 0, testList);
}
