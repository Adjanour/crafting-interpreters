# Jilox

For public honesty and learning in public: to satisfy my curiosity, I'm reading and implementing Crafting Interpreters while (re)learning Java.

## Build & run

Requires Java 26. Uses the Maven Wrapper — no global Maven install needed.

```bash
./mvnw compile
./mvnw exec:java                    # REPL
./mvnw exec:java -Dexec.args="try.lox"
./mvnw test
./mvnw clean
```

Generate AST classes (later chapters):

```bash
./mvnw exec:java \
  -Dexec.mainClass=com.craftinginterpreters.tool.GenerateAst \
  -Dexec.args="src/main/java/com/craftinginterpreters/lox"
```

This repository is where I do that learning and implementation. I'm exploring a learning and writing style that blends confidence and empathy with clarity, using witty, fun sentences to explain concepts and share the enthusiasm and magic behind computers and their theories. Cheers to the writer.
