/*!
 * @file real-number-literal-expression.class.h++
 */

#ifndef SQLXX__EXPRESSION__LITERAL__REAL_NUMBER_LITERAL_EXPRESSION_CLASS_HXX
#define SQLXX__EXPRESSION__LITERAL__REAL_NUMBER_LITERAL_EXPRESSION_CLASS_HXX

#include <sql++/expression/literal/basic-literal-expression.class.h++>

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
     * @brief 実数リテラルを表現するクラス（エイリアス）
     */
    using RealNumberLiteralExpression = BasicLiteralExpression<float>;
} // namespace expression
} // namespace sqlxx

#endif // SQLXX__EXPRESSION__LITERAL__REAL_NUMBER_LITERAL_EXPRESSION_CLASS_HXX
