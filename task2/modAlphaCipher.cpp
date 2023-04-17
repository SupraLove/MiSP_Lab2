//modAlphaCipher.cpp
#include "modAlphaCipher.h"

std::string modAlphaCipher::decoder(const std::string& cipher_st) // РАСШИФРОВАНИЕ
{
    std::string s = getValidText(cipher_st);
    std::string n_s = s;
    int dlina = s.size(); // st-строка с текстом, который вводится пользователем
    int nstrok = (dlina - 1) / key + 1; // key-количество столбцов в таблице
    int a = 0;
    for (int column_number = key; column_number > 0; column_number--) { // colum_number-номер столбца
        for (int line_number = 0; line_number < nstrok; line_number++) { // line_number-номер строки
            int position = key * line_number + column_number - 1; //
            if (position < dlina) {
                n_s[position] = s[a];
                a++;
            }
        }
    }
    return n_s;
}

std::string modAlphaCipher::coder(const std::string& open_st) // ЗАШИФРОВАНИЕ
{
    std::string s = getValidText(open_st);
    std::string n_s = s;
    int dlina = s.size(); // st-строка с текстом, который вводится пользователем
    int nstrok = (dlina - 1) / key + 1; //key-количество столбцов в таблице
    int a = 0;
    for (int column_number = key; column_number > 0; column_number--) { // colum_number-номер столбца
        for (int line_number = 0; line_number < nstrok; line_number++) { // line_number-номер строки
            int position = column_number + key * line_number - 1;
            if (position < dlina) {
                n_s[a] = open_st[position];
                a++;
            }
        }
    }
    return n_s;
}

inline std::string modAlphaCipher::getValidText(const std::string& s)
{
    std::string tmp;
    for (auto c: s) {
        if (isalpha(c)) {
            if (islower(c))
                tmp.push_back(toupper(c));
            else
                tmp.push_back(c);
        }
    }
    if (tmp.empty())
        throw cipher_error("Empty open text");
    return tmp;
}
