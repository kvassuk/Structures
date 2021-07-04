#include "pch.h"
#include "..\Structures\AnyType.h"
#include "..\Structures\exceptionType.h"
#include "..\Structures\exceptionType.cpp"
#include "..\Structures\AnyType.cpp"

class AnyTypeTest : public ::testing::Test
{
protected:
	void SetUp()override 
	{}
	void TearDown() override {
		container.~AnyType();
	}
	AnyType container;
};

TEST_F(AnyTypeTest, IntTest) {
	container = 5;
	EXPECT_EQ(5, container.ToInt());
	EXPECT_ANY_THROW(container.ToDouble());
	EXPECT_STREQ(container.current_container_type(), typeid(int).name());
}
TEST_F(AnyTypeTest, DoubleTest) {
	container = 5.5;
	EXPECT_DOUBLE_EQ(5.5, container.ToDouble());
	EXPECT_ANY_THROW(container.ToBool());
	EXPECT_STREQ(container.current_container_type(), typeid(double).name());
}
TEST_F(AnyTypeTest, FloatTest) {
	container = 5.5f;
	EXPECT_FLOAT_EQ(5.5, container.ToFloat());
	EXPECT_ANY_THROW(container.ToInt());
	EXPECT_STREQ(container.current_container_type(), typeid(float).name());
}

TEST_F(AnyTypeTest, CharTest) {
	container = 'A';
	EXPECT_EQ('A', container.ToChar());
	EXPECT_ANY_THROW(container.ToBool());
	EXPECT_STREQ(container.current_container_type(), typeid(char).name());
}

TEST_F(AnyTypeTest, BoolTest) {
	container = true;
	EXPECT_TRUE(container.ToBool());
	EXPECT_ANY_THROW(container.ToInt());
	EXPECT_STREQ(container.current_container_type(), typeid(bool).name());
}

TEST_F(AnyTypeTest, CopyConstructorTest) {
	container = 6.4;
	AnyType secondcontainer;
	secondcontainer = container;

	EXPECT_DOUBLE_EQ (6.4, secondcontainer.ToDouble());
	EXPECT_ANY_THROW(secondcontainer.ToInt());
	EXPECT_STREQ(secondcontainer.current_container_type(), typeid(double).name());
}
TEST_F(AnyTypeTest, CopyAssignmentOperatorTest) {
	container = 6.4f;
	AnyType secondcontainer(container);	
	EXPECT_FLOAT_EQ(6.4, secondcontainer.ToFloat());
	EXPECT_ANY_THROW(secondcontainer.ToInt());
	EXPECT_STREQ(secondcontainer.current_container_type(), typeid(float).name());
}

TEST_F(AnyTypeTest, SwapMethodTest) {
	container = 6.4f;
	AnyType secondcontainer('C');
	container.swap(secondcontainer);
	EXPECT_FLOAT_EQ(6.4, secondcontainer.ToFloat());
	EXPECT_EQ('C', container.ToChar());
	EXPECT_ANY_THROW(secondcontainer.ToInt());
	EXPECT_NO_THROW(container.ToChar());
	EXPECT_STREQ(secondcontainer.current_container_type(), typeid(float).name());
	EXPECT_STREQ(container.current_container_type(), typeid(char).name());
}

TEST_F(AnyTypeTest, MoveSemanticTest) {
	container = 6.4f;
	AnyType secondcontainer('C');
	secondcontainer = std::move(container);
	EXPECT_FLOAT_EQ(6.4, secondcontainer.ToFloat());	
	EXPECT_ANY_THROW(secondcontainer.ToInt());
	
	EXPECT_STREQ(secondcontainer.current_container_type(), typeid(float).name());
	EXPECT_STREQ(container.current_container_type(), "Bad cast exception");
}