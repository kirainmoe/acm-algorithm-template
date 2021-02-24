compile : template.tex check
	xelatex -shell-escape template.tex
	xelatex -shell-escape template.tex
update : template.tex
	xelatex -shell-escape template.tex
check : template.tex
	python3 check.py
clean : template.tex
	rm -rf template.aux
	rm -rf template.log
	rm -rf template.out
	rm -rf template.toc
