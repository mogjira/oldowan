all: oldowan strgen generate

oldowan: oldo-main.c
	gcc $< -o bin/oldowan -Wall

strgen: str-gen.c
	gcc $< -o bin/strgen -Wall

generate: generate-files.c
	gcc $< -o bin/genfiles -Wall

clean: 
	rm -r out/* ; rm bin/* ; rm gen/*
