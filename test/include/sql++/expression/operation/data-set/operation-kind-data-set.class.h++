/*!
 * @file operation-kind-data-set.class.h++
 */

// FIXME 【要修正】ファイル名を変更する予定 : operation-kind*.h++ => binary-operation-kind*.h++

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__OPERATION_KIND_DATA_SET_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__OPERATION_KIND_DATA_SET_HXX

#include <vector>

#include <sql++/expression/operation/operation-kind.enum-class.h++>

#include "./operation-kind-data-set-element.class.h++"

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
     * @brief ≪二項演算種別≫のテストケースで使用するデータセットを生成するクラス
     *
     * @see sqlxx::expression::BinaryOperationKind              テスト対象オブジェクトの型
     * @see sqlxx::test::expression::BinaryOperationKindDataSet データセット要素
     */
    class BinaryOperationKindDataSet
    {
    public:
        /*! @brief ≪二項演算種別≫のテストケースで使用するデータセットを生成する */
        static auto for_some_test_case()
            -> std::vector<BinaryOperationKindDataSetElement>;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * [ データパターン表 ] @n
     * <pre>
     * -----------------------------
     * |     | BinaryOperationKind |
     * |=====|=====================|
     * |  _0 | None                |
     * |-----|---------------------|
     * |  _1 | EqualTo             |
     * |-----|---------------------|
     * |  _2 | NotEqualTo          |
     * |-----|---------------------|
     * |  _3 | Less                |
     * |-----|---------------------|
     * |  _4 | LessEqual           |
     * |-----|---------------------|
     * |  _5 | Greater             |
     * |-----|---------------------|
     * |  _6 | GreaterEqual        |
     * |-----|---------------------|
     * |  _7 | LogicalNot          |
     * |-----|---------------------|
     * |  _8 | LogicalAnd          |
     * |-----|---------------------|
     * |  _9 | LogicalOr           |
     * |-----|---------------------|
     * | _10 | Is                  |
     * -----------------------------
     * </pre>
     *
     * [ 凡例 ] @n
     * @li BinaryOperationKind ... テスト対象関数の引数となるオブジェクト
     *
     * @return ≪二項演算種別≫のテストケースで使用するデータセット
     *
     * @see sqlxx::expression::to_string() テスト対象関数
     */
    auto BinaryOperationKindDataSet::for_some_test_case()
        -> std::vector<BinaryOperationKindDataSetElement>
    {
        // clang-format off
        return {
            // _0
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + BinaryOperationKind : ≪演算未定≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                BinaryOperationKind::None,

                // 期待結果 - to_string 関数
                "",
            },

            // _1
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + BinaryOperationKind : ≪等値比較演算≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                BinaryOperationKind::EqualTo,

                // 期待結果 - to_string 関数
                "=",
            },

            // _2
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + BinaryOperationKind : ≪非等値比較演算≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                BinaryOperationKind::NotEqualTo,

                // 期待結果 - to_string 関数
                "<>",
            },

            // _3
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + BinaryOperationKind : ≪比較演算（小なり）≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                BinaryOperationKind::Less,

                // 期待結果 - to_string 関数
                "<",
            },

            // _4
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + BinaryOperationKind : ≪比較演算（以下）≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                BinaryOperationKind::LessEqual,

                // 期待結果 - to_string 関数
                "<=",
            },

            // _5
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + BinaryOperationKind : ≪比較演算（大なり）≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                BinaryOperationKind::Greater,

                // 期待結果 - to_string 関数
                ">",
            },

            // _6
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + BinaryOperationKind : ≪比較演算（以上）≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                BinaryOperationKind::GreaterEqual,

                // 期待結果 - to_string 関数
                ">=",
            },

            // _7
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + BinaryOperationKind : ≪論理否定演算≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                BinaryOperationKind::LogicalNot,

                // 期待結果 - to_string 関数
                "NOT",
            },

            // _8
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + BinaryOperationKind : ≪論理積演算≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                BinaryOperationKind::LogicalAnd,

                // 期待結果 - to_string 関数
                "AND",
            },

            // _9
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + BinaryOperationKind : ≪論理和演算≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                BinaryOperationKind::LogicalOr,

                // 期待結果 - to_string 関数
                "OR",
            },

            // _10
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + BinaryOperationKind : ≪IS演算≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                BinaryOperationKind::Is,

                // 期待結果 - to_string 関数
                "IS",
            },
        };
        // clang-format on
    }
} // namespace expression
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__OPERATION_KIND_DATA_SET_HXX */
