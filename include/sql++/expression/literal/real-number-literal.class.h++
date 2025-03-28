/*!
 * @file real-number-literal.class.h++
 */

#ifndef SQLXX__EXPRESSION__LITERAL__REAL_NUMBER_LITERAL_CLASS_HXX
#define SQLXX__EXPRESSION__LITERAL__REAL_NUMBER_LITERAL_CLASS_HXX

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
     * @brief ≪実数リテラル式≫を表現するクラス（エイリアステンプレート）
     */
    using RealNumberLiteral = BasicLiteral<float>;
} // namespace expression
} // namespace sqlxx

#endif // SQLXX__EXPRESSION__LITERAL__REAL_NUMBER_LITERAL_CLASS_HXX
