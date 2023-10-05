OBJECTS = $(DIR_O)/str_func.o $(DIR_O)/str_input.o $(DIR_O)/onegin.o $(DIR_O)/func_sort.o $(DIR_O)/str_output.o $(DIR_O)/len_array.o $(DIR_O)/algoritm_sort.o
CC = g++
CFLAGS = -c -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE
DIR_O = object
DIR_SOUR = source
LFLAGS = -fsanitize=address


kotik.elf: $(OBJECTS)
	$(CC) $(OBJECTS) $(LFLAGS)  -o object/kotik.elf

$(DIR_O)/str_func.o: $(DIR_SOUR)/str_func.cpp $(DIR_SOUR)/str_func.h $(DIR_SOUR)/str_input.h
	$(CC) $(CFLAGS) $< -o $@

$(DIR_O)/onegin.o: $(DIR_SOUR)/onegin.cpp $(DIR_SOUR)/str_input.h $(DIR_SOUR)/func_sort.h $(DIR_SOUR)/str_func.h
	$(CC) $(CFLAGS) $< -o $@

$(DIR_O)/str_input.o: $(DIR_SOUR)/str_input.cpp $(DIR_SOUR)/str_input.h
	$(CC) $(CFLAGS) $< -o $@

$(DIR_O)/func_sort.o: $(DIR_SOUR)/func_sort.cpp $(DIR_SOUR)/func_sort.h $(DIR_SOUR)/str_input.h
	$(CC) $(CFLAGS) $< -o $@

$(DIR_O)/str_output.o: $(DIR_SOUR)/str_output.cpp $(DIR_SOUR)/func_sort.h $(DIR_SOUR)/str_input.h $(DIR_SOUR)/str_output.h
	$(CC) $(CFLAGS) $< -o $@

$(DIR_O)/len_array.o: $(DIR_SOUR)/len_array.cpp $(DIR_SOUR)/func_sort.h $(DIR_SOUR)/str_input.h
	$(CC) $(CFLAGS) $< -o $@

$(DIR_O)/algoritm_sort.o: $(DIR_SOUR)/algoritm_sort.cpp $(DIR_SOUR)/func_sort.h $(DIR_SOUR)/algoritm_sort.h
	$(CC) $(CFLAGS) $< -o $@


