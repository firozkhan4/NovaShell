# Novashell

Welcome to **Novashell**, a custom shell project designed to provide a simple and efficient command-line interface. This documentation serves as a comprehensive guide for users to understand, build, and extend the shell.

## Table of Contents
1. [Introduction](#introduction)
2. [Features](#features)
3. [Getting Started](#getting-started)
4. [Building Novashell](#building-novashell)
5. [Usage](#usage)
6. [Checklist to Create Your Own Shell](#checklist-to-create-your-own-shell)
7. [Contributing](#contributing)
8. [License](#license)

## Introduction
Novashell aims to replicate the basic functionalities of traditional command-line shells, allowing users to execute commands, manage files, and interact with the system in a user-friendly manner.

## Features
- Command execution with `fork()` and `execvp()`
- Support for built-in commands (`cd`, `exit`, etc.)
- Command loop with prompt display
- Basic I/O redirection
- Optional support for piping and background jobs
- History feature for previous commands (planned)

## Getting Started
### Prerequisites
- C/C++ compiler (e.g., `gcc` for C)
- Development tools (e.g., `make`, `gdb`)
- A text editor or IDE (e.g., `VS Code`, `Vim`)

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/novashell.git
   cd novashell
   ```
2. Compile the project:
   ```bash
   make
   ```

## Usage
To run Novashell:
```bash
./novashell
```
You will see a prompt like `my_shell>`. Enter commands as you would in a standard shell.

### Example Commands
- `ls` - List directory contents
- `cd <directory>` - Change current directory
- `echo Hello, World!` - Print "Hello, World!" to the terminal
- `exit` - Exit the shell

## Checklist to Create Your Own Shell
Follow this checklist step-by-step to build your own shell and gradually add advanced features:

### 1. Set Up the Development Environment
- [ ] Choose a programming language (e.g., **C** or **C++**).
- [ ] Install necessary tools (e.g., **gcc**, **gdb**, **make**).
- [ ] Set up a text editor or IDE.

### 2. Display the Shell Prompt
- [ ] Write code to display a prompt.
- [ ] Capture user input.

### 3. Parse the Input Command
- [ ] Tokenize the input string.
- [ ] Store tokens in an array (e.g., `argv[]`).

### 4. Create a Thread to Execute Commands
- [ ] Use `Thread` to create a new process.
- [ ] Handle execution errors.

### 5. Wait for the Thread Process
- [ ] Use `join()` to join for the child.

### 6. Handle Built-In Commands
- [ ] Implement `cd`, `exit`, and other essential commands.

### 7. Implement Command Loop
- [ ] Run the shell in an infinite loop until exit.

### 8. Improve Command Parsing
- [ ] Handle multiple spaces and errors.

### 9. Implement I/O Redirection
- [ ] Support output (`>`) and input (`<`) redirection.

### 10. Implement Piping
- [ ] Add support for piping (`|`).

### 11. Handle Signal Interrupts
- [ ] Manage signals like `Ctrl+C`.

### 12. Add Background Job Support
- [ ] Enable background execution with `&`.

### 13. Add History Feature
- [ ] Store and navigate previous commands.

### 14. Test and Debug
- [ ] Test various commands and fix issues.

### 15. Extend and Refine Features
- [ ] Implement tab completion and environment variables.

## Contributing
We welcome contributions! If you have suggestions or improvements, feel free to open an issue or submit a pull request.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

Thank you for using Novashell! We hope you find it helpful. If you have any questions, please feel free to reach out.
