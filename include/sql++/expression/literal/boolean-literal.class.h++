/*!
 * @file boolean-literal.class.h++
 */

#ifndef SQLXX__EXPRESSION__LITERAL__BOOLEAN_LITERAL_CLASS_HXX
#define SQLXX__EXPRESSION__LITERAL__BOOLEAN_LITERAL_CLASS_HXX

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
     * @brief 論理値のリテラルを表現するクラス（エイリアス）
     */
    using BooleanLiteral = BasicLiteral<bool>;
} // namespace expression
} // namespace sqlxx

#endif // SQLXX__EXPRESSION__LITERAL__BOOLEAN_LITERAL_CLASS_HXX
