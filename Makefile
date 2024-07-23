CC=gcc

# PKGS=glib-2.0

CFLAGS=-o3 -Werror -Wall -Wextra -Wpedantic -Wunused -Wsign-conversion -Wconversion -Wcast-qual -Wfloat-equal -Wunused-result -std=c11
# CFLAGS+=$(shell pkg-config --cflags $(PKGS))

# LDFLAGS=$(shell pkg-config --libs $(PKGS))

TARGET=$(shell basename `pwd`)
BUILD_DIR=build/
TEMP_DIR=/tmp/$(shell basename $(shell pwd))

SOURCES=$(wildcard src/*.c)

OBJECTS=$(addprefix $(TEMP_DIR)/, $(subst src/,,$(SOURCES:.c=.o)))

all: $(TARGET)

$(BUILD_DIR) $(TEMP_DIR):
	@mkdir -p $@

$(TARGET): $(BUILD_DIR) $(TEMP_DIR) $(OBJECTS)
	$(CC) -o build/$(TARGET) $(OBJECTS) $(LDFLAGS)

$(TEMP_DIR)/%.o: src/%.c $(TEMP_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o $(OBJECTS)
	@rm -rf $(BUILD_DIR) $(TEMP_DIR)
	@rm -rf build
