/*!
 * @file null-literal-expression.class.h++
 */

#ifndef SQLXX__EXPRESSION__NULL_LITERAL_EXPRESSION_CLASS_HXX
#define SQLXX__EXPRESSION__NULL_LITERAL_EXPRESSION_CLASS_HXX

#include <cstddef>

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
     * @brief NULL リテラルを表現するクラス（エイリアス）
     */
    using NullLiteralExpression = LiteralExpression<std::nullptr_t>;
} // namespace expression
} // namespace sqlxx

#endif // SQLXX__EXPRESSION__NULL_LITERAL_EXPRESSION_CLASS_HXX
