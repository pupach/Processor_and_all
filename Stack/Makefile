OBJECTS = $(DIR_O)/main.o $(DIR_O)/stack.o $(DIR_O)/hash.o $(DIR_LIB)/work_with_file.o  $(DIR_O)/verification_and_check.o
CC = g++
CC = g++
CFLAGS = -c -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

DIR_O = .
DIR_SOUR = .
DIR_LIB = ../my_lib

# 1) use wildcard to get all cpps
# 2) add a rule to make .o from .cpp
# 3) add var for list of all .o or .cpp files needed to make a project
# 4) target <executable>: $(OBJFILES)
#	g++ $(OBJFILES) -o <
# 5)

kotik.elf: $(OBJECTS)
	$(CC) $(OBJECTS) -o kotik.elf

$(DIR_O)/main.o: $(DIR_SOUR)/main.cpp $(DIR_SOUR)/verification_and_check.h $(DIR_SOUR)/stack.h $(DIR_SOUR)/type_stck_element.h $(DIR_SOUR)/stack.h
	$(CC) $(CFLAGS) $< -o $@

$(DIR_O)/stack.o: $(DIR_SOUR)/stack.cpp $(DIR_SOUR)/stack.h $(DIR_SOUR)/hash.h $(DIR_LIB)/work_with_file.h $(DIR_SOUR)/verification_and_check.h $(DIR_SOUR)/type_stck_element.h
	$(CC) $(CFLAGS) $< -o $@

$(DIR_O)/hash.o: $(DIR_SOUR)/hash.cpp $(DIR_SOUR)/hash.h $(DIR_SOUR)/type_stck_element.h
	$(CC) $(CFLAGS) $< -o $@

$(DIR_LIB)/work_with_file.o: $(DIR_LIB)/work_with_file.cpp $(DIR_LIB)/work_with_file.h $(DIR_SOUR)/type_stck_element.h
	$(CC) $(CFLAGS) $< -o $@

$(DIR_O)/verification_and_check.o: $(DIR_SOUR)/verification_and_check.cpp $(DIR_SOUR)/verification_and_check.h $(DIR_SOUR)/stack.h $(DIR_SOUR)/type_stck_element.h
	$(CC) $(CFLAGS) $< -o $@




