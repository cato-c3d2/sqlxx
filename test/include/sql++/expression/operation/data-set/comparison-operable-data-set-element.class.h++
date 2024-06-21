/*!
 * @file comparison-operable-data-set-element.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__COMPARISON_OPERABLE_DATA_SET_ELEMENT_CLASS_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__COMPARISON_OPERABLE_DATA_SET_ELEMENT_CLASS_HXX

#include <iostream>
#include <string>

#include <sql++/expression/condition-expression.class.h++>
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
     * @brief ≪比較演算式≫のテストケースで使用するデータセット要素
     *
     * テスト対象のオブジェクトとテスト対象のメンバ関数の期待結果を保持する。
     *
     * @see sqlxx::expression::ComparisonOperable              テスト対象クラス
     * @see sqlxx::test::expression::ComparisonOperableDataSet データセット
     */
    struct ComparisonOperableDataSetElement
    {
        /*!
         * @brief テスト対象オブジェクト
         */
        // TODO 暫定的に生のポインタを使用しているが、将来的にスマートポインタに変更する予定。
        ComparisonOperable * object;

        /*!
         * @brief テスト対象メンバ関数の引数
         *
         * @see sqlxx::expression::ComparisonOperable::equal_to()      テスト対象メンバ関数
         * @see sqlxx::expression::ComparisonOperable::not_equal_to()  テスト対象メンバ関数
         * @see sqlxx::expression::ComparisonOperable::less()          テスト対象メンバ関数
         * @see sqlxx::expression::ComparisonOperable::less_equal()    テスト対象メンバ関数
         * @see sqlxx::expression::ComparisonOperable::greater()       テスト対象メンバ関数
         * @see sqlxx::expression::ComparisonOperable::greater_equal() テスト対象メンバ関数
         * @see sqlxx::expression::ComparisonOperable::is()            テスト対象メンバ関数
         */
        // TODO 暫定的に生のポインタを使用しているが、将来的にスマートポインタに変更する予定。
        ComparisonOperable * argument;

        /*!
         * @brief 期待結果 - @c equal_to メンバ関数
         *
         * @see sqlxx::expression::ComparisonOperable::equal_to() テスト対象メンバ関数
         */
        ConditionExpression expectation_of_equal_to;

        /*!
         * @brief 期待結果 - @c not_equal_to メンバ関数
         *
         * @see sqlxx::expression::ComparisonOperable::not_equal_to() テスト対象メンバ関数
         */
        ConditionExpression expectation_of_not_equal_to;

        /*!
         * @brief 期待結果 - @c less メンバ関数
         *
         * @see sqlxx::expression::ComparisonOperable::less() テスト対象メンバ関数
         */
        ConditionExpression expectation_of_less;

        /*!
         * @brief 期待結果 - @c less_equal メンバ関数
         *
         * @see sqlxx::expression::ComparisonOperable::less_equal() テスト対象メンバ関数
         */
        ConditionExpression expectation_of_less_equal;

        /*!
         * @brief 期待結果 - @c greater メンバ関数
         *
         * @see sqlxx::expression::ComparisonOperable::greater() テスト対象メンバ関数
         */
        ConditionExpression expectation_of_greater;

        /*!
         * @brief 期待結果 - @c greater_equal メンバ関数
         *
         * @see sqlxx::expression::ComparisonOperable::greater_equal() テスト対象メンバ関数
         */
        ConditionExpression expectation_of_greater_equal;

        /*!
         * @brief 期待結果 - @c is メンバ関数
         *
         * @see sqlxx::expression::ComparisonOperable::is() テスト対象メンバ関数
         */
        ConditionExpression expectation_of_is;
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
        std::ostream &                           out,
        ComparisonOperableDataSetElement const & data_set_element)
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
        std::ostream &                           out,
        ComparisonOperableDataSetElement const & data_set_element)
        -> std::ostream &
    {
        std::string const object_as_string =
            data_set_element.object ? data_set_element.object->evaluate()
                                    : "(null-pointer)";
        std::string const argument_as_string =
            data_set_element.argument ? data_set_element.argument->evaluate()
                                      : "(null-pointer)";

        // clang-format off
        return out << "{ object : \""
                   << object_as_string
                   << "\", argument : \""
                   << argument_as_string
                   << "\", expectation_of_equal_to : \""
                   << data_set_element.expectation_of_equal_to
                   << "\", expectation_of_not_equal_to : \""
                   << data_set_element.expectation_of_not_equal_to
                   << "\", expectation_of_less : \""
                   << data_set_element.expectation_of_less
                   << "\", expectation_of_less_equal : \""
                   << data_set_element.expectation_of_less_equal
                   << "\", expectation_of_greater : \""
                   << data_set_element.expectation_of_greater
                   << "\", expectation_of_greater_equal : \""
                   << data_set_element.expectation_of_greater_equal
                   << "\", expectation_of_is : \""
                   << data_set_element.expectation_of_is
                   << "\" }";
        // clang-format on
    }
} // namespace expression
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__COMPARISON_OPERABLE_DATA_SET_ELEMENT_CLASS_HXX */
