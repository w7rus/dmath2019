// conmenu.hpp
//

#ifndef CONMENU_conmenu_h
#define CONMENU_conmenu_h
class menuEntry
{
protected:
  char * alias;
  menuEntry * menuEntry_prevEntry;
  menuEntry * menuEntry_nextEntry;
  menuEntry * menuEntry_parentEntryList;
public:
  menuEntry ();
  menuEntry (char * ptrMenuEntry_alias, menuEntry * ptrMenuEntry_prevEntry, menuEntry * ptrMenuEntry_nextEntry, menuEntry * menuEntry_parentEntryList);
  virtual ~ menuEntry ();
  void setAlias (char * str);
  char * getAlias ();
  void setNextEntry (menuEntry * ptrMenuEntry_nextEntry);
  menuEntry * getNextEntry ();
  void setPrevEntry (menuEntry * ptrMenuEntry_prevEntry);
  menuEntry * getPrevEntry ();
  void setParentEntryList (menuEntry * ptrMenuEntry_parentEntryList);
  menuEntry * getParentEntryList ();
};
class menuEntryContainer : public menuEntry
{
protected:
  menuEntry * menuEntryContainer_childEntryList;
  bool menuEntryContainer_showContents;
public:
  menuEntryContainer ();
  menuEntryContainer (char * ptrMenuEntry_alias, menuEntry * ptrMenuEntry_prevEntry, menuEntry * ptrMenuEntry_nextEntry, menuEntry * menuEntry_parentEntryList, menuEntry * menuEntryContainer_childEntryList, bool menuEntryContainer_showContents_);
  ~ menuEntryContainer ();
  void setChildEntryList (menuEntry * ptrMenuEntryContainer_childEntryList);
  menuEntry * getChildEntryList ();
  void setShowContentsState (bool menuEntryContainer_showContents_);
  bool getShowContentsState ();
  void printMenuEntryData ();
};
class menuEntryAction : public menuEntry
{
protected:
  void (* menuEntryAction_funcPtr) ();
public:
  menuEntryAction ();
  menuEntryAction (char * ptrMenuEntry_alias, menuEntry * ptrMenuEntry_prevEntry, menuEntry * ptrMenuEntry_nextEntry, menuEntry * menuEntry_parentEntryList, void (* menuEntryAction_funcPtr) ());
  ~ menuEntryAction ();
  void setAction_funcPtr (void (menuEntryAction_linkedFuncPtr) ());
  void * getAction_funcPtr ();
  void callAction_funcPtr ();
  void printMenuEntryData ();
};

void printMenu(menuEntry * ptrMenuEntry, unsigned int level, menuEntry * ptrMenuEntrySelected);
#endif
