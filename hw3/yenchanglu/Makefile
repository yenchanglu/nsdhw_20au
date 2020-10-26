FLAGS ?=

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
MKLROOT ?= /opt/intel/mkl
MKLEXT ?= a
CXXFLAGS :=
endif

ifeq ($(UNAME_S),Linux)
MKLROOT ?= ${HOME}/opt/conda
MKLEXT ?= so
CXXFLAGS := -Wl,--no-as-needed
endif

MKLLINKLINE := \
	${MKLROOT}/lib/libmkl_intel_lp64.${MKLEXT} \
	${MKLROOT}/lib/libmkl_sequential.${MKLEXT} \
	${MKLROOT}/lib/libmkl_core.${MKLEXT} \
	-lpthread -lm -ldl

CXX = g++
CXXFLAGS := ${CXXFLAGS} \
	-std=c++17 -O3 -g -m64 \
	-Wall -Wextra -Werror -shared -fPIC \
	-I${MKLROOT}/include\
	${MKLLINKLINE} \
	${FLAGS}

PY = python3
PYTEST = pytest
SUFFIX = $(shell python3-config --extension-suffix)
MODULE = _matrix$(SUFFIX)

$(MODULE): matrix.cpp
	$(CXX) $(CXXFLAGS) `$(PY) -m pybind11 --includes` $< -o $@

.PHONY: test
test: $(MODULE)
	$(PYTEST) -v -l

.PHONY: clean
clean:
	rm -rf *.so __pycache__ .pytest_cache performance.txt
