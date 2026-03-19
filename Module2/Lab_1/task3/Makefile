
ifeq ($(findstring Windows,$(OS)),Windows)
   
    TARGET_EXT = .exe
    RM_CMD = del /Q
    RUN_CMD = 
else
    
    TARGET_EXT = .out
    RM_CMD = rm -f
    RUN_CMD = ./
endif

TARGET = calculator$(TARGET_EXT)

HDRS_DIR = \
			Lab_1 \
			task3

SRCS = \
	    main.c  \
		calculator.c 

.PHONY: all build clean run

$(TARGET):
		gcc $(addprefix -I,$(HDRS_DIR)) $(SRCS) -o $(TARGET)

all: clean build

build: $(TARGET)

clean:
		$(RM_CMD) $(TARGET)	

run: 
		$(RUN_CMD)$(TARGET)