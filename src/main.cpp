#include "CommandLine.hpp"

int main()
{
    string userInput;
    CommandLine commandLine;

    while (1)
    {
        cout << "$$ ";
        getline(cin, userInput);

        if (userInput.empty())
            continue;
        else if (userInput == "exit" || userInput == "Exit" || userInput == "EXIT")
            break;
        else //user typed something other than exit
        {
            char* cString = new char [userInput.length()+1];
            strcpy(cString, userInput.c_str());

            commandLine.array2list(cString);

            if (commandLine.insertSpaces())
            {
                commandLine.list2array();
                commandLine.parse();
                commandLine.postfix();
                commandLine.buildTree();
                commandLine.execute();
                commandLine.deletion();
            }
            else
            {
                cout << "Mismatched parentheses/brackets or mismatched quotes\n";
                commandLine.clearCmdList();
            }

            delete [] cString;
            cString = 0;
        }
        
        userInput.clear();
    }

    return 0;
}
