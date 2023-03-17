/*!
 * @file sql++.h++
 */

#ifndef SQLXX__SQLXX_HXX
#define SQLXX__SQLXX_HXX

#include <sql++/closure/as-closure.class.h++>
#include <sql++/closure/from-closure.class.h++>
#include <sql++/closure/select-closure.class.h++>
#include <sql++/identifier/column.class.h++>
#include <sql++/identifier/table.class.h++>
#include <sql++/statement/select-statement.class.h++>

////////////////////////////////////////////////////////////////////////////////
//
// Alias declaration
//
////////////////////////////////////////////////////////////////////////////////

/*!
 * @namespace sqlxx
 *
 * @brief @c sql++ の名前空間
 *
 * C++ の文法上の制約のため @c sql++ ではなく @c sqlxx としている. @n
 */
namespace sqlxx
{
    namespace closure
    {
        /*! @brief @c AsClosure のエイリアス */
        using As = AsClosure;

        /*! @brief @c SelectClosure のエイリアス */
        using Select = SelectClosure;

        /*! @brief @c FromClosure のエイリアス */
        using From = FromClosure;
    }
}

// NOTE `namespace sqlxx` のドキュメントコメントはこのファイルに記述している

#endif /* SQLXX__SQLXX_HXX */
