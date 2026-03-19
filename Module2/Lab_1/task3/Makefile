TARGET =./calculator.out

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
		rm -rf $(TARGET)	

run: 
		$(TARGET)	










