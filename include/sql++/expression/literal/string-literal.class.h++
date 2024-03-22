/*!
 * @file string-literal.class.h++
 */

#ifndef SQLXX__EXPRESSION__LITERAL__STRING_LITERAL_CLASS_HXX
#define SQLXX__EXPRESSION__LITERAL__STRING_LITERAL_CLASS_HXX

#include <string>

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
     * @brief 文字列リテラルを表現するクラス（エイリアス）
     */
    using StringLiteral = BasicLiteral<std::string>;
} // namespace expression
} // namespace sqlxx

#endif // SQLXX__EXPRESSION__LITERAL__STRING_LITERAL_CLASS_HXX
