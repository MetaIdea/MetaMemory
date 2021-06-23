#include "Memory.h"

int main(int argc, char* argv[])
{
    if (argc <= 3) {
        std::cout << "Usage:\nwrite: metamemory -w processname pointeradress+offset1+... newvalue\nread: metamemory -r processname pointeradress+offset1+... valuetype\nvaluetype: int, float, byte, string\n";
		return 0;
    }
    else {
		try {
			for (int i = 1; i < argc; i++) {
				if (!std::string(argv[i]).compare("-w")) {
					if (++i == argc) { throw  "missing parameter"; }
					try { SetValue(argv[2], argv[3], argv[4]); }
					catch (...) { throw "error writing value"; }
				}
				else if (!std::string(argv[i]).compare("-r")) {
					if (++i == argc) { throw  "missing parameter"; }
					if (argc == 4) {
						try { std::cout << ReadValue(argv[2], argv[3], argv[4]) << std::endl; }
						catch (...) { throw "error reading value"; }
					}
					else {
						try { std::cout << ReadValue(argv[2], argv[3], "int") << std::endl; }
						catch (...) { throw "error reading value"; }
					}
				}
			}
			return 0;
		}
		catch (const char* Reason) { std::cerr << Reason << std::endl; exit(1); } //MessageBox(NULL, Reason, "ERROR", MB_ICONERROR);
		//MyObj.SetDebugOutput(std::cout);
		std::cin.get();
    }
}