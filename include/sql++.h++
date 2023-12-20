/*!
 * @file sql++.h++
 */

// NOTE 各名前空間のドキュメントコメントはこのファイルに記述している

#ifndef SQLXX__SQLXX_HXX
#define SQLXX__SQLXX_HXX

#include <sql++/closure/as-closure.class.h++>
#include <sql++/closure/from-closure.class.h++>
#include <sql++/closure/select-closure.class.h++>
#include <sql++/identifier/column-identifier.class.h++>
#include <sql++/identifier/table-identifier.class.h++>
#include <sql++/statement/select-statement.class.h++>

/*!
 * @namespace sqlxx
 *
 * @brief @c sql++ の名前空間
 *
 * C++ の文法上の制約のため @c sql++ ではなく @c sqlxx としている. @n
 */
namespace sqlxx
{

/*!
 * @namespace sqlxx::identifier
 *
 * @brief SQL の識別子 ( identifier ) に関するインライン名前空間
 */
inline namespace identifier
{
    ////////////////////////////////////////////////////////////////////////////
    //
    // Alias declaration
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief @c ColumnIdentifier のエイリアス
     */
    using Column = ColumnIdentifier;

    /*!
     * @brief @c TableIdentifier のエイリアス
     */
    using Table = TableIdentifier;
} // namespace identifier

/*!
 * @namespace sqlxx::closure
 *
 * @brief SQL の句 ( closure ) に関するインライン名前空間
 */
inline namespace closure
{
    /*!
     * @brief @c AsClosure のエイリアス
     */
    using As = AsClosure;

    /*!
     * @brief @c SelectClosure のエイリアス
     */
    using Select = SelectClosure;

    /*!
     * @brief @c FromClosure のエイリアス
     */
    using From = FromClosure;
} // namespace closure

/*!
 * @namespace sqlxx::statement
 *
 * @brief SQL の文 ( statement ) に関するインライン名前空間
 */
inline namespace statement
{}
} // namespace sqlxx

#endif /* SQLXX__SQLXX_HXX */
