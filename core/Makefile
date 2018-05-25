FILES=$(shell find -name "*.cpp" -type f)
OBJS =$(patsubst %.cpp, %.o, $(FILES))
OUT  =libcnescore.a

# add any extra flags if necessary #
CXXFLAGS := $(CFLAGS) -lpthread

all: $(BUILD)/$(OUT)

# Build the final archive #
$(BUILD)/$(OUT): $(OBJS)
	@echo -en "[\e[34;1m  AR  \e[0m] -c" $(OBJS) -o $(BUILD)/$(OUT)"\n"
	@$(AR) $(AFLAGS) $@ $(OBJS)

# Build each source file #
%.o: %.cpp
	@echo -e "[\e[31;1m  CXX  \e[0m] -c" $< -o $@
	@$(CC) $(CXXFLAGS) -c $< -o $@
