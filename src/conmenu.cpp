// conmenu.cpp
//

#include <typeinfo>
#include <iostream>
#include <iomanip>
#include "conmenu.hpp"
menuEntry::menuEntry ()
    : alias (NULL), menuEntry_prevEntry (NULL), menuEntry_nextEntry (NULL), menuEntry_parentEntryList (NULL)
    {
        menuEntry * ptrMenuEntry_propThis = this;
        char * ptrMenuEntry_propAlias = getAlias();
        menuEntry * ptrMenuEntry_propPrevEntry = getPrevEntry();
        menuEntry * ptrMenuEntry_propNextEntry = getNextEntry();
        menuEntry * ptrMenuEntry_propParentEntryList = getParentEntryList();
        {
            std::cout << "[" << "Constructed menuEntry (";
            std::cout << ptrMenuEntry_propThis;
            std::cout << ")]" << std::endl;
        }
        {
            if (alias == NULL) {
                std::cout << std::setw(4) << "" << typeid(ptrMenuEntry_propAlias).name() << "alias: ";
                std::cout << "Undefined" << std::endl;
            }
            else {
                std::cout << std::setw(4) << "" << typeid(ptrMenuEntry_propAlias).name() << "alias: ";
                std::cout << ptrMenuEntry_propAlias << std::endl;
            }
        }
        {
            std::cout << std::setw(4) << "" << typeid(ptrMenuEntry_propPrevEntry).name() << "menuEntry_prevEntry: ";
            if (ptrMenuEntry_propPrevEntry != NULL) {
                std::cout << ptrMenuEntry_propPrevEntry << std::endl;
            }
            else {
                std::cout << ptrMenuEntry_propPrevEntry << std::endl;
            }
        }
        {
            std::cout << std::setw(4) << "" << typeid(ptrMenuEntry_propNextEntry).name() << "menuEntry_nextEntry: ";
            if (ptrMenuEntry_propNextEntry != NULL) {
                std::cout << ptrMenuEntry_propNextEntry << std::endl;
            }
            else {
                std::cout << ptrMenuEntry_propNextEntry << std::endl;
            }
        }
        {
            std::cout << std::setw(4) << "" << typeid(ptrMenuEntry_propParentEntryList).name() << "ptrMenuEntry_parentEntryList: ";
            if (ptrMenuEntry_propParentEntryList != NULL) {
                std::cout << ptrMenuEntry_propParentEntryList << std::endl;
            }
            else {
                std::cout << ptrMenuEntry_propParentEntryList << std::endl;
            }
        }
    }
menuEntry::menuEntry (char * ptrMenuEntry_alias, menuEntry * ptrMenuEntry_prevEntry, menuEntry * ptrMenuEntry_nextEntry, menuEntry * menuEntry_parentEntryList)
    : alias (ptrMenuEntry_alias), menuEntry_prevEntry (ptrMenuEntry_prevEntry), menuEntry_nextEntry (ptrMenuEntry_nextEntry), menuEntry_parentEntryList (menuEntry_parentEntryList)
    {
        menuEntry * ptrMenuEntry_propThis = this;
        char * ptrMenuEntry_propAlias = getAlias();
        menuEntry * ptrMenuEntry_propPrevEntry = getPrevEntry();
        menuEntry * ptrMenuEntry_propNextEntry = getNextEntry();
        menuEntry * ptrMenuEntry_propParentEntryList = getParentEntryList();
        {
            std::cout << "[" << "Constructed menuEntry (";
            std::cout << ptrMenuEntry_propThis;
            std::cout << ")]" << std::endl;
        }
        {
            if (alias == NULL) {
                std::cout << std::setw(4) << "" << typeid(ptrMenuEntry_propAlias).name() << "alias: ";
                std::cout << "Undefined" << std::endl;
            }
            else {
                std::cout << std::setw(4) << "" << typeid(ptrMenuEntry_propAlias).name() << "alias: ";
                std::cout << ptrMenuEntry_propAlias << std::endl;
            }
        }
        {
            std::cout << std::setw(4) << "" << typeid(ptrMenuEntry_propPrevEntry).name() << "menuEntry_prevEntry: ";
            if (ptrMenuEntry_propPrevEntry != NULL) {
                std::cout << ptrMenuEntry_propPrevEntry << std::endl;
            }
            else {
                std::cout << ptrMenuEntry_propPrevEntry << std::endl;
            }
        }
        {
            std::cout << std::setw(4) << "" << typeid(ptrMenuEntry_propNextEntry).name() << "menuEntry_nextEntry: ";
            if (ptrMenuEntry_propNextEntry != NULL) {
                std::cout << ptrMenuEntry_propNextEntry << std::endl;
            }
            else {
                std::cout << ptrMenuEntry_propNextEntry << std::endl;
            }
        }
        {
            std::cout << std::setw(4) << "" << typeid(ptrMenuEntry_propParentEntryList).name() << "ptrMenuEntry_parentEntryList: ";
            if (ptrMenuEntry_propParentEntryList != NULL) {
                std::cout << ptrMenuEntry_propParentEntryList << std::endl;
            }
            else {
                std::cout << ptrMenuEntry_propParentEntryList << std::endl;
            }
        }
    }
menuEntry::~ menuEntry ()
    {
        std::cout << "[" << " Destructed menuEntry " << "]" << std::endl;
    }
void menuEntry::setAlias (char * str)
    {
        alias = str;
    }
char * menuEntry::getAlias ()
    {
        return alias;
    }
void menuEntry::setNextEntry (menuEntry * ptrMenuEntry_nextEntry)
    {
        menuEntry_nextEntry = ptrMenuEntry_nextEntry;
    }
menuEntry * menuEntry::getNextEntry ()
    {
        return menuEntry_nextEntry;
    }
void menuEntry::setPrevEntry (menuEntry * ptrMenuEntry_prevEntry)
    {
        menuEntry_prevEntry = ptrMenuEntry_prevEntry;
    }
menuEntry * menuEntry::getPrevEntry ()
    {
        return menuEntry_prevEntry;
    }
void menuEntry::setParentEntryList (menuEntry * ptrMenuEntry_parentEntryList)
    {
        menuEntry_parentEntryList = ptrMenuEntry_parentEntryList;
    }
menuEntry * menuEntry::getParentEntryList ()
    {
        return menuEntry_parentEntryList;
    }
menuEntryContainer::menuEntryContainer ()
    : menuEntry (), menuEntryContainer_childEntryList (NULL), menuEntryContainer_showContents (false)
    {
        menuEntry * ptrMenuEntry_propThis = this;
        menuEntry * ptrMenuEntryContainer_propChildEntryList = getChildEntryList();
        bool menuEntryContainer_propShowContents = getShowContentsState();
        {
            std::cout << "[" << "Constructed menuEntryContainer (";
            std::cout << ptrMenuEntry_propThis;
            std::cout << ")]" << std::endl;
        }
        {
            std::cout << std::setw(4) << "" << typeid(ptrMenuEntryContainer_propChildEntryList).name() << "ptrMenuEntry_parentEntryList: ";
            if (ptrMenuEntryContainer_propChildEntryList != NULL) {
                std::cout << ptrMenuEntryContainer_propChildEntryList << std::endl;
            }
            else {
                std::cout << ptrMenuEntryContainer_propChildEntryList << std::endl;
            }
        }
        {
            std::cout << std::setw(4) << "" << typeid(menuEntryContainer_propShowContents).name() << "menuEntryContainer_showContents: ";
            if (menuEntryContainer_propShowContents == true) {
                std::cout << menuEntryContainer_propShowContents << std::endl;
            }
            else {
                std::cout << menuEntryContainer_propShowContents << std::endl;
            }
        }
    }
menuEntryContainer::menuEntryContainer (char * ptrMenuEntry_alias, menuEntry * ptrMenuEntry_prevEntry, menuEntry * ptrMenuEntry_nextEntry, menuEntry * menuEntry_parentEntryList, menuEntry * menuEntryContainer_childEntryList, bool menuEntryContainer_showContents_)
    : menuEntry (ptrMenuEntry_alias, ptrMenuEntry_prevEntry, ptrMenuEntry_nextEntry, menuEntry_parentEntryList), menuEntryContainer_childEntryList (menuEntryContainer_childEntryList), menuEntryContainer_showContents (menuEntryContainer_showContents_)
    {
        menuEntry * ptrMenuEntry_propThis = this;
        menuEntry * ptrMenuEntryContainer_propChildEntryList = getChildEntryList();
        bool menuEntryContainer_propShowContents = getShowContentsState();
        {
            std::cout << "[" << "Constructed menuEntryContainer (";
            std::cout << ptrMenuEntry_propThis;
            std::cout << ")]" << std::endl;
        }
        {
            std::cout << std::setw(4) << "" << typeid(ptrMenuEntryContainer_propChildEntryList).name() << "ptrMenuEntry_parentEntryList: ";
            if (ptrMenuEntryContainer_propChildEntryList != NULL) {
                std::cout << ptrMenuEntryContainer_propChildEntryList << std::endl;
            }
            else {
                std::cout << ptrMenuEntryContainer_propChildEntryList << std::endl;
            }
        }
        {
            std::cout << std::setw(4) << "" << typeid(menuEntryContainer_propShowContents).name() << "menuEntryContainer_showContents: ";
            if (menuEntryContainer_propShowContents == true) {
                std::cout << menuEntryContainer_propShowContents << std::endl;
            }
            else {
                std::cout << menuEntryContainer_propShowContents << std::endl;
            }
        }
    }
menuEntryContainer::~ menuEntryContainer ()
    {
        std::cout << "[" << " Destructed menuEntryContainer " << "]" << std::endl;
    }
void menuEntryContainer::setChildEntryList (menuEntry * ptrMenuEntryContainer_childEntryList)
    {
        menuEntryContainer_childEntryList = ptrMenuEntryContainer_childEntryList;
    }
menuEntry * menuEntryContainer::getChildEntryList ()
    {
        return menuEntryContainer_childEntryList;
    }
void menuEntryContainer::setShowContentsState (bool menuEntryContainer_showContents_)
    {
        menuEntryContainer_showContents = menuEntryContainer_showContents_;
    }
bool menuEntryContainer::getShowContentsState ()
    {
        return menuEntryContainer_showContents;
    }
void menuEntryContainer::printMenuEntryData ()
    {
        menuEntry * ptrMenuEntry_propThis = this;
        char * ptrMenuEntry_propAlias = getAlias();
        menuEntry * ptrMenuEntry_propPrevEntry = getPrevEntry();
        menuEntry * ptrMenuEntry_propNextEntry = getNextEntry();
        menuEntry * ptrMenuEntry_propParentEntryList = getParentEntryList();
        menuEntry * ptrMenuEntryContainer_propChildEntryList = getChildEntryList();
        bool menuEntryContainer_propShowContents = getShowContentsState();
        {
            std::cout << "[" << "Displaying menuEntryContainer (";
            std::cout << ptrMenuEntry_propThis;
            std::cout << ")]" << std::endl;
        }
        {
            if (alias == NULL) {
                std::cout << std::setw(4) << "" << typeid(ptrMenuEntry_propAlias).name() << "alias: ";
                std::cout << "Undefined" << std::endl;
            }
            else
            {
                std::cout << std::setw(4) << "" << typeid(ptrMenuEntry_propAlias).name() << "alias: ";
                std::cout << ptrMenuEntry_propAlias << std::endl;
            }
        }
        {
            std::cout << std::setw(4) << "" << typeid(ptrMenuEntry_propPrevEntry).name() << "menuEntry_prevEntry: ";
            if (ptrMenuEntry_propPrevEntry != NULL) {
                std::cout << ptrMenuEntry_propPrevEntry << std::endl;
            }
            else
            {
                std::cout << ptrMenuEntry_propPrevEntry << std::endl;
            }
        }
        {
            std::cout << std::setw(4) << "" << typeid(ptrMenuEntry_propNextEntry).name() << "menuEntry_nextEntry: ";
            if (ptrMenuEntry_propNextEntry != NULL) {
                std::cout << ptrMenuEntry_propNextEntry << std::endl;
            }
            else
            {
                std::cout << ptrMenuEntry_propNextEntry << std::endl;
            }
        }
        {
            std::cout << std::setw(4) << "" << typeid(ptrMenuEntry_propParentEntryList).name() << "ptrMenuEntry_parentEntryList: ";
            if (ptrMenuEntry_propParentEntryList != NULL) {
                std::cout << ptrMenuEntry_propParentEntryList << std::endl;
            }
            else
            {
                std::cout << ptrMenuEntry_propParentEntryList << std::endl;
            }
        }
        {
            std::cout << std::setw(4) << "" << typeid(ptrMenuEntryContainer_propChildEntryList).name() << "ptrMenuEntry_parentEntryList: ";
            if (ptrMenuEntryContainer_propChildEntryList != NULL) {
                std::cout << ptrMenuEntryContainer_propChildEntryList << std::endl;
            }
            else
            {
                std::cout << ptrMenuEntryContainer_propChildEntryList << std::endl;
            }
        }
        {
            std::cout << std::setw(4) << "" << typeid(menuEntryContainer_propShowContents).name() << "menuEntryContainer_showContents: ";
            if (menuEntryContainer_propShowContents == true) {
                std::cout << menuEntryContainer_propShowContents << std::endl;
            }
            else {
                std::cout << menuEntryContainer_propShowContents << std::endl;
            }
        }
    }
menuEntryAction::menuEntryAction ()
    : menuEntry (), menuEntryAction_funcPtr (NULL)
    {
        menuEntry * ptrMenuEntry_propThis = this;
        void (* menuEntryAction_propFuncPtr) = getAction_funcPtr();
        {
            std::cout << "[" << "Created menuEntryAction (";
            std::cout << ptrMenuEntry_propThis;
            std::cout << ")]" << std::endl;
        }
        {
            std::cout << std::setw(4) << "" << typeid(menuEntryAction_propFuncPtr).name() << "menuEntryAction_funcPtr: ";
            if (menuEntryAction_propFuncPtr != NULL) {
                std::cout << menuEntryAction_propFuncPtr << std::endl;
            }
            else {
                std::cout << menuEntryAction_propFuncPtr << std::endl;
            }
        }
    }
menuEntryAction::menuEntryAction (char * ptrMenuEntry_alias, menuEntry * ptrMenuEntry_prevEntry, menuEntry * ptrMenuEntry_nextEntry, menuEntry * menuEntry_parentEntryList, void (* menuEntryAction_funcPtr) ())
    : menuEntry (ptrMenuEntry_alias, ptrMenuEntry_prevEntry, ptrMenuEntry_nextEntry, menuEntry_parentEntryList), menuEntryAction_funcPtr (menuEntryAction_funcPtr)
    {
        menuEntry * ptrMenuEntry_propThis = this;
        void (* menuEntryAction_propFuncPtr) = getAction_funcPtr();
        {
            std::cout << "[" << "Created menuEntryAction (";
            std::cout << ptrMenuEntry_propThis;
            std::cout << ")]" << std::endl;
        }
        {
            std::cout << std::setw(4) << "" << typeid(menuEntryAction_propFuncPtr).name() << "menuEntryAction_funcPtr: ";
            if (menuEntryAction_propFuncPtr != NULL) {
                std::cout << menuEntryAction_propFuncPtr << std::endl;
            }
            else {
                std::cout << menuEntryAction_propFuncPtr << std::endl;
            }
        }
    }
menuEntryAction::~ menuEntryAction ()
    {
        std::cout << "[" << " Destructed menuEntryAction " << "]" << std::endl;
    }
void menuEntryAction::setAction_funcPtr (void (menuEntryAction_linkedFuncPtr) ())
    {
        menuEntryAction_funcPtr = menuEntryAction_linkedFuncPtr;
    }
void * menuEntryAction::getAction_funcPtr ()
    {
        return (void *)menuEntryAction_funcPtr;
    }
void menuEntryAction::callAction_funcPtr ()
    {
        if (menuEntryAction_funcPtr) {
            std::cin.get();
            menuEntryAction_funcPtr();
        }
    }
void menuEntryAction::printMenuEntryData ()
    {
        menuEntry * ptrMenuEntry_propThis = this;
        char * ptrMenuEntry_propAlias = getAlias();
        menuEntry * ptrMenuEntry_propPrevEntry = getPrevEntry();
        menuEntry * ptrMenuEntry_propNextEntry = getNextEntry();
        menuEntry * ptrMenuEntry_propParentEntryList = getParentEntryList();
        void (* menuEntryAction_propFuncPtr) = getAction_funcPtr();
        {
            std::cout << "[" << "Displaying menuEntryAction (";
            std::cout << ptrMenuEntry_propThis;
            std::cout << ")]" << std::endl;
        }
        {
            if (alias == NULL) {
                std::cout << std::setw(4) << "" << typeid(ptrMenuEntry_propAlias).name() << "alias: ";
                std::cout << "Undefined" << std::endl;
            }
            else {
                std::cout << std::setw(4) << "" << typeid(ptrMenuEntry_propAlias).name() << "alias: ";
                std::cout << ptrMenuEntry_propAlias << std::endl;
            }
        }
        {
            std::cout << std::setw(4) << "" << typeid(ptrMenuEntry_propPrevEntry).name() << "menuEntry_prevEntry: ";
            if (ptrMenuEntry_propPrevEntry != NULL) {
                std::cout << ptrMenuEntry_propPrevEntry << std::endl;
            }
            else {
                std::cout << ptrMenuEntry_propPrevEntry << std::endl;
            }
        }
        {
            std::cout << std::setw(4) << "" << typeid(ptrMenuEntry_propNextEntry).name() << "menuEntry_nextEntry: ";
            if (ptrMenuEntry_propNextEntry != NULL) {
                std::cout << ptrMenuEntry_propNextEntry << std::endl;
            }
            else {
                std::cout << ptrMenuEntry_propNextEntry << std::endl;
            }
        }
        {
            std::cout << std::setw(4) << "" << typeid(ptrMenuEntry_propParentEntryList).name() << "ptrMenuEntry_parentEntryList: ";
            if (ptrMenuEntry_propParentEntryList != NULL) {
                std::cout << ptrMenuEntry_propParentEntryList << std::endl;
            }
            else {
                std::cout << ptrMenuEntry_propParentEntryList << std::endl;
            }
        }
        {
            std::cout << std::setw(4) << "" << typeid(menuEntryAction_propFuncPtr).name() << "menuEntryAction_funcPtr: ";
            if (menuEntryAction_propFuncPtr != NULL) {
                std::cout << menuEntryAction_propFuncPtr << std::endl;
            }
            else {
                std::cout << menuEntryAction_propFuncPtr << std::endl;
            }
        }
    }
void printMenu(menuEntry * ptrMenuEntry, unsigned int level, menuEntry * ptrMenuEntrySelected)
    {
        for (; ptrMenuEntry; ptrMenuEntry = (menuEntry *)ptrMenuEntry->getNextEntry()) {
            std::cout << std::setw(level * 4) << "";

            if (ptrMenuEntry == ptrMenuEntrySelected) {
                if (typeid(*ptrMenuEntry) == typeid(menuEntryContainer)) {
                    menuEntryContainer * ptrMenuEntryContainer = (menuEntryContainer *)ptrMenuEntry;
                    if (ptrMenuEntryContainer->getShowContentsState()) {
                        std::cout << "*[-] ";
                    }
                    else {
                        std::cout << "*[+] ";
                    }
                }
                if (typeid(*ptrMenuEntry) == typeid(menuEntryAction)) {
                    std::cout << "*</> ";
                }
                std::cout << ptrMenuEntry->getAlias() << " [ " << ptrMenuEntry << " ]" << std::endl;
            }
            else {
                if (typeid(*ptrMenuEntry) == typeid(menuEntryContainer)) {
                    menuEntryContainer * ptrMenuEntryContainer = (menuEntryContainer *)ptrMenuEntry;
                    if (ptrMenuEntryContainer->getShowContentsState()) {
                        std::cout << " [-] ";
                    }
                    else {
                        std::cout << " [+] ";
                    }
                }
                if (typeid(*ptrMenuEntry) == typeid(menuEntryAction)) {
                    std::cout << " </> ";
                }
                std::cout << ptrMenuEntry->getAlias() << " [ " << ptrMenuEntry << " ]" << std::endl;
            }
            
            if (typeid(*ptrMenuEntry) == typeid(menuEntryContainer)) {
                menuEntryContainer * ptrMenuEntryContainer = (menuEntryContainer *)ptrMenuEntry;
                if (ptrMenuEntryContainer->getChildEntryList() && ptrMenuEntryContainer->getShowContentsState()) {
                    printMenu(ptrMenuEntryContainer->getChildEntryList(), level + 1, ptrMenuEntrySelected);
                }
            }
        }

        return;
    }
