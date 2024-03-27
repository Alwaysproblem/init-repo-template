#!/bin/bash

# docker run -ti --rm --name conversion -v `pwd`:/workdir/ -v `pwd`/config:/config  alwaysproblem/md2pdf mdtopdf User_Guide.md

# cd docs
docker run --rm -v "$(pwd):/data" alwaysproblem/pandoc User_Guide_eisv.md -o example.pdf --template config/eisvogel.latex --listings --from markdown --pdf-engine=xelatex -N
