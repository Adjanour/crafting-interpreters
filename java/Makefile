JAVA_SRC = com/craftinginterpreters/lox
JAVA_PKG = com.craftinginterpreters.lox

all: Lox.class

Lox.class: $(JAVA_SRC)/*.java
	javac $(JAVA_SRC)/*.java

run: Lox.class
	java $(JAVA_PKG).Lox $(SCRIPT)

clean:
	find . -name "*.class" -delete
