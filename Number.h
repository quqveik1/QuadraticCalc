#pragma once


//{----------------------------------------------------------------------------------------------------------------
//! @ingroup SolutionSystem
//! @brief   ����� �����
//!
//! @usage @code
//! Number a, b, c;
//! a.num = _a;
//! b.num = _b;
//! c.num = _c;
//! Number solutions[2] = {};
//! int length = solveExpression(a, b, c, solutions);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------
struct Number
{
    //{----------------------------------------------------------------------------------------------------------------
    //! @ingroup SolutionSystem
    //! @brief   ����� � ���� double
    //! @endcode
    //}----------------------------------------------------------------------------------------------------------------
    double num;
    //{----------------------------------------------------------------------------------------------------------------
    //! @ingroup SolutionSystem
    //! @brief   ����� ������ ����������� � ������������ � toString
    //! @endcode
    //}----------------------------------------------------------------------------------------------------------------
    static const int stringNumberSize = 200;

    //{----------------------------------------------------------------------------------------------------------------
    //! @ingroup SolutionSystem
    //! @brief   ������������ �����(�����) � ������
    //!
    //! @see     unitTest()
    //! 
    //! @return  ����������� ������ �� char ������ stringNumberSize
    //!
    //! @usage @code
    //! Number d = {};
    //! d.num = 52;
    //! printf("%s", d.toString());
    //! @endcode
    //}----------------------------------------------------------------------------------------------------------------
    const char* toString();
};