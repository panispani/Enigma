# Enigma Machine Simulation

## Description
This is a simulation of an Enigma machine.  
If you need more information about how the machine works you can check the excellent [Wikipedia article](https://en.wikipedia.org/wiki/Enigma_machine)  

This implementation is configured with command line arguments and configuration files.

The program is called *enigma* and will be built by calling *make*
```sh
$ make
```
The program when run is given configuration file names as arguments.
The last configuration file will specify the wiring for the plugboard and the rest (if any) will specify the wiring for the rotors.

```sh
$ ./enigma rotors/I.rot rotors/II.rot rotors/II.rot plugboards/I.pb
```

Here the first rotor would use the mapping described in I.rot, and the second and third rotors would use the mapping described in II.rot. The plugboard would use the mapping described in I.pb.

The program reads input from stdin and prints output to stdout.

## Configuration files
### Rotors
Contains 26 numbers.  
The (0-based) ith number gives the (0-based) index into the alphabet that the ith letter maps to.
E.g. the configuration
```
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 0
```
shifts the alphabet up by one when mapped forwards and one doen when mapped backwards. (Remember that after each character is encrypted the first rotor is rotated by one position).

### Reflector
In this implementation it's not configurable.
Maps an input 
```
x -> (x + 13) % 26
```

### Plugboard
Contains an even number of numbers (including zero).  
The numbers are read in pairs and indicate a connection between two contacts on the plugboard. (the numbers are also 0-indexed).
For example the file plugboard/I.pb contains:
```
25 10 22 9 21 4
```
which corresponds to:  
'Z'(25) is connected to 'K'(10)  
'W'(22) is connected to 'J'(9)  
'V'(21) is connected to 'E'(4)  
All other letters are mapped to themselves

## Sample Configuration Files and A Small Testsuite

To run the testsuite, in this directory run:
```
./tests.py
```
This will only work if your compiled file is called *'enigma'*.

There are sample rotor configuration files in *rotors/*
and plugboard configuration files in *plugboards/*
