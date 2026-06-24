CXX      = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
BUILD    = build

.PHONY: all test-bigint test-vect2 test-polyset clean

all: test-bigint test-vect2 test-polyset

test-bigint: $(BUILD)/bigint-test
	$(BUILD)/bigint-test

test-vect2: $(BUILD)/vect2-test
	$(BUILD)/vect2-test

test-polyset: $(BUILD)/polyset-test
	$(BUILD)/polyset-test 1 2 3 2

$(BUILD)/bigint-test: bigint/reference/bigint.cpp bigint/main.cpp
	@mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) bigint/reference/bigint.cpp bigint/main.cpp \
		-I bigint/reference -o $@

$(BUILD)/vect2-test: vect2/reference/vect2.cpp vect2/main.cpp
	@mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) vect2/reference/vect2.cpp vect2/main.cpp \
		-I vect2/reference -o $@

$(BUILD)/polyset-test: polyset/given/array_bag.cpp polyset/given/tree_bag.cpp \
		polyset/reference/searchable_array_bag.cpp \
		polyset/reference/searchable_tree_bag.cpp \
		polyset/reference/set.cpp polyset/main.cpp
	@mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) \
		-I polyset/given -I polyset/reference \
		polyset/given/array_bag.cpp polyset/given/tree_bag.cpp \
		polyset/reference/searchable_array_bag.cpp \
		polyset/reference/searchable_tree_bag.cpp \
		polyset/reference/set.cpp polyset/main.cpp -o $@

clean:
	rm -rf $(BUILD)
