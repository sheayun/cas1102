INSTRUCTOR_SRC_DIR = .
INSTRUCTOR_SRC = $(INSTRUCTOR_SRC_DIR)/main.cpp \
                 $(INSTRUCTOR_SRC_DIR)/Shape.cpp \
				 $(INSTRUCTOR_SRC_DIR)/Circle.cpp \
				 $(INSTRUCTOR_SRC_DIR)/Rectangle.cpp \
				 $(INSTRUCTOR_SRC_DIR)/Triangle.cpp
CXX = g++
CXXFLAGS = -I$(INSTRUCTOR_SRC_DIR) --std=c++11
LDFLAGS =
TARGET = shapes

all: $(TARGET)

$(TARGET): $(INSTRUCTOR_SRC)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

clean:
	rm -f $(TARGET)
