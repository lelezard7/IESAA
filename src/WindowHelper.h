#ifndef WINDOWHELPER_H_
#define WINDOWHELPER_H_

#include "IField.h"
#include "App.h"


// 0x00000001 - 0x0000000F
#define ErrCode_FieldAlreadyExists   0x00000001

class WindowHelper
{

public:
    WindowHelper();
    virtual ~WindowHelper();

    virtual AppError addField(Field* field) = 0;
    virtual AppError addFieldToProfile(Field* field) = 0;
    virtual AppError addFieldToDefaultFields(Field* field) = 0;

};


#include <functional>

typedef std::function<AppError(Field*)> FieldReceiver;

#define createFieldReceiver(Obj, Func) \
    std::bind(&Func, &Obj, std::placeholders::_1)

#endif
