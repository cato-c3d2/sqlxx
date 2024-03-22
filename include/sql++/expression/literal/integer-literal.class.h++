/*!
 * @file integer-literal.class.h++
 */

#ifndef SQLXX__EXPRESSION__LITERAL__INTEGER_LITERAL_CLASS_HXX
#define SQLXX__EXPRESSION__LITERAL__INTEGER_LITERAL_CLASS_HXX

#include <sql++/expression/literal/basic-literal.class.h++>

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
    using IntegerLiteral = BasicLiteral<int>;
} // namespace expression
} // namespace sqlxx

#endif // SQLXX__EXPRESSION__LITERAL__INTEGER_LITERAL_CLASS_HXX
