#include "gtest/gtest.h"
#include "../src/Connector.hpp"
#include "../src/Command.hpp"
using namespace std;

//Testing Command execute function
TEST(CommandTest, CommandExecuteTest1)
{
	char cmd1[] = "echo";
	char cmd2[] = "hello";
	char* cmd3 = 0;

	char* cmd[3] = {cmd1, cmd2, cmd3};

	Command command;
	command.setArguments(cmd);

        EXPECT_TRUE(command.execute());
}

TEST(CommandTest, CommandExecuteTest2)
{
	char cmd1[] = "eco";
        char cmd2[] = "hello";
        char* cmd3 = 0;

        char* cmd[3] = {cmd1, cmd2, cmd3};

        Command command;
        command.setArguments(cmd);

        EXPECT_FALSE(command.execute());
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
