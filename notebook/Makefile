cppfiles=$(wildcard *.cpp)

notebook.pdf: notebook.tex $(cppfiles)
	pdflatex -shell-escape $<
