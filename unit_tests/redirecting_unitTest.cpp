#include "gtest/gtest.h"
#include "../src/Connector.hpp"
#include "../src/Command.hpp"
#include "../src/InputRedirector.hpp"
#include "../src/OutputRedirector.hpp"
#include "../src/OutputAppender.hpp"
using namespace std;

//Testing InputRedirector execute function
TEST(InputRedirectorTest, InputRedirectorExecute)
{
	//cat < CMakeLists.txt
	char cmd1[] = "cat"; char* cmd2 = 0;
	char* cmd[2] = {cmd1, cmd2};

	Connector* left = new Command();
	left->setArguments(cmd);

	char file1[] = "CMakeLists.txt"; char* file2 = 0;
        char* file[2] = {file1, file2};

	Connector* right = new Command();
	right->setArguments(file);

	InputRedirector inputRedirector;
	inputRedirector.setArguments(right->getArguments());
	inputRedirector.setLeftConnector(left);

	EXPECT_TRUE(inputRedirector.execute());
}

//Testing OutputRedirector execute function
TEST(OutputRedirectorTest, OutputRedirectorExecute)
{
	//echo this is a test output file > outputFile.txt
	char cmd1[] = "echo"; char cmd2[] = "this"; char cmd3[] = "is"; char cmd4[] = "a"; char cmd5[] = "test"; char cmd6[] = "output"; char cmd7[] = "file"; char* cmd8 = 0;
        char* cmd[8] = {cmd1, cmd2, cmd3, cmd4, cmd5, cmd6, cmd7, cmd8};

        Connector* left = new Command();
        left->setArguments(cmd);

        char file1[] = "outputFile.txt"; char* file2 = 0;
        char* file[2] = {file1, file2};

        Connector* right = new Command();
        right->setArguments(file);

        OutputRedirector outputRedirector;
        outputRedirector.setArguments(right->getArguments());
        outputRedirector.setLeftConnector(left);

        EXPECT_TRUE(outputRedirector.execute());
}

//Testing OutputAppender execute function
TEST(OutputAppenderTest, OutputAppenderExecute)
{
	//echo appending... >> outputFile.txt
	char cmd1[] = "echo"; char cmd2[] = "appending..."; char* cmd3 = 0;
        char* cmd[3] = {cmd1, cmd2, cmd3};

        Connector* left = new Command();
        left->setArguments(cmd);

        char file1[] = "outputFile.txt"; char* file2 = 0;
        char* file[2] = {file1, file2};

        Connector* right = new Command();
        right->setArguments(file);

        OutputAppender outputAppender;
        outputAppender.setArguments(right->getArguments());
        outputAppender.setLeftConnector(left);

        EXPECT_TRUE(outputAppender.execute());
}

int main(int argc, char** argv)
{
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
}
