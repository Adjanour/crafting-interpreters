JAVA_SRC = com/craftinginterpreters/lox
JAVA_PKG = com.craftinginterpreters.lox
SCRIPT ?= $(word 2,$(MAKECMDGOALS))

all: Lox.class

Lox.class: $(JAVA_SRC)/*.java
	javac $(JAVA_SRC)/*.java

run: Lox.class
	@if [ -z "$(SCRIPT)" ]; then echo "usage: make run <script.lox>"; exit 1; fi
	java $(JAVA_PKG).Lox $(SCRIPT)

%.lox:
	@:

clean:
	find . -name "*.class" -delete
