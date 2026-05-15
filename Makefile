DIR_LIB   := PWP/lib
SOURCES := $(shell find $(DIR_LIB) -name '*.cpp')
HEADERS  := $(shell find $(DIR_LIB) -name '*.hpp')
ALL_FILES := $(SOURCES) $(HEADERS)

FORMATTER := clang-format
LINTER    := clang-tidy

all: lint format

format:
	@echo "Formatting code..."
	$(FORMATTER) -i -style=file $(ALL_FILES)

format-check:
	@echo "Checking formatting..."
	$(FORMATTER) --dry-run --Werror -style=file $(ALL_FILES)

lint:
	@echo "Linting code..."
	$(LINTER) $(SOURCES) -- -I$(INCDIR)

build:
	cmake -S . -B build -G Ninja

compile:
	cmake --build build

clean:
	rm -rf build

test:
	ctest --test-dir build --output-on-failure