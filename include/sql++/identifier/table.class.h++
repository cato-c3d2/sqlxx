/*!
 * @file table.class.h++
 */

#ifndef SQLXX__IDENTIFIER__TABLE_CLASS_HXX
#define SQLXX__IDENTIFIER__TABLE_CLASS_HXX

////////////////////////////////////////////////////////////////////////////////
//
// Alias declaration
//
////////////////////////////////////////////////////////////////////////////////

#include <sql++/identifier/table-identifier.class.h++>

namespace sqlxx
{
inline namespace identifier
{
    /*!
     * @brief 互換性のために @c TableIdentifier を @c Table として別名定義している
     *
     * @deprecated @link TableIdentifier @endlink を使用してください
     */
    using Table = TableIdentifier;
} // namespace identifier
} // namespace sqlxx

#endif // SQLXX__IDENTIFIER__TABLE_CLASS_HXX
