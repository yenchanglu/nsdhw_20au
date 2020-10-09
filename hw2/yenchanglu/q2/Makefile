CXX = g++
CXXFLAGS = -O3 -Wall -Wextra -Werror -shared -std=c++11 -fPIC
PY = python3
PYTEST = pytest
MODULE = Vector2D

$(MODULE): $(MODULE).cpp
	$(CXX) $(CXXFLAGS) `$(PY) -m pybind11 --includes` $< -o $@`$(PY)-config --extension-suffix`

.PHONY: test
test: $(MODULE).*.so
	$(PYTEST) pybind_test.py

.PHONY: clean
clean:
	rm -rf *.so __pycache__ .pytest_cache
