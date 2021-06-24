# MetaMemory
A command line tool to manipulate the memory of other processes.

Usage:

Write to memory adress:
MetaMemory.exe -w ProcessName Adress Value

Example:
MetaMemory.exe -w ExampleProgram.exe 7D3EFFF 5

Read from memory adress:
MetaMemory.exe -r ProcessName Adress

Example:
MetaMemory.exe -r ExampleProgram.exe 7D3EFFF
