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


#define FLAG_NULL       0x00000000

#define DTID_Text       0x00010000
#define DTID_Boolean    0x00020000
#define DTID_Time       0x00040000
#define DTID_Date       0x00080000
#define DTID_DateTime   0x00100000

#define RFID_Value      0x00000001
#define RFID_Sheet      0x00000002

#define WID_FieldLineEdit       (DTID_Text     + RFID_Value)
#define WID_FieldTextEdit       (DTID_Text     + RFID_Sheet)
#define WID_FieldCheckBox       (DTID_Boolean  + RFID_Value)
#define WID_FieldTimeEdit       (DTID_Time     + RFID_Value)
#define WID_FieldDateEdit       (DTID_Date     + RFID_Value)
#define WID_FieldDateTimeEdit   (DTID_DateTime + RFID_Value)

#define GetDTID(Wid)   (Wid & 0x11110000)
#define GetRFID(Wid)   (Wid & 0x00001111)

#endif
