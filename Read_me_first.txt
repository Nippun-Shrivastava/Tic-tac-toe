**---------------------------**

1.  first install the dev c++ from here -> "https://sourceforge.net/projects/orwelldevcpp/"

2.  Copy "graphics.h" and "winbgim.h" files and paste to "include" folder of Dev-cpp directory.
    Default location is ("C:\Program Files (x86)\Dev-Cpp\MinGW64\include\").

3.  Copy "libbgi.a" and paste to file "lib" folder of Dev-Cpp directory.
    Default location is ("C:\Program Files (x86)\Dev-cpp\MinGW64\lib\").

4.  Now open "tic tac toe.cpp" and go to "Tools" option then select "compliler Options" set "compiler set to configure" To "TDM-GCC 4.9.2 32-bit Release.

5.  then tick on "Add the following commands when calling the linker" and paste the following text there "-static-libgcc- lbgi -lgdi32 -lcomdlg32 -luuid  -lole32 -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32". Then click ok and run the programmer by pressing F11.


