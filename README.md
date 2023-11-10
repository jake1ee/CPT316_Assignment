# Syntax Analyzer

This is a simple C++ program that performs syntax analysis on mathematical expressions. It checks whether the entered expressions are well-formed based on basic grammar rules.

## Table of Contents

- [Introduction](#introduction)
- [Usage](#usage)
- [Features](#features)
- [Examples](#examples)

## Introduction

The Syntax Analyzer project is a C++ program designed to analyze the syntax of mathematical expressions. This tool evaluates the well-formedness of input expressions, identifying valid numeric values, operators, and parentheses based on simple grammar rules. With an interactive and user-friendly interface, users can input mathematical expressions, and the program will tokenize, validate, and analyze the syntax to determine whether the expression adheres to the specified grammar.

## Usage

1. Clone the repository:

```bash
git clone https://github.com/yourusername/syntax-analyzer.git
cd syntax-analyzer
```

## Features

### Tokenization: 
The program efficiently tokenizes input expressions, breaking them down into fundamental components such as numbers, operators, and parentheses.

### Grammar Rules: 
 The syntax analyzer implements basic grammar rules to check the validity of mathematical expressions. It recognizes numeric values, operators, and the correct usage of parentheses.

### User Interaction: 
 The tool provides an interactive user experience, prompting users to enter mathematical expressions. The program continues processing expressions until the user inputs "E" to terminate the program.

### Syntax Analysis: 
The heart of the project lies in its ability to perform syntax analysis, determining whether the entered expression is well-formed and adheres to the defined grammar.

## Examples

* "E" to terminate the program *
Enter a String: (2 + 3) * 4 - 5
'(' Is a Parenthesis
'2' Is a Value
'+' Is an Operator
'3' Is a Value
')' Is a Parenthesis
'*' Is an Operator
'4' Is a Value
'-' Is an Operator
'5' Is a Value
String Accepted
