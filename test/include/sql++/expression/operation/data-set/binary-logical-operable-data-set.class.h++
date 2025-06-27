/*!
 * @file binary-logical-operable-data-set.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__BINARY_LOGICAL_OPERABLE_DATA_SET_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__BINARY_LOGICAL_OPERABLE_DATA_SET_HXX

#include <vector>

#include <sql++/expression/operation/binary-logical-operable.class.h++>

#include "../mock/binary-logical-operable-mock.class.h++"
#include "./binary-logical-operable-data-set-element.class.h++"

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
     * @see sqlxx::expression::BinaryLogicalOperable              テスト対象クラス
     * @see sqlxx::test::expression::BinaryLogicalOperableDataSet データセット要素
     */
    class BinaryLogicalOperableDataSet
    {
    public:
        /*! @brief ≪二項論理演算可能≫のテストケースで使用するデータセットを生成する */
        static auto for_some_test_case()
            -> std::vector<BinaryLogicalOperableDataSetElement>;
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
     * @see sqlxx::expression::BinaryLogicalOperable::logical_and() テスト対象メンバ関数
     * @see sqlxx::expression::BinaryLogicalOperable::logical_or()  テスト対象メンバ関数
     */
    auto BinaryLogicalOperableDataSet::for_some_test_case()
        -> std::vector<BinaryLogicalOperableDataSetElement>
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
                BinaryLogicalOperableMock {},

                // テスト対象メンバ関数の引数
                BinaryLogicalOperableMock {},

                // 期待結果 - logical_and メンバ関数
                BinaryLogicalOperableMock {
                    BinaryOperationKind::LogicalAnd,
                    BinaryLogicalOperableMock {},
                    BinaryLogicalOperableMock {},
                },

                // 期待結果 - logical_or メンバ関数
                BinaryLogicalOperableMock {
                    BinaryOperationKind::LogicalOr,
                    BinaryLogicalOperableMock {},
                    BinaryLogicalOperableMock {},
                },
            },
        };
        // clang-format on
    }
} // namespace expression
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__BINARY_LOGICAL_OPERABLE_DATA_SET_HXX */
