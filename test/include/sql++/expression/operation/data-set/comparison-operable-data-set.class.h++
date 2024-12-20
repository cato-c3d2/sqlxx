/*!
 * @file comparison-operable-data-set.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__COMPARISON_OPERABLE_DATA_SET_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__COMPARISON_OPERABLE_DATA_SET_HXX

#include <vector>

#include <sql++/expression/operation/binary-operation.class.h++>
#include <sql++/expression/operation/comparison-operable.class.h++>

#include "../mock/comparison-operable-mock-x.class.h++"
#include "../mock/comparison-operable-mock-y.class.h++"
#include "./comparison-operable-data-set-element.class.h++"

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
     * @brief ≪比較演算式≫のテストケースで使用するデータセットを生成するクラス
     *
     * @see sqlxx::expression::ComparisonOperable              テスト対象クラス
     * @see sqlxx::test::expression::ComparisonOperableDataSet データセット要素
     */
    class ComparisonOperableDataSet
    {
    public:
        /*! @brief ≪比較演算式≫のテストケースで使用するデータセットを生成する */
        static auto for_some_test_case()
            -> std::vector<ComparisonOperableDataSetElement>;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * [ データパターン表 ] @n
     * <pre>
     * ----------------------------
     * |    | object   | argument |
     * |====|==========|==========|
     * | _0 | X        | X        |
     * |----|          |----------|
     * | _1 |          | Y        |
     * |----|----------|----------|
     * | _2 | Y        | X        |
     * |----|          |----------|
     * | _3 |          | Y        |
     * ----------------------------
     * </pre>
     *
     * [ 凡例 ] @n
     * @li object   ... テスト対象メンバ関数の呼び出し元となるオブジェクト
     * @li argument ... テスト対象メンバ関数の引数
     * @li X        ... テスト対象クラスを継承したモッククラス（その一）のオブジェクト
     * @li Y        ... テスト対象クラスを継承したモッククラス（その二）のオブジェクト
     *
     * @return ≪比較演算式≫のテストケースで使用するデータセット
     *
     * @see sqlxx::expression::ComparisonOperable::equal_to()      テスト対象メンバ関数
     * @see sqlxx::expression::ComparisonOperable::not_equal_to()  テスト対象メンバ関数
     * @see sqlxx::expression::ComparisonOperable::less()          テスト対象メンバ関数
     * @see sqlxx::expression::ComparisonOperable::less_equal()    テスト対象メンバ関数
     * @see sqlxx::expression::ComparisonOperable::greater()       テスト対象メンバ関数
     * @see sqlxx::expression::ComparisonOperable::greater_equal() テスト対象メンバ関数
     * @see sqlxx::expression::ComparisonOperable::is()            テスト対象メンバ関数
     */
    auto ComparisonOperableDataSet::for_some_test_case()
        -> std::vector<ComparisonOperableDataSetElement>
    {
        // clang-format off
        return {
            // _0
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + object   : X
            // + argument : X
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                new ComparisonOperableMockX {},

                // テスト対象メンバ関数の引数
                new ComparisonOperableMockX {},

                // 期待結果 - equal_to メンバ関数
                BinaryOperation {
                    BinaryOperationKind::EqualTo,
                    new ComparisonOperableMockX {},
                    new ComparisonOperableMockX {},
                },

                // 期待結果 - not_equal_to メンバ関数
                BinaryOperation {
                    BinaryOperationKind::NotEqualTo,
                    new ComparisonOperableMockX {},
                    new ComparisonOperableMockX {},
                },

                // 期待結果 - less メンバ関数
                BinaryOperation {
                    BinaryOperationKind::Less,
                    new ComparisonOperableMockX {},
                    new ComparisonOperableMockX {},
                },

                // 期待結果 - less_equal メンバ関数
                BinaryOperation {
                    BinaryOperationKind::LessEqual,
                    new ComparisonOperableMockX {},
                    new ComparisonOperableMockX {},
                },

                // 期待結果 - greater メンバ関数
                BinaryOperation {
                    BinaryOperationKind::Greater,
                    new ComparisonOperableMockX {},
                    new ComparisonOperableMockX {},
                },

                // 期待結果 - greater_equal メンバ関数
                BinaryOperation {
                    BinaryOperationKind::GreaterEqual,
                    new ComparisonOperableMockX {},
                    new ComparisonOperableMockX {},
                },

                // 期待結果 - is メンバ関数
                BinaryOperation {
                    BinaryOperationKind::Is,
                    new ComparisonOperableMockX {},
                    new ComparisonOperableMockX {},
                },
            },

            // _1
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + object   : X
            // + argument : Y
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                new ComparisonOperableMockX {},

                // テスト対象メンバ関数の引数
                new ComparisonOperableMockY {},

                // 期待結果 - equal_to メンバ関数
                BinaryOperation {
                    BinaryOperationKind::EqualTo,
                    new ComparisonOperableMockX {},
                    new ComparisonOperableMockY {},
                },

                // 期待結果 - not_equal_to メンバ関数
                BinaryOperation {
                    BinaryOperationKind::NotEqualTo,
                    new ComparisonOperableMockX {},
                    new ComparisonOperableMockY {},
                },

                // 期待結果 - less メンバ関数
                BinaryOperation {
                    BinaryOperationKind::Less,
                    new ComparisonOperableMockX {},
                    new ComparisonOperableMockY {},
                },

                // 期待結果 - less_equal メンバ関数
                BinaryOperation {
                    BinaryOperationKind::LessEqual,
                    new ComparisonOperableMockX {},
                    new ComparisonOperableMockY {},
                },

                // 期待結果 - greater メンバ関数
                BinaryOperation {
                    BinaryOperationKind::Greater,
                    new ComparisonOperableMockX {},
                    new ComparisonOperableMockY {},
                },

                // 期待結果 - greater_equal メンバ関数
                BinaryOperation {
                    BinaryOperationKind::GreaterEqual,
                    new ComparisonOperableMockX {},
                    new ComparisonOperableMockY {},
                },

                // 期待結果 - is メンバ関数
                BinaryOperation {
                    BinaryOperationKind::Is,
                    new ComparisonOperableMockX {},
                    new ComparisonOperableMockY {},
                },
            },

            // _2
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + object   : Y
            // + argument : X
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                new ComparisonOperableMockY {},

                // テスト対象メンバ関数の引数
                new ComparisonOperableMockX {},

                // 期待結果 - equal_to メンバ関数
                BinaryOperation {
                    BinaryOperationKind::EqualTo,
                    new ComparisonOperableMockY {},
                    new ComparisonOperableMockX {},
                },

                // 期待結果 - not_equal_to メンバ関数
                BinaryOperation {
                    BinaryOperationKind::NotEqualTo,
                    new ComparisonOperableMockY {},
                    new ComparisonOperableMockX {},
                },

                // 期待結果 - less メンバ関数
                BinaryOperation {
                    BinaryOperationKind::Less,
                    new ComparisonOperableMockY {},
                    new ComparisonOperableMockX {},
                },

                // 期待結果 - less_equal メンバ関数
                BinaryOperation {
                    BinaryOperationKind::LessEqual,
                    new ComparisonOperableMockY {},
                    new ComparisonOperableMockX {},
                },

                // 期待結果 - greater メンバ関数
                BinaryOperation {
                    BinaryOperationKind::Greater,
                    new ComparisonOperableMockY {},
                    new ComparisonOperableMockX {},
                },

                // 期待結果 - greater_equal メンバ関数
                BinaryOperation {
                    BinaryOperationKind::GreaterEqual,
                    new ComparisonOperableMockY {},
                    new ComparisonOperableMockX {},
                },

                // 期待結果 - is メンバ関数
                BinaryOperation {
                    BinaryOperationKind::Is,
                    new ComparisonOperableMockY {},
                    new ComparisonOperableMockX {},
                },
            },

            // _3
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + object   : Y
            // + argument : Y
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                new ComparisonOperableMockY {},

                // テスト対象メンバ関数の引数
                new ComparisonOperableMockY {},

                // 期待結果 - equal_to メンバ関数
                BinaryOperation {
                    BinaryOperationKind::EqualTo,
                    new ComparisonOperableMockY {},
                    new ComparisonOperableMockY {},
                },

                // 期待結果 - not_equal_to メンバ関数
                BinaryOperation {
                    BinaryOperationKind::NotEqualTo,
                    new ComparisonOperableMockY {},
                    new ComparisonOperableMockY {},
                },

                // 期待結果 - less メンバ関数
                BinaryOperation {
                    BinaryOperationKind::Less,
                    new ComparisonOperableMockY {},
                    new ComparisonOperableMockY {},
                },

                // 期待結果 - less_equal メンバ関数
                BinaryOperation {
                    BinaryOperationKind::LessEqual,
                    new ComparisonOperableMockY {},
                    new ComparisonOperableMockY {},
                },

                // 期待結果 - greater メンバ関数
                BinaryOperation {
                    BinaryOperationKind::Greater,
                    new ComparisonOperableMockY {},
                    new ComparisonOperableMockY {},
                },

                // 期待結果 - greater_equal メンバ関数
                BinaryOperation {
                    BinaryOperationKind::GreaterEqual,
                    new ComparisonOperableMockY {},
                    new ComparisonOperableMockY {},
                },

                // 期待結果 - is メンバ関数
                BinaryOperation {
                    BinaryOperationKind::Is,
                    new ComparisonOperableMockY {},
                    new ComparisonOperableMockY {},
                },
            },
        };
        // clang-format on
    }
} // namespace expression
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__COMPARISON_OPERABLE_DATA_SET_HXX */
