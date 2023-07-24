########## Variables ##########

CXX = g++					# compiler
CXXFLAGS = -g -Wall -MMD -Werror=vla -std=c++20 			# compiler flags
MAKEFILE_NAME = ${firstword ${MAKEFILE_LIST}}	# makefile name

OBJECTS = functions.o commandInterpreter.o main.o board.o block.o subject.o 			# object files forming executable
DEPENDS = ${OBJECTS:.o=.d}			# substitute ".o" with ".d"
EXEC = judy				# executable name

########## Targets ##########

.PHONY : clean					# not file names

${EXEC} : ${OBJECTS}				# link step
	${CXX} ${CXXFLAGS} $^ -o $@		# additional object files before $^

${OBJECTS} : ${MAKEFILE_NAME}			# OPTIONAL : changes to this file => recompile

# make implicitly generates rules to compile C++ files that generate .o files

-include ${DEPENDS}				# include *.d files containing program dependences

clean :						# remove files that can be regenerated
	rm -f ${DEPENDS} ${OBJECTS} ${EXEC}
	

########## Command Line Arugments ##########

##idk how to make it run by default without having to type default

# a: ${EXEC}
# 	./${EXEC} a

# text: ${EXEC}
# 	./${EXEC} -text

# seed: ${EXEC}
# 	./${EXEC} -seed xxx

# scriptfile1: ${EXEC}
# 	./${EXEC} -scriptfile1 xxx

# scriptfile2: ${EXEC}
# 	./${EXEC} -scriptfile2 xxx

# startlevel: ${EXEC}
# 	./${EXEC} -startlevel 