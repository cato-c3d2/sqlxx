/*!
 * @file integer-literal-expression.class.h++
 */

#ifndef SQLXX__EXPRESSION__INTEGER_LITERAL_EXPRESSION_CLASS_HXX
#define SQLXX__EXPRESSION__INTEGER_LITERAL_EXPRESSION_CLASS_HXX

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
     * @brief 整数リテラルを表現するクラス（エイリアス）
     */
    using IntegerLiteralExpression = BasicLiteralExpression<int>;
} // namespace expression
} // namespace sqlxx

#endif // SQLXX__EXPRESSION__INTEGER_LITERAL_EXPRESSION_CLASS_HXX
