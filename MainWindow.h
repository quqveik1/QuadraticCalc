#pragma once
#include <Manager.h>

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup UI
//! @brief   ������� ����-�������� ����������
//!
//! @see     Manager
//! @endcode
//}----------------------------------------------------------------------------------------------------------------
struct MainWindow : Manager
{
    MainWindow(AbstractAppData* _app) :
        Manager(_app)
    {
    }

    //{----------------------------------------------------------------------------------------------------------------
    //! @ingroup UI
    //! @brief   ������ ������� ���������� ��� ��������� �������� ���������� ��� ��� ������������� �������� ������������ �������� ����
    //!
    //! @param   managerSize       ������ ����� �������� ����, ��������� ��� ���, �� ��� ������ ����������
    //! @param   _newRect          �������� ������ ������ ���������, � ����������� ������� ������ {}
    //!
    //! @return  0
    //!
    //!
    //! @usage @code
    //! appData->mainManager->onSize(appData->systemSettings->SizeOfScreen);
    //! @endcode
    //}----------------------------------------------------------------------------------------------------------------
    virtual int onSize(Vector managerSize, Rect _newRect = {}) override;
};