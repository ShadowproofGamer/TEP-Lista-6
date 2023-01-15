
#include "constants.h"
#include "Tests.h"
#include "Runner.h"
using namespace runner;

int main() {
	//test programu w przypadku nieznalezienia pliku / b³êdu pliku:
	//	Tests::test4();
	//test programu w przypadku prawid³owego pliku "Tekst1.txt":
	//	Tests::test5();
	//test programu w przypadku prawid³owego pliku (stara wersja):
	//	Tests::test6();
	//test programu w ka¿dym rzypadku:
	//	Tests::test7();



	runProgram("Tekst1.txt", 1000, 0.7, 0.03);








	return 0;
}