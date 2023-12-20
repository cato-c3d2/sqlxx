/*!
 * @file column.class.h++
 */

#ifndef SQLXX__IDENTIFIER__COLUMN_CLASS_HXX
#define SQLXX__IDENTIFIER__COLUMN_CLASS_HXX

#include <sql++/identifier/column-identifier.class.h++>

namespace sqlxx
{
inline namespace identifier
{
    ////////////////////////////////////////////////////////////////////////////
    //
    // Alias declaration
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief 互換性のために @c ColumnIdentifier を @c Column として別名定義している
     *
     * @deprecated @link ColumnIdentifier @endlink を使用してください
     */
    using Column [[deprecated("please use 'ColumnIdentifier'")]] =
        ColumnIdentifier;
} // namespace identifier
} // namespace sqlxx

#endif // SQLXX__IDENTIFIER__COLUMN_CLASS_HXX
