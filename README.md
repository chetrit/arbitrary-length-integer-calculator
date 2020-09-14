# arbitrary-length-integer-calculator

> This project is a calculator of mathematical expressions, working with integers of an arbitrary length, wich means It can performs operations on numbers way bigger than the maximal values of an ``int`` or a ``long`` (which are respectively 2^16 and 2^32), including parenthesis and operating priorities.

# Features

  - Import a HTML file and watch it magically convert to Markdown
  - Drag and drop images (requires your Dropbox account be linked)

# Installation and compilation
#### Installation
After cloning the repository, you have nothing else to installed since it is in C and without external libraries !
    
#### Compilation
Compilation using makefile:
```
make
```
Run the unit tests using the rule ``tests_run``: (criterion lib is required)
```
make tests_run
```

# Usage
```
./calc -h
USAGE
./calc base operators size_read

DESCRIPTION
- base: all the digits of the base
- operators: the symbols for the parentheses and the 5 operators
- size_read: number of characters to be read
```

# Examples

```
echo "3+6" | ./calc 0123456789 "()+-*/%"" 3

echo "----++-6(12)" | ./calc 0123456789 "()+-*/%" 10

echo "----++-6*12" | ./calc 0123456789 "()+-*/%" 11

echo "-(12-(4*32))" | ./calc 0123456789 "()+-*/%" 12

echo "-(12*(13+15/5*(6/(12+14%(30%5+(10*25)-46)+16)-20)/43)*20)*(-(12-98*42)*(16+63-50/3))" | ./calc 0123456789 "()+-*/%" 84
```
## Contributors

 - [Alexandre Chetrit](https://github.com/chetrit)
 - [Martin Olivier](https://github.com/martinoliv78)
 - [Axel Karcher](https://github.com/RinkusuTV)
