files=$(patsubst %.cpp,%,$(wildcard *.cpp)) 
files+=$(patsubst %.java,%.class,$(wildcard *.java))

all: $(files)

%: %.cpp
	g++ -g -ggdb -lm -std=c++11 -pipe -o $@ $<

%.class: %.java
	javac -g $<
