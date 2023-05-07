// TEST MAIN

#include "../headers/struct.h"
#include <iostream>

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>

TEST_CASE("List tests", "[list]")
{
/* test focus:
	Empty.
	Size.
	Clear.
	PushBack.
	PushFront.
	PopBack. Проверьте правильность работы на пустом списке.
	PopFront. Проверьте правильность работы на пустом списке.
*/

	List list_test; // m_size(0)

	// check size
	CHECK(list_test.Size() == 0);	// m_size 0

	list_test.PushFront(1); // m_size(1) (m_size++)
	list_test.PushFront(2); // m_size(2) (m_size++)

	// Создали пустой список и добавили 2 значения


	INFO("LIST HAVE 2 NODES, SIZE = 2");
	
	// check size
	CHECK(list_test.Size() == 2);	// m_size 2
	
	list_test.PushBack(3);
	list_test.PushBack(4);

	INFO("PUSHED 2 ELEMENTS TO BACK, SIZE = 4");

	// check size
	CHECK(list_test.Size() == 4);	// m_size 4

	// Popping

	CHECK(list_test.PopBack() == 4); // pop 4
	CHECK(list_test.PopBack() == 3); // pop 3

	// check size
	CHECK(list_test.Size() == 2);	// m_size 2

	// pop front

	CHECK(list_test.PopFront() == 2); // pop 2
	CHECK(list_test.PopFront() == 1); // pop 1

	// now list empty

	// check size
	CHECK(list_test.Size() == 0);	// m_size 0
}

TEST_CASE("List tests 2", "[list]")
{
	// part 2
	List list_test; // m_size(0)

	// check size
	CHECK(list_test.Size() == 0);	// m_size 0

	list_test.PushFront(1); // m_size(1) (m_size++)
	list_test.PushFront(2); // m_size(2) (m_size++)

	// Создали пустой список и добавили 2 значения

	// check size
	CHECK(list_test.Size() == 2);	// m_size 2

	list_test.Clear();

	// check size
	CHECK(list_test.Size() == 0);	// m_size 0

	// try pop
	// pop front

	// IF THIS FAIL IS OK
	INFO("POPING BACK FROM ASSUMABLY EMPTY LIST, FAIL = GOOD");
	CHECK(list_test.PopFront() == 2); // pop 2
	INFO("POPING BACK FROM ASSUMABLY EMPTY LIST, FAIL = GOOD");
	CHECK(list_test.PopFront() == 1); // pop 1

	list_test.PushBack(3);
	list_test.PushBack(4);

	INFO("PUSHED 2 ELEMENTS TO BACK, SIZE = 2");

	// check size
	CHECK(list_test.Size() == 2);	// m_size 2

	// Try pop 2 from back

	// Popping

	CHECK(list_test.PopBack() == 4); // pop 4
	CHECK(list_test.PopBack() == 3); // pop 3

	// check size
	CHECK(list_test.Size() == 0);	// m_size 0

	// pop 1 more from back, MUST FAIL
	// IF THIS FAIL IS OK
	INFO("POPING FRONT FROM ASSUMABLY EMPTY LIST, FAIL = GOOD");
	CHECK(list_test.PopFront() == 5); // pop 5 (must return exception string)
}

int main(int argc, char** argv)
{	
	return Catch::Session().run();
}