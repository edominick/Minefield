/**
 * Unit Tests for Field class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "Field.h"
 
class FieldTest : public ::testing::Test
{
	protected:
		FieldTest(){}
		virtual ~FieldTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(FieldTest, placeMineInBounds)
{
	Field minefield;
	
	minefield.placeMine(4,5);
	ASSERT_EQ( MINE_HIDDEN, minefield.get(4,5) );
}

TEST(FieldTest, placeMineOutBounds)
{
	Field minefield;

	minefield.placeMine(-3.3,5);
	ASSERT_EQ( MINE_HIDDEN, minefield.get(-3.3,5) );	
}

TEST(FieldTest, isSafeOutBounds)
{
	Field minefield;

	minefield.placeMine(-3.3,5);
	minefield.isSafe(-3.3, 5);
	ASSERT_EQ( MINE_HIDDEN, minefield.get(-3.3,5) );
}