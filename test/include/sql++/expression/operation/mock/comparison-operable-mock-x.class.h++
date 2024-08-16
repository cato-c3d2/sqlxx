/*!
 * @file comparison-operable-mock-x.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__MOCK__COMPARISON_OPERABLE_MOCK_X_CLASS_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__MOCK__COMPARISON_OPERABLE_MOCK_X_CLASS_HXX

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
     * @brief @c ComparisonOperable クラスを継承したモッククラス（その一）
     */
    class ComparisonOperableMockX : public virtual ComparisonOperable
    {
    public:
        /*!
         * @brief デストラクタ
         */
        virtual ~ComparisonOperableMockX() override = default;

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
        virtual auto clone() const -> ComparisonOperableMockX * override;
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
     * @param[in] x   モッククラスその一のオブジェクト
     *
     * @return 出力ストリーム
     */
    auto operator<<(std::ostream & out, ComparisonOperableMockX const & x)
        -> std::ostream &;

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    auto ComparisonOperableMockX::evaluate() const -> std::string
    {
        return "'X'";
    }

    auto ComparisonOperableMockX::clone() const -> ComparisonOperableMockX *
    {
        return new ComparisonOperableMockX { *this };
    }

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function definition
    //
    ////////////////////////////////////////////////////////////////////////////

    auto operator<<(std::ostream & out, ComparisonOperableMockX const & x)
        -> std::ostream &
    {
        return out << x.evaluate();
    }
} // namespace expression
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__MOCK__COMPARISON_OPERABLE_MOCK_X_CLASS_HXX */
