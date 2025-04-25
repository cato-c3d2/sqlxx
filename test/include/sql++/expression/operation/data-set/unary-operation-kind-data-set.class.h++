/*!
 * @file unary-operation-kind-data-set.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__UNARY_OPERATION_KIND_DATA_SET_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__UNARY_OPERATION_KIND_DATA_SET_HXX

#include <vector>

#include <sql++/expression/operation/unary-operation-kind.enum-class.h++>

#include "./unary-operation-kind-data-set-element.class.h++"

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
     * @brief ≪単項演算種別≫のテストケースで使用するデータセットを生成するクラス
     *
     * @see sqlxx::expression::UnaryOperationKind              テスト対象列挙型
     * @see sqlxx::test::expression::UnaryOperationKindDataSet データセット要素
     */
    class UnaryOperationKindDataSet
    {
    public:
        /*! @brief ≪単項演算種別≫のテストケースで使用するデータセットを生成する */
        static auto for_some_test_case()
            -> std::vector<UnaryOperationKindDataSetElement>;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * [ データパターン表 ] @n
     * <pre>
     * ---------------------------
     * |    | UnaryOperationKind |
     * |====|====================|
     * | _0 | None               |
     * |----|--------------------|
     * | _1 | LogicalNot         |
     * ---------------------------
     * </pre>
     *
     * [ 凡例 ] @n
     * @li UnaryOperationKind : テスト対象関数の引数となるオブジェクト
     *
     * @return ≪単項演算種別≫のテストケースで使用するデータセット
     *
     * @see sqlxx::expression::to_string() テスト対象関数
     */
    auto UnaryOperationKindDataSet::for_some_test_case()
        -> std::vector<UnaryOperationKindDataSetElement>
    {
        // clang-format off
        return {
            // _0
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + UnaryOperationKind : ≪演算種別未定≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                UnaryOperationKind::None,

                // 期待結果 - to_string 関数
                "",
            },
            // _1
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + UnaryOperationKind : ≪論理否定演算≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                UnaryOperationKind::LogicalNot,

                // 期待結果 - to_string 関数
                "NOT",
            },
        };
        // clang-format on
    }
} // namespace expression
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__UNARY_OPERATION_KIND_DATA_SET_HXX */
