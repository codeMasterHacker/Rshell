CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

project(rshell)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE( rshell
                src/main.cpp
                src/Command.cpp
                src/SemiColon.cpp
                src/DoubleAmpersand.cpp
		src/Or.cpp
                src/Pipe.cpp
                src/CommandLine.cpp
                src/TestCommand.cpp
                src/InputRedirector.cpp
                src/OutputRedirector.cpp
                src/OutputAppender.cpp
)

ADD_EXECUTABLE(	cmdExe_unitTest
		unit_tests/cmdExe_unitTest.cpp
                src/Command.cpp
)

ADD_EXECUTABLE( connector_unitTest
		unit_tests/connector_unitTest.cpp
		src/Command.cpp
                src/SemiColon.cpp
                src/DoubleAmpersand.cpp
                src/Or.cpp
                src/Pipe.cpp
)

ADD_EXECUTABLE( tstCmdExec_unitTest
		unit_tests/tstCmdExec_unitTest.cpp
		src/TestCommand.cpp
)

ADD_EXECUTABLE( redirecting_unitTest
		unit_tests/redirecting_unitTest.cpp
		src/Command.cpp
		src/InputRedirector.cpp
                src/OutputRedirector.cpp
                src/OutputAppender.cpp
)

TARGET_LINK_LIBRARIES(cmdExe_unitTest gtest)
TARGET_COMPILE_DEFINITIONS(cmdExe_unitTest PRIVATE gtest_disable_pthreads=ON)

TARGET_LINK_LIBRARIES(connector_unitTest gtest)
TARGET_COMPILE_DEFINITIONS(connector_unitTest PRIVATE gtest_disable_pthreads=ON)

TARGET_LINK_LIBRARIES(tstCmdExec_unitTest gtest)
TARGET_COMPILE_DEFINITIONS(tstCmdExec_unitTest PRIVATE gtest_disable_pthreads=ON)

TARGET_LINK_LIBRARIES(redirecting_unitTest gtest)
TARGET_COMPILE_DEFINITIONS(redirecting_unitTest PRIVATE gtest_disable_pthreads=ON)
