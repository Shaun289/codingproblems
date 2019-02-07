library_target=$(shell pwd)/library/target

TARGET = interval
SRCS = src/LeetCode_150_EvaluateReversePolishNotation.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

CPPFLAGS=-I$(library_target)/include -g -std=c++11
LDFLAGS=-L$(library_target)/lib -lgtest -lgtest_main -lpthread

all: $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LDFLAGS)

%.o: %.c
	@$(CXX) $(CFLAGS) $(CPPFLAGS) -c $<

gtest:
	@mkdir -p $(library_target)
	@(cd library/gtest; cmake -c CMakeLists.txt -DCMAKE_INSTALL_PREFIX=$(library_target) && make clean && make && make install)

clean:
	rm -f src/*.o
	rm -f $(TARGET)

