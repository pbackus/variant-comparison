CXX = clang++-8 -std=c++17 -stdlib=libc++
DC = ldc2
CC = clang-8 -std=c99
OBJDUMP_FLAGS = -dwr --no-show-raw-insn

all: cunion.txt cppvariant.txt dsumtype.txt dalgebraic.txt

clean:
	rm *.o *.txt

cunion.o: cunion.c
	$(CC) -c -O2 -o $@ $<

cppvariant.o: cppvariant.cpp
	$(CXX) -c -O2 -o $@ $<

dsumtype.o: dsumtype.d
	$(DC) -c -O2 -of=$@ $<

dalgebraic.o: dalgebraic.d
	$(DC) -c -O2 -of=$@ $<

cunion.txt: cunion.o
	objdump $(OBJDUMP_FLAGS) $< > $@

cppvariant.txt: cppvariant.o
	objdump $(OBJDUMP_FLAGS) $< | c++filt > $@

dsumtype.txt: dsumtype.o
	objdump $(OBJDUMP_FLAGS) $< | ddemangle > $@

dalgebraic.txt: dalgebraic.o
	objdump $(OBJDUMP_FLAGS) $< | ddemangle > $@
