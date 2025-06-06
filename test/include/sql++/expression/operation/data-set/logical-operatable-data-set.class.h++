/*!
 * @file logical-operatable-data-set.class.h++
 */

// FIXME 【要修正】ファイル名を変更する予定 : logical-operatable*.h++ => logical-operable*.h++

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
     * @see sqlxx::expression::LogicalOperable              テスト対象クラス
     * @see sqlxx::test::expression::LogicalOperableDataSet データセット要素
     */
    class LogicalOperableDataSet
    {
    public:
        /*! @brief ≪二項論理演算可能≫のテストケースで使用するデータセットを生成する */
        static auto for_some_test_case()
            -> std::vector<LogicalOperableDataSetElement>;
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
     * @li object   : テスト対象メンバ関数の呼び出し元となるオブジェクト
     * @li argument : テスト対象メンバ関数の引数
     * @li X        : テスト対象クラスを継承したモッククラスのオブジェクト
     *
     * @return ≪二項論理演算可能≫のテストケースで使用するデータセット
     *
     * @see sqlxx::expression::LogicalOperable::logical_and() テスト対象メンバ関数
     * @see sqlxx::expression::LogicalOperable::logical_or()  テスト対象メンバ関数
     */
    auto LogicalOperableDataSet::for_some_test_case()
        -> std::vector<LogicalOperableDataSetElement>
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
                LogicalOperableMock {},

                // テスト対象メンバ関数の引数
                LogicalOperableMock {},

                // 期待結果 - logical_and メンバ関数
                LogicalOperableMock {
                    BinaryOperationKind::LogicalAnd,
                    LogicalOperableMock {},
                    LogicalOperableMock {},
                },

                // 期待結果 - logical_or メンバ関数
                LogicalOperableMock {
                    BinaryOperationKind::LogicalOr,
                    LogicalOperableMock {},
                    LogicalOperableMock {},
                },
            },
        };
        // clang-format on
    }
} // namespace expression
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__LOGICAL_OPERATABLE_DATA_SET_HXX */
