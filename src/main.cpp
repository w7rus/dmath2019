#include <iostream>
#include <iomanip>
#include <fstream>
#include <typeinfo>
#include "conmenu.hpp"
#include "functions.hpp"

#ifdef _WIN32
    #include <stdint.h>
    #include <stdlib.h>
    typedef unsigned char uint8_t;

    #include<sstream>
    namespace std
    {
        template <typename T>
        std::string to_string(const T& value)
        {
            std::ostringstream oss;
            oss << value;
            return oss.str();
        }
    }
#endif

int g_arraySize = 1;
std::string g_outputFilePath;

void setArrayLength()
{
    std::cout << std::endl;
    std::cout << "Array length: ";
    std::cin >> g_arraySize;
    return;
}

void setOutputFile()
{
    std::cout << std::endl;
    std::cout << "Output file: ";
    std::getline(std::cin, g_outputFilePath);

    if (g_outputFilePath.size() > 256)
    {
        std::cout << "/!\\ Path to a file longer than 256 bytes is not allowed!" << std::endl;
        std::cout << "/i\\ Output will not be saved to file." << std::endl;
        g_outputFilePath.clear();
    }

    return;
}

void app_run()
{
    std::cout << "[Stage 1/] " << "Allocating..." << std::endl;
    uint8_t* arraySize = new uint8_t;
    if (arraySize == NULL)
    {
        std::cout << "Not enough memory to allocate " << sizeof(uint8_t) << " bytes!";
        return;
    }
    *arraySize = g_arraySize;

    std::cout << "[Stage 2/] " << "Allocating..." << std::endl;
    int* array = new int[*arraySize];
    if (array == NULL)
    {
        std::cout << "Not enough memory to allocate " << (sizeof(int) * *arraySize) << " bytes!";
        return;
    }

    std::cout << "[?] " << "Define custom array? (y/n): ";
    char keyPressed = std::cin.get();
    if (keyPressed == 'y' || keyPressed == 'Y')
    {
        std::cout << "[Stage 3/] " << "Defining..." << std::endl;
        for(uint8_t i = 0; i < *arraySize; i++)
        {
            for (;;)
            {
                bool hasValue = false;
                std::cout << "Value " << (int)i << "/" << (int)*arraySize << ": ";
                std::cin >> array[i];

                for (int j = 0; j < i; j++)
                {
                    if (array[j] == array[i])
                    {
                        hasValue = true;
                        break;
                    }
                }

                if (!hasValue)
                {
                    break;
                } else {
                    std::cout << "Value you just entered is already in the array!" << std::endl;
                }
            }
        }
    } else
    {
        std::cout << "[Stage 2/] " << "Generating..." << std::endl;
        for (int i = 0; i < *arraySize; i++)
        {
            int value = gen_int(0, *arraySize);
            for (;;)
            {
                bool hasValue = false;
                for (int j = 0; j < *arraySize; j++)
                {
                    if (array[j] == value)
                    {
                        hasValue = true;
                        break;
                    }
                }
                if (!hasValue)
                    break;
                value = gen_int(0, *arraySize);
            }
            array[i] = value;
        }
    }

    std::cout << "Original Array" << std::endl;
    std::cout << "[";
    for (uint8_t i = 0; i < *arraySize; i++) {
        std::cout << array[i];
        if (i != *arraySize - 1)
            std::cout << ",";
    }
    std::cout << "]";
    std::cout << std::endl;

    for (uint8_t i = 0; i < *arraySize - 1; i++) {
        for (int j = i + 1; j < *arraySize; j++) {
            if (array[i] > array[j]) {
                swap_int(&array[i], &array[j]);
            }
        }
    }

    std::ofstream file;
    if (!g_outputFilePath.empty())
    {
        file.open(g_outputFilePath.c_str());
        if (file.is_open()) {
            std::string buffer;

            buffer += "Original (Sorted) Array";
            buffer += '\n';
            buffer +=  '[';
            for (uint8_t i = 0; i < *arraySize; i++) {
                buffer += std::to_string(array[i]);
                if (i != *arraySize - 1)
                    buffer += ',';
            }
            buffer += "]";
            buffer += '\n';
            buffer += '\n';

            std::cout << buffer;
            file << buffer;

            buffer.clear();

            {
                uint64_t count = 1;

                for (;gen_arraySet(array, *arraySize);)
                {
                    buffer += "Set #";
                    buffer += std::to_string(count++);
                    buffer += '\n';
                    buffer += '[';
                    for (uint8_t i = 0; i < *arraySize; i++) {
                        buffer += std::to_string(array[i]);
                        if (i != *arraySize - 1)
                            buffer += ',';
                    }
                    buffer += ']';
                    buffer += '\n';

                    std::cout << buffer;
                    file << buffer;

                    buffer.clear();
                }
            }
        } else
        {
            std::cout << "/!\\ Cannot write file to [" << g_outputFilePath << "]" << std::endl;
        }
    } else
    {
        std::string buffer;

        buffer += "Original (Sorted) Array";
        buffer += '\n';
        buffer +=  '[';
        for (uint8_t i = 0; i < *arraySize; i++) {
            buffer += std::to_string(array[i]);
            if (i != *arraySize - 1)
                buffer += ',';
        }
        buffer += "]";
        buffer += '\n';
        buffer += '\n';

        std::cout << buffer;

        buffer.clear();

        {
            uint64_t count = 1;

            for (;gen_arraySet(array, *arraySize);)
            {
                buffer += "Set #";
                buffer += std::to_string(count++);
                buffer += '\n';
                buffer += '[';
                for (uint8_t i = 0; i < *arraySize; i++) {
                    buffer += std::to_string(array[i]);
                    if (i != *arraySize - 1)
                        buffer += ',';
                }
                buffer += ']';
                buffer += '\n';

                std::cout << buffer;

                buffer.clear();
            }
        }
    }

    std::cout << std::endl << "Press any key to continue..." << std::endl;
    std::cin.get();
    std::cin.get();

    delete(arraySize);
    delete(array);
}

int main(int argc, char const *argv[])
{
    char * ptrMenuObj_l0_0_title = new char[64];
    ptrMenuObj_l0_0_title = (char *)"Settings";
        char * ptrMenuObj_l0_1_title = new char[64];
        ptrMenuObj_l0_1_title = (char *)"Set array size";
        char * ptrMenuObj_l0_2_title = new char[64];
        ptrMenuObj_l0_2_title = (char *)"Set output file";

    char * ptrMenuObj_l1_0_title = new char[64];
    ptrMenuObj_l1_0_title = (char *)"Run";

    menuEntryContainer * ptrMenuObj_l0_0 = new menuEntryContainer(ptrMenuObj_l0_0_title, NULL, NULL, NULL, NULL, true);
        menuEntryAction * ptrMenuObj_l0_1 = new menuEntryAction(ptrMenuObj_l0_1_title, NULL, NULL, ptrMenuObj_l0_0, setArrayLength);
        menuEntryAction * ptrMenuObj_l0_2 = new menuEntryAction(ptrMenuObj_l0_2_title, ptrMenuObj_l0_1, NULL, ptrMenuObj_l0_0, setOutputFile);
        ptrMenuObj_l0_1->setNextEntry(ptrMenuObj_l0_2);
    ptrMenuObj_l0_0->setChildEntryList(ptrMenuObj_l0_1);

    menuEntryAction * ptrMenuObj_l1_0 = new menuEntryAction(ptrMenuObj_l1_0_title, ptrMenuObj_l0_0, NULL, NULL, app_run);
        ptrMenuObj_l0_0->setNextEntry(ptrMenuObj_l1_0);

    uint8_t* termWidth = new uint8_t;
    uint8_t* termHeight = new uint8_t;
    menuEntry * ptrMenuEntrySelected = ptrMenuObj_l0_0;
    for(;;) {
        term_clear();
        term_getDim(termWidth, termHeight);
        std::cout << std::setfill('=') << std::setw(*termWidth) << "" << std::setfill(' ') << std::endl;
        printMenu(ptrMenuObj_l0_0, 0, ptrMenuEntrySelected);
        std::cout << std::setfill('=') << std::setw(*termWidth) << "" << std::setfill(' ') << std::endl;
        std::cout << std::left << std::setw(20) << "[W] Previous Entry" << std::setw(20) << "[S] Next Entry" << std::setw(20) << "[A] Up Level" << std::setw(20) << "[D] Down Level" << std::setw(20) << "[Q] Toggle Disp." << std::setw(20) << "[E] Execute" << std::setw(20) << "[0] Exit" << std::endl;
        char keyPressed = std::cin.get();
        if (keyPressed == '0') break;
        if (keyPressed == 'a') {
            if (typeid(*ptrMenuEntrySelected) == typeid(menuEntryContainer)) {
                if (((menuEntryContainer *)ptrMenuEntrySelected)->getParentEntryList()) {
                    ptrMenuEntrySelected = ((menuEntryContainer *)ptrMenuEntrySelected)->getParentEntryList();
                }
            }
            if (typeid(*ptrMenuEntrySelected) == typeid(menuEntryAction)) {
                if (((menuEntryAction *)ptrMenuEntrySelected)->getParentEntryList()) {
                    ptrMenuEntrySelected = ((menuEntryAction *)ptrMenuEntrySelected)->getParentEntryList();
                }
            }
        }
        if (keyPressed == 'w') {
            if (ptrMenuEntrySelected->getPrevEntry()) {
                ptrMenuEntrySelected = ptrMenuEntrySelected->getPrevEntry();
            }
        }
        if (keyPressed == 'd') {
            if (typeid(*ptrMenuEntrySelected) == typeid(menuEntryContainer)) {
                if (((menuEntryContainer *)ptrMenuEntrySelected)->getChildEntryList()) {
                    if (!((menuEntryContainer *)ptrMenuEntrySelected)->getShowContentsState()) {
                        ((menuEntryContainer *)ptrMenuEntrySelected)->setShowContentsState(true);
                    }
                    ptrMenuEntrySelected = ((menuEntryContainer *)ptrMenuEntrySelected)->getChildEntryList();
                }
            }
        }
        if (keyPressed == 's') {
            if (ptrMenuEntrySelected->getNextEntry()) {
                ptrMenuEntrySelected = ptrMenuEntrySelected->getNextEntry();
            }
        }
        if (keyPressed == 'q') {
            if (typeid(*ptrMenuEntrySelected) == typeid(menuEntryContainer)) {
                if (((menuEntryContainer *)ptrMenuEntrySelected)->getShowContentsState()) {
                    ((menuEntryContainer *)ptrMenuEntrySelected)->setShowContentsState(false);
                }
                else {
                    ((menuEntryContainer *)ptrMenuEntrySelected)->setShowContentsState(true);
                }
            }
        }
        if (keyPressed == 'e') {
            if (typeid(*ptrMenuEntrySelected) == typeid(menuEntryAction)) {
                if (((menuEntryAction *)ptrMenuEntrySelected)->getAction_funcPtr()) {
                    ((menuEntryAction *)ptrMenuEntrySelected)->callAction_funcPtr();
                }
            }
        }
    }

    delete(ptrMenuObj_l0_0);
    delete(ptrMenuObj_l0_1);
    delete(ptrMenuObj_l0_2);
    delete(ptrMenuObj_l1_0);
    return 0;
}