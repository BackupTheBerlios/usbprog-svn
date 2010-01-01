DOCUMENT 	= USBprog.tex
DVIDOCUMENT 	= USBprog.dvi
PDFDOCUMENT 	= USBprog.pdf
SOURCES 	= USBprog.tex

DVIPARAMS	= -output-format dvi -src-specials
PDFPARAMS       =

default: pdf images
all: dvi pdf images

dvi: $(DVIDOCUMENT)
$(DVIDOCUMENT): $(SOURCES)
	pdflatex $(DVIPARAMS) $(DOCUMENT)

pdf: $(PDFDOCUMENT)
$(PDFDOCUMENT): $(SOURCES)
	pdflatex $(PDFPARAMS) $(DOCUMENT)

.PHONY : images
images:
	$(MAKE) -C images

clean:
	rm -f *.dvi *.pdf *.out *.log *.toc *.aux
