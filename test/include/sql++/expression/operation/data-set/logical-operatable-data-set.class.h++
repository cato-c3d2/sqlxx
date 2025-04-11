/*!
 * @file logical-operatable-data-set.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__LOGICAL_OPERATABLE_DATA_SET_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__LOGICAL_OPERATABLE_DATA_SET_HXX

#include <vector>

#include <sql++/expression/operation/logical-operatable.class.h++>

#include "../mock/logical-operatable-mock.class.h++"
#include "./logical-operatable-data-set-element.class.h++"

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
     * @brief ≪二項論理演算可能≫のテストケースで使用するデータセットを生成するクラス
     *
     * @see sqlxx::expression::LogicalOperatable              テスト対象クラス
     * @see sqlxx::test::expression::LogicalOperatableDataSet データセット要素
     */
    class LogicalOperatableDataSet
    {
    public:
        /*! @brief ≪二項論理演算可能≫のテストケースで使用するデータセットを生成する */
        static auto for_some_test_case()
            -> std::vector<LogicalOperatableDataSetElement>;
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
     * ----------------------------
     * </pre>
     *
     * [ 凡例 ] @n
     * @li object   ... テスト対象メンバ関数の呼び出し元となるオブジェクト
     * @li argument ... テスト対象メンバ関数の引数
     * @li X        ... テスト対象クラスを継承したモッククラスのオブジェクト
     *
     * @return ≪二項論理演算可能≫のテストケースで使用するデータセット
     *
     * @see sqlxx::expression::LogicalOperatable::logical_and() テスト対象メンバ関数
     * @see sqlxx::expression::LogicalOperatable::logical_or()  テスト対象メンバ関数
     */
    auto LogicalOperatableDataSet::for_some_test_case()
        -> std::vector<LogicalOperatableDataSetElement>
    {
        // clang-format off
        return {
            // _0
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + object   : （特になし）
            // + argument : （特になし）
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                LogicalOperatableMock {},

                // テスト対象メンバ関数の引数
                LogicalOperatableMock {},

                // 期待結果 - logical_and メンバ関数
                LogicalOperatableMock {
                    BinaryOperationKind::LogicalAnd,
                    LogicalOperatableMock {},
                    LogicalOperatableMock {},
                },

                // 期待結果 - logical_or メンバ関数
                LogicalOperatableMock {
                    BinaryOperationKind::LogicalOr,
                    LogicalOperatableMock {},
                    LogicalOperatableMock {},
                },
            },
        };
        // clang-format on
    }
} // namespace expression
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__LOGICAL_OPERATABLE_DATA_SET_HXX */
