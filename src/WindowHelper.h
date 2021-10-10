#ifndef WINDOWHELPER_H_
#define WINDOWHELPER_H_

#include "IField.h"


class WindowHelper
{

public:
    WindowHelper();
    virtual ~WindowHelper();

    virtual bool addField(Field* field) = 0;
    virtual bool addFieldToProfile(Field* field) = 0;
    virtual bool addFieldToDefaultFields(Field* field) = 0;

};


#include <functional>

typedef std::function<bool(Field*)> FieldReceiver;

#define createFieldReceiver(Obj, Func) \
    std::bind(&Func, &Obj, std::placeholders::_1)

#endif
