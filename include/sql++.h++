/*!
 * @file sql++.h++
 */

// NOTE 各名前空間のドキュメントコメントはこのファイルに記述している

#ifndef SQLXX__SQLXX_HXX
#define SQLXX__SQLXX_HXX

#include <sql++/clause/as-clause.class.h++>
#include <sql++/clause/from-clause.class.h++>
#include <sql++/clause/select-clause.class.h++>
#include <sql++/clause/where-clause.class.h++>
#include <sql++/expression/condition-expression.class.h++>
#include <sql++/expression/grouped-expression.class.h++>
#include <sql++/expression/identifier-expression.class.h++>
#include <sql++/expression/integer-literal-expression.class.h++>
#include <sql++/expression/logical-not-expression.class.h++>
#include <sql++/expression/null-literal-expression.class.h++>
#include <sql++/expression/string-literal-expression.class.h++>
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
 * @namespace sqlxx::clause
 *
 * @brief SQL の句 ( clause ) に関するインライン名前空間
 */
inline namespace clause
{
    /*!
     * @brief @c AsClause のエイリアス
     */
    using As = AsClause;

    /*!
     * @brief @c SelectClause のエイリアス
     */
    using Select = SelectClause;

    /*!
     * @brief @c FromClause のエイリアス
     */
    using From = FromClause;

    /*!
     * @brief @c WhereClause のエイリアス
     */
    using Where = WhereClause;
} // namespace clause

/*!
 * @namespace sqlxx::expression
 *
 * @brief SQL の式 ( expression ) に関するインライン名前空間
 */
inline namespace expression
{
    /*!
     * @brief @c IdentifierExpression のエイリアス
     */
    using Identifier = IdentifierExpression;

    /*!
     * @brief @c IntegerLiteralExpression のエイリアス
     */
    using IntegerLiteral = IntegerLiteralExpression;

    /*!
     * @brief @c StringLiteralExpression のエイリアス
     */
    using StringLiteral = StringLiteralExpression;

    /*!
     * @brief @c NullLiteralExpression のエイリアス
     */
    using NullLiteral = NullLiteralExpression;

    /*!
     * @brief NULL リテラルのオブジェクト
     */
    static NullLiteral null {};
} // namespace expression

/*!
 * @namespace sqlxx::statement
 *
 * @brief SQL の文 ( statement ) に関するインライン名前空間
 */
inline namespace statement
{}
} // namespace sqlxx

#endif /* SQLXX__SQLXX_HXX */
