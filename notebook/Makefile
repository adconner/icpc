sourcefiles=$(wildcard *.cpp) $(wildcard *.java)
objects=$(patsubst %.cpp,%.o,$(wildcard *.cpp))
classes=$(patsubst %.java,%.class,$(wildcard *.java))

notebook.pdf: notebook.tex $(sourcefiles)
	pdflatex -shell-escape $<
	pdflatex -shell-escape $<

ensurecompile: $(objects) $(classes)

%.o: %.cpp
	g++ -c $< -o $@

%.class: %.java
	javac $< -o $@
