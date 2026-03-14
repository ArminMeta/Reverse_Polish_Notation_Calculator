# **RPN Calculator in C++**

This project implements a **Reverse Polish Notation (RPN) calculator in C++** that evaluates mathematical expressions by first converting them from **infix notation** to **postfix notation (RPN)** and then computing the result.

The program demonstrates how **stacks, operator precedence, and expression parsing** can be used to evaluate mathematical expressions programmatically.

## **Project Overview**

In standard mathematics, expressions are written in **infix notation**, where operators are placed between operands:

`3 + 4 * 2`

Computers often evaluate expressions more easily using **Reverse Polish Notation (RPN)**, where operators come **after** operands:

`3 4 2 * +`

This project performs two main steps:

1. **Converts an infix expression to postfix (RPN)**  
2. **Evaluates the RPN expression using a stack**

The program uses **C++ STL containers** such as stacks and deques to manage operators and operands.

## **Features**

* Conversion from **infix notation to Reverse Polish Notation**  
* Mathematical evaluation of expressions  
* Operator precedence handling  
* Parentheses support `()` and `[]`  
* Error detection and exception handling  
* Stack-based evaluation algorithm

## **Supported Operators**

| Operator | Description |
| ----- | ----- |
| `+` | Addition |
| `-` | Subtraction |
| `*` | Multiplication |
| `/` | Division |

Operator precedence is implemented as:

| Operator | Priority |
| ----- | ----- |
| `*` `/` | High |
| `+` `-` | Medium |
| `(` `[` | Lowest |

## **How the Program Works**

### **1\. Expression Validation**

The program first checks that:

* The **first and last characters** are valid  
* Only **allowed characters** are used  
* Multi-digit numbers are **not allowed**  
* Parentheses are valid

If an invalid expression is entered, the program throws an exception.

### **2\. Infix to Postfix Conversion**

The function:

`string izvrnuto(string &izraz)`

converts the infix expression to **Reverse Polish Notation** using:

* a **stack** for operands

* a **deque** for operators

Example:

Input: `3+4*2`

Converted to RPN: `342*+`

### **3\. RPN Evaluation**

The function: `double racun(string &izraz)`

evaluates the postfix expression using a **stack-based algorithm**.

Steps:

1. Read expression from left to right  
2. Push numbers onto the stack  
3. When an operator appears:

   * Pop two numbers

   * Perform the operation

   * Push the result back onto the stack

Example:

`342*+`

Evaluation:

`4 * 2 = 8`

`3 + 8 = 11`

Result:

`11`

## **Example Usage**

Program input:

`Unesite vas izraz | ako zelite izac napisite EXIT`

`3+4*2`

Output:

`Vrijednost izraza je: 11`

To exit the program:

`EXIT`

## **Error Handling**

The program includes several runtime checks:

| Error | Description |
| ----- | ----- |
| Invalid characters | Expression contains unsupported symbols |
| Multi-digit numbers | Only single-digit numbers allowed |
| Invalid start/end | Expression must begin and end with number or bracket |
| Division by zero | Prevents invalid mathematical operations |

Example exception:

`throw logic_error("Nema djeljenja sa nulom");`

## **Technologies Used**

* **C++**

* **Standard Template Library (STL)**

Main STL containers used:

* `stack`  
* `deque`  
* `string`

## **Concepts Demonstrated**

This project demonstrates several important programming concepts:

* Stack-based algorithms  
* Expression parsing  
* Operator precedence  
* Reverse Polish Notation (RPN)  
* Exception handling  
* Use of C++ STL containers

## **Limitations**

Current limitations of the program include:

* Only **single-digit numbers** are supported  
* No support for **floating-point numbers**  
* No support for **advanced operators** (power, modulo, etc.)

## **Possible Improvements**

Future improvements could include:

* Support for **multi-digit numbers**  
* Support for **floating-point calculations**  
* Support for additional operators (`^`, `%`)  
* Graphical interface  
* Expression history  
* Interactive calculator mode

## **License**

This project is intended for **educational purposes**.

