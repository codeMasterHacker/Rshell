CXX = g++ -std=c++11
CXXFLAGS = -Wall -g

rshell: main.o Command.o DoubleAmpersand.o InputRedirector.o Or.o OutputAppender.o OutputRedirector.o Pipe.o SemiColon.o TestCommand.o CommandLine.o
	$(CXX) $(CXXFLAGS) -o rshell main.o Command.o DoubleAmpersand.o InputRedirector.o Or.o OutputAppender.o OutputRedirector.o Pipe.o SemiColon.o TestCommand.o CommandLine.o

main.o: main.cpp CommandLine.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Command.o: Connector.hpp

DoubleAmpersand.o: Connector.hpp

InputRedirector.o: Connector.hpp

Or.o: Connector.hpp

OutputAppender.o: Connector.hpp

OutputRedirector.o: Connector.hpp

Pipe.o: Connector.hpp

SemiColon.o: Connector.hpp

TestCommand.o: Connector.hpp

CommandLine.o: Command.hpp TestCommand.hpp SemiColon.hpp DoubleAmpersand.hpp Or.hpp Pipe.hpp OutputAppender.hpp OutputRedirector.hpp InputRedirector.hpp

clean:
	rm rshell main.o Command.o DoubleAmpersand.o InputRedirector.o Or.o OutputAppender.o OutputRedirector.o Pipe.o SemiColon.o TestCommand.o CommandLine.o
