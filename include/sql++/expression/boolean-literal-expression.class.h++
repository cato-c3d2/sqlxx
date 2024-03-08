/*!
 * @file boolean-literal-expression.class.h++
 */

#ifndef SQLXX__EXPRESSION__BOOLEAN_LITERAL_EXPRESSION_CLASS_HXX
#define SQLXX__EXPRESSION__BOOLEAN_LITERAL_EXPRESSION_CLASS_HXX

#include <sql++/expression/basic-literal-expression.class.h++>

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
     * @brief 論理値のリテラルを表現するクラス（エイリアス）
     */
    using BooleanLiteralExpression = BasicLiteralExpression<bool>;
} // namespace expression
} // namespace sqlxx

#endif // SQLXX__EXPRESSION__BOOLEAN_LITERAL_EXPRESSION_CLASS_HXX
