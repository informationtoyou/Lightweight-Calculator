# Lightweight Calculator
## Introduction
Lightweight Calculator is a console-based app which allows you to perform calculations such as basic arithmetic, and conversion.
## Details
Lightweight Calculator is made in C++ and is supported on Windows.
## Technical Requirements
You need to use a Windows OS, I recommend a modern one. I have not tested for Windows 7, 8, XP, 3.1 (the 3 latter nobody actually uses anymore and even the case with the former). I can confirm this works on Windows 10/11.
After all, it is a lightweight calculator.
## Pull Requests & Issues
Pull requests are welcomed, please make an issue if you have a suggestion for the calculator or have any problems while using the application.
This is a project to help me expand my knowledge of C++.
## Open Source is cool, so take advantage of it
Feel free to fork this if you want, spy on all the source-code. This is open-source and will remain under the MIT Licence for everyone to use.
## Installation Instructions
- Unzip the release file and extract it (you might want to use a program like WinRAR or 7Zip in certain circumstances)
- Launch the "Lightweight-Calculator.exe" file
- If this does not work, consider installing the Microsoft Visual C++ Redistributable which is included in the package.
- Normally, you should not require doing so as the release executable has been compiled using GCC which should already dynamically link with the required dependencies.
- If you have to install MS Visual C++ Redistributable please open an Issue so I can try to fix it, this is in early access.
### IMPORTANT: Unsigned Executable Notice
**The Lightweight Calculator executable is unsigned because this is an open-source project. You may see a warning from Windows SmartScreen when running the `.exe`. If you prefer, you can build the executable yourself using the provided source code.**
## DIY Do It Yourself
If you want to compile this yourself, you are more than welcome to do so, here are some instructions using the GCC compiler and Git:
1. Clone the repository
   ```bash
   git clone https://github.com/informationtoyou/Lightweight-Calculator.git
   cd Lightweight-Calculator
   ```
2. Build from main.cpp file
   ```bash
   g++ -o Lightweight-Calculator.exe main.cpp
   ```
3. Execute the executable
   ```bash
   ./Lightweight-Calculator.exe
   ```
## Notes
If you have any issues, please feel free to open an issue and/or contact me. Wishing you the best from my side!
