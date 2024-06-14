/*!
 * @file comparison-operable-mock-y.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__MOCK__COMPARISON_OPERABLE_MOCK_Y_CLASS_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__MOCK__COMPARISON_OPERABLE_MOCK_Y_CLASS_HXX

#include <iostream>
#include <string>

#include <sql++/expression/expression.class.h++>
#include <sql++/expression/operation/comparison-operable.class.h++>

namespace sqlxx::test
{
inline namespace expression
{
    ////////////////////////////////////////////////////////////////////////////
    //
    // Class definition
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief @c ComparisonOperable クラスを継承したモッククラス（その二）
     */
    class ComparisonOperableMockY : public virtual ComparisonOperable
    {
    public:
        /*!
         * @brief デストラクタ
         */
        virtual ~ComparisonOperableMockY() override = default;

        /*!
         * @brief この式の文字列表現を返却する
         *
         * @return この式の文字列表現
         */
        virtual auto evaluate() const -> std::string override;

        /*!
         * @brief このオブジェクトを複製する
         *
         * @return 複製したオブジェクトのポインタ
         */
        virtual auto clone() const -> ComparisonOperableMockY const * override;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function declaration
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief ストリーム出力演算
     *
     * @param[in] out 出力ストリーム
     * @param[in] y   モッククラスその二のオブジェクト
     *
     * @return 出力ストリーム
     */
    auto operator<<(std::ostream & out, ComparisonOperableMockY const & y)
        -> std::ostream &;

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    auto ComparisonOperableMockY::evaluate() const -> std::string
    {
        return "'Y'";
    }

    auto ComparisonOperableMockY::clone() const
        -> ComparisonOperableMockY const *
    {
        return new ComparisonOperableMockY { *this };
    }

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function definition
    //
    ////////////////////////////////////////////////////////////////////////////

    auto operator<<(std::ostream & out, ComparisonOperableMockY const & y)
        -> std::ostream &
    {
        return out << y.evaluate();
    }
} // namespace expression
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__MOCK__COMPARISON_OPERABLE_MOCK_Y_CLASS_HXX */
