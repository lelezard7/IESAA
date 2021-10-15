#include "AppStorage.h"


static DefaultFieldsCreator defaultFieldsCreator_s;
DefaultFieldsCreator* getDefaultFieldsCreator()
{ return &defaultFieldsCreator_s; }

static NamesSetsManager namesSetsManager_s;
NamesSetsManager* getNamesSetsManager()
{ return &namesSetsManager_s; }
