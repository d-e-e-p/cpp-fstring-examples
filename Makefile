#
# Makefile to drive cmake operations
# https://github.com/d-e-e-p/fixed-size-string-buffer
# Copyright (c) 2023 Sandeep <deep@tensorfield.ag>
# 

.PHONY: *
.DEFAULT_GOAL := help
INSTALL_LOCATION := ~/.local
CPM_SOURCE_CACHE:= .cache/CPM
#MAKEFLAGS += -j4
export CMAKE_BUILD_PARALLEL_LEVEL:= 4
# SHELL=/bin/bash -vx # for debug

include cmake/utils.mk

# Use the COMPARE_VERSIONS function to set the CMAKE_FRESH variable
# CMAKE_FRESH := $(shell python3 -c "$(COMPARE_VERSIONS_PY)")

BROWSER := python3 -c "$$BROWSER_PYSCRIPT"

help: ## this message
	@python3 -c "$$PRINT_HELP_PYSCRIPT" < $(MAKEFILE_LIST)

all: clean debug release test 

clean: ## remove build dir
	rm -rf build/

debug: ## create debug version of examples examples
	rm -rf ./build/debug/CMakeCache.txt
	cmake -S examples -B build/debug -DCMAKE_BUILD_TYPE=Debug
	cmake --build build/debug --config Debug 

release: ## create optimized version of examples
	rm -rf ./build/release/CMakeCache.txt
	cmake -S examples -B build/release -DCMAKE_BUILD_TYPE=Release
	cmake --build build/release --config Release 

test: release ## exercise all examples and compare output against validated version
	pytest -v


