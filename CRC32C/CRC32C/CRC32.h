/**
* @file CRC32.h
* @author Иванов А.И.
* @version 1.0
* @date 29.05.2021
* @copyright ИБСТ ПГУ
* @brief Заголовочный файл для модуля CRC32
*/
#pragma once;
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
/**
* @brief Программа получает crc32 от файла
*/
class CRC32
{
private:
string filename;
unsigned int CRC32calc(unsigned char *buf, unsigned long len);
public:
CRC32() = delete;
CRC32(string filename);
unsigned int calculate();
};
/**
* @brief Класс обработки ошибок CRC32_error
*/
class CRC32_error: public std::invalid_argument
{
public:
explicit CRC32_error (const std::string& what_arg):
std::invalid_argument(what_arg) {}
explicit CRC32_error (const char* what_arg):
std::invalid_argument(what_arg) {}
};
