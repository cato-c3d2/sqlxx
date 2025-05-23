/*!
 * @file logical-operatable-data-set-element.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__LOGICAL_OPERATABLE_DATA_SET_ELEMENT_CLASS_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__LOGICAL_OPERATABLE_DATA_SET_ELEMENT_CLASS_HXX

#include <iostream>
#include <string>

#include <sql++/expression/operation/logical-operatable.class.h++>

#include "../mock/logical-operatable-mock.class.h++"

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
     * @brief ≪二項論理演算可能≫のテストケースで使用するデータセット要素
     *
     * テスト対象オブジェクト及びテスト対象メンバ関数の期待結果を保持する。 @n
     *
     * @see sqlxx::expression::LogicalOperatable              テスト対象クラス
     * @see sqlxx::test::expression::LogicalOperatableDataSet データセット
     */
    struct LogicalOperatableDataSetElement
    {
        /*!
         * @brief テスト対象オブジェクト
         */
        LogicalOperatableMock object;

        /*!
         * @brief テスト対象メンバ関数の引数
         *
         * @see sqlxx::expression::LogicalOperatable::logical_and() テスト対象メンバ関数
         * @see sqlxx::expression::LogicalOperatable::logical_or()  テスト対象メンバ関数
         */
        LogicalOperatableMock argument;

        /*!
         * @brief 期待結果 - @c logical_and メンバ関数
         *
         * @see sqlxx::expression::LogicalOperatable::logical_and() テスト対象メンバ関数
         */
        LogicalOperatableMock expectation_of_logical_and;

        /*!
         * @brief 期待結果 - @c logical_or メンバ関数
         *
         * @see sqlxx::expression::LogicalOperatable::logical_or() テスト対象メンバ関数
         */
        LogicalOperatableMock expectation_of_logical_or;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function declaration
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief ストリーム出力演算
     *
     * @param[in] out              出力ストリーム
     * @param[in] data_set_element データセット要素
     *
     * @return 出力ストリーム
     */
    auto operator<<(
        std::ostream &                          out,
        LogicalOperatableDataSetElement const & data_set_element)
        -> std::ostream &;

    ////////////////////////////////////////////////////////////////////////////
    //
    // No class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function definition
    //
    ////////////////////////////////////////////////////////////////////////////

    auto operator<<(
        std::ostream &                          out,
        LogicalOperatableDataSetElement const & data_set_element)
        -> std::ostream &
    {
        // clang-format off
        return out << "{ object : \""
                   << data_set_element.object
                   << "\", argument : \""
                   << data_set_element.argument
                   << "\", expectation_of_logical_and : \""
                   << data_set_element.expectation_of_logical_and
                   << "\", expectation_of_logical_or : \""
                   << data_set_element.expectation_of_logical_or
                   << "\" }";
        // clang-format on
    }
} // namespace expression
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__LOGICAL_OPERATABLE_DATA_SET_ELEMENT_CLASS_HXX */
