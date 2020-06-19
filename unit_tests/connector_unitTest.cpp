#include "gtest/gtest.h"
#include "../src/Connector.hpp"
#include "../src/Command.hpp"
#include "../src/SemiColon.hpp"
#include "../src/DoubleAmpersand.hpp"
#include "../src/Or.hpp"
#include "../src/Pipe.hpp"
using namespace std;

//testing | connector (pipe)
TEST(ConnectorTest, PipeExecuteTest)
{
	char cmd1[] = "ls"; char* cmd2 = 0;
        char* cmd_1[2] = {cmd1, cmd2};
        
        Connector* command1 = new Command();
        command1->setArguments(cmd_1);
        
        char cmd3[] = "wc"; char cmd4[] = "-l"; char* cmd5 = 0;
        char* cmd_2[3] = {cmd3, cmd4, cmd5};
        
        Connector* command2 = new Command();
        command2->setArguments(cmd_2);
        
        Pipe pipe;
        pipe.setLeftConnector(command1);
        pipe.setRightConnector(command2);
        
        EXPECT_TRUE(pipe.execute());	
}

//testing || connector (logical or)
TEST(ConnectorTest, OrExecuteTest)
{
	char cmd1[] = "eco"; char cmd2[] = "hello"; char* cmd3 = 0;
        char* cmd_1[3] = {cmd1, cmd2, cmd3};
        
        Connector* command1 = new Command();
        command1->setArguments(cmd_1);
        
        char cmd4[] = "ls"; char* cmd5 = 0;
        char* cmd_2[2] = {cmd4, cmd5};
        
        Connector* command2 = new Command();
        command2->setArguments(cmd_2);
        
        Or logicalOr;
        logicalOr.setLeftConnector(command1);
        logicalOr.setRightConnector(command2);
        
        EXPECT_FALSE(logicalOr.execute());
}

//testing && connector (logical and)
TEST(ConnectorTest, DoubleAmpersandExecuteTest)
{
	char cmd1[] = "echo"; char cmd2[] = "hello"; char* cmd3 = 0;
        char* cmd_1[3] = {cmd1, cmd2, cmd3};

        Connector* command1 = new Command();
        command1->setArguments(cmd_1);

        char cmd4[] = "lz"; char* cmd5 = 0;
        char* cmd_2[2] = {cmd4, cmd5};

        Connector* command2 = new Command();
        command2->setArguments(cmd_2);

        DoubleAmpersand doubleAmpersand;
        doubleAmpersand.setLeftConnector(command1);
        doubleAmpersand.setRightConnector(command2);

        EXPECT_TRUE(doubleAmpersand.execute());        
}

//testing ; connector (semicolon)
TEST(ConnectorTest, SemiColonExecuteTest)
{
	char cmd1[] = "echo"; char cmd2[] = "hello"; char* cmd3 = 0;
        char* cmd_1[3] = {cmd1, cmd2, cmd3};

        Connector* command1 = new Command();
        command1->setArguments(cmd_1);

	char cmd4[] = "ls"; char* cmd5 = 0;
        char* cmd_2[2] = {cmd4, cmd5};

        Connector* command2 = new Command();
        command2->setArguments(cmd_2);

	SemiColon semicolon;
	semicolon.setLeftConnector(command1);
	semicolon.setRightConnector(command2);

        EXPECT_TRUE(semicolon.execute());
}

int main(int argc, char** argv)
{
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
}
