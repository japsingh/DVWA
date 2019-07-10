# DVWA
Damned Vulnerable Windows Application

In line with the other "Damned vulnerable" series of binaries, this is a demonstration of software vulnerabilities in a Windows desktop application, which lead to exploits. Currently, the following vulnerabilities are demonstrated:
1. Stack buffer overrun -- (ASLR, DEP, Stack checks disabled)
2. ROP ------------------- (ASLR, Stack checks disabled. DEP enabled)
3. Integer overflow ------ (ASLR, DEP, Stack checks disabled)
4. Virtual pointer ------- (ASLR, DEP, Stack checks disabled)

Feel free to use the code in trainings and other legal purposes.

Shellcode used:
https://github.com/peterferrie/win-exec-calc-shellcode

Usage:
1. Clone the repo locally
2. Launch DVWA\DVWA.sln (Visual studio 2017)
3. Build the solution in Release mode. This will generate all the executables in DVWA\Release folder.
4. Copy *.bin from DVWA\Exploit folder to DVWA\Release folder
5. From commandline, navigate to DVWA\Release folder
6. Execute Exploit.exe
