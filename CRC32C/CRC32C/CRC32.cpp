/**
 * @file CRC32.cpp
 */
#include <CRC32.h>
/**
* @brief Конструктор класса CRC32
* @param filename путь к файлу для вычисление crc32
* @throw CRC32_error, в случае ошибки
*/
CRC32::CRC32(string filename){
if(filename.empty())
throw CRC32_error("Введена пустая строка!");

	if(filename.find(".") == -1 || filename.find(".") == filename.length())
	throw CRC32_error("Не коректное расширение файла!");
       bool hasLetter = 0;
	for(auto s : filename)
if(s > 64 && s < 91 || s > 96 && s < 123) {
hasLetter = true;
break;
}
if(!hasLetter)
throw CRC32_error("Не коректное имя файла!");
this->filename = filename;
}
/**
* @brief Вычисление CRC32calc
* @param unsigned char *buf - содержимое файла
* @param unsigned long len - длинна файла
* @throw CRC32_error - если произошла ошибка
* @return Возвращает crc32 код
*/
unsigned int CRC32::CRC32calc(unsigned char *buf, unsigned long len)
{
if(buf[0] == 0)
throw CRC32_error("Пустой файл!");
unsigned long crc_table[256];
unsigned long crc;
for (int i = 0; i < 256; i++) {crc = i;for (int j = 0; j < 8; j++)
if(crc & 1)
crc = (crc >> 1) ^ 0x82F63B78;
else
crc = crc >> 1;
crc_table[i] = crc;
};
crc = 0xFFFFFFFFUL;
while (len--) {
crc = crc_table[(crc ^ *buf++) & 0xFF] ^ (crc >> 8);
}
return crc ^ 0xFFFFFFFFUL;
}
/**
* @brief Открытие файла и разбор его на переменные
* @throw CRC32_error - если произошла ошибка
* @return Вызывает метод CRC32calc передавая туда содержимое и длину файла
*/
unsigned int CRC32::calculate()
{
char buf[4096*64];
ifstream f (filename,std::ios::binary);
if(!f)
throw CRC32_error("Ошибка открытия файла!");
f.read(buf,4096*64);
return CRC32calc((unsigned char*)buf, f.gcount());
}
