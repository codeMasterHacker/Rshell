#include "gtest/gtest.h"
#include "../src/Connector.hpp"
#include "../src/TestCommand.hpp"
using namespace std;

//Testing the Test class execute function
TEST(TstCmdExec, TstCmdExec1) //test + (existing)path
{
	char arg1[] = "test"; char arg2[] = "CMakeLists.txt"; char* arg3 = 0;
	char* args[3] = {arg1, arg2, arg3};

	TestCommand test;
	test.setArguments(args);

	EXPECT_TRUE(test.execute());
}

TEST(TstCmdExec, TstCmdExec2) //test + (non-existing)path
{
	char arg1[] = "test"; char arg2[] = "CMakeListz.txt"; char* arg3 = 0;
        char* args[3] = {arg1, arg2, arg3};

        TestCommand test;
        test.setArguments(args);

        EXPECT_FALSE(test.execute());
}

TEST(TstCmdExec, TstCmdExec3) //[ + (existing)path + ]
{
	char arg1[] = "["; char arg2[] = "CMakeLists.txt"; char arg3[] = "]"; char* arg4 = 0;
        char* args[4] = {arg1, arg2, arg3, arg4};

        TestCommand test;
        test.setArguments(args);

        EXPECT_TRUE(test.execute());
}

TEST(TstCmdExec, TstCmdExec4) //[ + (non-existing)path + ]
{
	char arg1[] = "["; char arg2[] = "CMakeListz.txt"; char arg3[] = "]"; char* arg4 = 0;
        char* args[4] = {arg1, arg2, arg3, arg4};

        TestCommand test;
        test.setArguments(args);

        EXPECT_FALSE(test.execute());
}

TEST(TstCmdExec, TstCmdExec5)//test + -e + (existing)path
{
	char arg1[] = "test"; char arg2[] = "-e"; char arg3[] = "CMakeLists.txt"; char* arg4 = 0;
        char* args[4] = {arg1, arg2, arg3, arg4};

        TestCommand test;
        test.setArguments(args);

        EXPECT_TRUE(test.execute());
}

TEST(TstCmdExec, TstCmdExec6) //test + -e + (non-existing)path
{
	char arg1[] = "test"; char arg2[] = "-e"; char arg3[] = "CMakeListz.txt"; char* arg4 = 0;
        char* args[4] = {arg1, arg2, arg3, arg4};

        TestCommand test;
        test.setArguments(args);

        EXPECT_FALSE(test.execute());
}

TEST(TstCmdExec, TstCmdExec7) //[ + -e + (existing)path + ]
{
	char arg1[] = "["; char arg2[] = "-e"; char arg3[] = "CMakeLists.txt"; char arg4[] = "]"; char* arg5 = 0;
        char* args[5] = {arg1, arg2, arg3, arg4, arg5};

        TestCommand test;
        test.setArguments(args);

        EXPECT_TRUE(test.execute());
}

TEST(TstCmdExec, TstCmdExec8)//[ + -e + (non-existing)path + ]
{
	char arg1[] = "["; char arg2[] = "-e"; char arg3[] = "CMakeListz.txt"; char arg4[] = "]"; char* arg5 = 0;
        char* args[5] = {arg1, arg2, arg3, arg4, arg5};

        TestCommand test;
        test.setArguments(args);

        EXPECT_FALSE(test.execute());
}

TEST(TstCmdExec, TstCmdExec9) //test + -f + file
{
	char arg1[] = "test"; char arg2[] = "-f"; char arg3[] = "CMakeLists.txt"; char* arg4 = 0;
        char* args[4] = {arg1, arg2, arg3, arg4};

        TestCommand test;
        test.setArguments(args);

        EXPECT_TRUE(test.execute());
}

TEST(TstCmdExec, TstCmdExec10) //test + -f + directory
{
	char arg1[] = "test"; char arg2[] = "-f"; char arg3[] = "unit_tests/"; char* arg4 = 0;
        char* args[4] = {arg1, arg2, arg3, arg4};

        TestCommand test; 
        test.setArguments(args);
        
        EXPECT_FALSE(test.execute());
}

TEST(TstCmdExec, TstCmdExec11) //[ + -f + file + ]
{
	char arg1[] = "["; char arg2[] = "-f"; char arg3[] = "CMakeLists.txt"; char arg4[] = "]"; char* arg5 = 0;
        char* args[5] = {arg1, arg2, arg3, arg4, arg5};

        TestCommand test;
        test.setArguments(args);

        EXPECT_TRUE(test.execute());
}

TEST(TstCmdExec, TstCmdExec12) //[ + -f + directory + ]
{
	char arg1[] = "["; char arg2[] = "-f"; char arg3[] = "unit_tests/"; char arg4[] = "]"; char* arg5 = 0;
        char* args[5] = {arg1, arg2, arg3, arg4, arg5};

        TestCommand test;
        test.setArguments(args);

        EXPECT_FALSE(test.execute());
}

TEST(TstCmdExec, TstCmdExec13) //test + -d + file
{
	char arg1[] = "test"; char arg2[] = "-d"; char arg3[] = "CMakeLists.txt"; char* arg4 = 0;
        char* args[4] = {arg1, arg2, arg3, arg4};

        TestCommand test;
        test.setArguments(args);

        EXPECT_FALSE(test.execute());
}

TEST(TstCmdExec, TstCmdExec14) //test + -d + directory
{
	char arg1[] = "test"; char arg2[] = "-d"; char arg3[] = "unit_tests/"; char* arg4 = 0;
        char* args[4] = {arg1, arg2, arg3, arg4};

        TestCommand test;
        test.setArguments(args);

        EXPECT_TRUE(test.execute());
}

TEST(TstCmdExec, TstCmdExec15) //[ + -d + file + ]
{
	char arg1[] = "["; char arg2[] = "-d"; char arg3[] = "CMakeLists.txt"; char arg4[] = "]"; char* arg5 = 0;
        char* args[5] = {arg1, arg2, arg3, arg4, arg5};

        TestCommand test;
        test.setArguments(args);

        EXPECT_FALSE(test.execute());
}

TEST(TestClass, TestExecute16) //[ + -d + directory + ]
{
	char arg1[] = "["; char arg2[] = "-d"; char arg3[] = "unit_tests/"; char arg4[] = "]"; char* arg5 = 0;
        char* args[5] = {arg1, arg2, arg3, arg4, arg5};

        TestCommand test;
        test.setArguments(args);

        EXPECT_TRUE(test.execute());
}

int main(int argc, char** argv)
{
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
}
