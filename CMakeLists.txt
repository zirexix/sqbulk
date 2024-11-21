cmake_minimum_required(VERSION 3.16)

project(sqbulk LANGUAGES C CXX)

include_directories(sshh include)

add_executable(sqbulk
  main.cpp
  squirrel/sqapi.cpp squirrel/sqarray.h squirrel/sqbaselib.cpp squirrel/sqclass.cpp squirrel/sqclass.h squirrel/sqclosure.h squirrel/sqcompiler.cpp squirrel/sqcompiler.h squirrel/sqdebug.cpp squirrel/sqfuncproto.h squirrel/sqfuncstate.cpp squirrel/sqfuncstate.h squirrel/sqlexer.cpp squirrel/sqlexer.h squirrel/sqmem.cpp squirrel/sqobject.cpp squirrel/sqobject.h squirrel/sqopcodes.h squirrel/sqpcheader.h squirrel/sqstate.cpp squirrel/sqstate.h squirrel/sqstring.h squirrel/sqtable.cpp squirrel/sqtable.h squirrel/squserdata.h squirrel/squtils.h squirrel/sqvm.cpp squirrel/sqvm.h
  sqstdlib/sqstdaux.cpp sqstdlib/sqstdblob.cpp sqstdlib/sqstdblobimpl.h sqstdlib/sqstdio.cpp sqstdlib/sqstdmath.cpp sqstdlib/sqstdrex.cpp sqstdlib/sqstdstream.cpp sqstdlib/sqstdstream.h sqstdlib/sqstdstring.cpp sqstdlib/sqstdsystem.cpp
  sscpp/args.cpp sscpp/array.cpp sscpp/class.cpp sscpp/enum.cpp sscpp/function.cpp sscpp/instance.cpp sscpp/object.cpp sscpp/script.cpp sscpp/sq_module.cpp sscpp/table.cpp sscpp/vm.cpp
  sshh/allocators.hpp sshh/args.hpp sshh/array.hpp sshh/binding.hpp sshh/class.hpp sshh/enum.hpp sshh/exceptions.hpp sshh/function.hpp sshh/instance.hpp sshh/object.hpp sshh/script.hpp sshh/simplesquirrel.hpp sshh/sq_module.hpp sshh/table.hpp sshh/type.hpp sshh/vm.hpp
  bin/system.ss
)
set(BIN_NAME sqbulk)

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${PROJECT_BINARY_DIR}/sqbulk
    ${CMAKE_CURRENT_SOURCE_DIR}/bin/sqbulk
)


