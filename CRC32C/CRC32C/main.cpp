/**
* @file main.cpp
*/
#include <CRC32.h>
int main(int argc, char* argv[])
{
bool help = false;
unsigned int main_crc;
char* filename;
      try {
if(argc > 1) {
// Разбор аргументов
for(int i = 0; i < argc; i++) {
if (argv[i][0] == '-') {
if (argv[i][1] == 'h')
help = true;
} else if(i > 0)
filename = argv[i];
}
      // Реализация аргументов
CRC32 object(filename);
if(help) {
	cout << "Программе передаётся путь к файлу в виде 'file.txt' для вычисления      кода CRC-32C" << endl;
} else {
if(object.calculate() != 0)
cout << hex << object.calculate() << endl;
else
cout << "Не верный путь к файлу!" << endl;
}
}
} catch (const CRC32_error & e) {cerr << "Ошибка: " << e.what() << endl;
}
  return 0;
}
