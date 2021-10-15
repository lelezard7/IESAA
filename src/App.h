#ifndef APP_H_
#define APP_H_

#define APP_VERSION   0x000000000000
#define APP_NAME      "IESAA"

typedef int ID;

#define ID_Null    -1
#define ID_Start    0
#define ID_Step     1


#define ErrCode_No          0x00000000
#define ErrCode_Undefined   0xFFFFFFFF


#include <QString>

struct AppError
{
    AppError()
        : code(ErrCode_No)
        , description("") {};

    AppError(int code_, QString description_)
        : code(code_)
        , description(description_) {};

    int code;
    QString description;

    operator bool() const
    { return static_cast<bool>(code); };

};

#endif
