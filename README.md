# Syntax Analyzer
## Purpose
The program parses input files with defined language into abstract syntax trees and saves the output result as a dot graphs. <br/>
Output files named "{original filename}.{function name}.ext" and contains the control flow graph of certain function. <br />
The input language must match the following grammar:
```
identifier: "[a-zA-Z_][a-zA-Z_0-9]*";
str: "\"[^\"\\]*(?:\\.[^\"\\]*)*\"";
hex: "0[xX][0-9A-Fa-f]+";
bits: "0[bB][01]+";
dec: "[0-9]+";
bool: 'true'|'false';

list<item>: (item (',' item)*)?;

expr: {
  |binary: expr binOp expr
  |unary: unOp expr;
  |braces: '(' expr ')';
  |callOrIndexer: expr '(' list<expr> ')';
  |place: identifier;
  |literal: bool|str|char|hex|bits|dec;
};

typeRef: {
  |builtin: 'bool'|'byte'|'int'|'uint'|'long'|'ulong'|'char'|'string';
  |custom: identifier;
  |array: typeRef '(' (',')* ')';
};

statement: {
  |var: 'dim' list<identifier> 'as' typeRef;
  |if: 'if' expr 'then' statement* ('else' statement*)? 'end' 'if';
  |while: 'while' expr statement* 'wend';
  |do: 'do' statement* 'loop' ('while'|'until') expr;
  |break: 'break';
  |expression: expr ';';
};

funcSignature: identifier '(' list<argDef> ')' ('as' typeRef)? {
  argDef: identifier ('as' typeRef)?;
};

sourceItem: {
  |funcDef: 'function' funcSignature statement* 'end' 'function';
};

source: sourceItem*;
```
## Usage
```console
user@device:~$ make compile
user@device:~$ ./analyzer [filename...]
```
<br/>

## Input example
```
function set_sock(sock as int) as int
 if (sock == 0) then
    sock = 2;
  else
    sock = to_int(argv(1));
  end if
end function

function main(argc, argv as string())
  dim tmp, sock as int
  do
    tmp = tmp + 1;
    sock = sock * tmp;
  loop until sock < 655546
  set_sock(sock);
end function
```
<p align="right"><b><i>file-1</i></b></p>

```
function lib_func(m as Model, options)
  if m then
    while options
      opt = options(-1);
      m(opt);
      opt = options(0, -1);
    wend
    m(null);
  else
    m = Model(options(0));
    m(null);
  end if
end function
```
<p align="right"><b><i>file-2</i></b></p>

## Output example

<br />
<p align="center">
  <img src="https://github.com/Tvo-Po/custom-syntax-analyzer/assets/90851216/7b739370-c36a-4619-ba92-22ee223d7707" />
</p>
<p align="right"><b><i>file-1.main.ext</i></b></p>

<hr />

<br />
<p align="center">
  <img src="https://github.com/Tvo-Po/custom-syntax-analyzer/assets/90851216/f642a2ff-eec3-4cc9-bcbd-6e99253eee88" />
</p>
<p align="right"><b><i>file-1.main.ext</i></b></p>


<hr />

<br />
<p align="center">
  <img src="https://github.com/Tvo-Po/custom-syntax-analyzer/assets/90851216/a9feb226-58a8-44a5-80d8-8d24662bfb22" />
</p>
<p align="right"><b><i>file-2.lib_func.ext</i></b></p>
