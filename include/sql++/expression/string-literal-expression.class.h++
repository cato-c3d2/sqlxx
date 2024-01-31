/*!
 * @file string-literal-expression.class.h++
 */

#ifndef SQLXX__EXPRESSION__STRING_LITERAL_EXPRESSION_CLASS_HXX
#define SQLXX__EXPRESSION__STRING_LITERAL_EXPRESSION_CLASS_HXX

#include <string>

#include <sql++/expression/literal-expression.class.h++>

namespace sqlxx
{
inline namespace expression
{
    ////////////////////////////////////////////////////////////////////////////
    //
    // Class definition
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief 文字列リテラルを表現するクラス（エイリアス）
     */
    using StringLiteralExpression = LiteralExpression<std::string>;
} // namespace expression
} // namespace sqlxx

#endif // SQLXX__EXPRESSION__STRING_LITERAL_EXPRESSION_CLASS_HXX
