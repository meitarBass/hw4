//
// Created by Meitar Basson on 11/06/2022.
//

#ifndef HW4_EXCEPTION_H
#define HW4_EXCEPTION_H

#include <exception>

class DeckFileNotFound : public std::exception {
public:
    DeckFileNotFound() = default;
    ~DeckFileNotFound() override = default;
    const char* what() const noexcept override {return "Deck File Error: File not found\n";}
};

class DeckFileInvalidSize : public std::exception {
public:
    DeckFileInvalidSize() = default;
    ~DeckFileInvalidSize() override = default;
    const char* what() const noexcept override {return "Deck File Error: Deck size is invalid\n";}
};

class DeckFileFormatError : public std::exception {
private:
    int m_line;
public:
    explicit DeckFileFormatError(int line) : m_line(line) {};
    ~DeckFileFormatError() override = default;

    //TODO: manage line and card printing
    const char* what() const noexcept override {return "Deck File Error: File format error in line <lineNumberInDeckfile>\n";}
};
#endif //HW4_EXCEPTION_H
